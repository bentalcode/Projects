package cmakebuildsystem.core;

import base.core.ArrayLists;
import base.core.Environment;
import base.interfaces.OperatingSystemType;
import cmakebuildsystem.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String PROJECT_MANIFESTS_DIRECTORY_NAME = "projectManifests";
    private static final String MODULE_MANIFESTS_DIRECTORY_NAME = "moduleManifests";
    private static final String CMAKE_LISTS_MANIFESTS_DIRECTORY_NAME = "cmakeListsManifests";
    private static final String PROJECTS_DIRECTORY_NAME = "projects";
    private static final String MODULES_DIRECTORY_NAME = "modules";
    private static final String PROJECT_DEPLOYMENT_RESULTS_DIRECTORY_NAME = "projectDeploymentResults";
    private static final String PROJECT_MANIFEST_DEV_ENVIRONMENT = "projectManifest1.json";

    private static final List<String> PROJECT_MANIFESTS = ArrayLists.make(
        "projectManifest1.json");

    private static final List<String> MODULE_MANIFESTS = ArrayLists.make(
        "moduleManifest1.json");

    private static final List<String> CMAKE_LISTS_MANIFESTS = ArrayLists.make(
        "cmakeListsManifest1.json");

    private static final List<String> PROJECTS = ArrayLists.make(
        "project1.json");

    private static final List<String> MODULES = ArrayLists.make(
        "module1.json");

    private static final List<String> PROJECT_DEPLOYMENT_RESULTS = ArrayLists.make(
        "projectDeploymentResult1.json");

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets the resource of the project manifest of DevEnvironmentCMake project.
     */
    @Override
    public Path getDevEnvironmentCMakeProjectManifestResource() {
        Path path = ResourcePaths.create(
            dataDirectory(),
            PROJECT_MANIFESTS_DIRECTORY_NAME,
            PROJECT_MANIFEST_DEV_ENVIRONMENT);

        return path;
    }

    /**
     * Gets the resources of project manifests.
     */
    @Override
    public List<Path> getProjectManifestResources() {
        List<Path> result = new ArrayList<>();

        for (String projectManifest : PROJECT_MANIFESTS) {
            Path path = ResourcePaths.create(
                dataDirectory(),
                PROJECT_MANIFESTS_DIRECTORY_NAME,
                projectManifest);

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
                dataDirectory(),
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
                dataDirectory(),
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
                dataDirectory(),
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
                dataDirectory(),
                MODULES_DIRECTORY_NAME,
                module);

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
                dataDirectory(),
                PROJECT_DEPLOYMENT_RESULTS_DIRECTORY_NAME,
                projectDeploymentResult);

            result.add(path);
        }

        return result;
    }

    /**
     * Gets the data directory.
     */
    private static String dataDirectory() {
        OperatingSystemType operatingSystemType = Environment.getOperatingSystem();
        String operatingSystemDirectory = operatingSystemType.toString().toLowerCase();
        return ResourcePaths.create(operatingSystemDirectory, DATA_DIRECTORY_NAME).toString();
    }
}
