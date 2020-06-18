package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildElementList;
import cmakebuild.interfaces.ICMakeListsFile;
import cmakebuild.interfaces.ICMakeWriter;

/**
 * The CMakeListsFile class implements a file of a CMakeLists.
 */
public final class CMakeListsFile implements ICMakeListsFile {
    private final ICMakeBuildElementList elements;

    /**
     * The CMakeListsFile constructor.
     */
    public CMakeListsFile(ICMakeBuildElementList elements) {
        Conditions.validateNotNull(
            elements,
            "The elements of a CMakeLists file.");

        this.elements = elements;
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
        // Writes the elements of a file...
        //
        this.elements.compile(writer, contextData);
    }
}
