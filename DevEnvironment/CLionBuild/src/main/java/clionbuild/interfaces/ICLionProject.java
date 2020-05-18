package clionbuild.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.nio.file.Path;
import java.util.List;

/**
 * The ICLionProject interface defines a CLion project.
 */
public interface ICLionProject extends IUnaryComparator<ICLionProject>, IJsonSerialization {
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
    List<ICLionModule> getModules();
}
