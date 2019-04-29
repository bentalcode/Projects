package json.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets simple resources of Json.
     */
    List<Path> getSimpleJsonResources();
}
