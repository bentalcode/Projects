package base.interfaces;

import java.math.BigInteger;
import java.util.Collection;
import java.util.Map;

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
     * With a big integer.
     */
    IHashCodeBuilder withBigInteger(BigInteger value);

    /**
     * With a boolean array.
     */
    IHashCodeBuilder withBooleanArray(boolean[] array);

    /**
     * With a byte array.
     */
    IHashCodeBuilder withByteArray(byte[] array);

    /**
     * With a short array.
     */
    IHashCodeBuilder withShortArray(short[] array);

    /**
     * With an integer array.
     */
    IHashCodeBuilder withIntegerArray(int[] array);

    /**
     * With a long array.
     */
    IHashCodeBuilder withLongArray(long[] array);

    /**
     * With a float array.
     */
    IHashCodeBuilder withFloatArray(float[] array);

    /**
     * With a double array.
     */
    IHashCodeBuilder withDoubleArray(double[] array);

    /**
     * With a character array.
     */
    IHashCodeBuilder withCharacterArray(char[] array);

    /**
     * With a string array.
     */
    IHashCodeBuilder withStringArray(String[] array);

    /**
     * With a big integer array.
     */
    IHashCodeBuilder withBigIntegerArray(BigInteger[] array);

    /**
     * With a boolean two dimensional array.
     */
    IHashCodeBuilder withBooleanArray(boolean[][] array);

    /**
     * With a byte two dimensional array.
     */
    IHashCodeBuilder withByteArray(byte[][] array);

    /**
     * With a short two dimensional array.
     */
    IHashCodeBuilder withShortArray(short[][] array);

    /**
     * With an integer two dimensional array.
     */
    IHashCodeBuilder withIntegerArray(int[][] array);

    /**
     * With a long two dimensional array.
     */
    IHashCodeBuilder withLongArray(long[][] array);

    /**
     * With a float two dimensional array.
     */
    IHashCodeBuilder withFloatArray(float[][] array);

    /**
     * With a double two dimensional array.
     */
    IHashCodeBuilder withDoubleArray(double[][] array);

    /**
     * With a character two dimensional array.
     */
    IHashCodeBuilder withCharacterArray(char[][] array);

    /**
     * With a string two dimensional array.
     */
    IHashCodeBuilder withStringArray(String[][] array);

    /**
     * With a big integer two dimensional array.
     */
    IHashCodeBuilder withBigIntegerArray(BigInteger[][] array);

    /**
     * With a generic object.
     */
    <T extends Comparable<T>> IHashCodeBuilder withObject(T obj);

    /**
     * With a generic object and a provider.
     */
    <T> IHashCodeBuilder withObject(T obj, IHashCodeProvider<T> provider);

    /**
     * With a generic array.
     */
    <T extends Comparable<T>> IHashCodeBuilder withArray(T[] array);

    /**
     * With a generic array and a provider.
     */
    <T> IHashCodeBuilder withArray(T[] array, IHashCodeProvider<T> provider);

    /**
     * With a generic two dimensional array.
     */
    <T extends Comparable<T>> IHashCodeBuilder withArray(T[][] array);

    /**
     * With a generic two dimensional array and a provider.
     */
    <T> IHashCodeBuilder withArray(T[][] array, IHashCodeProvider<T> provider);

    /**
     * With a generic collection.
     */
    <T extends Comparable<T>> IHashCodeBuilder withCollection(Collection<T> collection);

    /**
     * With a generic collection and a provider.
     */
    <T> IHashCodeBuilder withCollection(Collection<T> collection, IHashCodeProvider<T> provider);

    /**
     * With a generic iterator.
     */
    <T extends Comparable<T>> IHashCodeBuilder withIterator(IIterator<T> iterator);

    /**
     * With a generic iterator and a provider.
     */
    <T> IHashCodeBuilder withIterator(IIterator<T> iterator, IHashCodeProvider<T> provider);

    /**
     * With a generic iterable.
     */
    <T extends Comparable<T>> IHashCodeBuilder withIterable(IIterable<T> iterable);

    /**
     * With a generic iterable and a provider.
     */
    <T> IHashCodeBuilder withIterable(IIterable<T> iterable, IHashCodeProvider<T> provider);

    /**
     * With a generic map.
     */
    <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> IHashCodeBuilder withMap(Map<TKey, TValue> map);

    /**
     * With a generic map and providers.
     */
    <TKey, TValue> IHashCodeBuilder withMap(
        Map<TKey, TValue> map,
        IHashCodeProvider<TKey> keyProvider,
        IHashCodeProvider<TValue> valueProvider);

    /**
     * Builds the resultant hash code.
     */
    int build();
}
