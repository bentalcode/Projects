package cmakebuildsystem.interfaces;

/**
 * The ICMakeBuildDeployer interface defines a deployer of a CMake build.
 */
public interface ICMakeBuildDeployer {
    /**
     * Deploys a CMake project.
     */
    ICMakeProjectDeploymentResult deploy(ICMakeProjectManifest manifest);

    /**
     * Simulates a deployment of a CMake project.
     */
    ICMakeProjectDeploymentResult simulate(ICMakeProjectManifest manifest);
}
