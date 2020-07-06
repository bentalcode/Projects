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
import basicio.interfaces.MatchPolicyType;
import java.io.RandomAccessFile;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
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
     */
    @Override
    public boolean update(IUpdateRecord updateRecord) {
        Conditions.validateNotNull(
            updateRecord,
            "The update record.");

        List<IUpdateRecord> updateRecords = ArrayLists.of(updateRecord);

        int numberOfUpdates = this.update(
            updateRecords,
            MatchPolicyType.FirstMatch);

        return numberOfUpdates > 0;
    }

    /**
     * Updates a line that matches an update record.
     * The search direction is from bottom to top.
     */
    @Override
    public boolean updateFromEnd(IUpdateRecord updateRecord) {
        Conditions.validateNotNull(
            updateRecord,
            "The update record.");

        List<IUpdateRecord> updateRecords = ArrayLists.of(updateRecord);

        int numberOfUpdates = this.updateFromEnd(
            updateRecords,
            MatchPolicyType.FirstMatch);

        return numberOfUpdates > 0;
    }

    /**
     * Updates lines that matches update records.
     * The search direction is from top to bottom.
     */
    @Override
    public int update(
        List<IUpdateRecord> updateRecords,
        MatchPolicyType policyType) {

        Conditions.validateNotNull(
            updateRecords,
            "The update records.");

        Conditions.validateNotNull(
            policyType,
            "The update policy type.");

        //
        // Create the reader of lines...
        //
        FileLineReader reader = new FileLineReader(this.randomAccessFile);
        this.destructorHandler.register(reader);

        //
        // Updates the lines...
        //
        int numberOfMatches = this.update(reader, updateRecords, policyType);

        return numberOfMatches;
    }

    /**
     * Updates lines that matches update records.
     * The search direction is from bottom to top.
     */
    public int updateFromEnd(
        List<IUpdateRecord> updateRecords,
        MatchPolicyType policyType) {

        Conditions.validateNotNull(
            updateRecords,
            "The update records.");

        Conditions.validateNotNull(
            policyType,
            "The update policy type.");

        //
        // Create the reverse reader of lines...
        //
        FileLineReverseReader reader = new FileLineReverseReader(this.randomAccessFile);
        this.destructorHandler.register(reader);

        //
        // Updates the lines...
        //
        int numberOfMatches = this.update(reader, updateRecords, policyType);

        return numberOfMatches;
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
        List<IUpdateRecord> updateRecords,
        MatchPolicyType policyType) {

        //
        // Create the matching patterns...
        //
        List<Pattern> patterns = this.createMatchingPatterns(updateRecords);

        //
        // Process each line...
        //
        int numberOfMatches = 0;

        while (reader.hasNext()) {
            String line = reader.next();

            long lineIndex = reader.currentLineNumber();
            long startLinePosition = reader.currentLineStartPosition();
            long endLinePosition = reader.currentLineEndPosition();

            //
            // Process the line...
            //
            if (this.processLine(
                    line,
                    lineIndex,
                    startLinePosition,
                    endLinePosition,
                    updateRecords,
                    patterns)) {

                ++numberOfMatches;

                if (policyType == MatchPolicyType.FirstMatch ||
                    (policyType == MatchPolicyType.AllMatches && numberOfMatches == updateRecords.size())) {

                    break;
                }
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
        List<IUpdateRecord> updateRecords,
        List<Pattern> patterns) {

        assert(updateRecords.size() == patterns.size());

        for (int i = 0; i < updateRecords.size(); ++i) {
            IUpdateRecord updateRecord = updateRecords.get(i);
            Pattern pattern = patterns.get(i);

            Matcher matcher = pattern.matcher(line);

            if (matcher.matches()) {
                this.updateLine(
                    line,
                    lineIndex,
                    startLinePosition,
                    endLinePosition,
                    updateRecord);

                return true;
            }
        }

        return false;
    }

    /**
     * Updates a line.
     */
    private void updateLine(
        String line,
        long lineIndex,
        long startLinePosition,
        long endLinePosition,
        IUpdateRecord updateRecord) {

        long updateSize = updateRecord.getNewContent().length();

        if (updateSize > line.length()) {
            String errorMessage =
                "The FileLineUpdater can not replace content of a line: " + lineIndex +
                " since the new content is larger than the replaced content.";

            this.log.error(errorMessage);
            throw new BasicIOException(errorMessage);
        }

        RandomAccessFiles.seek(this.randomAccessFile, startLinePosition);
        RandomAccessFiles.write(this.randomAccessFile, updateRecord.getNewContent());
        RandomAccessFiles.seek(this.randomAccessFile, endLinePosition);
    }

    /**
     * Creates matching patterns.
     */
    private static List<Pattern> createMatchingPatterns(List<IUpdateRecord> updateRecords) {
        List<Pattern> patterns = new ArrayList<>(updateRecords.size());

        for (IUpdateRecord updateRecord : updateRecords) {
            Pattern pattern = Pattern.compile(updateRecord.getMatchingRegex());
            patterns.add(pattern);
        }

        return patterns;
    }
}
