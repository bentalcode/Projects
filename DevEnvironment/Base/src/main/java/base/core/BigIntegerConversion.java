package base.core;

import base.BaseException;
import base.interfaces.IBigIntegerConversion;
import java.math.BigInteger;

/**
 * The BigIntegerConversion class implements conversions for a big integer.
 */
public final class BigIntegerConversion implements IBigIntegerConversion {
    /**
     * The BigIntegerConversion constructor.
     */
    public BigIntegerConversion() {
    }

    /**
     * Converts a big integer to a byte.
     */
    @Override
    public byte toByte(BigInteger value) {
        byte result;

        try {
            result = value.byteValueExact();
        }
        catch (ArithmeticException e) {
            String errorMessage =
                "Failed to convert a big integer: " + value + " to a byte." +
                " The input big integer is over a byte range.";

            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a big integer to a short.
     */
    @Override
    public short toShort(BigInteger value) {
        short result;

        try {
            result = value.shortValueExact();
        }
        catch (ArithmeticException e) {
            String errorMessage =
                "Failed to convert a big integer: " + value + " to a short." +
                " The input big integer is over a short range.";

            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a big integer to an integer.
     */
    @Override
    public int toInteger(BigInteger value) {
        int result;

        try {
            result = value.intValueExact();
        }
        catch (ArithmeticException e) {
            String errorMessage =
                "Failed to convert a big integer: " + value + " to an integer." +
                " The input big integer is over an integer range.";

            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Converts a big integer to a long.
     */
    @Override
    public long toLong(BigInteger value) {
        long result;

        try {
            result = value.longValueExact();
        }
        catch (ArithmeticException e) {
            String errorMessage =
                "Failed to convert a big integer: " + value + " to a long." +
                " The input big integer is over a long range.";

            throw new BaseException(errorMessage, e);
        }

        return result;
    }
}
