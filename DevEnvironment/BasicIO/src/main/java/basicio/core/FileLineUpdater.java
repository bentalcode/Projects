package basicio.core;

import base.core.ArrayLists;
import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import base.interfaces.IDestructorHandler;
import basicio.BasicIOException;
import basicio.interfaces.ILineReader;
import basicio.interfaces.ILineUpdater;
import basicio.interfaces.IUpdateRecord;
import basicio.interfaces.LineSeparatorType;
import basicio.interfaces.MatchPolicyType;
import java.io.RandomAccessFile;
import java.nio.file.Path;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.regex.Matcher;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The FileLineUpdater class implements an updater of lines of a file.
 */
public final class FileLineUpdater implements ILineUpdater, ICloseable {
    private final RandomAccessFile randomAccessFile;
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The FileLineUpdater constructor.
     */
    public FileLineUpdater(Path path) {
        RandomAccessFile randomAccessFile = RandomAccessFiles.create(path, "rw");
        this.destructorHandler.register(randomAccessFile);
        this.randomAccessFile = randomAccessFile;
    }

    /**
     * Updates a line that matches an update record.
     * The search direction is from top to bottom.
     * Returns the number of lines which got updated.
     */
    @Override
    public int update(IUpdateRecord updateRecord) {
        Conditions.validateNotNull(
            updateRecord,
            "The update record.");

        List<IUpdateRecord> updateRecords = ArrayLists.make(updateRecord);

        return this.update(updateRecords);
    }

    /**
     * Updates a line that matches an update record.
     * The search direction is from bottom to top.
     * Returns the number of lines which got updated.
     */
    @Override
    public int updateFromEnd(IUpdateRecord updateRecord) {
        Conditions.validateNotNull(
            updateRecord,
            "The update record.");

        List<IUpdateRecord> updateRecords = ArrayLists.make(updateRecord);

        return this.updateFromEnd(updateRecords);
    }

    /**
     * Updates lines that matches update records.
     * The search direction is from top to bottom.
     * Returns the number of lines which got updated.
     */
    @Override
    public int update(List<IUpdateRecord> updateRecords) {
        Conditions.validateNotNull(
            updateRecords,
            "The update records.");

        //
        // Create the reader of lines...
        //
        FileLineReader reader = new FileLineReader(this.randomAccessFile);
        this.destructorHandler.register(reader);

        //
        // Updates the lines...
        //
        return this.update(reader, updateRecords);
    }

    /**
     * Updates lines that matches update records.
     * The search direction is from bottom to top.
     * Returns the number of lines which got updated.
     */
    @Override
    public int updateFromEnd(List<IUpdateRecord> updateRecords) {
        Conditions.validateNotNull(
            updateRecords,
            "The update records.");

        //
        // Create the reverse reader of lines...
        //
        FileLineReverseReader reader = new FileLineReverseReader(this.randomAccessFile);
        this.destructorHandler.register(reader);

        //
        // Updates the lines...
        //
        return this.update(reader, updateRecords);
    }

    /**
     * Closes this resource gracefully.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Updates lines.
     */
    private int update(
        ILineReader reader,
        List<IUpdateRecord> updateRecords) {

        //
        // Create the update queue...
        //
        Queue<IUpdateRecord> queue = createUpdateQueue(updateRecords);

        //
        // Process each line...
        //
        int numberOfMatches = 0;

        while (reader.hasNext() && !queue.isEmpty()) {
            String line = reader.next();

            long lineIndex = reader.currentLineNumber();
            long startLinePosition = reader.currentLineStartPosition();
            long endLinePosition = reader.currentLineEndPosition();
            LineSeparatorType lineSeparator = reader.currentLineSeparator();

            //
            // Process the line...
            //
            if (this.processLine(
                    line,
                    lineIndex,
                    startLinePosition,
                    endLinePosition,
                    lineSeparator,
                    queue)) {

                ++numberOfMatches;
            }
        }

        return numberOfMatches;
    }

    /**
     * Processes a line.
     */
    private boolean processLine(
        String line,
        long lineIndex,
        long startLinePosition,
        long endLinePosition,
        LineSeparatorType lineSeparator,
        Queue<IUpdateRecord> updateRecords) {

        boolean status = false;

        int numberOfUpdates = updateRecords.size();

        for (int i = 0; i < numberOfUpdates; ++i) {
            IUpdateRecord updateRecord = updateRecords.poll();
            assert (updateRecord != null);

            Matcher matcher = updateRecord.getMatchingRegex().matcher(line);

            if (matcher.matches()) {
                this.updateLine(
                    line,
                    lineIndex,
                    startLinePosition,
                    endLinePosition,
                    lineSeparator,
                    matcher,
                    updateRecord);

                status = true;

                if (updateRecord.getPolicyType() == MatchPolicyType.AllMatches) {
                     updateRecords.offer(updateRecord);
                }
            }
            else {
                updateRecords.offer(updateRecord);
            }
        }

        return status;
    }

    /**
     * Updates a line.
     */
    private void updateLine(
        String line,
        long lineIndex,
        long startLinePosition,
        long endLinePosition,
        LineSeparatorType lineSeparator,
        Matcher matcher,
        IUpdateRecord updateRecord) {

        String newContent = updateRecord.getNewContent(line, matcher);

        int currSize = line.length();
        int updateSize = newContent.length();

        if (updateSize != currSize) {
            String errorMessage =
                "The FileLineUpdater can not replace content of a line: " + lineIndex +
                " since the length of the new content is different than the length of the original content.";

            this.log.error(errorMessage);
            throw new BasicIOException(errorMessage);
        }

        RandomAccessFiles.seek(this.randomAccessFile, startLinePosition);
        RandomAccessFiles.write(this.randomAccessFile, newContent);
        RandomAccessFiles.seek(this.randomAccessFile, endLinePosition);
    }

    /**
     * Creates an update queue.
     */
    private static Queue<IUpdateRecord> createUpdateQueue(List<IUpdateRecord> updateRecords) {
        Queue<IUpdateRecord> queue = new LinkedList<>();

        for (IUpdateRecord record : updateRecords) {
            queue.offer(record);
        }

        return queue;
    }
}
