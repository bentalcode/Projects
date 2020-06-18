package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.CMakeBuildException;
import cmakebuildsystem.interfaces.ICMakeModule;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CMakeModuleDependencyManager class implements a dependency manager for cmake modules.
 */
public final class CMakeModuleDependencyManager implements ICMakeModuleDependencyManager {
    private final Map<String, ICMakeModule> modules;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CMakeModuleDependencyManager constructor.
     */
    public CMakeModuleDependencyManager(Map<String, ICMakeModule> modules) {
        Conditions.validateNotNull(
            modules,
            "The modules map.");

        this.modules = modules;
    }

    /**
     * Resolves the modules dependencies.
     */
    @Override
    public Map<String, List<ICMakeModule>> resolveModulesDependencies() {
        Map<String, List<ICMakeModule>> modulesDependencies = new HashMap<>();

        for (Map.Entry<String, ICMakeModule> moduleEntry : this.modules.entrySet()) {
            String name = moduleEntry.getKey();
            ICMakeModule module = moduleEntry.getValue();

            this.resolveModuleDependencies(
                name,
                module,
                modulesDependencies);
        }

        return modulesDependencies;
    }

    /**
     * Resolves dependencies of a specific module.
     */
    private void resolveModuleDependencies(
        String name,
        ICMakeModule module,
        Map<String, List<ICMakeModule>> modulesDependencies) {

        if (!name.equals(module.getName())) {
            String errorMessage = "The name of the module is not matching.";

            this.log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        List<ICMakeModule> dependentModules = new ArrayList<>();

        for (String dependentModuleName : module.getDependentModules()) {
            ICMakeModule dependentModule = this.modules.get(dependentModuleName);
            dependentModules.add(dependentModule);
        }

        modulesDependencies.put(module.getName(), dependentModules);
    }
}
