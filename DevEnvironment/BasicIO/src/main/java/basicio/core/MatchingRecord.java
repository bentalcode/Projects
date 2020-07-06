package basicio.core;

import base.core.Conditions;
import basicio.interfaces.IMatchingRecord;
import basicio.interfaces.MatchPolicyType;
import java.util.regex.Pattern;

/**
 * The MatchingRecord class implements a matching record.
 */
public final class MatchingRecord implements IMatchingRecord {
    private final Pattern matchingPattern;
    private final MatchPolicyType policyType;

    /**
     * The MatchingRecord constructor.
     */
    public MatchingRecord(String matchingPattern) {
        this(matchingPattern, MatchPolicyType.FirstMatch);
    }

    /**
     * The MatchingRecord constructor.
     */
    public MatchingRecord(String matchingPattern, MatchPolicyType policyType) {
        Conditions.validateNotNull(
            matchingPattern,
            "The matching pattern.");

        this.matchingPattern = Pattern.compile(matchingPattern);
        this.policyType = policyType;
    }

    /**
     * Gets the matching pattern.
     */
    @Override
    public Pattern getMatchingPattern() {
        return this.matchingPattern;
    }

    /**
     * Gets the policy type.
     */
    @Override
    public MatchPolicyType getPolicyType() {
        return this.policyType;
    }
}
