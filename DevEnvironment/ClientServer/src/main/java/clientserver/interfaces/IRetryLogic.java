package clientserver.interfaces;

import java.util.Set;

/**
 * The IRetryLogic interface defines a generic retry logic.
 */
public interface IRetryLogic extends ILogic {
    /**
     * Gets the set of the absorbed exception types.
     */
    Set<Class<?>> getAbsorbedExceptions();
}
