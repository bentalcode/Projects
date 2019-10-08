package datastructures.bitarray.core;

import base.core.AbstractBinaryComparator;
import base.core.Arrays;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IPrimitiveSize;
import base.interfaces.IReverseIterator;
import datastructures.bitarray.interfaces.BinaryBitOperator;
import datastructures.bitarray.interfaces.IBit32Array;
import datastructures.bitarray.interfaces.UnaryBitOperator;
import datastructures.collections.core.Collections;

/**
 * The Bit32Array class implements a bit array of size 32.
 */
public final class Bit32Array implements IBit32Array {
    private static int Size = IPrimitiveSize.InBits.IntegerSize;

    private int data;
    private final IBinaryComparator<IBit32Array> comparator;

    /**
     * Copies a bit array.
     */
    public static IBit32Array copy(IBit32Array bitArray) {
        return new Bit32Array(bitArray);
    }

    /**
     * The Bit32Array constructor.
     */
    public Bit32Array() {
        this(
            0,
            Bit32Array.defaultComparator());
    }

    /**
     * The Bit32Array constructor.
     */
    public Bit32Array(int data) {
        this(
            data,
            Bit32Array.defaultComparator());
    }

    /**
     * The Bit32Array constructor.
     */
    public Bit32Array(IBinaryComparator<IBit32Array> comparator) {
        this(
            0,
            comparator);
    }

    /**
     * The Bit32Array constructor.
     */
    public Bit32Array(
        int data,
        IBinaryComparator<IBit32Array> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a bit array.");

        this.data = data;
        this.comparator = comparator;
    }

    /**
     * The Bit32Array copy constructor.
     */
    public Bit32Array(IBit32Array array) {
        this(
            array,
            Bit32Array.defaultComparator());
    }

    /**
     * The Bit32Array copy constructor.
     */
    public Bit32Array(
        IBit32Array array,
        IBinaryComparator<IBit32Array> comparator) {

        Conditions.validateNotNull(
            array,
            "The bit array.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a bit array.");

        this.data = array.toInteger();
        this.comparator = comparator;
    }

    /**
     * Turns on a bit at the specified index.
     */
    @Override
    public void turnOn(int index) {
        this.set(index, 1);
    }

    /**
     * Turns off a bit at the specified index.
     */
    @Override
    public void turnOff(int index) {
        this.set(index, 0);
    }

    /**
     * Checks whether a bit at the specified index is on.
     */
    @Override
    public boolean isOn(int index) {
        return this.get(index) != 0;
    }

    /**
     * Checks whether a bit at the specified index is off.
     */
    @Override
    public boolean isOff(int index) {
        return this.get(index) == 0;
    }

    /**
     * Sets a value of a bit at the specified index.
     */
    @Override
    public void set(int index, int value) {
        this.validateIndex(index);

        int mask = 1 << index;

        if (Bits.isOne(value)) {
            this.data |= mask;
        }
        else {
            int invertMask = ~mask;
            this.data &= invertMask;
        }
    }

    /**
     * Gets a value of a bit at the specified index.
     */
    @Override
    public int get(int index) {
        this.validateIndex(index);

        int mask = 1 << index;

        int bitValue = Bits.bitValue(this.data & mask);
        assert(Bits.isBitValue(bitValue));

        return bitValue;
    }

    /**
     * Sets the bit at the specified index to the complement of its current value.
     */
    @Override
    public void flip(int index) {
        this.validateIndex(index);

        int mask = 1 << index;

        this.data ^= mask;
    }

    /**
     * Returns the number of bits set to true in this bit array.
     */
    @Override
    public int cardinality() {
        int numberOfBitsOn = 0;

        int currValue = this.data;

        while (currValue != 0) {
            if ((currValue & 1) == 1) {
                ++numberOfBitsOn;
            }
        }

        return numberOfBitsOn;
    }

    /**
     * Sets all the bits to false.
     */
    @Override
    public void clear() {
        this.data = 0;
    }

    /**
     * Gets the size of the bit array.
     */
    @Override
    public int size() {
        return Bit32Array.Size;
    }

    /**
     * Checks whether the bit array is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Performs a logical AND.
     */
    @Override
    public void and(IBit32Array other) {
        this.operate(BinaryBitOperator.And, other);
    }

    /**
     * Performs a logical OR.
     */
    @Override
    public void or(IBit32Array other) {
        this.operate(BinaryBitOperator.Or, other);
    }

    /**
     * Performs a logical XOR.
     */
    @Override
    public void xor(IBit32Array other) {
        this.operate(BinaryBitOperator.Xor, other);
    }

    /**
     * Performs a logical NOT.
     */
    @Override
    public void not() {
        this.operate(UnaryBitOperator.Not);
    }

    /**
     * Performs a logical bit operator.
     */
    @Override
    public void operate(BinaryBitOperator bitOperator, IBit32Array other) {
        this.data = bitOperator.evaluate(this.data, other.toInteger());
    }

    /**
     * Performs a logical bit operator.
     */
    @Override
    public void operate(UnaryBitOperator bitOperator) {
        this.data = bitOperator.evaluate(this.data);
    }

    /**
     * Performs a logical AND on the specified index.
     */
    @Override
    public void and(int index, int value) {
        this.operate(BinaryBitOperator.And, index, value);
    }

    /**
     * Performs a logical OR on the specified index.
     */
    @Override
    public void or(int index, int value) {
        this.operate(BinaryBitOperator.Or, index, value);
    }

    /**
     * Performs a logical XOR on the specified index.
     */
    @Override
    public void xor(int index, int value) {
        this.operate(BinaryBitOperator.Xor, index, value);
    }

    /**
     * Performs a logical NOT on the specified index.
     */
    @Override
    public void not(int index) {
        this.operate(UnaryBitOperator.Not, index);
    }

    /**
     * Performs a logical bit operator on the specified index.
     */
    @Override
    public void operate(BinaryBitOperator bitOperator, int index, int value) {
        Conditions.validateNotNull(
            bitOperator,
            "The bit operator.");

        int newValue = bitOperator.evaluate(this.get(index), value);
        this.set(index, newValue);
    }

    /**
     * Performs a logical bit operator on the specified index.
     */
    @Override
    public void operate(UnaryBitOperator bitOperator, int index) {
        int value = this.get(index);
        int newValue = bitOperator.evaluateBit(value);
        this.set(index, newValue);
    }

    /**
     * Converts the bits to an integer.
     */
    @Override
    public int toInteger() {
        return this.data;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<Boolean> getIterator() {
        return Bit32ArrayIterator.of(this);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<Boolean> getReverseIterator() {
        return Bit32ArrayReverseIterator.of(this);
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getIterator());
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.comparator.getHashCode(this);
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IBit32Array other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IBit32Array other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IBit32Array> defaultComparator() {
        return new Bit32Array.Comparator();
    }

    /**
     * The Comparator class implements a comparator of a bit array.
     */
    public static final class Comparator extends AbstractBinaryComparator<IBit32Array> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IBit32Array obj) {
            return new HashCodeBuilder(3, 5)
                .withInteger(obj.toInteger())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IBit32Array lhs, IBit32Array rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withInteger(lhs.toInteger(), rhs.toInteger())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IBit32Array lhs, IBit32Array rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withInteger(lhs.toInteger(), rhs.toInteger())
                .build();
        }
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index) {
        int startIndex = 0;
        int endIndex = Bit32Array.Size - 1;
        Arrays.validateIndex(index, startIndex, endIndex);
    }
}
