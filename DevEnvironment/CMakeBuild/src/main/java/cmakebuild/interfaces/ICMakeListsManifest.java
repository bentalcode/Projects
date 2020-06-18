package cmakebuild.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;

/**
 * The ICMakeListsManifest interface defines a manifest of a CMakeLists file.
 */
public interface ICMakeListsManifest extends IUnaryComparator<ICMakeListsManifest>, IJsonSerialization {
    /**
     * Gets the version of cmake.
     */
    String getCMakeVersion();

    /**
     * Gets the version of project.
     */
    String getProjectVersion();

    /**
     * Gets the path of preset.
     */
    String getPresetPath();

    /**
     * Gets the path of postset.
     */
    String getPostsetPath();

    /**
     * Gets the includes files property.
     */
    String getIncludesFilesProperty();

    /**
     * Gets the sources files property.
     */
    String getSourcesFilesProperty();

    /**
     * Gets the includes property.
     */
    String getIncludesProperty();

    /**
     * Gets the sources property.
     */
    String getSourcesProperty();
}
