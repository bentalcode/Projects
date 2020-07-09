package basicio.interfaces;

import base.core.Enums;

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
            return "\r\n";
        }
    },

    Unix("unix") {
        /**
         * Gets the token of a line separator.
         */
        @Override
        public String getToken() {
            return "\n";
        }
    },

    Mac("mac") {
        /**
         * Gets the token of a line separator.
         */
        @Override
        public String getToken() {
            return "\r";
        }
    };

    private final String name;

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
     * Finds the corresponding line separator.
     * Returns null of no line separator is matching.
     */
    public static LineSeparatorType findLineSeparator(char first, char second) {
        for (LineSeparatorType separatorType : LineSeparatorType.values()) {
            String token = separatorType.getToken();

            if (token.length() == 2 && token.charAt(0) == first && token.charAt(1) == second) {
                return separatorType;
            }
            else if (token.length() == 1) {
                if (token.charAt(0) == second) {
                    return separatorType;
                }
            }
        }

        return null;
    }

    /**
     * Parses an enum string.
     */
    public static LineSeparatorType parse(String str) {
        return Enums.parse(LineSeparatorType.class, str);
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static LineSeparatorType tryParse(String str) {
        return Enums.tryParse(LineSeparatorType.class, str);
    }
}
