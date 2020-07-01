package basicio.core;

import base.core.ArrayLists;
import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import base.interfaces.IDestructorHandler;
import basicio.BasicIOException;
import basicio.interfaces.ILineUpdater;
import basicio.interfaces.IUpdateRecord;
import basicio.interfaces.UpdatePolicyType;
import java.io.RandomAccessFile;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The FileLineUpdater class implements a reader of lines of a file.
 */
public final class FileLineUpdater implements ILineUpdater, ICloseable {
    private static final long endLineSeparatorSize = 2;

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
     * Updates a line.
     */
    @Override
    public boolean update(
        IUpdateRecord updateRecord,
        UpdatePolicyType policyType) {

        Conditions.validateNotNull(
            updateRecord,
            "The update record.");

        Conditions.validateNotNull(
            policyType,
            "The update policy type.");

        List<IUpdateRecord> updateRecords = ArrayLists.of(updateRecord);

        int numberOfUpdates = this.update(
            updateRecords,
            policyType);

        return numberOfUpdates > 0;
    }

    /**
     * Updates lines.
     * Returns the number of updates.
     */
    @Override
    public int update(
        List<IUpdateRecord> updateRecords,
        UpdatePolicyType policyType) {

        Conditions.validateNotNull(
            updateRecords,
            "The update records.");

        Conditions.validateNotNull(
            policyType,
            "The update policy type.");

        List<Pattern> patterns = new ArrayList<>(updateRecords.size());

        for (IUpdateRecord updateRecord : updateRecords) {
            Pattern pattern = Pattern.compile(updateRecord.getMatchingRegex());
            patterns.add(pattern);
        }

        int numberOfMatches = 0;
        int lineIndex = 0;

        while (true) {
            long startLinePosition = RandomAccessFiles.getFilePointer(this.randomAccessFile);

            String line = RandomAccessFiles.readLine(this.randomAccessFile);

            if (line == null) {
                break;
            }

            long endLinePosition = RandomAccessFiles.getFilePointer(this.randomAccessFile);
            ++lineIndex;

            if (this.processLine(
                    line,
                    lineIndex,
                    startLinePosition,
                    endLinePosition,
                    updateRecords,
                    patterns)) {

                ++numberOfMatches;
            }

            if (policyType == UpdatePolicyType.FirstMatch ||
                policyType == UpdatePolicyType.AllMatches && numberOfMatches == updateRecords.size()) {

                break;
            }
        }

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

        long endUpdatePosition = startLinePosition + updateRecord.getNewContent().length();

        if (endUpdatePosition + endLineSeparatorSize > endLinePosition) {
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
}
