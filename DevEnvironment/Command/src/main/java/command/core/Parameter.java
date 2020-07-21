package command.core;

import base.core.Conditions;
import base.core.Conversion;
import base.core.IFromString;
import command.interfaces.IParameter;
import command.interfaces.IParameterMetadata;
import java.math.BigInteger;
import java.time.Duration;
import java.util.Date;

/**
 * The Parameter class implements a parameter.
 */
public final class Parameter implements IParameter {
    private final IParameterMetadata metaData;
    private final String value;

    /**
     * Creates a help parameter.
     */
    public static IParameter createHelpParameter() {
        return new Parameter(ParameterMetadata.createHelpParameter(), null);
    }

    /**
     * The Parameter constructor.
     */
    public Parameter(
        IParameterMetadata metaData,
        String value) {

        Conditions.validateNotNull(
            metaData,
            "The metaData of a parameter.");

        this.metaData = metaData;
        this.value = value;
    }

    /**
     * Gets a metadata of a parameter.
     */
    @Override
    public IParameterMetadata getMetadata() {
        return this.metaData;
    }

    /**
     * Checks whether the value of the parameter is set.
     */
    @Override
    public boolean isSet() {
        return this.value != null;
    }

    /**
     * Gets a boolean value of a parameter.
     */
    @Override
    public boolean getBooleanValue() {
        return Conversion.stringConversion().toBoolean(this.value);
    }

    /**
     * Gets a byte value of a parameter.
     */
    @Override
    public byte getByteValue() {
        return Conversion.stringConversion().toByte(this.value);
    }

    /**
     * Gets a short value of a parameter.
     */
    @Override
    public short getShortValue() {
        return Conversion.stringConversion().toShort(this.value);
    }

    /**
     * Gets an integer value of a parameter.
     */
    @Override
    public int getIntegerValue() {
        return Conversion.stringConversion().toInteger(this.value);
    }

    /**
     * Gets a long value of a parameter.
     */
    @Override
    public long getLongValue() {
        return Conversion.stringConversion().toLong(this.value);
    }

    /**
     * Gets a float value of a parameter.
     */
    @Override
    public float getFloatValue() {
        return Conversion.stringConversion().toFloat(this.value);
    }

    /**
     * Gets a double value of a parameter.
     */
    @Override
    public double getDoubleValue() {
        return Conversion.stringConversion().toDouble(this.value);
    }

    /**
     * Gets a character value of a parameter.
     */
    @Override
    public char getCharacterValue() {
        return Conversion.stringConversion().toCharacter(this.value);
    }

    /**
     * Gets a string value of a parameter.
     */
    @Override
    public String getStringValue() {
        return this.value;
    }

    /**
     * Gets an enum value of a parameter.
     */
    @Override
    public <T extends Enum<T>> T getEnumValue(IFromString<T> transformer) {
        return transformer.fromString(this.value);
    }

    /**
     * Gets a big integer value of a parameter.
     */
    @Override
    public BigInteger getBigIntegerValue(int radix) {
        return Conversion.stringConversion().toBigInteger(this.value, radix);
    }

    /**
     * Gets a date value of a parameter.
     */
    @Override
    public Date getDateValue() {
        return Conversion.stringConversion().toDate(this.value);
    }

    /**
     * Gets a duration value of a parameter.
     */
    @Override
    public Duration getDurationValue() {
        return Conversion.stringConversion().toDuration(this.value);
    }

    /**
     * Gets a string array value of a parameter.
     */
    @Override
    public String[] getStringArrayValue() {
        String value = this.value;

        if (value == null) {
            return null;
        }

        return value.split(",");
    }
}
