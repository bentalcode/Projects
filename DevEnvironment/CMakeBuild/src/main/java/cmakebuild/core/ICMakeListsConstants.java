package cmakebuild.core;

/**
 * The ICMakeListsConstants interface defines constants for definitions of a CMakeLists file.
 */
public interface ICMakeListsConstants {
    String cmakeMinimumRequired = "cmake_minimum_required";
    String version = "VERSION";
    String project = "project";
    String privateLinkLibrary = "PRIVATE";
    String staticLibrary = "STATIC";

    String setCommand = "set";
    String includeDirectoriesCommand = "include_directories";
    String addLibraryCommand = "add_library";
    String addExecutableCommand = "add_executable";
    String targetLinkLibrariesCommand = "target_link_libraries";
}
