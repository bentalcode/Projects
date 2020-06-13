package cmakebuild.core;

import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeModuleManifest;
import java.util.List;
import java.util.Map;

/**
 * The ICMakeProjectDeploymentData interface defines runtime data of a project deployment.
 */
public interface ICMakeProjectDeploymentData {
    /**
     * Gets the module by name.
     */
    ICMakeModule getModule(String name);

    /**
     * Gets the manifest of a module by name.
     */
    ICMakeModuleManifest getModuleManifest(String name);

    /**
     * Gets the dependencies of a module by name.
     */
    List<ICMakeModule> getModuleDependencies(String name);

    /**
     * Return whether the module is effective.
     */
    boolean moduleEffective(String name);

    /**
     * Gets the data of the deployment.
     */
    Map<String, String> getData();

    /**
     * Sets the data of a module.
     */
    void setModuleData(String name, String data);
}
