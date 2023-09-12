package cmakebuildsystem.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;

import java.util.List;

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
     * Gets the paths of preset.
     */
    List<String> getPresetPaths();

    /**
     * Gets the paths of postset.
     */
    List<String> getPostsetPaths();

    /**
     * Gets the path of build properties.
     */
    String getBuildPropertiesPath();

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
     * Gets the sources' property.
     */
    String getSourcesProperty();
}
