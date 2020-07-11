package basicio.interfaces;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The IUpdateRecord interface defines an update record.
 */
public interface IUpdateRecord {
    /**
     * Gets the matching regex.
     */
    Pattern getMatchingRegex();

    /**
     * Gets the new content.
     */
    String getNewContent(String currContent, Matcher matcher);

    /**
     * Gets the policy type.
     */
    MatchPolicyType getPolicyType();
}
