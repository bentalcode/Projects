package clientserver.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.time.Duration;

/**
 * The IRetryPolicy interface defines a retry policy.
 */
public interface IRetryPolicy extends
    IUnaryComparator<IRetryPolicy>,
    IJsonSerialization {

    /**
     * Gets the number of attempts.
     */
    int getNumberOfAttempts();

    /**
     * Gets the interval duration.
     */
    Duration getIntervalDuration();
}
