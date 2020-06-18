package cmakebuildsystem.core;

import cmakebuildsystem.interfaces.ICMakeModule;
import java.util.List;
import java.util.Map;

/**
 * The ICMakeModuleDependencyManager interface defines a dependency manager for cmake modules.
 */
public interface ICMakeModuleDependencyManager {
    /**
     * Resolves the modules dependencies.
     */
    Map<String, List<ICMakeModule>> resolveModulesDependencies();
}
