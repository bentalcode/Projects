package cmakebuild.interfaces;

import cmakebuild.core.ICMakeBuildContextData;

/**
 * The ICMakeBuildElement interface defines an element of a CMake build.
 */
public interface ICMakeBuildElement {
    /**
     * Compiles a CMake build.
     */
    void compile(
        ICMakeWriter writer,
        ICMakeBuildContextData contextData);
}
