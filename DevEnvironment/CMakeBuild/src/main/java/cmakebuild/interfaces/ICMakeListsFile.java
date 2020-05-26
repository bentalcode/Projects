package cmakebuild.interfaces;

/**
 * The ICMakeListsFile interface defines a CMakeLists file.
 * CMakeLists.txt file contains a set of directives and instructions describing
 * the project's source files and targets (executable, library, or both).
 */
public interface ICMakeListsFile extends ICMakeBuildElement {
    /**
     * Compiles a CMake build.
     */
    void compile(ICMakeWriter writer);
}
