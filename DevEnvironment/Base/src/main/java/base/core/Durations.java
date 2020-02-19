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
     * Disables the default constructor - This is a static class.
     */
    private Durations() {
    }
}
