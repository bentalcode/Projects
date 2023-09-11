package base.interfaces;

/**
 * The IDoubleConversion interface defines conversions for a double.
 */
public interface IDoubleConversion {
    /**
     * Converts a double to a float.
     */
    float toFloat(double value);

    /**
     * Parses a double.
     */
    double parse(String value);

    /**
     * Tries to parse a double.
     */
    Double tryParse(String value);
}
