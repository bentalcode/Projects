package cmakebuildsystem.core;

import base.core.ArrayLists;
import base.core.Environment;
import base.core.ResourcePathBuilder;
import base.interfaces.OperatingSystemType;
import cmakebuildsystem.interfaces.ICMakeProjectResources;
import testbase.core.ResourcePaths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The DevEnvironmentCMakeProjectResources class implements CMAKE resources of Dev Environment project.
 */
public final class DevEnvironmentCMakeProjectResources implements ICMakeProjectResources {
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String PROJECT_MANIFESTS_DIRECTORY_NAME = "projectManifests";
    private static final String PROJECT_DEPLOYMENT_RESULTS_DIRECTORY_NAME = "projectDeploymentResults";
    private static final String PROJECT_MANIFEST = "projectManifest.json";

    private static final List<String> PROJECT_MANIFESTS = ArrayLists.make(
        "projectManifest.json");

    private static final List<String> PROJECT_DEPLOYMENT_RESULTS = ArrayLists.make(
        "projectDeploymentResult.json");

    /**
     * The CMakeProjectResources constructor.
     */
    public DevEnvironmentCMakeProjectResources() {
    }

    /**
     * Gets path of cmake project manifest of DevEnvironment project.
     */
    @Override
    public Path getCMakeProjectManifestPath() {
        return ResourcePaths.create(
            dataDirectory("devEnvironment"),
            PROJECT_MANIFESTS_DIRECTORY_NAME,
            PROJECT_MANIFEST);
    }

    /**
     * Gets the resources of project manifests.
     */
    @Override
    public List<Path> getProjectManifestResources() {
        List<Path> result = new ArrayList<>();

        for (String projectManifest : PROJECT_MANIFESTS) {
            Path path = ResourcePaths.create(
                dataDirectory("devEnvironment"),
                PROJECT_MANIFESTS_DIRECTORY_NAME,
                projectManifest);

            result.add(path);
        }

        return result;
    }

    /**
     * Gets the resources of project deployment results.
     */
    @Override
    public List<Path> getProjectDeploymentResultResources() {
        List<Path> result = new ArrayList<>();

        for (String projectDeploymentResult : PROJECT_DEPLOYMENT_RESULTS) {
            Path path = ResourcePaths.create(
                    dataDirectory("devEnvironment"),
                    PROJECT_DEPLOYMENT_RESULTS_DIRECTORY_NAME,
                    projectDeploymentResult);

            result.add(path);
        }

        return result;
    }

    /**
     * Gets data directory.
     */
    private static String dataDirectory(String projectName) {
        OperatingSystemType operatingSystemType = Environment.getOperatingSystem();
        String operatingSystemDirectory = operatingSystemType.toString().toLowerCase();

        String path = new ResourcePathBuilder()
            .addComponent(DATA_DIRECTORY_NAME)
            .addComponent(projectName)
            .addComponent(operatingSystemDirectory)
            .build();

        return path;
    }
}
