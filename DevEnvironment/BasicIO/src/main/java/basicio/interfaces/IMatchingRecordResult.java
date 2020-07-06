package basicio.interfaces;

import java.util.List;

/**
 * The IMatchingRecordResult interface defines a result of a matching record.
 */
public interface IMatchingRecordResult {
    /**
     * Adds a matching line.
     */
    void addMatchingLine(long lineNumber);

    /**
     * Gets the matching lines.
     */
    List<Long> getMatchingLines();

    /**
     * Checks whether there is a match.
     */
    boolean hasMatch();

    /**
     * Gets the number of a matching lines.
     */
    int matchingLinesSize();
}
