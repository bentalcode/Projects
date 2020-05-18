package clionbuild.core;

import base.core.Conditions;
import clionbuild.interfaces.ICLionBuildDeployer;
import clionbuild.interfaces.ICLionProject;
import clionbuild.interfaces.ICLionProjectDeploymentResult;
import clionbuild.interfaces.ICLionProjectManifest;

/**
 * The CLionBuildDeployer class implements a deployer of a CLion Build.
 */
public final class CLionBuildDeployer implements ICLionBuildDeployer {
    /**
     * The CLionBuildDeployer constructor.
     */
    public CLionBuildDeployer() {
    }

    /**
     * Deploys a CLion Build.
     */
    @Override
    public ICLionProjectDeploymentResult deploy(ICLionProjectManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a CLion project.");

        ICLionProject project = this.scanProject(manifest);

        CLionProjectDeployer projectDeployer = new CLionProjectDeployer(
            manifest,
            project);

        return projectDeployer.deploy();
    }

    /**
     * Simulates a deployment of a CLion Build.
     */
    @Override
    public ICLionProjectDeploymentResult simulate(ICLionProjectManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a CLion project.");

        ICLionProject project = this.scanProject(manifest);

        CLionProjectDeployer projectDeployer = new CLionProjectDeployer(
            manifest,
            project);

        return projectDeployer.simulate();
    }

    /**
     * Scans a project.
     */
    private ICLionProject scanProject(ICLionProjectManifest manifest) {
        CLionProjectScanner scanner = new CLionProjectScanner(manifest);
        ICLionProject project = scanner.scan();
        return project;
    }
}
