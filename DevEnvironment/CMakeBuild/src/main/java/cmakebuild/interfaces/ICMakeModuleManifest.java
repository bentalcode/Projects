package cmakebuild.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The ICMakeModuleManifest interface defines a manifest of a CMake module.
 */
public interface ICMakeModuleManifest extends IUnaryComparator<ICMakeModuleManifest>, IJsonSerialization {
    /**
     * Gets the name of the module.
     */
    String getName();

    /**
     * Gets the path of the module.
     */
    String getPath();

    /**
     * Gets the target path of the CMakeLists file.
     */
    String getCMakeListsTargetPath();

    /**
     * Gets the extensions of a header files.
     */
    List<String> getHeaderFileExtensions();

    /**
     * Gets the extensions of a source file.
     */
    List<String> getSourceFileExtensions();

    /**
     * Gets the extensions of a CMakeLists file.
     */
    List<String> getCMakeListsFileExtensions();

    /**
     * Gets the manifest of a CMakeLists file.
     */
    ICMakeListsManifest getCMakeListsManifest();
}
