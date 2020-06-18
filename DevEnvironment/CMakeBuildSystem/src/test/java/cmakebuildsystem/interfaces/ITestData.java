package cmakebuildsystem.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the resource of the project manifest of DevEnvironmentCMake project.
     */
    Path getDevEnvironmentCMakeProjectManifestResource();

    /**
     * Gets the resources of project manifests.
     */
    List<Path> getProjectManifestResources();

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

    /**
     * Gets the resources of project deployment results.
     */
    List<Path> getProjectDeploymentResultResources();
}
