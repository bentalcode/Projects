package cmakebuildsystem.core;

import java.util.Map;

/**
 * The ICMakeBuildContextData interface defines context data of a cmake build.
 */
public interface ICMakeBuildContextData {
    /**
     * Gets the context data of a module.
     */
    ICMakeModuleContextData getModuleContextData(String name);

    /**
     * Sets generic data of a build.
     */
    void setData(String name, String data);

    /**
     * Gets generic data of a build.
     */
    Map<String, String> getData();
}
