package testbase.core;

import base.core.Paths;
import base.core.ResourcePathBuilder;
import testbase.interfaces.ITestData;
import java.nio.file.Path;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DataDirectoryName = "data";

    /**
     * The TestData constructor.
     */
    public TestData() {
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
