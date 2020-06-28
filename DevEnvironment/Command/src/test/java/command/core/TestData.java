package command.core;

import base.core.ArrayLists;
import command.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String dataDirectoryName = "data";
    private static final String manifestsDirectoryName = "manifests";

    private static final List<String> commandManifests = ArrayLists.of(
        "manifest1.json");

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets the resources of commands manifests.
     */
    @Override
    public List<Path> getCommandManifestResources() {
        List<Path> result = new ArrayList<>();

        for (String commandManifest : commandManifests) {
            Path path = ResourcePaths.create(
                dataDirectoryName,
                manifestsDirectoryName,
                commandManifest);

            result.add(path);
        }

        return result;
    }
}
