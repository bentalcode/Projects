package base.core;

import base.interfaces.IHashCodeBuilder;
import base.interfaces.IHashCodeProvider;
import base.interfaces.IPrimitiveSize;
import java.util.Collection;

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
        int lowSection = value;
        int highSection = value << IPrimitiveSize.InBits.ShortSize;

        int currentCode = lowSection;
        currentCode += highSection;

        this.updateCode(currentCode);

        return this;
    }

    /**
     * With an integer. (Size of an integer is 4 bytes.)
     */
    @Override
    public IHashCodeBuilder withInteger(int value) {
        int currentCode = value;

        this.updateCode(currentCode);

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
     * With a boolean array.
     */
    @Override
    public IHashCodeBuilder withBooleanArray(boolean[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withBoolean(array[i]);
        }

        return this;
    }

    /**
     * With a byte array.
     */
    @Override
    public IHashCodeBuilder withByteArray(byte[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withByte(array[i]);
        }

        return this;
    }

    /**
     * With a short array.
     */
    @Override
    public IHashCodeBuilder withShortArray(short[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withShort(array[i]);
        }

        return this;
    }

    /**
     * With an integer array.
     */
    @Override
    public IHashCodeBuilder withIntegerArray(int[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withInteger(array[i]);
        }

        return this;
    }

    /**
     * With a long array.
     */
    @Override
    public IHashCodeBuilder withLongArray(long[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withLong(array[i]);
        }

        return this;
    }

    /**
     * With a float array.
     */
    @Override
    public IHashCodeBuilder withFloatArray(float[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withFloat(array[i]);
        }

        return this;
    }

    /**
     * With a double array.
     */
    @Override
    public IHashCodeBuilder withDoubleArray(double[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withDouble(array[i]);
        }

        return this;
    }

    /**
     * With a character array.
     */
    @Override
    public IHashCodeBuilder withCharacterArray(char[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withCharacter(array[i]);
        }

        return this;
    }

    /**
     * With a string array.
     */
    @Override
    public IHashCodeBuilder withStringArray(String[] array) {
        for (int i = 0; i < array.length; ++i) {
            this.withString(array[i]);
        }

        return this;
    }

    /**
     * With a generic object.
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
    public <T> IHashCodeBuilder withArray(T[] array, IHashCodeProvider<T> provider) {
        for (int i = 0; i < array.length; ++i) {
            this.withObject(array[i], provider);
        }

        return this;
    }

    /**
     * With a generic collection.
     */
    @Override
    public <T> IHashCodeBuilder withCollection(Collection<T> collection, IHashCodeProvider<T> provider) {
        for (T item : collection) {
            this.withObject(item, provider);
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