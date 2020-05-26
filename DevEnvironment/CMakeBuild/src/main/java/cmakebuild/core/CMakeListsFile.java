package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildElement;
import cmakebuild.interfaces.ICMakeListsFile;
import cmakebuild.interfaces.ICMakeWriter;
import java.util.List;

/**
 * The CMakeListsFile class implements a file of a CMakeLists.
 */
public final class CMakeListsFile implements ICMakeListsFile {
    private final List<ICMakeBuildElement> elements;

    /**
     * The CMakeListsFile constructor.
     */
    public CMakeListsFile(List<ICMakeBuildElement> elements) {
        Conditions.validateNotNull(
            elements,
            "The elements of a CMakeLists file.");

        this.elements = elements;
    }

    /**
     * Compiles a CMake build.
     */
    @Override
    public void compile(ICMakeWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        /**
         * Writes the elements of a file...
         */
        for (ICMakeBuildElement element : this.elements) {
            element.compile(writer);
            writer.newLine();
        }
    }
}
