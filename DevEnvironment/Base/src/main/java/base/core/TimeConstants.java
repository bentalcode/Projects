package base.core;

import org.joda.time.format.DateTimeFormatter;
import org.joda.time.format.DateTimeFormatterBuilder;
import org.joda.time.format.PeriodFormatter;
import org.joda.time.format.PeriodFormatterBuilder;

/**
 * The TimeConstants class implements constants for time.
 */
public final class TimeConstants {
    private static final String DateTimeDefaultPattern = "MM/dd/yyyy HH:mm:ss.SSS";
    private static String DurationDefaultPattern = "HH:mm:ss.SSS";

    /**
     * Get the default date-time formatter.
     */
    public static DateTimeFormatter defaultDateTimeFormatter() {
        DateTimeFormatter formatter = new DateTimeFormatterBuilder()
            .appendPattern(TimeConstants.DateTimeDefaultPattern)
            .toFormatter();

        return formatter;
    }

    /**
     * Gets the default duration formatter.
     */
    public static PeriodFormatter defaultDurationFormatter() {
        PeriodFormatter formatter = new PeriodFormatterBuilder()
            .appendHours()
            .appendSuffix(":")
            .appendMinutes()
            .appendSuffix(":")
            .appendSeconds()
            .appendSuffix(".")
            .appendMillis()
            .toFormatter();

        return formatter;
    }
}
