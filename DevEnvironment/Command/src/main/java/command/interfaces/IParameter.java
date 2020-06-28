package command.interfaces;

import base.core.IFromString;
import java.math.BigInteger;
import java.time.Duration;
import java.util.Date;

/**
 * The IParameter interface defines a parameter.
 */
public interface IParameter {
    /**
     * Gets a metadata of a parameter.
     */
    IParameterMetadata getMetadata();

    /**
     * Gets a boolean value of a parameter.
     */
    boolean getBooleanValue();

    /**
     * Gets a byte value of a parameter.
     */
    byte getByteValue();

    /**
     * Gets a short value of a parameter.
     */
    short getShortValue();

    /**
     * Gets an integer value of a parameter.
     */
    int getIntegerValue();

    /**
     * Gets a long value of a parameter.
     */
    long getLongValue();

    /**
     * Gets a float value of a parameter.
     */
    float getFloatValue();

    /**
     * Gets a double value of a parameter.
     */
    double getDoubleValue();

    /**
     * Gets a character value of a parameter.
     */
    char getCharacterValue();

    /**
     * Gets a string value of a parameter.
     */
    String getStringValue();

    /**
     * Gets an enum value of a parameter.
     */
    <T extends Enum<T>> T getEnumValue(IFromString<T> transformer);

    /**
     * Gets a big integer value of a parameter.
     */
    BigInteger getBigIntegerValue(int radix);

    /**
     * Gets a date value of a parameter.
     */
    Date getDateValue();

    /**
     * Gets a duration value of a parameter.
     */
    Duration getDurationValue();
}
