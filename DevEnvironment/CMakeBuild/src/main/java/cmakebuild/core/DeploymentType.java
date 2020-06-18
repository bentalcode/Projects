package cmakebuild.core;

import base.core.Strings;
import cmakebuild.CMakeBuildException;
import cmakebuild.interfaces.ICMakeModule;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

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
    private final static Logger log = LoggerFactory.getLogger(DeploymentType.class);

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

    /**
     * Parses an enum string.
     */
    public static DeploymentType parse(String value) {
        DeploymentType type = tryParse(value);

        if (type == null) {
            String errorMessage =
                "The string: " + value + " is not matching to any type of enum: DeploymentType.";

            log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        return type;
    }

    /**
     * Tries to parse an enum string.
     * Return null of the string value is not matching to a specific enum.
     */
    public static DeploymentType tryParse(String value) {
        if (Strings.isNullOrEmpty(value)) {
            return null;
        }

        for (DeploymentType moduleType : DeploymentType.values()) {
            if (moduleType.name.equalsIgnoreCase(value)) {
                return moduleType;
            }
        }

        return null;
    }
}
