package json.interfaces;

import base.interfaces.IPair;
import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets information of simple json resources.
     */
    List<IPair<Path, Class<?>>> getSimpleJsonResourcesInformation();
}
