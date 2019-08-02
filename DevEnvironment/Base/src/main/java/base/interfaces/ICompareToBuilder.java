package base.interfaces;

import java.util.Collection;
import java.util.Map;

/**
 * The ICompareToBuilder interface defines a compare to builder.
 */
public interface ICompareToBuilder {
    /**
     * With a compare status.
     */
    ICompareToBuilder withCompareStatus(int status);

    /**
     * With a boolean.
     */
    ICompareToBuilder withBoolean(boolean lhs, boolean rhs);

    /**
     * With a byte.
     */
    ICompareToBuilder withByte(byte lhs, byte rhs);

    /**
     * With a short.
     */
    ICompareToBuilder withShort(short lhs, short rhs);

    /**
     * With an integer.
     */
    ICompareToBuilder withInteger(int lhs, int rhs);

    /**
     * With a long.
     */
    ICompareToBuilder withLong(long lhs, long rhs);

    /**
     * With a float.
     */
    ICompareToBuilder withFloat(float lhs, float rhs);

    /**
     * With a double.
     */
    ICompareToBuilder withDouble(double lhs, double rhs);

    /**
     * With a character.
     */
    ICompareToBuilder withCharacter(char lhs, char rhs);

    /**
     * With a string.
     */
    ICompareToBuilder withString(String lhs, String rhs);

    /**
     * With a boolean array.
     */
    ICompareToBuilder withBooleanArray(boolean[] lhs, boolean[] rhs);

    /**
     * With a byte array.
     */
    ICompareToBuilder withByteArray(byte[] lhs, byte[] rhs);

    /**
     * With a short array.
     */
    ICompareToBuilder withShortArray(short[] lhs, short[] rhs);

    /**
     * With an integer array.
     */
    ICompareToBuilder withIntegerArray(int[] lhs, int[] rhs);

    /**
     * With a long array.
     */
    ICompareToBuilder withLongArray(long[] lhs, long[] rhs);

    /**
     * With a float array.
     */
    ICompareToBuilder withFloatArray(float[] lhs, float[] rhs);

    /**
     * With a double array.
     */
    ICompareToBuilder withDoubleArray(double[] lhs, double[] rhs);

    /**
     * With a character array.
     */
    ICompareToBuilder withCharacterArray(char[] lhs, char[] rhs);

    /**
     * With a string array.
     */
    ICompareToBuilder withStringArray(String[] lhs, String[] rhs);

    /**
     * With a boolean two dimensional array.
     */
    ICompareToBuilder withBooleanArray(boolean[][] lhs, boolean[][] rhs);

    /**
     * With a byte two dimensional array.
     */
    ICompareToBuilder withByteArray(byte[][] lhs, byte[][] rhs);

    /**
     * With a short two dimensional array.
     */
    ICompareToBuilder withShortArray(short[][] lhs, short[][] rhs);

    /**
     * With an integer two dimensional array.
     */
    ICompareToBuilder withIntegerArray(int[][] lhs, int[][] rhs);

    /**
     * With a long two dimensional array.
     */
    ICompareToBuilder withLongArray(long[][] lhs, long[][] rhs);

    /**
     * With a float two dimensional array.
     */
    ICompareToBuilder withFloatArray(float[][] lhs, float[][] rhs);

    /**
     * With a double two dimensional array.
     */
    ICompareToBuilder withDoubleArray(double[][] lhs, double[][] rhs);

    /**
     * With a character two dimensional array.
     */
    ICompareToBuilder withCharacterArray(char[][] lhs, char[][] rhs);

    /**
     * With a string two dimensional array.
     */
    ICompareToBuilder withStringArray(String[][] lhs, String[][] rhs);

    /**
     * With a generic object.
     */
    <T> ICompareToBuilder withObject(T lhs, T rhs, IComparableComparator<T> comparator);

    /**
     * With a generic array.
     */
    <T> ICompareToBuilder withArray(T[] lhs, T[] rhs, IComparableComparator<T> comparator);

    /**
     * With a generic two dimensional array.
     */
    <T> ICompareToBuilder withArray(T[][] lhs, T[][] rhs, IComparableComparator<T> comparator);

    /**
     * With a generic collection.
     */
    <T> ICompareToBuilder withCollection(Collection<T> lhs, Collection<T> rhs, IComparableComparator<T> comparator);

    /**
     * With a generic iterator.
     */
    <T> ICompareToBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs, IComparableComparator<T> comparator);

    /**
     * With a generic map.
     */
    <TKey, TValue> ICompareToBuilder withMap(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IComparableComparator<TKey> keyComparator,
        IComparableComparator<TValue> valueComparator);

    /**
     * Builds the resultant compare status.
     */
    int build();
}
