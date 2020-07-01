package basicio.core;

import base.core.Conditions;
import basicio.interfaces.IUpdateRecord;

/**
 * The UpdateRecord class implements an update record.
 */
public final class UpdateRecord implements IUpdateRecord {
    private final String matchingRegex;
    private final String newContent;

    /**
     * The UpdateData constructor.
     */
    public UpdateRecord(String matchingRegex, String newContent) {
        Conditions.validateNotNull(
            matchingRegex,
            "The matching regex.");

        Conditions.validateNotNull(
            newContent,
            "The new content of the data.");

        this.matchingRegex = matchingRegex;
        this.newContent = newContent;
    }

    /**
     * Gets the matching regex.
     */
    @Override
    public String getMatchingRegex() {
        return this.matchingRegex;
    }

    /**
     * Gets the new content.
     */
    @Override
    public String getNewContent() {
        return this.newContent;
    }
}
