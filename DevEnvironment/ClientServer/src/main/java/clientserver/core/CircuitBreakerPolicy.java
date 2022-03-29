package clientserver.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import clientserver.interfaces.ICircuitBreakerPolicy;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.time.Duration;

/**
 * The CircuitBreakerPolicy class implements a circuit breaker policy.
 */
public final class CircuitBreakerPolicy implements ICircuitBreakerPolicy {
    private static final int DEFAULT_FAILURE_THRESHOLD = 5;
    private static final Duration DEFAULT_FAILURE_THRESHOLD_TIMEOUT = Duration.ofSeconds(300);
    private static final int DEFAULT_SUCCESS_THRESHOLD = 3;
    private static final Duration DEFAULT_SUCCESS_THRESHOLD_TIMEOUT = Duration.ofSeconds(300);
    private static final Duration DEFAULT_RECOVERY_DURATION = Duration.ofSeconds(30);

    private static final String PROPERTY_FAILURE_THRESHOLD = "failureThreshold";
    private static final String PROPERTY_FAILURE_THRESHOLD_TIMEOUT = "failureThresholdTimeout";
    private static final String PROPERTY_SUCCESS_THRESHOLD = "successThreshold";
    private static final String PROPERTY_SUCCESS_THRESHOLD_TIMEOUT = "successThresholdTimeout";
    private static final String PROPERTY_RECOVERY_DURATION = "recoveryDuration";

    private final int failureThreshold;
    private final Duration failureThresholdTimeout;
    private final int successThreshold;
    private final Duration successThresholdTimeout;
    private final Duration recoveryDuration;
    private final IBinaryComparator<ICircuitBreakerPolicy> comparator = CircuitBreakerPolicy.defaultComparator();

    /**
     * Gets the default circuit breaker policy.
     */
    public static ICircuitBreakerPolicy defaultCircuitBreakerPolicy() {
        return new CircuitBreakerPolicy(
            DEFAULT_FAILURE_THRESHOLD,
            DEFAULT_FAILURE_THRESHOLD_TIMEOUT,
            DEFAULT_SUCCESS_THRESHOLD,
            DEFAULT_SUCCESS_THRESHOLD_TIMEOUT,
            DEFAULT_RECOVERY_DURATION);
    }

    /**
     * The CircuitBreakerPolicy constructor.
     */
    public CircuitBreakerPolicy(
        int failureThreshold,
        Duration failureThresholdTimeout,
        int successThreshold,
        Duration successThresholdTimeout,
        Duration recoveryDuration) {

        Conditions.validate(
            failureThreshold >= 1,
            "The failure threshold has to be larger than zero.");

        Conditions.validateNotNull(
            failureThresholdTimeout,
            "The failure threshold timeout.");

        Conditions.validate(
            successThreshold >= 1,
            "The success threshold has to be larger than zero.");

        Conditions.validateNotNull(
            successThresholdTimeout,
            "The success threshold timeout.");

        Conditions.validateNotNull(
            recoveryDuration,
            "The recovery duration.");

        this.failureThreshold = failureThreshold;
        this.failureThresholdTimeout = failureThresholdTimeout;

        this.successThreshold = successThreshold;
        this.successThresholdTimeout = successThresholdTimeout;

        this.recoveryDuration = recoveryDuration;
    }

    /**
     * Gets the failure threshold.
     *
     * The failure threshold that trips the circuit breaker from a Close State into an Open State.
     * This threshold is only reached when a specified number of failures have occurred during the
     * specified failure threshold timeout.
     */
    @Override
    public int getFailureThreshold() {
        return this.failureThreshold;
    }

    /**
     * Gets the failure threshold timeout.
     *
     * The timeout in which the failure threshold is effective.
     * After this timeout is expired, the current failure counter is reset automatically to zero.
     */
    @Override
    public Duration getFailureThresholdTimeout() {
        return this.failureThresholdTimeout;
    }

    /**
     * Gets the success threshold.
     *
     * The success threshold that move the circuit breaker from a Half-Open State into a Closed State.
     * Once this threshold is reached, the circuit breaker will get reset.
     * This threshold represents the last consecutive success attempts in the Half-Open State.
     */
    @Override
    public int getSuccessThreshold() {
        return this.successThreshold;
    }

    /**
     * Gets the success threshold timeout.
     *
     * The timeout in which the success threshold is effective.
     * After this timeout is expired, the current success counter is reset automatically to zero.
     */
    @Override
    public Duration getSuccessThresholdTimeout() {
        return this.successThresholdTimeout;
    }

    /**
     * Gets the recovery duration.
     * The duration in which the circuit breaker will spend in the Open State, which gives
     * the system a recovery time.
     * After the recovery duration is expired, the circuit breaker will move from the Open State to
     * the Half-Open State.
     */
    @Override
    public Duration getRecoveryDuration() {
        return this.recoveryDuration;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(ICircuitBreakerPolicy other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(ICircuitBreakerPolicy other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICircuitBreakerPolicy> defaultComparator() {
        return new CircuitBreakerPolicy.Comparator();
    }

    /**
     * The Comparator class implements a comparator of a retry policy.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICircuitBreakerPolicy> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICircuitBreakerPolicy obj) {
            return new HashCodeBuilder(61, 67)
                .withInteger(obj.getFailureThreshold())
                .withDuration(obj.getFailureThresholdTimeout())
                .withInteger(obj.getSuccessThreshold())
                .withDuration(obj.getSuccessThresholdTimeout())
                .withDuration(obj.getRecoveryDuration())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICircuitBreakerPolicy lhs, ICircuitBreakerPolicy rhs) {
            return new EqualBuilder()
                .withInteger(lhs.getFailureThreshold(), rhs.getFailureThreshold())
                .withDuration(lhs.getFailureThresholdTimeout(), rhs.getFailureThresholdTimeout())
                .withInteger(lhs.getSuccessThreshold(), rhs.getSuccessThreshold())
                .withDuration(lhs.getSuccessThresholdTimeout(), rhs.getSuccessThresholdTimeout())
                .withDuration(lhs.getRecoveryDuration(), rhs.getRecoveryDuration())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(ICircuitBreakerPolicy lhs, ICircuitBreakerPolicy rhs) {
            return new CompareToBuilder()
                .withInteger(lhs.getFailureThreshold(), rhs.getFailureThreshold())
                .withDuration(lhs.getFailureThresholdTimeout(), rhs.getFailureThresholdTimeout())
                .withInteger(lhs.getSuccessThreshold(), rhs.getSuccessThreshold())
                .withDuration(lhs.getSuccessThresholdTimeout(), rhs.getSuccessThresholdTimeout())
                .withDuration(lhs.getRecoveryDuration(), rhs.getRecoveryDuration())
                .build();
        }
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeIntegerProperty(CircuitBreakerPolicy.PROPERTY_FAILURE_THRESHOLD, this.getFailureThreshold());
        writer.writeDurationProperty(CircuitBreakerPolicy.PROPERTY_FAILURE_THRESHOLD_TIMEOUT, this.getFailureThresholdTimeout());
        writer.writeIntegerProperty(CircuitBreakerPolicy.PROPERTY_SUCCESS_THRESHOLD, this.getSuccessThreshold());
        writer.writeDurationProperty(CircuitBreakerPolicy.PROPERTY_SUCCESS_THRESHOLD_TIMEOUT, this.getSuccessThresholdTimeout());
        writer.writeDurationProperty(CircuitBreakerPolicy.PROPERTY_RECOVERY_DURATION, this.getRecoveryDuration());
    }

    /**
     * Reads an object from a json reader.
     */
    public static ICircuitBreakerPolicy readJson(IJsonObjectReader reader) {
        int failureThreshold = reader.readIntegerProperty(CircuitBreakerPolicy.PROPERTY_FAILURE_THRESHOLD);
        Duration failureThresholdTimeout = reader.readDurationProperty(CircuitBreakerPolicy.PROPERTY_FAILURE_THRESHOLD_TIMEOUT);
        int successThreshold = reader.readIntegerProperty(CircuitBreakerPolicy.PROPERTY_SUCCESS_THRESHOLD);
        Duration successThresholdTimeout = reader.readDurationProperty(CircuitBreakerPolicy.PROPERTY_SUCCESS_THRESHOLD_TIMEOUT);
        Duration recoveryDuration = reader.readDurationProperty(CircuitBreakerPolicy.PROPERTY_RECOVERY_DURATION);

        return new CircuitBreakerPolicy(
            failureThreshold,
            failureThresholdTimeout,
            successThreshold,
            successThresholdTimeout,
            recoveryDuration);
    }
}
