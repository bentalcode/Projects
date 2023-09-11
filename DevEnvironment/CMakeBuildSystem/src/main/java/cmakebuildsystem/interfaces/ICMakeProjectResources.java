package cmakebuildsystem.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ICMakeProjectResources interface defines CMAKE resources of project.
 */
public interface ICMakeProjectResources {
    /**
     * Gets path of cmake project manifest.
     */
    Path getCMakeProjectManifestPath();

    /**
     * Gets the resources of project manifests.
     */
    List<Path> getProjectManifestResources();

    /**
     * Gets the resources of project deployment results.
     */
    List<Path> getProjectDeploymentResultResources();

    /**
     * Gets the resources of module manifests.
     */
    List<Path> getModuleManifestResources();

    /**
     * Gets the resources of CMakeLists manifests.
     */
    List<Path> getCMakeListsManifestResources();

    /**
     * Gets the resources of projects.
     */
    List<Path> getProjectResources();

    /**
     * Gets the resources of modules.
     */
    List<Path> getModuleResources();
}
