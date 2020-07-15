package base.interfaces;

import base.BaseException;
import base.core.Enums;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The OperatingSystemType defines types of supported operating systems.
 */
public enum OperatingSystemType {
    Windows() {
        /**
         * Checks whether this is an operating system based on the system value.
         */
        public boolean isOperatingSystem(String value) {
            return value.startsWith("win");
        }
    },

    Unix() {
        /**
         * Checks whether this is an operating system based on the system value.
         */
        public boolean isOperatingSystem(String value) {
            return
                value.startsWith("nix") ||
                value.startsWith("nux") ||
                value.startsWith("aix");
        }
    },

    Mac() {
        /**
         * Checks whether this is an operating system based on the system value.
         */
        public boolean isOperatingSystem(String value) {
            return value.startsWith("mac");
        }
    },

    Solaris() {
        /**
         * Checks whether this is an operating system based on the system value.
         */
        public boolean isOperatingSystem(String value) {
            return value.startsWith("sunos");
        }
    };

    private static final Logger log = LoggerFactory.getLogger(OperatingSystemType.class);

    /**
     * The OperatingSystemType constructor.
     */
    OperatingSystemType() {
    }

    /**
     * Checks whether this is an operating system based on the system value.
     */
    public abstract boolean isOperatingSystem(String value);

    /**
     * Gets the type of the operating system based on the system value.
     */
    public static OperatingSystemType getOperatingSystem(String value) {
        String systemValue = value.toLowerCase();

        if (OperatingSystemType.Windows.isOperatingSystem(systemValue)) {
            return OperatingSystemType.Windows;
        }
        else if (OperatingSystemType.Unix.isOperatingSystem(systemValue)) {
            return OperatingSystemType.Unix;
        }
        else if (OperatingSystemType.Mac.isOperatingSystem(systemValue)) {
            return OperatingSystemType.Mac;
        }
        else if (OperatingSystemType.Solaris.isOperatingSystem(systemValue)) {
            return OperatingSystemType.Solaris;
        }
        else {
            String errorMessage = "The operating system: " + value + " is not supported.";
            log.error(errorMessage);

            throw new BaseException(errorMessage);
        }
    }

    /**
     * Gets the string representation of this enum.
     */
    @Override
    public String toString() {
        return this.name();
    }

    /**
     * Parses this enum.
     */
    public static OperatingSystemType parse(String str) {
        return Enums.parse(OperatingSystemType.class, str);
    }

    /**
     * Tries to parse this enum
     */
    public static OperatingSystemType tryParse(String str) {
        return Enums.tryParse(OperatingSystemType.class, str);
    }
}
