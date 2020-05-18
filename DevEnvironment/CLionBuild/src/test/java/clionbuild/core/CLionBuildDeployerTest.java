package clionbuild.core;

import base.core.ResourceReader;
import clionbuild.interfaces.ICLionBuildDeployer;
import clionbuild.interfaces.ICLionProjectDeploymentResult;
import clionbuild.interfaces.ICLionProjectManifest;
import clionbuild.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.nio.file.Path;
import java.util.List;

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
        List<Path> projectManifestsPaths = this.testData.getProjectManifestResources();
        List<Path> projectDeploymentResultsPaths = this.testData.getProjectDeploymentResultResources();
        assert(projectManifestsPaths.size() == projectDeploymentResultsPaths.size());

        int manifestIndex = 0;
        int resultIndex = 0;

        while (manifestIndex < projectManifestsPaths.size() && resultIndex < projectDeploymentResultsPaths.size()) {
            String projectManifestJson = ResourceReader.loadString(projectManifestsPaths.get(manifestIndex));
            ICLionProjectManifest manifest = CLionProjectManifest.fromJson(projectManifestJson);

            String projectDeploymentResultJson = ResourceReader.loadString(projectDeploymentResultsPaths.get(resultIndex));
            ICLionProjectDeploymentResult projectDeploymentResult = CLionProjectDeploymentResult.fromJson(projectDeploymentResultJson);

            this.testCLionBuildDeployer(manifest, projectDeploymentResult);

            ++manifestIndex;
            ++resultIndex;
        }
    }

    /**
     * Tests the logic of a CLion Build Deployer.
     */
    private void testCLionBuildDeployer(
        ICLionProjectManifest manifest,
        ICLionProjectDeploymentResult expectedResult) {

        ICLionBuildDeployer deployer = new CLionBuildDeployer();
        ICLionProjectDeploymentResult result = deployer.simulate(manifest);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of CLion Build deployment.");
    }
}
