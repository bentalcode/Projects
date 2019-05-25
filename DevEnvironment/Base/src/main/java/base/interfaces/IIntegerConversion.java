package base.interfaces;

/**
 * The IIntegerConversion interface defines conversions for an integer.
 */
public interface IIntegerConversion {
    /**
     * Converts an integer to a byte.
     */
    byte toByte(int value);

    /**
     * Converts an integer to a short.
     */
    short toShort(int value);

    /**
     * Parses an integer.
     */
    int parse(String value);

    /**
     * Tries to parse an integer.
     */
    Integer tryParse(String value);
}
