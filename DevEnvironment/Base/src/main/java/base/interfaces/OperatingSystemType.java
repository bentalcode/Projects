package base.interfaces;

import base.BaseException;
import base.core.Enums;
import base.core.MacPathSettings;
import base.core.OperatingSystemControlSettings;
import base.core.PosixUnixPathSettings;
import base.core.UnixPathSettings;
import base.core.WindowsPathSettings;
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
            return value.contains("windows");
        }

        /**
         * Creates control settings of an operating system.
         */
        public IOperatingSystemControlSettings createControlSettings() {
            return new OperatingSystemControlSettings(
                new WindowsPathSettings());
        }
    },

    Unix() {
        /**
         * Checks whether this is an operating system based on the system value.
         */
        public boolean isOperatingSystem(String value) {
            return
                value.contains("linux") ||
                value.contains("unix") ||
                value.contains("mpe/ix") ||
                value.contains("freebsd") ||
                value.contains("irix") ||
                value.contains("digital unix");
        }

        /**
         * Creates control settings of an operating system.
         */
        public IOperatingSystemControlSettings createControlSettings() {
            return new OperatingSystemControlSettings(
                new UnixPathSettings());
        }
    },

    Mac() {
        /**
         * Checks whether this is an operating system based on the system value.
         */
        public boolean isOperatingSystem(String value) {
            return value.contains("mac os");
        }

        /**
         * Creates control settings of an operating system.
         */
        public IOperatingSystemControlSettings createControlSettings() {
            return new OperatingSystemControlSettings(
                new MacPathSettings());
        }
    },

    PosixUnix() {
        /**
         * Checks whether this is an operating system based on the system value.
         */
        public boolean isOperatingSystem(String value) {
            return
                value.contains("sun os") ||
                value.contains("sunos") ||
                value.contains("solaris") ||
                value.contains("hp-ux") ||
                value.contains("aix");
        }

        /**
         * Creates control settings of an operating system.
         */
        public IOperatingSystemControlSettings createControlSettings() {
            return new OperatingSystemControlSettings(
                new PosixUnixPathSettings());
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
        else if (OperatingSystemType.PosixUnix.isOperatingSystem(systemValue)) {
            return OperatingSystemType.PosixUnix;
        }
        else {
            String errorMessage = "The operating system: " + value + " is not supported.";
            log.error(errorMessage);

            throw new BaseException(errorMessage);
        }
    }

    /**
     * Creates control settings of an operating system.
     */
    public abstract IOperatingSystemControlSettings createControlSettings();

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
