package basicio.interfaces;

import base.core.Strings;
import basicio.BasicIOException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The UpdatePolicyType enum defines types of update policies.
 */
public enum UpdatePolicyType {
    FirstMatch("firstMatch") {

    },

    AllMatches("allMatches") {
    };

    private final String name;
    private final static Logger log = LoggerFactory.getLogger(UpdatePolicyType.class);

    /**
     * The UpdatePolicyType constructor.
     */
    UpdatePolicyType(String name) {
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
    public static UpdatePolicyType parse(String value) {
        UpdatePolicyType type = tryParse(value);

        if (type == null) {
            String errorMessage =
                "The string: " + value + " is not matching to any type of enum: UpdatePolicyType.";

            log.error(errorMessage);
            throw new BasicIOException(errorMessage);
        }

        return type;
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static UpdatePolicyType tryParse(String value) {
        if (Strings.isNullOrEmpty(value)) {
            return null;
        }

        for (UpdatePolicyType moduleType : UpdatePolicyType.values()) {
            if (moduleType.name.equalsIgnoreCase(value)) {
                return moduleType;
            }
        }

        return null;
    }
}
