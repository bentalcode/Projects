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
import datastructures.bitarray.interfaces.IBitArray;
import datastructures.bitarray.interfaces.UnaryBitOperator;
import base.core.Collections;

/**
 * The BitArray class implements a bit array for managing a compact array of bits.
 * The BitArray class uses internally for each unit the Bit32Array class.
 */
public final class BitArray implements IBitArray {
    private static final int unitSizeInBits = IBit32Array.sizeInBits;

    private final IBit32Array[] data;
    private final int size;
    private final IBinaryComparator<IBitArray> comparator;

    /**
     * Creates a a bit array.
     */
    public static IBitArray make(int numberOfBits) {
        return new BitArray(numberOfBits, defaultComparator());
    }

    /**
     * Copies a bit array.
     */
    public static IBitArray copy(IBitArray bitArray) {
        return new BitArray(bitArray, defaultComparator());
    }

    /**
     * The BitArray constructor.
     */
    public BitArray(
        int numberOfBits,
        IBinaryComparator<IBitArray> comparator) {

        Conditions.validate(
            numberOfBits > 0,
            "The number of bits has to be positive.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a bit array.");

        this.data = this.createBitArray(numberOfBits);
        this.size = numberOfBits;
        this.comparator = comparator;
    }

    /**
     * The BitArray copy constructor.
     */
    private BitArray(
        IBitArray array,
        IBinaryComparator<IBitArray> comparator) {

        Conditions.validateNotNull(
            array,
            "The array to copy.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a bit array.");

        this.data = this.copyBitArray(array.toBit32Array());
        this.size = array.size();
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

        int unitIndex = this.unitIndexOf(index);
        int bitIndex = this.bitIndexOf(index);

        this.data[unitIndex].set(bitIndex, value);
    }

    /**
     * Gets a value of a bit at the specified index.
     */
    @Override
    public int get(int index) {
        this.validateIndex(index);

        int unitIndex = this.unitIndexOf(index);
        int bitIndex = this.bitIndexOf(index);

        int bitValue = this.data[unitIndex].get(bitIndex);
        assert(Bits.isBitValue(bitValue));

        return bitValue;
    }

    /**
     * Sets the bits to the complement of its current value.
     */
    @Override
    public void flip() {
        this.operate(UnaryBitOperator.Not);
    }

    /**
     * Sets the bit at the specified index to the complement of its current value.
     */
    @Override
    public void flip(int index) {
        this.validateIndex(index);

        int unitIndex = this.unitIndexOf(index);
        int bitIndex = this.bitIndexOf(index);

        this.data[unitIndex].flip(bitIndex);
    }

    /**
     * Returns the number of bits set to true.
     */
    @Override
    public int cardinality() {
        int numberOfBitsOn = 0;

        int numberOfUnits = this.numberOfUnits();
        int unitIndex = 0;

        //
        // Operate on the unit level from unit {0...N-1}...
        //
        while (unitIndex < numberOfUnits - 1) {
            numberOfBitsOn += this.data[unitIndex].cardinality();
            
            ++unitIndex;
        }

        //
        // Operate on the last unit either as a whole or bit by bit...
        //
        int lastUnitBitStartIndex = 0;
        int lastUnitBitEndIndex = this.bitIndexOf(this.size - 1);
        
        numberOfBitsOn += this.data[unitIndex].cardinality(lastUnitBitStartIndex, lastUnitBitEndIndex);

        return numberOfBitsOn;
    }

    /**
     * Sets all the bits to false.
     */
    @Override
    public void clear() {
        int numberOfUnits = this.numberOfUnits();

        //
        // Operate on the unit level from unit {0...N-1}...
        //
        int unitIndex = 0;

        while (unitIndex < numberOfUnits - 1) {
            this.data[unitIndex].clear();
            ++unitIndex;
        }

        //
        // Operate on the last unit either as a whole or bit by bit...
        //
        int lastUnitBitStartIndex = 0;
        int lastUnitBitEndIndex = this.bitIndexOf(this.size() - 1);

        this.data[unitIndex].clear(lastUnitBitStartIndex, lastUnitBitEndIndex);
    }

    /**
     * Sets all the bits at the specified range to false.
     */
    @Override
    public void clear(int startIndex, int endIndex) {
        this.validateIndex(startIndex);
        this.validateIndex(endIndex);

        assert(startIndex <= endIndex);

        if (startIndex > endIndex) {
            return;
        }

        int startUnitIndex = this.unitIndexOf(startIndex);
        int startBitIndex = this.bitIndexOf(startIndex);

        int endUnitIndex = this.unitIndexOf(endIndex);
        int endBitIndex = this.bitIndexOf(endIndex);

        int numberOfUnits = Dimensions.indexes(startUnitIndex, endUnitIndex);

        if (numberOfUnits == 0) {
            return;
        }

        if (numberOfUnits == 1) {
            //
            // Update the single unit either as a whole or bit by bit...
            //
            this.data[startUnitIndex].clear(startBitIndex, endBitIndex);
        }
        else {
            //
            // Update the start unit either as a whole or bit by bit...
            //
            this.data[startUnitIndex].clear(startBitIndex, BitArray.unitSizeInBits - 1);

            //
            // Update the middle units as a whole...
            //
            for (int unitIndex = startUnitIndex + 1; unitIndex <= endUnitIndex - 1; ++unitIndex) {
                this.data[unitIndex].clear();
            }

            //
            // Update the end unit either as a whole or bit by bit...
            //
            this.data[endUnitIndex].clear(0, endBitIndex);
        }
    }

    /**
     * Sets all the bits to true.
     */
    @Override
    public void enable() {
        int numberOfUnits = this.numberOfUnits();

        //
        // Operate on the unit level from unit {0...N-1}...
        //
        int unitIndex = 0;

        while (unitIndex < numberOfUnits - 1) {
            this.data[unitIndex].enable();
            ++unitIndex;
        }

        //
        // Operate on the last unit either as a whole or bit by bit...
        //
        int lastUnitBitStartIndex = 0;
        int lastUnitBitEndIndex = this.bitIndexOf(this.size - 1);

        this.data[unitIndex].enable(lastUnitBitStartIndex, lastUnitBitEndIndex);
    }

    /**
     * Sets all the bits at the specified range to false.
     */
    @Override
    public void enable(int startIndex, int endIndex) {
        this.validateIndex(startIndex);
        this.validateIndex(endIndex);

        assert(startIndex <= endIndex);

        if (startIndex > endIndex) {
            return;
        }

        int startUnitIndex = this.unitIndexOf(startIndex);
        int startBitIndex = this.bitIndexOf(startIndex);

        int endUnitIndex = this.unitIndexOf(endIndex);
        int endBitIndex = this.bitIndexOf(endIndex);

        int numberOfUnits = Dimensions.indexes(startUnitIndex, endUnitIndex);

        if (numberOfUnits == 0) {
            return;
        }

        if (numberOfUnits == 1) {
            //
            // Update the single unit either as a whole or bit by bit...
            //
            this.data[startUnitIndex].enable(startBitIndex, endBitIndex);
        }
        else {
            //
            // Update the start unit either as a whole or bit by bit...
            //
            this.data[startUnitIndex].enable(startBitIndex, BitArray.unitSizeInBits - 1);

            //
            // Update the middle units as a whole...
            //
            for (int unitIndex = startUnitIndex + 1; unitIndex <= endUnitIndex - 1; ++unitIndex) {
                this.data[unitIndex].enable();
            }

            //
            // Update the end unit either as a whole or bit by bit...
            //
            this.data[endUnitIndex].enable(0, endBitIndex);
        }
    }

    /**
     * Gets the size of the bit array.
     */
    @Override
    public int size() {
        return this.size;
    }

    /**
     * Checks whether the bit array is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Performs a logical AND on this bit array with the other bit array.
     */
    @Override
    public void andOperator(IBitArray other) {
        this.operate(BinaryBitOperator.And, other);
    }

    /**
     * Performs a logical OR on this bit array with the other bit array.
     */
    @Override
    public void orOperator(IBitArray other) {
        this.operate(BinaryBitOperator.Or, other);
    }

    /**
     * Performs a logical XOR on this bit array with the other bit array.
     */
    @Override
    public void xorOperator(IBitArray other) {
        this.operate(BinaryBitOperator.Xor, other);
    }

    /**
     * Performs a logical NOT on this bit array.
     */
    @Override
    public void notOperator() {
        this.operate(UnaryBitOperator.Not);
    }

    /**
     * Performs a logical bit operator on this bit array with the other bit array.
     */
    @Override
    public void operate(BinaryBitOperator bitOperator, IBitArray other) {
        Conditions.validateNotNull(
            bitOperator,
            "The bit operator.");

        Conditions.validateNotNull(
            other,
            "The other bit array.");

        int lhsSize = this.size();
        int rhsSize = other.size();

        IBit32Array[] lhsData = this.data;
        IBit32Array[] rhsData = other.toBit32Array();

        int lhsNumOfUnits = lhsData.length;
        int rhsNumOfUnits = rhsData.length;

        int numberOfBits = Math.min(lhsSize, rhsSize);
        int numberOfUnits = Math.min(lhsNumOfUnits, rhsNumOfUnits);

        //
        // Operate on the unit level from unit {0...N-1}...
        //
        int unitIndex = 0;

        while (unitIndex < numberOfUnits - 1) {
            lhsData[unitIndex].operate(bitOperator, rhsData[unitIndex]);
            ++unitIndex;
        }

        //
        // Operate on the last unit either as a whole or bit by bit...
        //
        int lastUnitBitStartIndex = 0;
        int lastUnitBitEndIndex = this.bitIndexOf(numberOfBits - 1);

        if (lastUnitBitEndIndex == BitArray.unitSizeInBits -1) {
            lhsData[unitIndex].operate(bitOperator, rhsData[unitIndex]);
        }
        else {
            for (int bitIndex = lastUnitBitStartIndex; bitIndex <= lastUnitBitEndIndex; ++bitIndex) {
                lhsData[unitIndex].operate(bitOperator, bitIndex, rhsData[unitIndex].get(bitIndex));
            }
        }
    }

    /**
     * Performs a logical bit operator on this bit array.
     */
    @Override
    public void operate(UnaryBitOperator bitOperator) {
        Conditions.validateNotNull(
            bitOperator,
            "The bit operator.");

        int numberOfUnits = this.numberOfUnits();

        //
        // Operate on the unit level from unit {0...N-1}...
        //
        int unitIndex = 0;

        while (unitIndex < numberOfUnits - 1) {
            this.data[unitIndex].operate(bitOperator);
            ++unitIndex;
        }

        //
        // Operate on the last unit either as a whole or bit by bit...
        //
        int lastUnitBitStartIndex = 0;
        int lastUnitBitEndIndex = this.bitIndexOf(this.size - 1);

        if (lastUnitBitEndIndex == BitArray.unitSizeInBits -1) {
            this.data[unitIndex].operate(bitOperator);
        }
        else {
            for (int bitIndex = lastUnitBitStartIndex; bitIndex <= lastUnitBitEndIndex; ++bitIndex) {
                this.data[unitIndex].operate(bitOperator, bitIndex);
            }
        }
    }

    /**
     * Converts the bits to a native array.
     */
    @Override
    public int[] toArray() {
        int[] array = new int[this.data.length];

        for (int unitIndex = 0; unitIndex < this.data.length; ++unitIndex) {
            array[unitIndex] = this.data[unitIndex].toInteger();
        }

        return array;
    }

    /**
     * Converts the bits to a 32 bit array.
     */
    @Override
    public IBit32Array[] toBit32Array() {
        return this.data;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<Boolean> getIterator() {
        return BitArrayIterator.make(this);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<Boolean> getReverseIterator() {
        return BitArrayReverseIterator.make(this);
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
    public boolean isEqual(IBitArray other) {
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
    public int compareTo(IBitArray other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IBitArray> defaultComparator() {
        return new BitArray.Comparator();
    }

    /**
     * The Comparator class implements a comparator of a bit array.
     */
    public static final class Comparator extends AbstractBinaryComparator<IBitArray> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IBitArray obj) {
            return new HashCodeBuilder(293, 307)
                .withIntegerArray(obj.toArray())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IBitArray lhs, IBitArray rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withIntegerArray(lhs.toArray(), rhs.toArray())
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
        public int compareTo(IBitArray lhs, IBitArray rhs) {
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
                .withIntegerArray(lhs.toArray(), rhs.toArray())
                .build();
        }
    }

    /**
     * Creates a bit array.
     */
    private IBit32Array[] createBitArray(int numberOfBits) {
        assert(numberOfBits > 0);

        if (numberOfBits <= 0) {
            return null;
        }

        int numberOfUnits = this.numberOfUnits(numberOfBits);
        IBit32Array[] data = new IBit32Array[numberOfUnits];

        for (int i = 0; i < data.length; ++i) {
            data[i] = Bit32Array.make();
        }

        return data;
    }

    /**
     * Copies a bit array.
     */
    private static IBit32Array[] copyBitArray(IBit32Array[] originData) {
        IBit32Array[] data = new IBit32Array[originData.length];

        for (int i = 0; i < data.length; ++i) {
            data[i] = Bit32Array.copy(originData[i]);
        }

        return data;
    }

    /**
     * Gets the number of units.
     */
    private int numberOfUnits() {
        return this.data.length;
    }

    /**
     * Calculates the number of units.
     */
    private int numberOfUnits(int numberOfBits) {
        return (numberOfBits % BitArray.unitSizeInBits) == 0 ?
            (numberOfBits / BitArray.unitSizeInBits) :
            (numberOfBits / BitArray.unitSizeInBits) + 1;
    }

    /**
     * Calculates the index of a unit.
     */
    private int unitIndexOf(int index) {
        return index / BitArray.unitSizeInBits;
    }

    /**
     * Calculates the index of a bit in a unit.
     */
    private int bitIndexOf(int index) {
        return index % BitArray.unitSizeInBits;
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index) {
        int startIndex = 0;
        int endIndex = this.size - 1;
        Indexes.validateIndex(index, startIndex, endIndex);
    }
}
