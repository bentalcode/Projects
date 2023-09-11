package base.core;

import base.BaseException;
import base.interfaces.IDoubleConversion;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The DoubleConversion class implements conversions for a double.
 */
public final class DoubleConversion implements IDoubleConversion {
    private final Logger log = LoggerFactory.getLogger(this.getClass());

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
                "The input double is over of the range of a float.";

            this.log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return (float)value;
    }

    /**
     * Parses an integer.
     */
    @Override
    public double parse(String value) {
        double result;

        try {
            result = Double.parseDouble(value);
        } catch (NumberFormatException e) {
            String errorMessage =
                "Failed to convert a string to a double due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Tries to parse an integer.
     */
    @Override
    public Double tryParse(String value) {
        Double result = null;

        try {
            result = Double.parseDouble(value);
        } catch (NumberFormatException e) {
            String warningMessage =
                "Failed to convert a string to a double due to the following error: " + e.getMessage();

            this.log.warn(warningMessage, e);
        }

        return result;
    }
}
