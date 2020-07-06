package basicio.interfaces;

import java.util.regex.Pattern;

/**
 * The IMatchingRecord interface defines a matching record.
 */
public interface IMatchingRecord {
    /**
     * Gets the matching pattern.
     */
    Pattern getMatchingPattern();

    /**
     * Gets the policy type.
     */
    MatchPolicyType getPolicyType();
}
