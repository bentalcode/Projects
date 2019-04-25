package base.core;

import base.interfaces.IComparatorFactory;
import base.interfaces.IHashCodeBuilder;
import base.interfaces.IHashCodeProvider;
import base.interfaces.IPrimitiveSize;

import java.util.Collection;

/**
 * The HashCodeBuilder class implements a hash code builder.
 */
public final class HashCodeBuilder implements IHashCodeBuilder {
    private final IComparatorFactory comparatorFactory = new ComparatorFactory();

    private final int factorPrimeNumber;
    private int code;

    /**
     * The HashCodeBuilder constructor.
     */
    public HashCodeBuilder(int initialPrimeNumber, final int factorPrimeNumber) {
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
     * With a boolean.
     */
    @Override
    public IHashCodeBuilder withBoolean(boolean value) {
        int currentCode = (value) ? 1 : 0;
        this.updateCode(currentCode);
        return this;
    }

    /**
     * With a byte.
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
     * With a short.
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
     * With an integer.
     */
    @Override
    public IHashCodeBuilder withInteger(int value) {
        int currentCode = value;

        this.updateCode(currentCode);

        return this;
    }

    /**
     * With a long.
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
     * With a float.
     */
    @Override
    public IHashCodeBuilder withFloat(float value) {
        return this;
    }

    /**
     * With a double.
     */
    @Override
    public IHashCodeBuilder withDouble(double value) {
        return this;
    }

    /**
     * With a character.
     */
    @Override
    public IHashCodeBuilder withCharacter(char value) {
        return this;
    }

    /**
     * With a string.
     */
    @Override
    public IHashCodeBuilder withString(String value) {
        return this;
    }

    /**
     * With a boolean array.
     */
    @Override
    public IHashCodeBuilder withBooleanArray(boolean[] value) {
        return this;
    }

    /**
     * With a byte array.
     */
    @Override
    public IHashCodeBuilder withByteArray(byte[] value) {
        return this;
    }

    /**
     * With a short array.
     */
    @Override
    public IHashCodeBuilder withShortArray(short[] value) {
        return this;
    }

    /**
     * With an integer array.
     */
    @Override
    public IHashCodeBuilder withIntegerArray(int[] value) {
        return this;
    }

    /**
     * With a float array.
     */
    @Override
    public IHashCodeBuilder withFloatArray(float[] value) {
        return this;
    }

    /**
     * With a double array.
     */
    @Override
    public IHashCodeBuilder withDoubleArray(double[] value) {
        return this;
    }

    /**
     * With a character array.
     */
    @Override
    public IHashCodeBuilder withCharacterArray(char[] value) {
        return this;
    }

    /**
     * With a string array.
     */
    @Override
    public IHashCodeBuilder withStringArray(String[] value) {
        return this;
    }

    /**
     * With a generic.
     */
    @Override
    public <T> IHashCodeBuilder withGeneric(T obj, IHashCodeProvider<T> provider) {
        return this;
    }

    /**
     * With a generic array.
     */
    @Override
    public <T> IHashCodeBuilder withArray(T[] array, IHashCodeProvider<T> provider) {
        return this;
    }

    /**
     * With a generic collection.
     */
    @Override
    public <T> IHashCodeBuilder withCollection(Collection<T> lhs, IHashCodeProvider<T> provider) {
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
