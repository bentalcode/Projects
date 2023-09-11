package cmakebuildsystem.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The IIgnoreRules interface defines an ignore rules section.
 */
public interface IIgnoreRules extends IUnaryComparator<IIgnoreRules>, IJsonSerialization {
    /**
     * Gets the path patterns.
     */
    List<String> getPathPatterns();
}
