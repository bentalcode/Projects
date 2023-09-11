package basicio.core;

import base.core.Conditions;
import basicio.interfaces.IUpdateRecord;
import basicio.interfaces.MatchPolicyType;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The UpdateRecord class implements an update record.
 */
public final class UpdateRecord implements IUpdateRecord {
    private final Pattern matchingRegex;
    private final String newContent;
    private final MatchPolicyType policyType;

    /**
     * The UpdateData constructor.
     */
    public UpdateRecord(
        String matchingRegex,
        String newContent,
        MatchPolicyType policyType) {

        Conditions.validateNotNull(
            matchingRegex,
            "The matching regex.");

        Conditions.validateNotNull(
            newContent,
            "The new content of the data.");

        this.matchingRegex = Pattern.compile(matchingRegex);
        this.newContent = newContent;
        this.policyType = policyType;
    }

    /**
     * Gets the matching regex.
     */
    @Override
    public Pattern getMatchingRegex() {
        return this.matchingRegex;
    }

    /**
     * Gets the new content.
     */
    @Override
    public String getNewContent(String currContent, Matcher matcher) {
        return this.newContent;
    }

    /**
     * Gets the policy type.
     */
    @Override
    public MatchPolicyType getPolicyType() {
        return this.policyType;
    }
}
