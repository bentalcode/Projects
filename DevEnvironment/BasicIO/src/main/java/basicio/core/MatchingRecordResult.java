package basicio.core;

import basicio.interfaces.IMatchingRecordResult;
import java.util.ArrayList;
import java.util.List;

/**
 * The MatchingRecordResult class implements a result of a matching record.
 */
public final class MatchingRecordResult implements IMatchingRecordResult {
    private final List<Long> matchingLines = new ArrayList<>();

    /**
     * The MatchingRecordResult constructor.
     */
    public MatchingRecordResult() {
    }

    /**
     * Adds a matching line.
     */
    @Override
    public void addMatchingLine(long lineNumber) {
        this.matchingLines.add(lineNumber);
    }

    /**
     * Gets the matching lines.
     */
    @Override
    public List<Long> getMatchingLines() {
        return this.matchingLines;
    }

    /**
     * Checks whether there is a match.
     */
    @Override
    public boolean hasMatch() {
        return !this.matchingLines.isEmpty();
    }

    /**
     * Gets the number of a matching lines.
     */
    @Override
    public int matchingLinesSize() {
        return this.matchingLines.size();
    }
}
