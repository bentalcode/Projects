package cmakebuildsystem.core;

import base.core.ArrayLists;
import cmakebuildsystem.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String dataDirectoryName = "data";
    private static final String projectManifestsDirectoryName = "projectManifests";
    private static final String moduleManifestsDirectoryName = "moduleManifests";
    private static final String cmakeListsManifestsDirectoryName = "cmakeListsManifests";
    private static final String projectsDirectoryName = "projects";
    private static final String modulesDirectoryName = "modules";
    private static final String projectDeploymentResultsDirectoryName = "projectDeploymentResults";
    private static final String projectManifestDevEnvironment = "projectManifest1.json";

    private static final List<String> projectManifests = ArrayLists.of(
        "projectManifest1.json");

    private static final List<String> moduleManifests = ArrayLists.of(
        "moduleManifest1.json");

    private static final List<String> cmakeListsManifests = ArrayLists.of(
        "cmakeListsManifest1.json");

    private static final List<String> projects = ArrayLists.of(
        "project1.json");

    private static final List<String> modules = ArrayLists.of(
        "module1.json");

    private static final List<String> projectDeploymentResults = ArrayLists.of(
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
            dataDirectoryName,
            projectManifestsDirectoryName,
            projectManifestDevEnvironment);

        return path;
    }

    /**
     * Gets the resources of project manifests.
     */
    @Override
    public List<Path> getProjectManifestResources() {
        List<Path> result = new ArrayList<>();

        for (String projectManifest : projectManifests) {
            Path path = ResourcePaths.create(
                dataDirectoryName,
                projectManifestsDirectoryName,
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

        for (String moduleManifest : moduleManifests) {
            Path path = ResourcePaths.create(
                dataDirectoryName,
                moduleManifestsDirectoryName,
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

        for (String cmakeListsManifest : cmakeListsManifests) {
            Path path = ResourcePaths.create(
                dataDirectoryName,
                cmakeListsManifestsDirectoryName,
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

        for (String project : projects) {
            Path path = ResourcePaths.create(
                dataDirectoryName,
                projectsDirectoryName,
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

        for (String module : modules) {
            Path path = ResourcePaths.create(
                dataDirectoryName,
                modulesDirectoryName,
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

        for (String projectDeploymentResult : projectDeploymentResults) {
            Path path = ResourcePaths.create(
                dataDirectoryName,
                projectDeploymentResultsDirectoryName,
                projectDeploymentResult);

            result.add(path);
        }

        return result;
    }
}
