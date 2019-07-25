package json.core;

import base.core.Pair;
import base.core.Paths;
import base.core.ResourcePathBuilder;
import base.interfaces.IPair;
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

    private static final List<IPair<String, Class<?>>> SimpleJsonResourcesInformation = new ArrayList<>();

    static {
        SimpleJsonResourcesInformation.add(Pair.of("simpleResource1.json", Types.class));
        SimpleJsonResourcesInformation.add(Pair.of("simpleResource2.json", Fruit.class));
        SimpleJsonResourcesInformation.add(Pair.of("simpleResource3.json", Colors.class));
    }

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets information of simple json resources.
     */
    @Override
    public List<IPair<Path, Class<?>>> getSimpleJsonResourcesInformation() {
        List<IPair<Path, Class<?>>> information = new ArrayList<>();

        for (IPair<String, Class<?>> resourceInformation : TestData.SimpleJsonResourcesInformation) {
            Path path = this.createSimpleJsonResourcePath(resourceInformation.first());
            Class<?> classType = resourceInformation.second();

            information.add(Pair.of(path, classType));
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
