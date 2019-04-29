package json.core;

import base.core.Paths;
import base.core.ResourcePathBuilder;
import json.interfaces.ITestData;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DataDirectoryName = "data";
    private static final String SimpleJsonResourcesDirectoryName = "simpleJsonResources";

    private static final String[] SimpleJsonResourceNames = {
        "simpleResource1.json"
    };

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets simple resources of Json.
     */
    public List<Path> getSimpleJsonResources() {
        List<Path> paths = new ArrayList<>();

        for (String resourceName : TestData.SimpleJsonResourceNames) {
            paths.add(this.createSimpleJsonResourcePath(resourceName));
        }

        return paths;
    }

    /**
     * Creates a path of a simple json resource.
     */
    public Path createSimpleJsonResourcePath(String resourceName) {

        return this.createResourcePath(
            TestData.DataDirectoryName,
            TestData.SimpleJsonResourcesDirectoryName,
            resourceName);
    }

    /**
     * Creates a path of a resource.
     */
    public Path createResourcePath(
        String rootDirectory,
        String subDirectory,
        String resourceName) {

        String path = new ResourcePathBuilder()
            .addComponent(rootDirectory)
            .addComponent(subDirectory)
            .addComponent(resourceName)
            .build();

        return Paths.create(path);
    }
}
