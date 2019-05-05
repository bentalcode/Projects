package base.core;

import base.interfaces.IIntegerConversion;

/**
 * The IntegerConversion class implements conversions for an integer.
 */
public final class IntegerConversion implements IIntegerConversion {
    /**
     * The IntegerConversion constructor.
     */
    public IntegerConversion() {
    }

    /**
     * Converts an integer to a byte.
     */
    public byte toByte(int value) {
        if (value > Byte.MAX_VALUE || value < Byte.MIN_VALUE) {
            String errorMessage =
                "Failed to convert an integer: " + value + " to a byte." +
                "The input integer is out of range.";

            throw new BaseException(errorMessage);
        }

        return (byte)value;
    }

    /**
     * Converts an integer to a short.
     */
    public short toShort(int value) {
        if (value > Short.MAX_VALUE || value < Short.MIN_VALUE) {
            String errorMessage =
                "Failed to convert an integer: " + value + " to a short." +
                "The input integer is out of range.";

            throw new BaseException(errorMessage);
        }

        return (short)value;
    }
}
