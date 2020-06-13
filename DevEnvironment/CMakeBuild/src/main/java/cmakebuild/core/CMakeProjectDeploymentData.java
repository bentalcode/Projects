package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.CMakeBuildException;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeModuleManifest;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CMakeProjectDeploymentData class implements runtime data of a project deployment.
 */
public final class CMakeProjectDeploymentData implements ICMakeProjectDeploymentData {
    private final Map<String, ICMakeModule> modules;
    private final Map<String, ICMakeModuleManifest> modulesManifests;
    private final Map<String, List<ICMakeModule>> modulesDependencies;
    private final Set<String> effectiveModules;
    private final Map<String, String> data = new HashMap<>();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CMakeProjectDeploymentData constructor.
     */
    public CMakeProjectDeploymentData(
        Map<String, ICMakeModule> modules,
        Map<String, ICMakeModuleManifest> modulesManifests,
        Map<String, List<ICMakeModule>> modulesDependencies,
        Set<String> effectiveModules) {

        Conditions.validateNotNull(
            modules,
            "The modules map.");

        Conditions.validateNotNull(
            modulesManifests,
            "The modules-manifests map.");

        Conditions.validateNotNull(
            modulesDependencies,
            "The modules-dependencies map.");

        Conditions.validateNotNull(
            effectiveModules,
            "The effective modules.");

        this.modules = modules;
        this.modulesManifests = modulesManifests;
        this.modulesDependencies = modulesDependencies;
        this.effectiveModules = effectiveModules;
    }

    /**
     * Gets the module by name.
     */
    @Override
    public ICMakeModule getModule(String name) {
        if (!this.modules.containsKey(name)) {
            String errorMessage = "The module: " + name + " is not defined in this project.";

            this.log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        return this.modules.get(name);
    }

    /**
     * Gets the manifest of a module by name.
     */
    @Override
    public ICMakeModuleManifest getModuleManifest(String name) {
        if (!this.modulesManifests.containsKey(name)) {
            String errorMessage = "The manifest of module: " + name + " is not defined in this project.";

            this.log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        return this.modulesManifests.get(name);
    }

    /**
     * Gets the dependencies of a module by name.
     */
    @Override
    public List<ICMakeModule> getModuleDependencies(String name) {
        if (!this.modulesDependencies.containsKey(name)) {
            String errorMessage = "The dependent modules of module: " + name + " are not defined in this project.";

            this.log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        return this.modulesDependencies.get(name);
    }

    /**
     * Return whether the module is effective.
     */
    @Override
    public boolean moduleEffective(String name) {
        return this.effectiveModules.contains(name);
    }

    /**
     * Gets the data of the deployment.
     */
    @Override
    public Map<String, String> getData() {
        return this.data;
    }

    /**
     * Sets the data of a module.
     */
    @Override
    public void setModuleData(String name, String data) {
        this.data.put(name, data);
    }
}
