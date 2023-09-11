package cmakebuildsystem.core;

import cmakebuildsystem.interfaces.ICMakeModule;

/**
 * The DeploymentType enum defines various types of a deployment.
 */
public enum DeploymentType {
    Deployment("deployment") {
        /**
         * Creates the deployment logic of a module.
         */
        @Override
        public IModuleDeploymentLogic createModuleDeploymentLogic(ICMakeModule module) {
            return new ModuleDeploymentLogic(module);
        }
    },

    Simulation("simulation") {
        /**
         * Creates the deployment logic of a module.
         */
        @Override
        public IModuleDeploymentLogic createModuleDeploymentLogic(ICMakeModule module) {
            return new ModuleDeploymentSimulationLogic(module);
        }
    };

    private final String name;

    /**
     * The DeploymentType constructor.
     */
    DeploymentType(String name) {
        this.name = name;
    }

    /**
     * Creates the deployment logic of a module.
     */
    public abstract IModuleDeploymentLogic createModuleDeploymentLogic(ICMakeModule module);

    /**
     * Gets the string representation of a cmake module type.
     */
    public String toString() {
        return this.name;
    }
}
