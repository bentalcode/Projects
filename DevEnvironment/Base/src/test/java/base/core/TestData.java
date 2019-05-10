package base.core;

import base.interfaces.ITestData;
import java.nio.file.Path;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DataDirectoryName = "data";
    private static final String PrimesDirectoryName = "primes";
    private static final String PrimesFileName = "primes.txt";

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets path of a primes resource.
     */
    public Path getPrimesResourcePath() {
        Path path = this.createResourcePath(
            TestData.DataDirectoryName,
            TestData.PrimesDirectoryName,
            TestData.PrimesFileName);

        return path;
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
