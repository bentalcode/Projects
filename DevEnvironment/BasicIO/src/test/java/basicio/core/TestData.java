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
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String FILE_FORMAT_DIRECTORY_NAME = "fileFormat";
    private static final String PARAGRAPHS_DIRECTORY_NAME = "paragraphs";
    private static final String PARAGRAPH_FILE_NAME = "paragraph";
    private static final String PARAGRAPH_FILE_EXTENSION = "txt";

    private static final String[] FILE_FORMAT_RESOURCE_NAMES = {
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

        for (String path : TestData.FILE_FORMAT_RESOURCE_NAMES) {
            Path requestPath = ResourcePaths.create(
                TestData.DATA_DIRECTORY_NAME,
                TestData.FILE_FORMAT_DIRECTORY_NAME,
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
                .addComponent(TestData.DATA_DIRECTORY_NAME)
                .addComponent(TestData.PARAGRAPHS_DIRECTORY_NAME)
                .addComponent(PARAGRAPH_FILE_NAME + paragraphIndex)
                .setExtension(TestData.PARAGRAPH_FILE_EXTENSION)
                .build();


            result.add(Paths.create(path));
        }

        return result;
    }
}
