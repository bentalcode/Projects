package cmakebuildsystem.core;

/**
 * The CMakeListsConstants class implements constants for definitions of a CMakeLists file.
 */
public final class CMakeListsConstants {
    public static final String CMAKE_MINIMUM_REQUIRED = "cmake_minimum_required";
    public static final String VERSION = "VERSION";
    public static final String PROJECT = "project";
    public static final String PRIVATE_LINK_LIBRARY = "PRIVATE";
    public static final String STATIC_LIBRARY = "STATIC";

    public static final String SET_COMMAND = "set";
    public static final String INCLUDE_DIRECTORIES_COMMAND = "include_directories";
    public static final String ADD_LIBRARY_COMMAND = "add_library";
    public static final String ADD_EXECUTABLE_COMMAND = "add_executable";
    public static final String TARGET_LINK_LIBRARIES_COMMAND = "target_link_libraries";
    public static final String CONFIGURE_FILE_COMMAND = "configure_file";

    public static final String RESOURCES_DIRECTORY_VARIABLE_NAME = "RESOURCES_DIRECTORY_NAME";

    public static final String BUILD_DIRECTORY_NAME = "build";
    public static final String RESOURCES_DIRECTORY_NAME = "resources";
    public static final String MANIFEST_DIRECTORY_NAME = "manifests";

    public static final String DEFAULT_CMAKE_LISTS_PRESET_FILE_NAME = "defaultCMakeListsPreset.txt";
    public static final String DEFAULT_CMAKE_LISTS_POSTSET_FILE_NAME = "defaultCMakeListsPostset.txt";
    public static final String DEFAULT_CMAKE_LISTS_BUILD_PROPERTIES_FILE_NAME = "defaultCMakeListsBuildProperties.txt";

    public static final String CMAKE_CXX_STANDARD_VERSION_VARIABLE_NAME = "CMAKE_CXX_STANDARD";
    public static final String CMAKE_CXX_STANDARD_VERSION = "14";

    /**
     * Disables the default constructor - This is a static class.
     */
    private CMakeListsConstants() {
    }
}
