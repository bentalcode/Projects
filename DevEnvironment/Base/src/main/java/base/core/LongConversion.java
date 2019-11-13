package base.core;

import base.BaseException;
import base.interfaces.ILongConversion;

/**
 * The LongConversion class implements conversions for a long.
 */
public final class LongConversion implements ILongConversion {
    /**
     * The LongConversion constructor.
     */
    public LongConversion() {
    }

    /**
     * Converts a long to a byte.
     */
    public byte toByte(long value) {
        if (value > Byte.MAX_VALUE || value < Short.MIN_VALUE) {
            String errorMessage =
                "Failed to convert a long: " + value + " to a byte." +
                " The input long is over of the range of a byte.";

            throw new BaseException(errorMessage);
        }

        return (byte)value;
    }

    /**
     * Converts a long to a short.
     */
    public short toShort(long value) {
        if (value > Short.MAX_VALUE || value < Short.MIN_VALUE) {
            String errorMessage =
                "Failed to convert a long: " + value + " to a short." +
                " The input long is over the range of a short.";

            throw new BaseException(errorMessage);
        }

        return (short)value;
    }

    /**
     * Converts a long to an integer.
     */
    public int toInteger(long value) {
        if (value > Integer.MAX_VALUE || value < Integer.MIN_VALUE) {
            String errorMessage =
                "Failed to convert a long: " + value + " to an integer." +
                " The input long is over the range of an integer.";

            throw new BaseException(errorMessage);
        }

        return (int)value;
    }
}
