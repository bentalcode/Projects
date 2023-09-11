package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeBuildElement;
import cmakebuildsystem.interfaces.ICMakeWriter;

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
    public void compile(
        ICMakeWriter writer,
        ICMakeBuildContextData contextData) {

        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        Conditions.validateNotNull(
            contextData,
            "The context data.");

        String line =
            CMakeListsConstants.PROJECT +
            "(" + this.moduleName + " " + CMakeListsConstants.VERSION + " " + this.version + ")";

        writer.write(line);
    }
}
