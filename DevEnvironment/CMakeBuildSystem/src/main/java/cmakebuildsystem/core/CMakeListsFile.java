package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeBuildElementList;
import cmakebuildsystem.interfaces.ICMakeListsFile;
import cmakebuildsystem.interfaces.ICMakeWriter;

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
