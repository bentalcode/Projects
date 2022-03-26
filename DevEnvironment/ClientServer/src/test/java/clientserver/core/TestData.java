package clientserver.core;

import clientserver.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String RETRY_POLICY_DIRECTORY_NAME = "retryPolicy";

    private static final String[] RETRY_POLICY_RESOURCE_NAMES = {
        "retryPolicy.json"
    };

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets paths of retry policies.
     */
    @Override
    public List<Path> getRetryPolicyPaths() {
        List<Path> result = new ArrayList<>();

        for (String path : TestData.RETRY_POLICY_RESOURCE_NAMES) {
            Path requestPath = ResourcePaths.create(
                TestData.DATA_DIRECTORY_NAME,
                TestData.RETRY_POLICY_DIRECTORY_NAME,
                path);

            result.add(requestPath);
        }

        return result;
    }
}
