package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildElement;
import cmakebuild.interfaces.ICMakeWriter;

/**
 * The ProjectVersion class implements a version of a project.
 */
public final class ProjectVersion implements ICMakeBuildElement {
    private final String moduleName;
    private final String version;

    /**
     * The CMakeVersion constructor.
     */
    public ProjectVersion(
        String moduleName,
        String version) {

        Conditions.validateStringNotNullOrEmpty(
            moduleName,
            "The name of a module.");

        Conditions.validateStringNotNullOrEmpty(
            version,
            "The version of a project.");

        this.moduleName = moduleName;
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
            ICMakeListsConstants.project +
            "(" + this.moduleName + " " + ICMakeListsConstants.version + " " + this.version + ")";

        writer.write(line);
    }
}
