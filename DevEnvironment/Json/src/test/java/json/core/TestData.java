package json.core;

import base.core.Pair;
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

    private static final List<Pair<String, Class<?>>> SimpleJsonResourcesInformation = new ArrayList<>();

    static {
        SimpleJsonResourcesInformation.add(new Pair<>("simpleResource1.json", Fruit.class));
        //SimpleJsonResourcesInformation.add(new Pair<>("simpleResource2.json", Colors.class));
    }

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets information of simple json resources.
     */
    public List<Pair<Path, Class<?>>> getSimpleJsonResourcesInformation() {
        List<Pair<Path, Class<?>>> information = new ArrayList<>();

        for (Pair<String, Class<?>> resourceInformation : TestData.SimpleJsonResourcesInformation) {
            Path path = this.createSimpleJsonResourcePath(resourceInformation.first());
            Class<?> classType = resourceInformation.second();

            information.add(new Pair<>(path, classType));
        }

        return information;
    }

    /**
     * Creates a path of a simple json resource.
     */
    private Path createSimpleJsonResourcePath(String resourceName) {
        return this.createResourcePath(
            TestData.DataDirectoryName,
            TestData.SimpleJsonResourcesDirectoryName,
            resourceName);
    }

    /**
     * Creates a path of a resource.
     */
    private Path createResourcePath(
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
