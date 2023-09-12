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
 * The VideoRenderingVisualizerCMakeProjectResources class implements CMAKE resources of
 * VideoRenderingVisualizer project.
 */
public final class VideoRenderingVisualizerCMakeProjectResources implements ICMakeProjectResources {
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String PROJECT_MANIFESTS_DIRECTORY_NAME = "projectManifests";
    private static final String MODULE_MANIFESTS_DIRECTORY_NAME = "moduleManifests";
    private static final String CMAKE_LISTS_MANIFESTS_DIRECTORY_NAME = "cmakeListsManifests";
    private static final String PROJECTS_DIRECTORY_NAME = "projects";
    private static final String MODULES_DIRECTORY_NAME = "modules";
    private static final String PROJECT_DEPLOYMENT_RESULTS_DIRECTORY_NAME = "projectDeploymentResults";
    private static final String PROJECT_MANIFEST = "projectManifest.json";

    private static final List<String> PROJECT_MANIFESTS = ArrayLists.make(
        "projectManifest.json");

    private static final List<String> MODULE_MANIFESTS = ArrayLists.make(
        "baseTestManifest.json");

    private static final List<String> CMAKE_LISTS_MANIFESTS = ArrayLists.make(
        "cmakeListsManifest.json");

    private static final List<String> PROJECTS = ArrayLists.make(
        "project.json");

    private static final List<String> MODULES = ArrayLists.make(
        "baseModule.json");

    private static final List<String> PROJECT_DEPLOYMENT_RESULTS = ArrayLists.make(
        "projectDeploymentResult.json");

    /**
     * The CMakeProjectResources constructor.
     */
    public VideoRenderingVisualizerCMakeProjectResources() {
    }

    /**
     * Gets path of cmake project manifest of DevEnvironment project.
     */
    @Override
    public Path getCMakeProjectManifestPath() {
        return ResourcePaths.create(
            dataDirectory("videoRenderingVisualizer"),
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
                dataDirectory("videoRenderingVisualizer"),
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
                    dataDirectory("videoRenderingVisualizer"),
                    PROJECT_DEPLOYMENT_RESULTS_DIRECTORY_NAME,
                    projectDeploymentResult);

            result.add(path);
        }

        return result;
    }

    /**
     * Gets the resources of module manifests.
     */
    @Override
    public List<Path> getModuleManifestResources() {
        List<Path> result = new ArrayList<>();

        for (String moduleManifest : MODULE_MANIFESTS) {
            Path path = ResourcePaths.create(
                dataDirectory("videoRenderingVisualizer"),
                MODULE_MANIFESTS_DIRECTORY_NAME,
                moduleManifest);

            result.add(path);
        }

        return result;
    }

    /**
     * Gets the resources of CMakeLists manifests.
     */
    @Override
    public List<Path> getCMakeListsManifestResources() {
        List<Path> result = new ArrayList<>();

        for (String cmakeListsManifest : CMAKE_LISTS_MANIFESTS) {
            Path path = ResourcePaths.create(
                dataDirectory("videoRenderingVisualizer"),
                CMAKE_LISTS_MANIFESTS_DIRECTORY_NAME,
                cmakeListsManifest);

            result.add(path);
        }

        return result;
    }

    /**
     * Gets the resources of projects.
     */
    @Override
    public List<Path> getProjectResources() {
        List<Path> result = new ArrayList<>();

        for (String project : PROJECTS) {
            Path path = ResourcePaths.create(
                dataDirectory("videoRenderingVisualizer"),
                PROJECTS_DIRECTORY_NAME,
                project);

            result.add(path);
        }

        return result;
    }

    /**
     * Gets the resources of modules.
     */
    @Override
    public List<Path> getModuleResources() {
        List<Path> result = new ArrayList<>();

        for (String module : MODULES) {
            Path path = ResourcePaths.create(
                dataDirectory("videoRenderingVisualizer"),
                MODULES_DIRECTORY_NAME,
                module);

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
