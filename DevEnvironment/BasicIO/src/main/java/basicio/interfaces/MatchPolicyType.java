package basicio.interfaces;

import base.core.Strings;
import basicio.BasicIOException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The MatchPolicyType enum defines types of match policies.
 */
public enum MatchPolicyType {
    FirstMatch("firstMatch") {
    },

    AllMatches("allMatches") {
    };

    private final String name;
    private final static Logger log = LoggerFactory.getLogger(MatchPolicyType.class);

    /**
     * The MatchPolicyType constructor.
     */
    MatchPolicyType(String name) {
        this.name = name;
    }

    /**
     * Gets the string representation of an enum.
     */
    public String toString() {
        return this.name;
    }

    /**
     * Parses an enum string.
     */
    public static MatchPolicyType parse(String value) {
        MatchPolicyType type = tryParse(value);

        if (type == null) {
            String errorMessage =
                "The string: " + value + " is not matching to any type of enum: MatchPolicyType.";

            log.error(errorMessage);
            throw new BasicIOException(errorMessage);
        }

        return type;
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static MatchPolicyType tryParse(String value) {
        if (Strings.isNullOrEmpty(value)) {
            return null;
        }

        for (MatchPolicyType moduleType : MatchPolicyType.values()) {
            if (moduleType.name.equalsIgnoreCase(value)) {
                return moduleType;
            }
        }

        return null;
    }
}
