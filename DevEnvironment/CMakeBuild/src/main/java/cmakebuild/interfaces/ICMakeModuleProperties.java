package cmakebuild.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The ICMakeModuleProperties interface defines properties of a CMakeLists module.
 */
public interface ICMakeModuleProperties extends IUnaryComparator<ICMakeModuleProperties>, IJsonSerialization {
    /**
     * Gets the path of the module.
     */
    String getPath();

    /**
     * Gets the target path of the CMakeLists file.
     */
    String getCMakeListsTargetPath();

    /**
     * Gets the extensions of a header files.
     */
    List<String> getHeaderFileExtensions();

    /**
     * Gets the extensions of a source file.
     */
    List<String> getSourceFileExtensions();

    /**
     * Gets the extensions of a CMakeLists file.
     */
    List<String> getCMakeListsFileExtensions();
}
