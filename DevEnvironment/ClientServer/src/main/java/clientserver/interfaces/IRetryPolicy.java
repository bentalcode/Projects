package clientserver.interfaces;

import json.interfaces.IJsonSerialization;
import org.joda.time.Duration;

/**
 * The IRetryPolicy interface defines a retry policy.
 */
public interface IRetryPolicy extends IJsonSerialization {
    /**
     * Gets the number of attempts.
     */
    int getNumberOfAttempts();

    /**
     * Gets the interval duration.
     */
    Duration getIntervalDuration();
}
