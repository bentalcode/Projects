package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeBuildCommand;
import cmakebuildsystem.interfaces.ICMakeBuildElement;
import cmakebuildsystem.interfaces.ICMakeWriter;

/**
 * The ProjectProperties class implements properties of a project.
 */
public final class ProjectProperties implements ICMakeBuildElement {
    private final String moduleName;

    private static final String PROJECT_VARIABLE_NAME = "PROJECT_NAME";

    /**
     * The ProjectProperties constructor.
     */
    public ProjectProperties(String moduleName) {
        Conditions.validateStringNotNullOrEmpty(
            moduleName,
            "The name of a module.");

        this.moduleName = moduleName;
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

        //
        // Create a variable for the project name...
        //
        ICMakeBuildCommand setCommand = SetCommand.make(
            PROJECT_VARIABLE_NAME,
            moduleName);

        setCommand.compile(writer, contextData);
    }
}
