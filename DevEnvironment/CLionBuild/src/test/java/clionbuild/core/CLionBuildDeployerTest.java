package clionbuild.core;

import base.core.ResourceReader;
import base.interfaces.IDeployer;
import clionbuild.interfaces.ICLionProjectManifest;
import clionbuild.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.nio.file.Path;

/**
 * The CLionBuildDeployerTest class implements tests for a CLion Build Deployer.
 */
public final class CLionBuildDeployerTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The HeapSortTest constructor.
     */
    public CLionBuildDeployerTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the logic of a CLion Build Deployer.
     */
    @Test
    public void cLionBuildDeployerTest() {
        for (Path path : this.testData.getProjectManifestsResources()) {
            String json = ResourceReader.loadString(path);
            ICLionProjectManifest manifest = CLionProjectManifest.fromJson(json);
            this.testCLionBuildDeployer(manifest);
        }
    }

    /**
     * Tests the logic of a CLion Build Deployer.
     */
    private void testCLionBuildDeployer(ICLionProjectManifest manifest) {
        IDeployer deployer = new CLionBuildDeployer(manifest);
        deployer.deploy();
    }
}
