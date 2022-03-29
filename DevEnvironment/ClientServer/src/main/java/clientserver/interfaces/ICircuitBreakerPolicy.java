package clientserver.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.time.Duration;

/**
 * The ICircuitBreakerPolicy interface defines a Circuit Breaker Policy.
 */
public interface ICircuitBreakerPolicy extends
    IUnaryComparator<ICircuitBreakerPolicy>,
    IJsonSerialization {

    /**
     * Gets the failure threshold.
     *
     * The failure threshold that trips the circuit breaker from a Close State into an Open State.
     * This threshold is only reached when a specified number of failures have occurred during the
     * specified failure threshold timout.
     */
    int getFailureThreshold();

    /**
     * Gets the failure threshold timeout.
     *
     * The timeout in which the failure threshold is effective.
     * After this timeout is expired, the current failure counter is reset automatically to zero.
     */
    Duration getFailureThresholdTimeout();

    /**
     * Gets the success threshold.
     *
     * The success threshold that move the circuit breaker from a Half-Open State into a Closed State.
     * Once this threshold is reached, the circuit breaker will get reset.
     * This threshold represents the last consecutive success attempts in the Half-Open State.
     */
    int getSuccessThreshold();

    /**
     * Gets the success threshold timeout.
     *
     * The timeout in which the success threshold is effective.
     * After this timeout is expired, the current success counter is reset automatically to zero.
     */
    Duration getSuccessThresholdTimeout();

    /**
     * Gets the recovery duration.
     * The duration in which the circuit breaker will spend in the Open State, which gives
     * the system a recovery time.
     * After the recovery duration is expired, the circuit breaker will move from the Open State to
     * the Half-Open State.
     */
    Duration getRecoveryDuration();
}
