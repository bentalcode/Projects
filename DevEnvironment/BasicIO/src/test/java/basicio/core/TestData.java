package basicio.core;

import basicio.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String dataDirectoryName = "data";
    private static final String fileFormatDirectoryName = "fileFormat";

    private static final String[] fileFormatResourceNames = {
        "UnixFormat.h",
        "WindowsFormat.h"
    };

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets paths of files in different formats.
     */
    @Override
    public List<Path> getFileFormatResourcePaths() {
        List<Path> result = new ArrayList<>();

        for (String path : TestData.fileFormatResourceNames) {
            Path requestPath = ResourcePaths.create(
                TestData.dataDirectoryName,
                TestData.fileFormatDirectoryName,
                path);

            result.add(requestPath);
        }

        return result;
    }
}
