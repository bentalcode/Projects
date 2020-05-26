package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildElement;
import cmakebuild.interfaces.ICMakeWriter;

/**
 * The CMakeVersion class implements a version of CMake.
 */
public final class CMakeVersion implements ICMakeBuildElement {
    private final String version;

    /**
     * The CMakeVersion constructor.
     */
    public CMakeVersion(String version) {
        Conditions.validateStringNotNullOrEmpty(
            version,
            "The version of CMake.");

        this.version = version;
    }

    /**
     * Compiles a CMake build.
     */
    @Override
    public void compile(ICMakeWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        String line =
            ICMakeListsConstants.cmakeMinimumRequired +
            "(" + ICMakeListsConstants.version + " " + this.version + ")";

        writer.write(line);
    }
}
