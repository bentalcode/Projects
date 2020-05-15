package clionbuild.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The ICLionProjectManifest interface defines a manifest of a CLion project.
 */
public interface ICLionProjectManifest extends IUnaryComparator<ICLionProjectManifest>, IJsonSerialization {
    /**
     * Gets the name of the project.
     */
    String getName();

    /**
     * Gets the path of the root of the project.
     */
    String getRootPath();

    /**
     * Gets the list of the modules manifests.
     */
    List<ICLionModuleManifest> getModulesManifests();
}
