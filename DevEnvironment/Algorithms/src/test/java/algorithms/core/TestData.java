package algorithms.core;

import algorithms.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String CATALAN_DIRECTORY_NAME = "catalan";
    private static final String CATALANS_FILE_NAME = "catalans.txt";

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
            TestData.DATA_DIRECTORY_NAME,
            TestData.CATALAN_DIRECTORY_NAME,
            TestData.CATALANS_FILE_NAME);

        return path;
    }
}
