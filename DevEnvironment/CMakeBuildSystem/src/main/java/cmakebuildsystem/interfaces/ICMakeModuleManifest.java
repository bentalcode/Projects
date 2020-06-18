package cmakebuildsystem.interfaces;

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
     * Gets the type of the module.
     */
    CMakeModuleType getType();

    /**
     * Gets the propertis of the module.
     */
    ICMakeModuleProperties getProperties();

    /**
     * Gets the manifest of a CMakeLists file.
     */
    ICMakeListsManifest getCMakeListsManifest();

    /**
     * Gets the dependent modules.
     */
    List<String> getDependentModules();
}
