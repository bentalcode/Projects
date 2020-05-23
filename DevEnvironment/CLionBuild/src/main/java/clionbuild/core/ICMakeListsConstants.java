package clionbuild.core;

/**
 * The ICMakeListsConstants interface defines constants for definitions of a CMakeLists file.
 */
public interface ICMakeListsConstants {
    String cmakeMinimumRequired = "cmake_minimum_required";
    String version = "VERSION";
    String project = "project";

    String setInstruction = "set";
    String includeDirectoriesInstruction = "include_directories";
    String addLibraryInstruction = "add_library";
}
