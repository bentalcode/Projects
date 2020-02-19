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
    private static final String dataDirectoryName = "data";
    private static final String retryPolicyDirectoryName = "retryPolicy";

    private static final String[] retryPolicyResourceNames = {
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

        for (String path : TestData.retryPolicyResourceNames) {
            Path requestPath = ResourcePaths.create(
                TestData.dataDirectoryName,
                TestData.retryPolicyDirectoryName,
                path);

            result.add(requestPath);
        }

        return result;
    }
}
