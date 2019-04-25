package base.interfaces;

import java.util.Collection;

/**
 * The IHashCodeBuilder interface defines a hash code builder.
 */
public interface IHashCodeBuilder {
    /**
     * With a code.
     */
    IHashCodeBuilder withCode(int code);

    /**
     * With a boolean.
     */
    IHashCodeBuilder withBoolean(boolean value);

    /**
     * With a byte.
     */
    IHashCodeBuilder withByte(byte value);

    /**
     * With a short.
     */
    IHashCodeBuilder withShort(short value);

    /**
     * With an integer.
     */
    IHashCodeBuilder withInteger(int value);

    /**
     * With a long.
     */
    IHashCodeBuilder withLong(long value);

    /**
     * With a float.
     */
    IHashCodeBuilder withFloat(float value);

    /**
     * With a double.
     */
    IHashCodeBuilder withDouble(double value);

    /**
     * With a character.
     */
    IHashCodeBuilder withCharacter(char value);

    /**
     * With a string.
     */
    IHashCodeBuilder withString(String value);

    /**
     * With a boolean array.
     */
    IHashCodeBuilder withBooleanArray(boolean[] value);

    /**
     * With a byte array.
     */
    IHashCodeBuilder withByteArray(byte[] value);

    /**
     * With a short array.
     */
    IHashCodeBuilder withShortArray(short[] value);

    /**
     * With an integer array.
     */
    IHashCodeBuilder withIntegerArray(int[] value);

    /**
     * With a float array.
     */
    IHashCodeBuilder withFloatArray(float[] value);

    /**
     * With a double array.
     */
    IHashCodeBuilder withDoubleArray(double[] value);

    /**
     * With a character array.
     */
    IHashCodeBuilder withCharacterArray(char[] value);

    /**
     * With a string array.
     */
    IHashCodeBuilder withStringArray(String[] value);

    /**
     * With a generic.
     */
    <T> IHashCodeBuilder withGeneric(T obj, IHashCodeProvider<T> provider);

    /**
     * With a generic array.
     */
    <T> IHashCodeBuilder withArray(T[] array, IHashCodeProvider<T> provider);

    /**
     * With a generic collection.
     */
    <T> IHashCodeBuilder withCollection(Collection<T> lhs, IHashCodeProvider<T> provider);

    /**
     * Builds the resultant hash code.
     */
    int build();
}
