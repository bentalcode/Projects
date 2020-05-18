package clionbuild.interfaces;

/**
 * The ICLionBuildDeployer interface defines a deployer of a CLion build.
 */
public interface ICLionBuildDeployer {
    /**
     * Deploys a CLion project.
     */
    ICLionProjectDeploymentResult deploy(ICLionProjectManifest manifest);

    /**
     * Simulates a deployment of a CLion project.
     */
    ICLionProjectDeploymentResult simulate(ICLionProjectManifest manifest);
}
