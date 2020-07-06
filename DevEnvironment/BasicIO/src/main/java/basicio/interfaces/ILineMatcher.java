package basicio.interfaces;

import java.util.List;

/**
 * The ILineMatcher interface defines a line matcher.
 */
public interface ILineMatcher {
    /**
     * Matches lines by a matching record and returns it's matching result.
     */
    IMatchingRecordResult match(IMatchingRecord matchingRecord);

    /**
     * Matches lines by matching records and returns it's matching results.
     */
    List<IMatchingRecordResult> match(List<IMatchingRecord> matchingRecords);
}
