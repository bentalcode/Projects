package base.interfaces;

import java.math.BigInteger;
import java.time.Duration;
import java.util.Collection;
import java.util.Date;
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
     * With a double and an epsilon.
     */
    ICompareToBuilder withDouble(double lhs, double rhs, double epsilon);

    /**
     * With an almost double.
     */
    ICompareToBuilder withAlmostDouble(double lhs, double rhs);

    /**
     * With an almost double and an epsilon.
     */
    ICompareToBuilder withAlmostDouble(double lhs, double rhs, double epsilon);

    /**
     * With a character.
     */
    ICompareToBuilder withCharacter(char lhs, char rhs);

    /**
     * With a string.
     */
    ICompareToBuilder withString(String lhs, String rhs);

    /**
     * With an enum.
     */
    <T extends Enum<T>> ICompareToBuilder withEnum(T lhs, T rhs);

    /**
     * With a big integer.
     */
    ICompareToBuilder withBigInteger(BigInteger lhs, BigInteger rhs);

    /**
     * With a date.
     */
    ICompareToBuilder withDate(Date lhs, Date rhs);

    /**
     * With a duration.
     */
    ICompareToBuilder withDuration(Duration lhs, Duration rhs);

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
     * With a big integer array.
     */
    ICompareToBuilder withBigIntegerArray(BigInteger[] lhs, BigInteger[] rhs);

    /**
     * With a boolean two-dimensional array.
     */
    ICompareToBuilder withBooleanArray(boolean[][] lhs, boolean[][] rhs);

    /**
     * With a byte two-dimensional array.
     */
    ICompareToBuilder withByteArray(byte[][] lhs, byte[][] rhs);

    /**
     * With a short two-dimensional array.
     */
    ICompareToBuilder withShortArray(short[][] lhs, short[][] rhs);

    /**
     * With an integer two-dimensional array.
     */
    ICompareToBuilder withIntegerArray(int[][] lhs, int[][] rhs);

    /**
     * With a long two-dimensional array.
     */
    ICompareToBuilder withLongArray(long[][] lhs, long[][] rhs);

    /**
     * With a float two-dimensional array.
     */
    ICompareToBuilder withFloatArray(float[][] lhs, float[][] rhs);

    /**
     * With a double two-dimensional array.
     */
    ICompareToBuilder withDoubleArray(double[][] lhs, double[][] rhs);

    /**
     * With a character two-dimensional array.
     */
    ICompareToBuilder withCharacterArray(char[][] lhs, char[][] rhs);

    /**
     * With a string two-dimensional array.
     */
    ICompareToBuilder withStringArray(String[][] lhs, String[][] rhs);

    /**
     * With a big integer two-dimensional array.
     */
    ICompareToBuilder withBigIntegerArray(BigInteger[][] lhs, BigInteger[][] rhs);

    /**
     * With a generic object.
     */
    <T extends Comparable<T>> ICompareToBuilder withObject(T lhs, T rhs);

    /**
     * With a generic object and a comparator.
     */
    <T> ICompareToBuilder withObject(T lhs, T rhs, IComparableComparator<T> comparator);

    /**
     * With a generic array.
     */
    <T extends Comparable<T>> ICompareToBuilder withArray(T[] lhs, T[] rhs);

    /**
     * With a generic array and a comparator.
     */
    <T extends Comparable<T>> ICompareToBuilder withArray(T[] lhs, T[] rhs, IComparableComparator<T> comparator);

    /**
     * With a generic two-dimensional array.
     */
    <T extends Comparable<T>> ICompareToBuilder withArray(T[][] lhs, T[][] rhs);

    /**
     * With a generic two-dimensional array and a comparator.
     */
    <T extends Comparable<T>> ICompareToBuilder withArray(T[][] lhs, T[][] rhs, IComparableComparator<T> comparator);

    /**
     * With a generic collection.
     */
    <T extends Comparable<T>> ICompareToBuilder withCollection(Collection<T> lhs, Collection<T> rhs);

    /**
     * With a generic collection and a comparator.
     */
    <T extends Comparable<T>> ICompareToBuilder withCollection(Collection<T> lhs, Collection<T> rhs, IComparableComparator<T> comparator);

    /**
     * With a generic iterator.
     */
    <T extends Comparable<T>> ICompareToBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs);

    /**
     * With a generic iterator and a comparator.
     */
    <T> ICompareToBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs, IComparableComparator<T> comparator);

    /**
     * With a generic iterable.
     */
    <T extends Comparable<T>> ICompareToBuilder withIterable(IIterable<T> lhs, IIterable<T> rhs);

    /**
     * With a generic iterable and a comparator.
     */
    <T> ICompareToBuilder withIterable(IIterable<T> lhs, IIterable<T> rhs, IComparableComparator<T> comparator);

    /**
     * With a generic map.
     */
    <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> ICompareToBuilder withMap(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs);

    /**
     * With a generic map and comparators.
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
