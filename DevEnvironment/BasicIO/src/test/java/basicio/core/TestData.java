package basicio.core;

import base.core.Paths;
import base.core.ResourcePathBuilder;
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
    private static final String paragraphsDirectoryName = "paragraphs";
    private static final String paragraphFileName = "paragraph";
    private static final String paragraphFileExtension = "txt";

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

    /**
     * Gets paths of paragraphs.
     */
    public List<Path> getParagraphResourcePaths() {
        List<Path> result = new ArrayList<>();

        int paragraphStartIndex = 1;
        int paragraphEndIndex = 62;

        for (int paragraphIndex = paragraphStartIndex; paragraphIndex <= paragraphEndIndex; ++paragraphIndex) {
            String path = new ResourcePathBuilder()
                .addComponent(TestData.dataDirectoryName)
                .addComponent(TestData.paragraphsDirectoryName)
                .addComponent(paragraphFileName + paragraphIndex)
                .setExtension(TestData.paragraphFileExtension)
                .build();


            result.add(Paths.create(path));
        }

        return result;
    }
}
