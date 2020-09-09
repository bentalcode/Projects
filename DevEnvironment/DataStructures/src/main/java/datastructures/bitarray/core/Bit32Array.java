package datastructures.bitarray.core;

import base.core.AbstractBinaryComparator;
import base.core.Bits;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.Dimensions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Indexes;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.bitarray.interfaces.BinaryBitOperator;
import datastructures.bitarray.interfaces.IBit32Array;
import datastructures.bitarray.interfaces.UnaryBitOperator;
import base.core.Collections;

/**
 * The Bit32Array class implements a bit array of size 32.
 */
public final class Bit32Array implements IBit32Array {
    private static final int allBitsMask = 0xFFFFFFFF;

    private int bits;
    private final IBinaryComparator<IBit32Array> comparator;

    /**
     * Creates a bit 32 array.
     */
    public static IBit32Array make() {
        return new Bit32Array(0, Bit32Array.defaultComparator());
    }

    /**
     * Creates a bit 32 array.
     */
    public static IBit32Array make(int bits) {
        return new Bit32Array(bits, Bit32Array.defaultComparator());
    }

    /**
     * Copies a bit array.
     */
    public static IBit32Array copy(IBit32Array bitArray) {
        return new Bit32Array(bitArray, Bit32Array.defaultComparator());
    }

    /**
     * The Bit32Array constructor.
     */
    private Bit32Array(
        int bits,
        IBinaryComparator<IBit32Array> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a bit array.");

        this.bits = bits;
        this.comparator = comparator;
    }

    /**
     * The Bit32Array copy constructor.
     */
    private Bit32Array(
        IBit32Array array,
        IBinaryComparator<IBit32Array> comparator) {

        Conditions.validateNotNull(
            array,
            "The bit array to copy.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a bit array.");

        this.bits = array.toInteger();
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

        if (Bits.isOn(value)) {
            this.bits |= mask;
        }
        else {
            mask = ~mask;
            this.bits &= mask;
        }
    }

    /**
     * Gets a value of a bit at the specified index.
     */
    @Override
    public int get(int index) {
        this.validateIndex(index);

        int mask = 1 << index;

        int bitValue = Bits.bitValue(this.bits & mask);
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

        this.bits ^= mask;
    }

    /**
     * Returns the number of bits set to true.
     */
    @Override
    public int cardinality() {
        int numberOfBitsOn = 0;

        int currValue = this.bits;

        while (currValue != 0) {
            currValue = currValue & (currValue - 1);
            ++numberOfBitsOn;
        }

        return numberOfBitsOn;
    }

    /**
     * Returns the number of bits in the specified range.
     */
    @Override
    public int cardinality(int startIndex, int endIndex) {
        this.validateIndex(startIndex);
        this.validateIndex(endIndex);

        assert (startIndex <= endIndex);
        int length = Dimensions.length(startIndex, endIndex);

        if (length == 0) {
            return 0;
        }

        int numberOfBitsOn = 0;

        int currValue = this.bits;

        int currIndex = startIndex;
        currValue >>= startIndex;

        while (currValue != 0 && currIndex <= endIndex) {

            if (Bits.isOn(currValue & 1)) {
                ++numberOfBitsOn;
            }

            ++currIndex;
            currValue >>= 1;
        }

        return numberOfBitsOn;
    }

    /**
     * Sets all the bits to false.
     */
    @Override
    public void clear() {
        this.bits = 0;
    }

    /**
     * Sets all the bits at the specified range to false.
     */
    @Override
    public void clear(int startIndex, int endIndex) {
        this.validateIndex(startIndex);
        this.validateIndex(endIndex);

        assert(startIndex <= endIndex);
        int length = Dimensions.length(startIndex, endIndex);

        if (length == 0) {
            return;
        }

        if (length == IBit32Array.sizeInBits) {
            this.bits = 0;
            return;
        }

        int mask = 1 << length;
        --mask;

        mask <<= startIndex;
        mask = ~mask;

        this.bits &= mask;
    }

    /**
     * Sets all the bits to true.
     */
    @Override
    public void enable() {
        this.bits = allBitsMask;
    }

    /**
     * Sets all the bits at the specified range to true.
     */
    @Override
    public void enable(int startIndex, int endIndex) {
        this.validateIndex(startIndex);
        this.validateIndex(endIndex);

        assert(startIndex <= endIndex);
        int length = Dimensions.length(startIndex, endIndex);

        if (length == 0) {
            return;
        }

        if (length == IBit32Array.sizeInBits) {
            this.bits = allBitsMask;
            return;
        }

        int mask = 1 << length;
        --mask;

        mask <<= startIndex;

        this.bits |= mask;
    }

    /**
     * Gets the size of the bit array.
     */
    @Override
    public int size() {
        return IBit32Array.sizeInBits;
    }

    /**
     * Checks whether the bit array is empty.
     */
    @Override
    public boolean empty() {
        return false;
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
        Conditions.validateNotNull(
            bitOperator,
            "The bit binary operator.");

        Conditions.validateNotNull(
            other,
            "The other bit array.");

        this.bits = bitOperator.evaluate(this.bits, other.toInteger());
    }

    /**
     * Performs a logical bit operator.
     */
    @Override
    public void operate(UnaryBitOperator bitOperator) {
        Conditions.validateNotNull(
            bitOperator,
            "The bit unary operator.");

        this.bits = bitOperator.evaluate(this.bits);
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
            "The binary bit operator.");

        int currValue = this.get(index);
        int newValue = bitOperator.evaluate(currValue, value);
        this.set(index, newValue);
    }

    /**
     * Performs a logical bit operator on the specified index.
     */
    @Override
    public void operate(UnaryBitOperator bitOperator, int index) {
        Conditions.validateNotNull(
            bitOperator,
            "The unary bit operator.");

        int currValue = this.get(index);
        int newValue = bitOperator.evaluateBit(currValue);
        this.set(index, newValue);
    }

    /**
     * Converts the bits to an integer.
     */
    @Override
    public int toInteger() {
        return this.bits;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<Boolean> getIterator() {
        return Bit32ArrayIterator.make(this);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<Boolean> getReverseIterator() {
        return Bit32ArrayReverseIterator.make(this);
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
            return new HashCodeBuilder(281, 283)
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
        int endIndex = IBit32Array.sizeInBits - 1;

        Indexes.validateIndex(index, startIndex, endIndex);
    }
}
