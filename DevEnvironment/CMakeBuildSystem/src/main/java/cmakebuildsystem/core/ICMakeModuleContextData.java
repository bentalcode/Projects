package cmakebuildsystem.core;

import cmakebuildsystem.interfaces.ICMakeListsManifest;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import cmakebuildsystem.interfaces.ICMakeVariable;
import java.util.List;

/**
 * The ICMakeModuleContextData interface defines context data of a module in a cmake build.
 */
public interface ICMakeModuleContextData {
    /**
     * Gets the module.
     */
    ICMakeModule getModule();

    /**
     * Gets the manifest of a module.
     */
    ICMakeModuleManifest getManifest();

    /**
     * Gets the manifest of a cmakelists.
     */
    ICMakeListsManifest getCMakeListsManifest();

    /**
     * Gets the dependencies of a module.
     */
    List<ICMakeModule> getDependencies();

    /**
     * Return whether a module is effective.
     */
    boolean effective();

    /**
     * Sets a variable of a module.
     */
    void setVariable(ICMakeVariable variable);

    /**
     * Gets a variable of a module.
     */
    ICMakeVariable getVariable(String name);
}
