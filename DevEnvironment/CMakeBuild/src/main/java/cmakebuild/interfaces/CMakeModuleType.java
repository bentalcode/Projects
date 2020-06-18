package cmakebuild.interfaces;

import base.core.ArrayLists;
import base.core.Strings;
import cmakebuild.CMakeBuildException;
import cmakebuild.core.AddExecutableCommand;
import cmakebuild.core.AddLibraryCommand;
import cmakebuild.core.TargetLinkLibrariesCommand;
import java.util.List;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CMakeModuleType enum defines various types of cmake modules.
 */
public enum CMakeModuleType {
    Library("library") {
        /**
         * Gets the corresponding cmake commands.
         */
        @Override
        public List<ICMakeBuildCommand> createCommands(String moduleName) {
            return ArrayLists.of(
                new AddLibraryCommand(moduleName));
        }
    },

    Executable("executable") {
        /**
         * Gets the corresponding cmake commands.
         */
        public List<ICMakeBuildCommand> createCommands(String moduleName) {
            return ArrayLists.of(
                new AddExecutableCommand(moduleName),
                new TargetLinkLibrariesCommand(moduleName));
        }
    };

    private final String name;
    private final static Logger log = LoggerFactory.getLogger(CMakeModuleType.class);

    /**
     * The CMakeModuleType constructor.
     */
    CMakeModuleType(String name) {
        this.name = name;
    }

    /**
     * Gets the corresponding cmake commands.
     */
    public abstract List<ICMakeBuildCommand> createCommands(String moduleName);

    /**
     * Gets the string representation of a cmake module type.
     */
    public String toString() {
        return this.name;
    }

    /**
     * Parses an enum string.
     */
    public static CMakeModuleType parse(String value) {
        CMakeModuleType type = tryParse(value);

        if (type == null) {
            String errorMessage =
                "The string: " + value + " is not matching to any type of enum: CMakeModuleType.";

            log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        return type;
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static CMakeModuleType tryParse(String value) {
        if (Strings.isNullOrEmpty(value)) {
            return null;
        }

        for (CMakeModuleType moduleType : CMakeModuleType.values()) {
            if (moduleType.name.equalsIgnoreCase(value)) {
                return moduleType;
            }
        }

        return null;
    }
}
