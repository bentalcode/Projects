package clientserver.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import clientserver.interfaces.IRetryPolicy;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.time.Duration;

/**
 * The RetryPolicy class implements a retry policy.
 */
public final class RetryPolicy implements IRetryPolicy {
    private static final int DEFAULT_NUMBER_OF_INTERVALS = 5;
    private static final Duration DEFAULT_INTERVAL_DURATION = Duration.ofMillis(1500);
    private static final String PROPERTY_NUMBER_OF_ATTEMPTS = "numberOfAttempts";
    private static final String PROPERTY_INTERVAL_DURATION = "intervalDuration";

    private final int numberOfAttempts;
    private final Duration intervalDuration;
    private final IBinaryComparator<IRetryPolicy> comparator = RetryPolicy.defaultComparator();

    /**
     * Gets the default retry policy.
     */
    public static IRetryPolicy defaultRetryPolicy() {
        return new RetryPolicy(DEFAULT_NUMBER_OF_INTERVALS, DEFAULT_INTERVAL_DURATION);
    }

    /**
     * The RetryPolicy constructor.
     */
    public RetryPolicy(
        int numberOfAttempts,
        Duration intervalDuration) {

        Conditions.validate(
            numberOfAttempts >= 1,
            "The number of attempts has to be larger than one.");

        Conditions.validateNotNull(
            intervalDuration,
            "The interval duration.");

        this.numberOfAttempts = numberOfAttempts;
        this.intervalDuration = intervalDuration;
    }

    /**
     * Gets the number of attempts.
     */
    @Override
    public int getNumberOfAttempts() {
        return this.numberOfAttempts;
    }

    /**
     * Gets the interval duration.
     */
    @Override
    public Duration getIntervalDuration() {
        return this.intervalDuration;
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
    public boolean isEqual(IRetryPolicy other) {
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
    public int compareTo(IRetryPolicy other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IRetryPolicy> defaultComparator() {
        return new RetryPolicy.Comparator();
    }

    /**
     * The Comparator class implements a comparator of a retry policy.
     */
    public static final class Comparator extends AbstractBinaryComparator<IRetryPolicy> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IRetryPolicy obj) {
            return new HashCodeBuilder(89, 97)
                .withInteger(obj.getNumberOfAttempts())
                .withDuration(obj.getIntervalDuration())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IRetryPolicy lhs, IRetryPolicy rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withInteger(lhs.getNumberOfAttempts(), rhs.getNumberOfAttempts())
                .withDuration(lhs.getIntervalDuration(), rhs.getIntervalDuration())
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
        public int compareTo(IRetryPolicy lhs, IRetryPolicy rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withInteger(lhs.getNumberOfAttempts(), rhs.getNumberOfAttempts())
                .withDuration(lhs.getIntervalDuration(), rhs.getIntervalDuration())
                .build();
        }
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeIntegerProperty(RetryPolicy.PROPERTY_NUMBER_OF_ATTEMPTS, this.getNumberOfAttempts());
        writer.writeDurationProperty(RetryPolicy.PROPERTY_INTERVAL_DURATION, this.getIntervalDuration());
    }

    /**
     * Reads an object from a json reader.
     */
    public static IRetryPolicy readJson(IJsonObjectReader reader) {
        int numberOfAttempts = reader.readIntegerProperty(RetryPolicy.PROPERTY_NUMBER_OF_ATTEMPTS);
        Duration intervalDuration = reader.readDurationProperty(RetryPolicy.PROPERTY_INTERVAL_DURATION);

        return new RetryPolicy(
            numberOfAttempts,
            intervalDuration);
    }
}
