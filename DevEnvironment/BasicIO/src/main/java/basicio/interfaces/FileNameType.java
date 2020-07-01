package basicio.interfaces;

import base.BaseException;
import basicio.core.FileNames;
import base.core.Strings;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

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
    private final static Logger log = LoggerFactory.getLogger(FileNameType.class);

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
    public static FileNameType parse(String value) {
        FileNameType type = tryParse(value);

        if (type == null) {
            String errorMessage =
                "The string: " + value + " is not matching to any type of enum: FileNameType.";

            log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return type;
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static FileNameType tryParse(String value) {
        if (Strings.isNullOrEmpty(value)) {
            return null;
        }

        for (FileNameType moduleType : FileNameType.values()) {
            if (moduleType.name.equalsIgnoreCase(value)) {
                return moduleType;
            }
        }

        return null;
    }
}
