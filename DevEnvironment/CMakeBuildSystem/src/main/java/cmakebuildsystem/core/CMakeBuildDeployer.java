package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeBuildDeployer;
import cmakebuildsystem.interfaces.ICMakeProject;
import cmakebuildsystem.interfaces.ICMakeProjectDeploymentResult;
import cmakebuildsystem.interfaces.ICMakeProjectManifest;
import cmakebuildsystem.interfaces.IMakeProjectDeployer;

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

        return new CMakeProjectDeployer(
            manifest,
            project);
    }

    /**
     * Scans a project.
     */
    private ICMakeProject scanProject(ICMakeProjectManifest manifest) {
        CMakeProjectScanner scanner = new CMakeProjectScanner(manifest);
        return scanner.scan();
    }
}
