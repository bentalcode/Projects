package base.interfaces;

import java.math.BigInteger;

/**
 * The IBigIntegerConversion interface defines conversions for a big integer.
 */
public interface IBigIntegerConversion {
    /**
     * Converts a big integer to a byte.
     */
    byte toByte(BigInteger value);

    /**
     * Converts a big integer to a short.
     */
    short toShort(BigInteger value);

    /**
     * Converts a big integer to an integer.
     */
    int toInteger(BigInteger value);

    /**
     * Converts a big integer to an long.
     */
    long toLong(BigInteger value);
}
