package cmakebuildsystem.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The ICMakeProjectManifest interface defines a manifest of a CMake project.
 */
public interface ICMakeProjectManifest extends IUnaryComparator<ICMakeProjectManifest>, IJsonSerialization {
    /**
     * Gets the name of the project.
     */
    String getName();

    /**
     * Gets the path of the root of the project.
     */
    String getRootPath();

    /**
     * Gets the effective modules.
     */
    List<String> getEffectiveModules();

    /**
     * Gets the list of the modules manifests.
     */
    List<ICMakeModuleManifest> getModulesManifests();

    /**
     * Gets settings of an editor.
     */
    IEditorSettings getEditorSettings();

    /**
     * Gets to ignore rules.
     */
    IIgnoreRules getIgnoreRules();
}
