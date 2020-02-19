package base.core;

import java.text.DateFormat;
import java.text.SimpleDateFormat;

/**
 * The TimeConstants class implements constants for times.
 */
public final class TimeConstants {
    private static final String dateDefaultPattern = "yyyy-mm-dd hh:mm:ss";
    private static final String durationDefaultPattern = "hh:mm:ss.SSS";

    /**
     * Get the default date-time formatter.
     */
    public static DateFormat defaultDateTimeFormatter() {
        return new SimpleDateFormat(TimeConstants.dateDefaultPattern);
    }

    /**
     * Get the default duration formatter.
     */
    public static String defaultDurationFormatter() {
        return TimeConstants.durationDefaultPattern;
    }

    /**
     * The TimeConstants constructor - Disables the default constructor.
     */
    private TimeConstants() {
    }
}
