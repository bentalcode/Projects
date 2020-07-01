package basicio.interfaces;

import base.core.Strings;
import basicio.BasicIOException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The SearchDirection enum defines types of search direction.
 */
public enum SearchDirectionType {
    TopToBottom("topToBottom") {

    },

    BottomToTop("bottomToTop") {
    };

    private final String name;
    private final static Logger log = LoggerFactory.getLogger(SearchDirectionType.class);

    /**
     * The UpdatePolicyType constructor.
     */
    SearchDirectionType(String name) {
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
    public static SearchDirectionType parse(String value) {
        SearchDirectionType type = tryParse(value);

        if (type == null) {
            String errorMessage =
                "The string: " + value + " is not matching to any type of enum: SearchDirectionType.";

            log.error(errorMessage);
            throw new BasicIOException(errorMessage);
        }

        return type;
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static SearchDirectionType tryParse(String value) {
        if (Strings.isNullOrEmpty(value)) {
            return null;
        }

        for (SearchDirectionType moduleType : SearchDirectionType.values()) {
            if (moduleType.name.equalsIgnoreCase(value)) {
                return moduleType;
            }
        }

        return null;
    }
}
