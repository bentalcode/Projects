package base.interfaces;

import java.util.Collection;

/**
 * The IEqualBuilder interface defines an equal builder.
 */
public interface IEqualBuilder {
    /**
     * With an equality status.
     */
    IEqualBuilder withStatus(boolean status);

    /**
     * With a boolean.
     */
    IEqualBuilder withBoolean(boolean lhs, boolean rhs);

    /**
     * With a byte.
     */
    IEqualBuilder withByte(byte lhs, byte rhs);

    /**
     * With a short.
     */
    IEqualBuilder withShort(short lhs, short rhs);

    /**
     * With an integer.
     */
    IEqualBuilder withInteger(int lhs, int rhs);

    /**
     * With a long.
     */
    IEqualBuilder withLong(long lhs, long rhs);

    /**
     * With a float.
     */
    IEqualBuilder withFloat(float lhs, float rhs);

    /**
     * With a double.
     */
    IEqualBuilder withDouble(double lhs, double rhs);

    /**
     * With a character.
     */
    IEqualBuilder withCharacter(char lhs, char rhs);

    /**
     * With a string.
     */
    IEqualBuilder withString(String lhs, String rhs);

    /**
     * With a boolean array.
     */
    IEqualBuilder withBooleanArray(boolean[] lhs, boolean[] rhs);

    /**
     * With a byte array.
     */
    IEqualBuilder withByteArray(byte[] lhs, byte[] rhs);

    /**
     * With a short array.
     */
    IEqualBuilder withShortArray(short[] lhs, short[] rhs);

    /**
     * With an integer array.
     */
    IEqualBuilder withIntegerArray(int[] lhs, int[] rhs);

    /**
     * With a long array.
     */
    IEqualBuilder withLongArray(long[] lhs, long[] rhs);

    /**
     * With a float array.
     */
    IEqualBuilder withFloatArray(float[] lhs, float[] rhs);

    /**
     * With a double array.
     */
    IEqualBuilder withDoubleArray(double[] lhs, double[] rhs);

    /**
     * With a character array.
     */
    IEqualBuilder withCharacterArray(char[] lhs, char[] rhs);

    /**
     * With a string array.
     */
    IEqualBuilder withStringArray(String[] lhs, String[] rhs);

    /**
     * With a generic object.
     */
    <T> IEqualBuilder withObject(T lhs, T rhs, IBinaryComparator<T> comparator);

    /**
     * With a generic array.
     */
    <T> IEqualBuilder withArray(T[] lhs, T[] rhs, IBinaryComparator<T> comparator);

    /**
     * With a generic collection.
     */
    <T> IEqualBuilder withCollection(Collection<T> lhs, Collection<T> rhs, IBinaryComparator<T> comparator);

    /**
     * With a generic iterator.
     */
    <T> IEqualBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs, IBinaryComparator<T> comparator);

    /**
     * Builds the resultant equality status.
     */
    boolean build();
}
