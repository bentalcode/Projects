package basicio.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets paths of files in different formats.
     */
    List<Path> getFileFormatResourcePaths();

    /**
     * Gets paths of paragraphs.
     */
    List<Path> getParagraphResourcePaths();
}
