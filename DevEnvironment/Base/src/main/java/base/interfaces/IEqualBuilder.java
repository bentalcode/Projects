package base.interfaces;

import java.math.BigInteger;
import java.time.Duration;
import java.util.Collection;
import java.util.Date;
import java.util.Map;

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
     * With a double and an epsilon.
     */
    IEqualBuilder withDouble(double lhs, double rhs, double epsilon);

    /**
     * With an almost double.
     */
    IEqualBuilder withAlmostDouble(double lhs, double rhs);

    /**
     * With an almost double and epsilon.
     */
    IEqualBuilder withAlmostDouble(double lhs, double rhs, double epsilon);

    /**
     * With a character.
     */
    IEqualBuilder withCharacter(char lhs, char rhs);

    /**
     * With a string.
     */
    IEqualBuilder withString(String lhs, String rhs);

    /**
     * With an enum.
     */
    <T extends Enum<T>> IEqualBuilder withEnum(T lhs, T rhs);

    /**
     * With a big integer.
     */
    IEqualBuilder withBigInteger(BigInteger lhs, BigInteger rhs);

    /**
     * With a date.
     */
    IEqualBuilder withDate(Date lhs, Date rhs);

    /**
     * With a duration.
     */
    IEqualBuilder withDuration(Duration lhs, Duration rhs);

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
     * With a big integer array.
     */
    IEqualBuilder withBigIntegerArray(BigInteger[] lhs, BigInteger[] rhs);

    /**
     * With a boolean two-dimensional array.
     */
    IEqualBuilder withBooleanArray(boolean[][] lhs, boolean[][] rhs);

    /**
     * With a byte two-dimensional array.
     */
    IEqualBuilder withByteArray(byte[][] lhs, byte[][] rhs);

    /**
     * With a short two-dimensional array.
     */
    IEqualBuilder withShortArray(short[][] lhs, short[][] rhs);

    /**
     * With an integer two-dimensional array.
     */
    IEqualBuilder withIntegerArray(int[][] lhs, int[][] rhs);

    /**
     * With a long two-dimensional array.
     */
    IEqualBuilder withLongArray(long[][] lhs, long[][] rhs);

    /**
     * With a float two-dimensional array.
     */
    IEqualBuilder withFloatArray(float[][] lhs, float[][] rhs);

    /**
     * With a double two-dimensional array.
     */
    IEqualBuilder withDoubleArray(double[][] lhs, double[][] rhs);

    /**
     * With a character two-dimensional array.
     */
    IEqualBuilder withCharacterArray(char[][] lhs, char[][] rhs);

    /**
     * With a string two-dimensional array.
     */
    IEqualBuilder withStringArray(String[][] lhs, String[][] rhs);

    /**
     * With a big integer array.
     */
    IEqualBuilder withBigIntegerArray(BigInteger[][] lhs, BigInteger[][] rhs);

    /**
     * With a generic object.
     */
    <T extends Comparable<T>> IEqualBuilder withObject(T lhs, T rhs);

    /**
     * With a generic object and a comparator.
     */
    <T> IEqualBuilder withObject(T lhs, T rhs, IEquatableComparator<T> comparator);

    /**
     * With a generic array.
     */
    <T extends Comparable<T>> IEqualBuilder withArray(T[] lhs, T[] rhs);

    /**
     * With a generic array and a comparator.
     */
    <T extends Comparable<T>> IEqualBuilder withArray(T[] lhs, T[] rhs, IEquatableComparator<T> comparator);

    /**
     * With a generic two-dimensional array.
     */
    <T extends Comparable<T>> IEqualBuilder withArray(T[][] lhs, T[][] rhs);

    /**
     * With a generic two-dimensional array and a comparator.
     */
    <T> IEqualBuilder withArray(T[][] lhs, T[][] rhs, IEquatableComparator<T> comparator);

    /**
     * With a generic collection.
     */
    <T extends Comparable<T>> IEqualBuilder withCollection(Collection<T> lhs, Collection<T> rhs);

    /**
     * With a generic collection and a comparator.
     */
    <T extends Comparable<T>> IEqualBuilder withCollection(Collection<T> lhs, Collection<T> rhs, IEquatableComparator<T> comparator);

    /**
     * With a generic iterator.
     */
    <T extends Comparable<T>> IEqualBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs);

    /**
     * With a generic iterator and a comparator.
     */
    <T extends Comparable<T>> IEqualBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs, IEquatableComparator<T> comparator);

    /**
     * With a generic iterator and a reverse iterator.
     */
    <T extends Comparable<T>> IEqualBuilder withIteratorAndReverseIterator(IIterator<T> lhs, IReverseIterator<T> rhs);

    /**
     * With a generic iterator, a reverse iterator and a comparator.
     */
    <T extends Comparable<T>> IEqualBuilder withIteratorAndReverseIterator(IIterator<T> lhs, IReverseIterator<T> rhs, IEquatableComparator<T> comparator);

    /**
     * With a generic iterable.
     */
    <T extends Comparable<T>> IEqualBuilder withIterable(IIterable<T> lhs, IIterable<T> rhs);

    /**
     * With a generic iterable and a comparator.
     */
    <T> IEqualBuilder withIterable(IIterable<T> lhs, IIterable<T> rhs, IEquatableComparator<T> comparator);

    <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> IEqualBuilder withMap(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs);

    /**
     * With a generic map and comparators.
     */
    <TKey, TValue> IEqualBuilder withMap(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IEquatableComparator<TKey> keyComparator,
        IEquatableComparator<TValue> valueComparator);

    /**
     * Builds the resultant equality status.
     */
    boolean build();
}
