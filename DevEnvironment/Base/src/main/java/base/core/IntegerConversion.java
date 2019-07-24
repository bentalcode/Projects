package base.core;

import base.interfaces.IIntegerConversion;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The IntegerConversion class implements conversions for an integer.
 */
public final class IntegerConversion implements IIntegerConversion {
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The IntegerConversion constructor.
     */
    public IntegerConversion() {
    }

    /**
     * Converts an integer to a byte.
     */
    @Override
    public byte toByte(int value) {
        if (value > Byte.MAX_VALUE || value < Byte.MIN_VALUE) {
            String errorMessage =
                "Failed to convert an integer: " + value + " to a byte." +
                "The input integer is out of range.";

            log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return (byte)value;
    }

    /**
     * Converts an integer to a short.
     */
    @Override
    public short toShort(int value) {
        if (value > Short.MAX_VALUE || value < Short.MIN_VALUE) {
            String errorMessage =
                "Failed to convert an integer: " + value + " to a short." +
                "The input integer is out of range.";

            log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return (short)value;
    }

    /**
     * Parses an integer.
     */
    @Override
    public int parse(String value) {
        int result;

        try {
            result = Integer.parseInt(value.trim());
        } catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string to an integer due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Tries to parse an integer.
     */
    @Override
    public Integer tryParse(String value) {
        Integer result = null;

        try {
            result = Integer.parseInt(value);
        } catch (NumberFormatException e) {
        }

        return result;
    }
}
