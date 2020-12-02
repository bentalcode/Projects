package cmakebuildsystem.interfaces;

import base.core.ArrayLists;
import base.core.Enums;
import cmakebuildsystem.core.AddExecutableCommand;
import cmakebuildsystem.core.AddLibraryCommand;
import cmakebuildsystem.core.CMakeBuildProperties;
import cmakebuildsystem.core.TargetLinkLibrariesCommand;
import java.nio.file.Path;
import java.util.List;

/**
 * The CMakeModuleType enum defines various types of cmake modules.
 */
public enum CMakeModuleType {
    Library("library") {
        /**
         * Gets the corresponding build properties.
         */
        @Override
        public ICMakeBuildElement createBuildProperties(Path path) {
            return CMakeBuildProperties.make();
        }

        /**
         * Gets the corresponding cmake commands.
         */
        @Override
        public List<ICMakeBuildCommand> createCommands(String moduleName) {
            return ArrayLists.make(
                new AddLibraryCommand(moduleName));
        }
    },

    Executable("executable") {
        /**
         * Gets the corresponding build properties.
         */
        @Override
        public ICMakeBuildElement createBuildProperties(Path path) {
            return CMakeBuildProperties.make(path);
        }

        /**
         * Gets the corresponding cmake commands.
         */
        @Override
        public List<ICMakeBuildCommand> createCommands(String moduleName) {
            return ArrayLists.make(
                new AddExecutableCommand(moduleName),
                new TargetLinkLibrariesCommand(moduleName));
        }
    };

    private final String name;

    /**
     * The CMakeModuleType constructor.
     */
    CMakeModuleType(String name) {
        this.name = name;
    }

    /**
     * Gets the corresponding build properties.
     */
    public abstract ICMakeBuildElement createBuildProperties(Path path);

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
    public static CMakeModuleType parse(String str) {
        return Enums.parse(CMakeModuleType.class, str);
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static CMakeModuleType tryParse(String str) {
        return Enums.tryParse(CMakeModuleType.class, str);
    }
}
