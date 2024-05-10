package cmakebuildsystem.core;

import base.core.ResourceReader;
import cmakebuildsystem.interfaces.*;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.nio.file.Path;
import java.util.List;

/**
 * The CMakeBuildDeployment class implements a CMake Build Deployment.
 */
public final class CMakeBuildDeployment {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The HeapSortTest constructor.
     */
    public CMakeBuildDeployment() {
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
}
