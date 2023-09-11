package cmakebuildsystem.core;

import base.core.FileComparator;
import base.core.Files;
import base.core.ResourceReader;
import base.interfaces.IComparableComparator;
import cmakebuildsystem.interfaces.*;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.io.File;
import java.nio.file.Path;
import java.util.List;
import java.util.Map;
import org.junit.Test;

/**
 * The CMakeBuildDeployerTest class implements tests for a CMake Build Deployer.
 */
public final class CMakeBuildDeployerTest {
    ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The HeapSortTest constructor.
     */
    public CMakeBuildDeployerTest() {
    }

    /**
     * Deploys a CMake build.
     */
    @Test
    public void deployCMakeBuild() {
        List<ICMakeProjectResources> projects = this.testData.getCMakeProjects();

        for (ICMakeProjectResources project : projects) {
            deployCMakeBuild(project);
        }
    }

    /**
     * Tests the logic of deploying a CMake build by using a simulation.
     */
    @Test
    public void deployCMakeProjectBuildTest() {
        List<ICMakeProjectResources> projects = this.testData.getCMakeProjects();

        for (ICMakeProjectResources project : projects) {
            testDeployCMakeBuild(project);
        }
    }

    /**
     * Deploys a CMake build.
     */
    private void deployCMakeBuild(ICMakeProjectResources project) {
        Path path = project.getCMakeProjectManifestPath();
        String json = ResourceReader.loadString(path);
        ICMakeProjectManifest manifest = CMakeProjectManifest.fromJson(json);

        ICMakeBuildDeployer deployer = new CMakeBuildDeployer();
        ICMakeProjectDeploymentResult result = deployer.deploy(manifest);

        this.assertion.assertNotNull(result, "Null deployment result.");
    }

    /**
     * Tests the logic of deploying a CMake build by using a simulation.
     */
    private void testDeployCMakeBuild(ICMakeProjectResources project) {
        List<Path> projectManifestsPaths = project.getProjectManifestResources();
        List<Path> projectDeploymentResultsPaths = project.getProjectDeploymentResultResources();
        assert(projectManifestsPaths.size() == projectDeploymentResultsPaths.size());

        int manifestIndex = 0;
        int resultIndex = 0;

        while (manifestIndex < projectManifestsPaths.size() && resultIndex < projectDeploymentResultsPaths.size()) {
            String projectManifestJson = ResourceReader.loadString(projectManifestsPaths.get(manifestIndex));
            ICMakeProjectManifest manifest = CMakeProjectManifest.fromJson(projectManifestJson);

            String projectDeploymentResultJson = ResourceReader.loadString(projectDeploymentResultsPaths.get(resultIndex));
            ICMakeProjectDeploymentResult projectDeploymentResult = CMakeProjectDeploymentResult.fromJson(projectDeploymentResultJson);

            this.testCMakeBuildDeployer(manifest, projectDeploymentResult);

            ++manifestIndex;
            ++resultIndex;
        }
    }

    /**
     * Tests the logic of a CMake Build Deployer.
     */
    private void testCMakeBuildDeployer(
        ICMakeProjectManifest manifest,
        ICMakeProjectDeploymentResult expectedResult) {

        ICMakeBuildDeployer deployer = new CMakeBuildDeployer();
        ICMakeProjectDeploymentResult result = deployer.simulate(manifest);

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
    }

    /**
     * Validates a deployment file.
     */
    private void validateDeploymentFile(
        String content,
        String expectedContent) {

        File file = Files.createTemporaryFile("cmakeDeploymentResult", "cmakeDeployment.txt", content);
        File expectedFile = Files.createTemporaryFile("cmakeDeploymentResult", "cmakeDeployment.txt", expectedContent);

        IComparableComparator<Path> comparator = new FileComparator();
        int status = comparator.compareTo(file.toPath(), expectedFile.toPath());

        this.assertion.assertTrue(
            status == 0,
            "Incorrect logic for creating a deployment file.");
    }
}
