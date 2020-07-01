package basicio.interfaces;

import base.core.Strings;
import basicio.BasicIOException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The LineSeparatorType enum defines a types of a line separator.
 */
public enum LineSeparatorType {

    Windows("windows") {
        /**
         * Gets the token of a line separator.
         */
        @Override
        public String getToken() {
            return "/r/n";
        }
    },

    Unix("unix") {
        /**
         * Gets the token of a line separator.
         */
        @Override
        public String getToken() {
            return "/n";
        }
    },

    Mac("mac") {
        /**
         * Gets the token of a line separator.
         */
        @Override
        public String getToken() {
            return "/r";
        }
    };

    private final String name;
    private final static Logger log = LoggerFactory.getLogger(LineSeparatorType.class);

    /**
     * The LineSeparatorType constructor.
     */
    LineSeparatorType(String name) {
        this.name = name;
    }

    /**
     * Gets the string representation of an enum.
     */
    public String toString() {
        return this.name;
    }

    /**
     * Gets the token of a line separator.
     */
    public abstract String getToken();

    /**
     * Parses an enum string.
     */
    public static LineSeparatorType parse(String value) {
        LineSeparatorType type = tryParse(value);

        if (type == null) {
            String errorMessage =
                "The string: " + value + " is not matching to any type of enum: LineSeparatorType.";

            log.error(errorMessage);
            throw new BasicIOException(errorMessage);
        }

        return type;
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static LineSeparatorType tryParse(String value) {
        if (Strings.isNullOrEmpty(value)) {
            return null;
        }

        for (LineSeparatorType moduleType : LineSeparatorType.values()) {
            if (moduleType.name.equalsIgnoreCase(value)) {
                return moduleType;
            }
        }

        return null;
    }
}
