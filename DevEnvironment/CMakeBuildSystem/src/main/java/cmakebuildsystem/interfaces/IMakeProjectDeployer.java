package cmakebuildsystem.interfaces;

/**
 * The ICMakeProjectDeployer interface defines a deployer of a CMake project.
 */
public interface IMakeProjectDeployer {
    /**
     * Deploys a CMake project.
     */
    ICMakeProjectDeploymentResult deploy();

    /**
     * Simulates a deployment of a CMake project.
     */
    ICMakeProjectDeploymentResult simulate();
}
