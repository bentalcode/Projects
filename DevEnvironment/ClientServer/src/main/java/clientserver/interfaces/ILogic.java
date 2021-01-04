package clientserver.interfaces;

import json.interfaces.IJsonSerialization;

/**
 * The ILogic interface defines a generic logic.
 */
public interface ILogic extends base.interfaces.ILogic, IJsonSerialization {
    /**
     * Gets the name of the logic.
     */
    String name();
}
