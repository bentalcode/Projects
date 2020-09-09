package datastructures.bitarray.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;

/**
 * The IBitArray interface defines a bit array, which manages a compact array of bits.
 */
public interface IBitArray extends
    ISizableCollection,
    IIterable<Boolean>,
    IReverseIterable<Boolean>,
    IUnaryComparator<IBitArray> {

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
     * Sets the bits to the complement of its current value.
     */
    void flip();

    /**
     * Sets the bit at the specified index to the complement of its current value.
     */
    void flip(int index);

    /**
     * Returns the number of bits set to true.
     */
    int cardinality();

    /**
     * Sets all the bits to false.
     */
    void clear();

    /**
     * Sets all the bits at the specified range to false.
     */
    void clear(int startIndex, int endIndex);

    /**
     * Sets all the bits to true.
     */
    void enable();

    /**
     * Sets all the bits at the specified range to true.
     */
    void enable(int startIndex, int endIndex);

    /**
     * Performs a logical AND on this bit array with the other bit array.
     */
    void andOperator(IBitArray other);

    /**
     * Performs a logical OR on this bit array with the other bit array.
     */
    void orOperator(IBitArray other);

    /**
     * Performs a logical XOR on this bit array with the other bit array.
     */
    void xorOperator(IBitArray other);

    /**
     * Performs a logical NOT on this bit array.
     */
    void notOperator();

    /**
     * Performs a logical bit operator on this bit array with the other bit array.
     */
    void operate(BinaryBitOperator bitOperator, IBitArray other);

    /**
     * Performs a logical bit operator on this bit array.
     */
    void operate(UnaryBitOperator bitOperator);

    /**
     * Converts the bits to a native array.
     */
    int[] toArray();

    /**
     * Converts the bits to a 32 bit array.
     */
    IBit32Array[] toBit32Array();
}
