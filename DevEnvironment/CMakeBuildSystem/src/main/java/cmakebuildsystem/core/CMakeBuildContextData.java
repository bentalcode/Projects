package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.CMakeBuildException;
import cmakebuildsystem.interfaces.ICMakeListsManifest;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import cmakebuildsystem.interfaces.ICMakeProjectManifest;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CMakeBuildContextData class implements context data of a cmake build.
 */
public final class CMakeBuildContextData implements ICMakeBuildContextData {
    private final ICMakeProjectManifest projectManifest;
    private final Map<String, ICMakeModuleContextData> modulesContextData = new HashMap<>();
    private final Map<String, String> data = new HashMap<>();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CMakeBuildContextData constructor.
     */
    public CMakeBuildContextData(
        ICMakeProjectManifest projectManifest,
        Map<String, ICMakeModule> modules,
        Map<String, ICMakeModuleManifest> modulesManifests,
        Map<String, List<ICMakeModule>> modulesDependencies,
        Set<String> effectiveModules) {

        Conditions.validateNotNull(
            projectManifest,
            "The project manifest.");

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
            "The effective modules set.");

        this.projectManifest = projectManifest;

        this.createModulesContextData(
            modules,
            modulesManifests,
            modulesDependencies,
            effectiveModules);
    }

    /**
     * Gets the context data of a module.
     */
    @Override
    public ICMakeModuleContextData getModuleContextData(String name) {
        if (!this.modulesContextData.containsKey(name)) {
            String errorMessage = "The context data of module: " + name + " is not defined.";

            this.log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        return this.modulesContextData.get(name);
    }

    /**
     * Sets generic data of the build.
     */
    @Override
    public void setData(String name, String data) {
        this.data.put(name, data);
    }

    /**
     * Gets generic data of the build.
     */
    @Override
    public Map<String, String> getData() {
        return this.data;
    }

    /**
     * Creates the context data of modules.
     */
    private void createModulesContextData(
        Map<String, ICMakeModule> modules,
        Map<String, ICMakeModuleManifest> modulesManifests,
        Map<String, List<ICMakeModule>> modulesDependencies,
        Set<String> effectiveModules) {

        for (Map.Entry<String, ICMakeModule> moduleEntry : modules.entrySet()) {
            String moduleName = moduleEntry.getKey();
            ICMakeModule module = moduleEntry.getValue();

            ICMakeModuleManifest moduleManifest = modulesManifests.get(moduleName);
            List<ICMakeModule> moduleDependencies = modulesDependencies.get(moduleName);
            boolean effectiveModule = effectiveModules.contains(moduleName);

            ICMakeListsManifest cmakeListsManifest = calculateCMakeListManifest(
                projectManifest,
                moduleManifest);

            ICMakeModuleContextData contextData = new CMakeModuleContextData(
                module,
                moduleManifest,
                cmakeListsManifest,
                moduleDependencies,
                effectiveModule);

            this.modulesContextData.put(moduleName, contextData);
        }
    }

    /**
     * Calculate manifest of CMake Lists.
     */
    private static ICMakeListsManifest calculateCMakeListManifest(
        ICMakeProjectManifest projectManifest,
        ICMakeModuleManifest moduleManifest) {

        ICMakeListsManifest manifest = moduleManifest.getCMakeListsManifest();

        if (manifest == null) {
            manifest = projectManifest.getCMakeListsManifest();
        }

        if (manifest == null) {
            manifest = CMakeListsManifest.defaultManifest();
        }

        return manifest;
    }
}
