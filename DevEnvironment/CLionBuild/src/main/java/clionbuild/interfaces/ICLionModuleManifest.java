package clionbuild.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;

import java.util.List;

/**
 * The ICLionModuleManifest interface defines a manifest of a CLion module.
 */
public interface ICLionModuleManifest extends IUnaryComparator<ICLionModuleManifest>, IJsonSerialization {
    /**
     * Gets the name of the module.
     */
    String getName();

    /**
     * Gets the root path of the module.
     */
    String getRootPath();

    /**
     * Gets the path of the CMakeLists file.
     */
    String getCMakeListsFilePath();

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
}
