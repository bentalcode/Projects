package datastructures.bitarray.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.bitarray.interfaces.IBitArray;

/**
 * The BitArrayIterator class implements an iterator of a bit array.
 */
public final class BitArrayIterator implements IIterator<Boolean> {
    private final IBitArray bitArray;
    private int currIndex;

    /**
     * Creates an iterator of a bit array.
     */
    public static IIterator<Boolean> make(IBitArray bitArray) {
        return new BitArrayIterator(bitArray);
    }

    /**
     * The BitArrayIterator constructor.
     */
    private BitArrayIterator(IBitArray bitArray) {
        Conditions.validateNotNull(
            bitArray,
            "The bit array.");

        this.bitArray = bitArray;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currIndex < this.bitArray.size();
    }

    /**
     * Gets the next element.
     */
    @Override
    public Boolean next() {
        assert(this.hasNext());

        boolean currElement = this.bitArray.isOn(this.currIndex);
        ++this.currIndex;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currIndex = 0;
    }
}
