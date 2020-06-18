package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.CMakeBuildException;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import cmakebuildsystem.interfaces.ICMakeVariable;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CMakeModuleContextData class implements context data of a module in a cmake build.
 */
public final class CMakeModuleContextData implements ICMakeModuleContextData {
    private final ICMakeModule module;
    private final ICMakeModuleManifest manifest;
    private final List<ICMakeModule> dependencies;
    private final boolean effective;
    private final Map<String, ICMakeVariable> variables = new HashMap<>();
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CMakeModuleContextData constructor.
     */
    public CMakeModuleContextData(
        ICMakeModule module,
        ICMakeModuleManifest manifest,
        List<ICMakeModule> dependencies,
        boolean effective) {

        Conditions.validateNotNull(
            module,
            "The modules.");

        Conditions.validateNotNull(
            manifest,
            "The manifest.");

        Conditions.validateNotNull(
            dependencies,
            "The dependencies.");

        this.module = module;
        this.manifest = manifest;
        this.dependencies = dependencies;
        this.effective = effective;
    }

    /**
     * Gets the module.
     */
    @Override
    public ICMakeModule getModule() {
        return this.module;
    }

    /**
     * Gets the manifest of a module.
     */
    @Override
    public ICMakeModuleManifest getManifest() {
        return this.manifest;
    }

    /**
     * Gets the dependencies of a module.
     */
    @Override
    public List<ICMakeModule> getDependencies() {
        return this.dependencies;
    }

    /**
     * Return whether a module is effective.
     */
    @Override
    public boolean effective() {
        return this.effective;
    }

    /**
     * Sets a variable of a module.
     */
    @Override
    public void setVariable(ICMakeVariable variable) {
        Conditions.validateNotNull(
            variable,
            "The variable of a module.");

        this.variables.put(variable.getName(), variable);
    }

    /**
     * Gets a variable of a module.
     */
    @Override
    public ICMakeVariable getVariable(String name) {
        if (!this.variables.containsKey(name)) {
            String errorMessage = "The variable name: " + name + " does not exist.";

            this.log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        return this.variables.get(name);
    }
}
