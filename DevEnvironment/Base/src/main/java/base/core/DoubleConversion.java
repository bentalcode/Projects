package base.core;

import base.interfaces.IDoubleConversion;

/**
 * The DoubleConversion class implements conversions for a double.
 */
public final class DoubleConversion implements IDoubleConversion {
    /**
     * The LongConversion constructor.
     */
    public DoubleConversion() {
    }

    /**
     * Converts a double to a float.
     */
    public float toFloat(double value) {
        if (value > Float.MAX_VALUE) {
            String errorMessage =
                "Failed to convert a double: " + value + " to a float." +
                "The input double is out of range.";

            throw new BaseException(errorMessage);
        }

        return (float)value;
    }
}
