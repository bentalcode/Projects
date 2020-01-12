package clientserver.core;

import base.core.Casting;
import base.core.Conditions;
import base.core.EqualBuilder;
import clientserver.interfaces.IRetryPolicy;
import json.core.JsonStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import org.joda.time.Duration;

/**
 * The RetryPolicy class implements a retry policy.
 */
public final class RetryPolicy implements IRetryPolicy {
    private static final int DefaultNumberOfIntervals = 5;
    private static final Duration DefaultIntervalDuration = Duration.standardSeconds(3);

    private static final String PropertyNumberOfAttempts = "numberOfAttempts";
    private static final String PropertyIntervalDuration = "intervalDuration";

    private final int numberOfAttempts;
    private final Duration intervalDuration;

    /**
     * The RetryPolicy constructor.
     */
    public static IRetryPolicy defaultRetryPolicy() {
        return new RetryPolicy(DefaultNumberOfIntervals, DefaultIntervalDuration);
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
    public String toString() {
        return JsonStream.serialize(this);
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
    public boolean isEqual(IRetryPolicy other) {
        return new EqualBuilder()
            .withInteger(this.getNumberOfAttempts(), other.getNumberOfAttempts())
            .withDuration(this.getIntervalDuration(), other.getIntervalDuration())
            .build();
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeIntegerProperty(RetryPolicy.PropertyNumberOfAttempts, this.numberOfAttempts);
        writer.writeDurationProperty(RetryPolicy.PropertyIntervalDuration, this.intervalDuration);
    }

    /**
     * Reads a json.
     */
    public static IRetryPolicy readJson(IJsonObjectReader reader) {
        int numberOfAttempts = reader.readIntegerProperty(RetryPolicy.PropertyNumberOfAttempts);
        Duration intervalDuration = reader.readDurationProperty(RetryPolicy.PropertyIntervalDuration);

        return new RetryPolicy(
            numberOfAttempts,
            intervalDuration);
    }
}
