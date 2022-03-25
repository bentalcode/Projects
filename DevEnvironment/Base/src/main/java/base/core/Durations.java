package base.core;

import java.time.Duration;

/**
 * The Durations class implements complementary APIs for durations.
 */
public final class Durations {
    /**
     * Parses a duration from string.
     */
    public static Duration parse(String value) {
        Conditions.validateNotNull(
            value,
            "The duration.");

        return Duration.parse(value);
    }

    /**
     * Parses a duration from string with a formatter.
     */
    public static Duration parse(String value, String formatter) {
        Conditions.validateNotNull(
            value,
            "The duration.");

        Conditions.validateNotNull(
            formatter,
            "The formatter of a duration.");

        throw new UnsupportedOperationException();
    }

    /**
     * Converts a duration to a string.
     */
    public static String toString(Duration value) {
        Conditions.validateNotNull(
            value,
            "The value of a duration.");

        return value.toString();
    }

    /**
     * Converts a duration to a string with a formatter.
     */
    public static String toString(Duration value, String formatter) {
        Conditions.validateNotNull(
            value,
            "The value of a duration.");

        Conditions.validateNotNull(
            formatter,
            "The formatter of a duration.");

        throw new UnsupportedOperationException();
    }

    /**
     * Checks whether the left hand side duration is less than the right hand side duration.
     */
    public static boolean isShorter(Duration left, Duration right) {
        int compareStatus = Durations.compareTo(left, right);
        return compareStatus == -1;
    }

    /**
     * Checks whether the left hand side duration is less or equal than the right hand side duration.
     */
    public static boolean isShorterOrEqual(Duration left, Duration right) {
        int compareStatus = Durations.compareTo(left, right);
        return compareStatus <= 0;
    }

    /**
     * Checks whether the left hand side duration is longer than the right hand side duration.
     */
    public static boolean isLonger(Duration left, Duration right) {
        int compareStatus = Durations.compareTo(left, right);
        return compareStatus == 1;
    }

    /**
     * Checks whether the left hand side duration is longer or equal than the right hand side duration.
     */
    public static boolean isLongerOrEqual(Duration left, Duration right) {
        int compareStatus = Durations.compareTo(left, right);
        return compareStatus >= 0;
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    public static int compareTo(Duration left, Duration right) {
        if (left == null && right == null) {
            return 0;
        }

        if (left == null) {
            return -1;
        }

        if (right == null) {
            return 1;
        }

        return left.compareTo(right);
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Durations() {
    }
}
