package clientserver.core;

import base.core.Pair;
import base.core.Paths;
import base.core.ResourcePathBuilder;
import base.interfaces.IPair;
import clientserver.interfaces.ITestData;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DataDirectoryName = "data";
    private static final String JsonDirectoryName = "json";

    private static final List<IPair<String, Class<?>>> JsonResourcesInformation = new ArrayList<>();

    static {
        JsonResourcesInformation.add(Pair.of("retryPolicy.json", RetryPolicy.class));
    }

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets information of json resources.
     */
    @Override
    public List<IPair<Path, Class<?>>> getJsonResourcesInformation() {
        List<IPair<Path, Class<?>>> information = new ArrayList<>();

        for (IPair<String, Class<?>> resourceInformation : TestData.JsonResourcesInformation) {
            Path path = this.createJsonResourcePath(resourceInformation.first());
            Class<?> classType = resourceInformation.second();

            information.add(Pair.of(path, classType));
        }

        return information;
    }

    /**
     * Creates a path of a json resource.
     */
    private Path createJsonResourcePath(String resourceName) {
        return this.createResourcePath(
            TestData.DataDirectoryName,
            TestData.JsonDirectoryName,
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
