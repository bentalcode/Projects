package datastructures.bitarray.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.bitarray.interfaces.IBit32Array;

/**
 * The Bit32ArrayReverseIterator class implements a reverse iterator of a bit 32 array.
 */
public final class Bit32ArrayReverseIterator implements IReverseIterator<Boolean> {
    private final IBit32Array bitArray;
    private int currIndex;

    /**
     * Creates an iterator of a bit 32 array.
     */
    public static IReverseIterator<Boolean> make(IBit32Array bitArray) {
        return new Bit32ArrayReverseIterator(bitArray);
    }

    /**
     * The BitArrayIterator constructor.
     */
    private Bit32ArrayReverseIterator(IBit32Array bitArray) {
        Conditions.validateNotNull(
            bitArray,
            "The bit 32 array.");

        this.bitArray = bitArray;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currIndex >= 0;
    }

    /**
     * Gets the next element.
     */
    @Override
    public Boolean next() {
        assert(this.hasNext());

        boolean currElement = this.bitArray.isOn(this.currIndex);
        --this.currIndex;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currIndex = this.bitArray.size() - 1;
    }
}
