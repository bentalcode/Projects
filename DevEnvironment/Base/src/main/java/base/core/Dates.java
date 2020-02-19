package base.core;

import base.BaseException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Dates class implements complementary APIs for dates.
 */
public final class Dates {
    private static final Logger log = LoggerFactory.getLogger(Dates.class);

    /**
     * Parses a date from string.
     */
    public static Date parse(String value) {
        DateFormat formatter = new SimpleDateFormat();
        return Dates.parse(value, formatter);
    }

    /**
     * Parses a date from string with a formatter.
     */
    public static Date parse(String value, DateFormat formatter) {
        Conditions.validateNotNull(
            value,
            "The date.");

        Conditions.validateNotNull(
            formatter,
            "The formatter of a date.");

        Date result;

        try {
            result = formatter.parse(value);
        }
        catch (ParseException e) {
            String errorMessage =
                "Failed to parse a date: " + value +
                ", due to the following error: " + e.getMessage();

            log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return result;
    }

    /**
     * Converts a date to a string.
     */
    public static String toString(Date value) {
        DateFormat formatter = new SimpleDateFormat();
        return Dates.toString(value, formatter);
    }

    /**
     * Converts a date to a string with a formatter.
     */
    public static String toString(Date value, DateFormat formatter) {
        Conditions.validateNotNull(
            value,
            "The value of a date.");

        Conditions.validateNotNull(
            formatter,
            "The formatter of a date.");

        return formatter.format(value);
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Dates() {
    }
}
