package cmakebuild.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.nio.file.Path;
import java.util.List;

/**
 * The ICMakeModule interface defines a CMake module.
 */
public interface ICMakeModule extends IUnaryComparator<ICMakeModule>, IJsonSerialization {
    /**
     * Gets the name of the module.
     */
    String getName();

    /**
     * Gets the root path of the module.
     */
    Path getRootPath();

    /**
     * Gets the paths of the header files.
     */
    List<Path> getHeaderFilesPaths();

    /**
     * Gets the paths of the source files.
     */
    List<Path> getSourceFilesPaths();

    /**
     * Gets the path of the CMakeLists file.
     */
    Path getCMakeListsFilePath();
}
