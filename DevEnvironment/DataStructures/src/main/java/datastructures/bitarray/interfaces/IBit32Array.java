package datastructures.bitarray.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IPrimitiveSize;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;

/**
 * The IBit32Array interface defines a bit array of size 32.
 */
public interface IBit32Array extends
    ISizableCollection,
    IIterable<Boolean>,
    IReverseIterable<Boolean>,
    IUnaryComparator<IBit32Array> {

    int sizeInBits = IPrimitiveSize.InBits.IntegerSize;

    /**
     * Turns on a bit at the specified index.
     */
    void turnOn(int index);

    /**
     * Turns off a bit at the specified index.
     */
    void turnOff(int index);

    /**
     * Checks whether a bit at the specified index is on.
     */
    boolean isOn(int index);

    /**
     * Checks whether a bit at the specified index is off.
     */
    boolean isOff(int index);

    /**
     * Sets a value of a bit at the specified index.
     */
    void set(int index, int value);

    /**
     * Gets a value of a bit at the specified index.
     */
    int get(int index);

    /**
     * Sets the bit at the specified index to the complement of its current value.
     */
    void flip(int index);

    /**
     * Returns the number of bits set to true.
     */
    int cardinality();

    /**
     * Returns the number of bits set to true in the specified range.
     */
    int cardinality(int startIndex, int endIndex);

    /**
     * Sets all the bits to false.
     */
    void clear();

    /**
     * Sets all the bits in the specified range to false.
     */
    void clear(int startIndex, int endIndex);

    /**
     * Sets all the bits to true.
     */
    void enable();

    /**
     * Sets all the bits in the specified range to true.
     */
    void enable(int startIndex, int endIndex);

    /**
     * Performs a logical AND.
     */
    void and(IBit32Array other);

    /**
     * Performs a logical OR.
     */
    void or(IBit32Array other);

    /**
     * Performs a logical XOR.
     */
    void xor(IBit32Array other);

    /**
     * Performs a logical NOT.
     */
    void not();

    /**
     * Performs a logical bit operator.
     */
    void operate(BinaryBitOperator bitOperator, IBit32Array other);

    /**
     * Performs a logical bit operator.
     */
    void operate(UnaryBitOperator bitOperator);

    /**
     * Performs a logical AND on the specified index.
     */
    void and(int index, int value);

    /**
     * Performs a logical OR on the specified index.
     */
    void or(int index, int value);

    /**
     * Performs a logical XOR on the specified index.
     */
    void xor(int index, int value);

    /**
     * Performs a logical NOT on the specified index.
     */
    void not(int index);

    /**
     * Performs a logical bit operator on the specified index.
     */
    void operate(BinaryBitOperator bitOperator, int index, int value);

    /**
     * Performs a logical bit operator on the specified index.
     */
    void operate(UnaryBitOperator bitOperator, int index);

    /**
     * Converts the bits to an integer.
     */
    int toInteger();
}
