package cmakebuildsystem.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.nio.file.Path;
import java.util.List;

/**
 * The ICMakeProject interface defines a CMake project.
 */
public interface ICMakeProject extends IUnaryComparator<ICMakeProject>, IJsonSerialization {
    /**
     * Gets the name of the project.
     */
    String getName();

    /**
     * Gets the path of the root of the project.
     */
    Path getRootPath();

    /**
     * Gets the list of the modules.
     */
    List<ICMakeModule> getModules();
}
