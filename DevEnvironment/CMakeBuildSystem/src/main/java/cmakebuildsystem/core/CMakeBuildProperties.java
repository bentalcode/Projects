package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeBuildElement;
import cmakebuildsystem.interfaces.ICMakeWriter;

import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeBuildProperties class implements a build properties of CMake.
 */
public final class CMakeBuildProperties implements ICMakeBuildElement {
    private final List<ICMakeBuildElement> variables = new ArrayList<>();

    private ICMakeBuildElement properties;

    /**
     * Creates a new cmake build properties.
     */
    public static ICMakeBuildElement make() {
        return new CMakeBuildProperties(null);
    }

    /**
     * Creates a new cmake build properties.
     */
    public static ICMakeBuildElement make(Path path) {
        return new CMakeBuildProperties(path);
    }

    /**
     * The CMakeBuildProperties constructor.
     */
    private CMakeBuildProperties(Path path) {
        this.addVariables(this.variables);

        if (path != null) {
            this.properties = new CMakeResource(path);
        }
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

        for (ICMakeBuildElement variable : this.variables) {
            variable.compile(writer, contextData);
        }

        if (this.properties != null) {
            writer.newLine();
            this.properties.compile(writer, contextData);
        }
    }

    /**
     * Adds variables.
     */
    private void addVariables(List<ICMakeBuildElement> variables) {
        ICMakeBuildElement cmakeCXXStandardVersionVariable = SetCommand.make(
            CMakeListsConstants.CMAKE_CXX_STANDARD_VERSION_VARIABLE_NAME,
            CMakeListsConstants.CMAKE_CXX_STANDARD_VERSION);

        ICMakeBuildElement resourcesVariable = SetCommand.make(
            CMakeListsConstants.RESOURCES_DIRECTORY_VARIABLE_NAME,
            CMakeListsConstants.RESOURCES_DIRECTORY_NAME);

        variables.add(cmakeCXXStandardVersionVariable);
        variables.add(resourcesVariable);
    }
}
