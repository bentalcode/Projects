package clientserver.interfaces;

import base.interfaces.IRunnable;
import json.interfaces.IJsonSerialization;

/**
 * The ILogic interface defines a generic logic.
 */
public interface ILogic extends IRunnable, IJsonSerialization {
    /**
     * Gets the name of the logic.
     */
    String name();
}
