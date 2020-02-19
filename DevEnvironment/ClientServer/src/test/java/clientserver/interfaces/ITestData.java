package clientserver.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets paths of retry policies.
     */
    List<Path> getRetryPolicyPaths();
}
