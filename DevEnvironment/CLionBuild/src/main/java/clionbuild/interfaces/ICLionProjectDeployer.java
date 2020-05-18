package clionbuild.interfaces;

/**
 * The ICLionProjectDeployer interface defines a deployer of a CLion project.
 */
public interface ICLionProjectDeployer {
    /**
     * Deploys a CLion project.
     */
    ICLionProjectDeploymentResult deploy();

    /**
     * Simulates a deployment of a CLion project.
     */
    ICLionProjectDeploymentResult simulate();
}
