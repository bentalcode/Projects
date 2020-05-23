package clionbuild.core;

import base.core.FileComparator;
import base.core.Files;
import base.core.ResourceReader;
import base.core.Writers;
import base.interfaces.IComparableComparator;
import clionbuild.CLionBuildException;
import clionbuild.interfaces.ICLionBuildDeployer;
import clionbuild.interfaces.ICLionProjectDeploymentResult;
import clionbuild.interfaces.ICLionProjectManifest;
import clionbuild.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.util.List;
import java.util.Map;

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
     * Deploys the clion build.
     */
    @Test
    public void deployCLionDevEnvironmentBuild() {
        Path path = this.testData.getDevEnvironmentCLionProjectManifestResource();
        String json = ResourceReader.loadString(path);
        ICLionProjectManifest manifest = CLionProjectManifest.fromJson(json);

        ICLionBuildDeployer deployer = new CLionBuildDeployer();
        deployer.deploy(manifest);
    }
    /**
     * Tests the logic of a CLion Build Deployer by using a simulation.
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

        Map<String, String> deploymentData = result.getDeploymentData();
        Map<String, String> expectedDeploymentData = expectedResult.getDeploymentData();

        this.assertion.assertEquals(
            deploymentData,
            expectedDeploymentData,
            "Incorrect deployment data result.");

        for (Map.Entry<String, String> entry : deploymentData.entrySet()) {
            String path = entry.getKey();
            String content = entry.getValue();
            String expectedContent = expectedDeploymentData.get(path);

            this.validateDeploymentFile(
                content,
                expectedContent);
        }

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of CLion Build deployment.");
    }

    /**
     * Validates a deployment file.
     */
    private void validateDeploymentFile(
        String content,
        String expectedContent) {

        File file = this.createTempFile(content);
        File expectedFile = this.createTempFile(expectedContent);

        IComparableComparator<Path> comparator = new FileComparator();
        int status = comparator.compareTo(file.toPath(), expectedFile.toPath());

        this.assertion.assertTrue(
            status == 0,
            "Incorrect logic for creating a deployment file.");
    }

    /**
     * Creates a temporary file.
     */
    private File createTempFile(String content) {
        File file = Files.createTemporaryFile("clionDeploymentResult", "clionDeployment.txt");

        try (FileWriter writer = Writers.createFileWriter(file.toPath())) {
            Writers.write(writer, content);
            Writers.flush(writer);
        }
        catch (IOException e) {
            String errorMessage = "Failed to create a temporary file.";
            throw new CLionBuildException(errorMessage);
        }

        file.deleteOnExit();

        return file;
    }
}
