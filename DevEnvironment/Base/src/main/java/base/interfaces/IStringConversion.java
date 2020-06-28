package base.interfaces;

import java.math.BigInteger;
import java.time.Duration;
import java.util.Date;

/**
 * The IStringConversion interface defines conversions for a string.
 */
public interface IStringConversion {
    /**
     * Converts a string to a boolean.
     */
    boolean toBoolean(String value);

    /**
     * Converts a string to a byte.
     */
    byte toByte(String value);

    /**
     * Converts a string to a short.
     */
    short toShort(String value);

    /**
     * Converts a string to an integer.
     */
    int toInteger(String value);

    /**
     * Converts a string to a long.
     */
    long toLong(String value);

    /**
     * Converts a string to a float.
     */
    float toFloat(String value);

    /**
     * Converts a string to a double.
     */
    double toDouble(String value);

    /**
     * Converts a string to a character.
     */
    char toCharacter(String value);

    /**
     * Converts a string to a big integer.
     */
    BigInteger toBigInteger(String value, int radix);

    /**
     * Converts a string to a date.
     */
    Date toDate(String value);

    /**
     * Converts a string to a duration.
     */
    Duration toDuration(String value);

    /**
     * Converts a string to a string array.
     */
    String[] toArray(String value);

    /**
     * Converts a string to a string array.
     */
    String[] toArray(String value, String separator);

    /**
     * Converts a string to bytes.
     */
    byte[] toBytes(String value);
}
