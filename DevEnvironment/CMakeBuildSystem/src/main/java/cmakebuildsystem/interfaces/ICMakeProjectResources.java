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
}
