package basicio.interfaces;

import base.core.Enums;
import basicio.core.FileNames;

/**
 * The FileNameType enum defines types of files name.
 */
public enum FileNameType {
    Camel("camel") {
        /**
         * Gets tokens of a file name.
         */
        public String[] getTokens(String fileName) {
            return FileNames.getCamelCasedTokens(fileName);
        }
    },

    Pascal("pascal") {
        /**
         * Gets tokens of a file name.
         */
        public String[] getTokens(String fileName) {
            return FileNames.getPascalCasedTokens(fileName);
        }
    },
    
    Kabab("kabab") {
        /**
         * Gets tokens of a file name.
         */
        public String[] getTokens(String fileName) {
            return FileNames.getKababCasedTokens(fileName);
        }
    },

    Snake("snake") {
        /**
         * Gets tokens of a file name.
         */
        public String[] getTokens(String fileName) {
            return FileNames.getSnakeCasedTokens(fileName);
        }
    };

    private final String name;

    /**
     * The FileNameType constructor.
     */
    FileNameType(String name) {
        this.name = name;
    }

    /**
     * Gets tokens of a file name.
     */
    public abstract String[] getTokens(String fileName);

    /**
     * Gets the string representation of a cmake module type.
     */
    public String toString() {
        return this.name;
    }

    /**
     * Parses an enum string.
     */
    public static FileNameType parse(String str) {
        return Enums.parse(FileNameType.class, str);
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static FileNameType tryParse(String str) {
        return Enums.tryParse(FileNameType.class, str);
    }
}
