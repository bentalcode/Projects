package clientserver.interfaces;

import base.interfaces.IRunnable;
import json.interfaces.IJsonSerialization;

import java.util.Set;

/**
 * The IRetryLogic interface defines a generic retry logic.
 */
public interface IRetryLogic extends IRunnable, IJsonSerialization {
    /**
     * Gets the name of the logic.
     */
    String name();

    /**
     * Gets the set of the absorbed exception types.
     */
    Set<Class<?>> getAbsorbedExceptions();
}
