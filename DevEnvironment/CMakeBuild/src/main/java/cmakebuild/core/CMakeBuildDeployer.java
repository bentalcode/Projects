package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildDeployer;
import cmakebuild.interfaces.ICMakeProject;
import cmakebuild.interfaces.ICMakeProjectDeploymentResult;
import cmakebuild.interfaces.ICMakeProjectManifest;
import cmakebuild.interfaces.IMakeProjectDeployer;

/**
 * The CMakeBuildDeployer class implements a deployer of a CMake Build.
 */
public final class CMakeBuildDeployer implements ICMakeBuildDeployer {
    /**
     * The CMakeBuildDeployer constructor.
     */
    public CMakeBuildDeployer() {
    }

    /**
     * Deploys a CMake Build.
     */
    @Override
    public ICMakeProjectDeploymentResult deploy(ICMakeProjectManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a CMake project.");

        IMakeProjectDeployer projectDeployer = this.createProjectDeployer(manifest);

        return projectDeployer.deploy();
    }

    /**
     * Simulates a deployment of a CMake Build.
     */
    @Override
    public ICMakeProjectDeploymentResult simulate(ICMakeProjectManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a CMake project.");

        IMakeProjectDeployer projectDeployer = this.createProjectDeployer(manifest);

        return projectDeployer.simulate();
    }

    /**
     * Creates the project deployer.
     */
    private IMakeProjectDeployer createProjectDeployer(ICMakeProjectManifest manifest) {
        ICMakeProject project = this.scanProject(manifest);

        IMakeProjectDeployer projectDeployer = new CMakeProjectDeployer(
            manifest,
            project);

        return projectDeployer;
    }

    /**
     * Scans a project.
     */
    private ICMakeProject scanProject(ICMakeProjectManifest manifest) {
        CMakeProjectScanner scanner = new CMakeProjectScanner(manifest);
        ICMakeProject project = scanner.scan();
        return project;
    }
}
