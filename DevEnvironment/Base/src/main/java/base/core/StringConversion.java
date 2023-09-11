package base.core;

import base.BaseException;
import base.interfaces.IStringConversion;
import java.math.BigInteger;
import java.time.Duration;
import java.util.Date;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The StringConversion class implements conversions for a string.
 */
public final class StringConversion implements IStringConversion {
    private static final String SEPARATOR = ",";

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The StringConversion constructor.
     */
    public StringConversion() {
    }

    /**
     * Converts a string to a boolean.
     */
    @Override
    public boolean toBoolean(String value) {
        boolean result;

        try {
            result = Boolean.parseBoolean(value);
        }
        catch (IllegalArgumentException | NullPointerException e) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a boolean" +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a string to a byte.
     */
    @Override
    public byte toByte(String value) {
        byte result;

        try {
            result = Byte.parseByte(value);
        }
        catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a byte" +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a string to a short.
     */
    @Override
    public short toShort(String value) {
        short result;

        try {
            result = Short.parseShort(value);
        }
        catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a short" +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a string to an integer.
     */
    @Override
    public int toInteger(String value) {
        int result;

        try {
            result = Integer.parseInt(value);
        }
        catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string: " + value + " to an integer" +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a string to a long.
     */
    @Override
    public long toLong(String value) {
        long result;

        try {
            result = Long.parseLong(value);
        }
        catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a long" +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a string to a float.
     */
    @Override
    public float toFloat(String value) {
        float result;

        try {
            result = Float.parseFloat(value);
        }
        catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a float" +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a string to a double.
     */
    @Override
    public double toDouble(String value) {
        double result;

        try {
            result = Double.parseDouble(value);
        }
        catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a double" +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a string to a character.
     */
    @Override
    public char toCharacter(String value) {
        if (value == null || value.length() != 1) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a character." +
                " The input string is not a single character long.";

            this.log.error(value);
            throw new BaseException(errorMessage);
        }

        return value.charAt(0);
    }

    /**
     * Converts a string to a big integer.
     */
    @Override
    public BigInteger toBigInteger(String value, int radix) {
        BigInteger result;

        try {
            result = new BigInteger(value, radix);
        }
        catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a big integer" +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a string to a date.
     */
    @Override
    public Date toDate(String value) {
        return Dates.parse(value);
    }

    /**
     * Converts a string to a duration.
     */
    @Override
    public Duration toDuration(String value) {
        return Durations.parse(value);
    }

    /**
     * Converts a string to a string array.
     */
    @Override
    public String[] toArray(String value) {
        return this.toArray(value, StringConversion.SEPARATOR);
    }

    /**
     * Converts a string to a string array.
     */
    @Override
    public String[] toArray(String value, String separator) {
        Conditions.validateNotNull(
            value,
            "The array value.");

        String array = value.trim();
        return array.split(separator);
    }

    /**
     * Converts a string to bytes.
     */
    @Override
    public byte[] toBytes(String value) {
        return Bytes.fromString(value);
    }
}
