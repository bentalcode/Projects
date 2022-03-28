package base.core;

import base.interfaces.IHashCodeBuilder;
import base.interfaces.IHashCodeProvider;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IPrimitiveSize;
import java.math.BigInteger;
import java.time.Duration;
import java.util.Collection;
import java.util.Date;
import java.util.Map;

/**
 * The HashCodeBuilder class implements a hash code builder.
 */
public final class HashCodeBuilder implements IHashCodeBuilder {
    private final int factorPrimeNumber;
    private int code;

    /**
     * The HashCodeBuilder constructor.
     */
    public HashCodeBuilder(int initialPrimeNumber, int factorPrimeNumber) {
        Conditions.validate(
            Primes.isPrime(initialPrimeNumber),
            "The initial prime number is not a prime.");

        Conditions.validate(
            Primes.isPrime(factorPrimeNumber),
            "The factor prime number is not a prime.");

        this.factorPrimeNumber = factorPrimeNumber;
        this.code = initialPrimeNumber;
    }

    /**
     * With a code.
     */
    @Override
    public IHashCodeBuilder withCode(int code) {
        this.updateCode(code);
        return this;
    }

    /**
     * With a boolean. (Size of the boolean in java is virtual machine dependent.)
     */
    @Override
    public IHashCodeBuilder withBoolean(boolean value) {
        int currentCode = (value) ? 1 : 0;
        this.updateCode(currentCode);
        return this;
    }

    /**
     * With a byte. (Size of a byte is 1 byte.)
     */
    @Override
    public IHashCodeBuilder withByte(byte value) {
        int currentCode = 0;

        int offset = 0;

        int numberOfBytesInInteger = IPrimitiveSize.InBytes.IntegerSize;

        for (int i = 0; i < numberOfBytesInInteger; ++i) {
            currentCode += value << offset;

            offset += IPrimitiveSize.InBits.ByteSize;
        }

        this.updateCode(currentCode);

        return this;
    }

    /**
     * With a short. (Size of a short is 2 bytes.)
     */
    @Override
    public IHashCodeBuilder withShort(short value) {
        //
        // Low Section: value
        // High Section: value << IPrimitiveSize.InBits.ShortSize
        //
        int currentCode = value;
        currentCode += (value << IPrimitiveSize.InBits.ShortSize);

        this.updateCode(currentCode);

        return this;
    }

    /**
     * With an integer. (Size of an integer is 4 bytes.)
     */
    @Override
    public IHashCodeBuilder withInteger(int value) {
        this.updateCode(value);
        return this;
    }

    /**
     * With a long. (Size of a long is 8 bytes.)
     */
    @Override
    public IHashCodeBuilder withLong(long value) {
        long lowMask  = 0x00000000FFFFFFFF;

        int lowSection = (int)(value & lowMask);
        int highSection = (int)(value >> IPrimitiveSize.InBits.IntegerSize);

        int currentCode = lowSection;
        currentCode += highSection;

        this.updateCode(currentCode);

        return this;
    }

    /**
     * With a float. (Size of a float is 4 bytes.)
     */
    @Override
    public IHashCodeBuilder withFloat(float value) {
        int currentCode = (int)value;
        this.updateCode(currentCode);

        return this;
    }

    /**
     * With a double. (Size of a double is 8 bytes.)
     */
    @Override
    public IHashCodeBuilder withDouble(double value) {
        long currentValue = (long)value;
        return this.withLong(currentValue);
    }

    /**
     * With a character. (Size of a double is 2 bytes.)
     */
    @Override
    public IHashCodeBuilder withCharacter(char value) {
        short currentValue = (short)value;
        return this.withShort(currentValue);
    }

    /**
     * With a string.
     */
    @Override
    public IHashCodeBuilder withString(String value) {
        for (int i = 0; i < value.length(); ++i) {
            this.withCharacter(value.charAt(i));
        }

        return this;
    }

    /**
     * With an enum.
     */
    @Override
    public <T extends Enum<T>> IHashCodeBuilder withEnum(Enum<T> value) {
        this.withInteger(value.hashCode());
        return this;
    }

    /**
     * With a big integer.
     */
    @Override
    public IHashCodeBuilder withBigInteger(BigInteger value) {
        for (byte byteValue : value.toByteArray()) {
            this.withByte(byteValue);
        }

        return this;
    }

    /**
     * With a date.
     */
    @Override
    public IHashCodeBuilder withDate(Date value) {
        this.withLong(value.getTime());
        return this;
    }

    /**
     * With a duration.
     */
    @Override
    public IHashCodeBuilder withDuration(Duration value) {
        this.withLong(value.toMillis());
        return this;
    }

    /**
     * With a boolean array.
     */
    @Override
    public IHashCodeBuilder withBooleanArray(boolean[] array) {
        for (boolean item : array) {
            this.withBoolean(item);
        }

        return this;
    }

    /**
     * With a byte array.
     */
    @Override
    public IHashCodeBuilder withByteArray(byte[] array) {
        for (byte item : array) {
            this.withByte(item);
        }

        return this;
    }

    /**
     * With a short array.
     */
    @Override
    public IHashCodeBuilder withShortArray(short[] array) {
        for (short item : array) {
            this.withShort(item);
        }

        return this;
    }

    /**
     * With an integer array.
     */
    @Override
    public IHashCodeBuilder withIntegerArray(int[] array) {
        for (int item : array) {
            this.withInteger(item);
        }

        return this;
    }

    /**
     * With a long array.
     */
    @Override
    public IHashCodeBuilder withLongArray(long[] array) {
        for (long item : array) {
            this.withLong(item);
        }

        return this;
    }

    /**
     * With a float array.
     */
    @Override
    public IHashCodeBuilder withFloatArray(float[] array) {
        for (float item : array) {
            this.withFloat(item);
        }

        return this;
    }

    /**
     * With a double array.
     */
    @Override
    public IHashCodeBuilder withDoubleArray(double[] array) {
        for (double item : array) {
            this.withDouble(item);
        }

        return this;
    }

    /**
     * With a character array.
     */
    @Override
    public IHashCodeBuilder withCharacterArray(char[] array) {
        for (char item : array) {
            this.withCharacter(item);
        }

        return this;
    }

    /**
     * With a string array.
     */
    @Override
    public IHashCodeBuilder withStringArray(String[] array) {
        for (String item : array) {
            this.withString(item);
        }

        return this;
    }

    /**
     * With a big integer array.
     */
    @Override
    public IHashCodeBuilder withBigIntegerArray(BigInteger[] array) {
        for (BigInteger item : array) {
            this.withBigInteger(item);
        }

        return this;
    }

    /**
     * With a boolean two dimensional array.
     */
    @Override
    public IHashCodeBuilder withBooleanArray(boolean[][] array) {
        int rowsLength = array.length;
        int columnsLength = array[0].length;

        for (boolean[] booleans : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withBoolean(booleans[column]);
            }
        }

        return this;
    }

    /**
     * With a byte two dimensional array.
     */
    @Override
    public IHashCodeBuilder withByteArray(byte[][] array) {
        int columnsLength = array[0].length;

        for (byte[] bytes : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withByte(bytes[column]);
            }
        }

        return this;
    }

    /**
     * With a short two dimensional array.
     */
    @Override
    public IHashCodeBuilder withShortArray(short[][] array) {
        int columnsLength = array[0].length;

        for (short[] shorts : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withShort(shorts[column]);
            }
        }

        return this;
    }

    /**
     * With an integer two dimensional array.
     */
    @Override
    public IHashCodeBuilder withIntegerArray(int[][] array) {
        int rowsLength = array.length;
        int columnsLength = array[0].length;

        for (int[] ints : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withInteger(ints[column]);
            }
        }

        return this;
    }

    /**
     * With a long two dimensional array.
     */
    @Override
    public IHashCodeBuilder withLongArray(long[][] array) {
        int rowsLength = array.length;
        int columnsLength = array[0].length;

        for (long[] longs : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withLong(longs[column]);
            }
        }

        return this;
    }

    /**
     * With a float two dimensional array.
     */
    @Override
    public IHashCodeBuilder withFloatArray(float[][] array) {
        int rowsLength = array.length;
        int columnsLength = array[0].length;

        for (float[] floats : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withFloat(floats[column]);
            }
        }

        return this;
    }

    /**
     * With a double two dimensional array.
     */
    @Override
    public IHashCodeBuilder withDoubleArray(double[][] array) {
        int columnsLength = array[0].length;

        for (double[] doubles : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withDouble(doubles[column]);
            }
        }

        return this;
    }

    /**
     * With a character two dimensional array.
     */
    @Override
    public IHashCodeBuilder withCharacterArray(char[][] array) {
        int columnsLength = array[0].length;

        for (char[] chars : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withCharacter(chars[column]);
            }
        }

        return this;
    }

    /**
     * With a string two dimensional array.
     */
    @Override
    public IHashCodeBuilder withStringArray(String[][] array) {
        int columnsLength = array[0].length;

        for (String[] strings : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withString(strings[column]);
            }
        }

        return this;
    }

    /**
     * With a big integer two dimensional array.
     */
    @Override
    public IHashCodeBuilder withBigIntegerArray(BigInteger[][] array) {
        int columnsLength = array[0].length;

        for (BigInteger[] bigIntegers : array) {
            for (int column = 0; column < columnsLength; ++column) {
                this.withBigInteger(bigIntegers[column]);
            }
        }

        return this;
    }

    /**
     * With a generic object.
     */
    @Override
    public <T extends Comparable<T>> IHashCodeBuilder withObject(T obj) {
        IHashCodeProvider<T> provider = base.core.Comparator.make();
        return this.withObject(obj, provider);
    }

    /**
     * With a generic object and a provider.
     */
    @Override
    public <T> IHashCodeBuilder withObject(T obj, IHashCodeProvider<T> provider) {
        int currentCode = provider.getHashCode(obj);
        this.updateCode(currentCode);
        return this;
    }

    /**
     * With a generic array.
     */
    @Override
    public <T extends Comparable<T>> IHashCodeBuilder withArray(T[] array) {
        IHashCodeProvider<T> provider = base.core.Comparator.make();
        return this.withArray(array, provider);
    }

    /**
     * With a generic array and a provider.
     */
    @Override
    public <T> IHashCodeBuilder withArray(T[] array, IHashCodeProvider<T> provider) {
        return this.withIterator(ArrayIterator.make(array), provider);
    }

    /**
     * With a generic two dimensional array.
     */
    @Override
    public <T extends Comparable<T>> IHashCodeBuilder withArray(T[][] array) {
        IHashCodeProvider<T> provider = base.core.Comparator.make();
        return this.withArray(array, provider);
    }

    /**
     * With a generic two dimensional array and a provider.
     */
    @Override
    public <T> IHashCodeBuilder withArray(T[][] array, IHashCodeProvider<T> provider) {
        return this.withIterator(TwoDimensionalArrayIterator.make(array), provider);
    }

    /**
     * With a generic collection.
     */
    @Override
    public <T extends Comparable<T>> IHashCodeBuilder withCollection(Collection<T> collection) {
        IHashCodeProvider<T> provider = base.core.Comparator.make();
        return this.withCollection(collection, provider);
    }

    /**
     * With a generic collection and a provider.
     */
    @Override
    public <T> IHashCodeBuilder withCollection(Collection<T> collection, IHashCodeProvider<T> provider) {
        return this.withIterator(Iterator.make(collection), provider);
    }

    /**
     * With a generic iterator.
     */
    @Override
    public <T extends Comparable<T>> IHashCodeBuilder withIterator(IIterator<T> iterator) {
        IHashCodeProvider<T> provider = base.core.Comparator.make();
        return this.withIterator(iterator, provider);
    }

    /**
     * With a generic iterator and a provider.
     */
    @Override
    public <T> IHashCodeBuilder withIterator(IIterator<T> iterator, IHashCodeProvider<T> provider) {
        while (iterator.hasNext()) {
            T item = iterator.next();

            this.withObject(item, provider);
        }

        return this;
    }

    /**
     * With a generic iterable.
     */
    @Override
    public <T extends Comparable<T>> IHashCodeBuilder withIterable(IIterable<T> iterable) {
        IHashCodeProvider<T> provider = base.core.Comparator.make();
        return this.withIterator(iterable.getIterator(), provider);
    }

    /**
     * With a generic iterable and a provider.
     */
    @Override
    public <T> IHashCodeBuilder withIterable(IIterable<T> iterable, IHashCodeProvider<T> provider) {
        return this.withIterator(iterable.getIterator(), provider);
    }

    /**
     * With a generic map.
     */
    @Override
    public <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> IHashCodeBuilder withMap(Map<TKey, TValue> map) {
        IHashCodeProvider<TKey> keyProvider = base.core.Comparator.make();
        IHashCodeProvider<TValue> valueProvider = base.core.Comparator.make();
        return this.withMap(map, keyProvider, valueProvider);
    }

    /**
     * With a generic map and providers.
     */
    @Override
    public <TKey, TValue> IHashCodeBuilder withMap(
        Map<TKey, TValue> map,
        IHashCodeProvider<TKey> keyProvider,
        IHashCodeProvider<TValue> valueProvider) {

        for (TKey item : map.keySet()) {
            this.withObject(item, keyProvider);
        }

        for (TValue value : map.values()) {
            this.withObject(value, valueProvider);
        }

        return this;
    }

    /**
     * Updates the code.
     */
    private void updateCode(int code) {
        this.code = this.code * this.factorPrimeNumber + code;
    }

    /**
     * Builds the resultant hash code.
     * In this case, simply return the existing calculated hash code.
     */
    @Override
    public int build() {
        return this.code;
    }
}
