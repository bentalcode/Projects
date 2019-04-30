package base.interfaces;

/**
 * The ILongConversion interface defines conversions for a long.
 */
public interface ILongConversion {
    /**
     * Converts a long to a byte.
     */
    byte toByte(long value);

    /**
     * Converts a long to a short.
     */
    short toShort(long value);

    /**
     * Converts a long to an integer.
     */
    int toInteger(long value);
}
