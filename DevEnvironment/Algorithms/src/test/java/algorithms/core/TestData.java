package algorithms.core;

import algorithms.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String dataDirectoryName = "data";
    private static final String catalanDirectoryName = "catalan";
    private static final String catalansFileName = "catalans.txt";

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets path of a catalan resource.
     */
    @Override
    public Path getCatalanResourcePath()
     {
        Path path = ResourcePaths.create(
            TestData.dataDirectoryName,
            TestData.catalanDirectoryName,
            TestData.catalansFileName);

        return path;
    }
}
