package clionbuild.core;

import base.core.Conditions;
import base.interfaces.IDeployer;
import clionbuild.interfaces.ICLionProject;
import clionbuild.interfaces.ICLionProjectManifest;

/**
 * The CLionBuildDeployer class implements a deployer of a CLion Build.
 */
public final class CLionBuildDeployer implements IDeployer {
    private final ICLionProjectManifest manifest;

    /**
     * The CLionBuildDeployer constructor.
     */
    public CLionBuildDeployer(ICLionProjectManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a CLion project.");

        this.manifest = manifest;
    }

    /**
     * Deploys a the CLion Build.
     */
    @Override
    public void deploy() {
        ICLionProject project = this.scanProject();
    }

    /**
     * Scans a project.
     */
    private ICLionProject scanProject() {
        CLionProjectScanner scanner = new CLionProjectScanner(this.manifest);
        ICLionProject project = scanner.scan();
        return project;
    }
}
