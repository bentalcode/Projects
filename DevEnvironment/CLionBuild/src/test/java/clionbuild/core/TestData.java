package clionbuild.core;

import base.core.ArrayLists;
import clionbuild.interfaces.ITestData;
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
    private static final String cmakeListsManifestsDirectoryName = "cmakeListsManifests";

    private static final List<String> projectManifests = ArrayLists.of(
        "projectManifest1.json");

    private static final List<String> cmakeListsManifests = ArrayLists.of(
        "cmakeListsManifest1.json");

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets the resources of project manifests.
     */
    @Override
    public List<Path> getProjectManifestsResources() {
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
     * Gets the resources of CMakeLists manifests.
     */
    @Override
    public List<Path> getCMakeListsManifestsResources() {
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
}
