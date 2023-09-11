package base.core;

import java.text.DateFormat;
import java.text.SimpleDateFormat;

/**
 * The TimeConstants class implements constants for times.
 */
public final class TimeConstants {
    private static final String DATE_PATTERN = "yyyy-mm-dd hh:mm:ss";
    private static final String DURATION_PATTERN = "hh:mm:ss.SSS";

    /**
     * Get the default date-time formatter.
     */
    public static DateFormat defaultDateTimeFormatter() {
        return new SimpleDateFormat(TimeConstants.DATE_PATTERN);
    }

    /**
     * Get the default duration formatter.
     */
    public static String defaultDurationFormatter() {
        return TimeConstants.DURATION_PATTERN;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private TimeConstants() {
    }
}
