package datastructures.bitarray.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.bitarray.interfaces.IBitArray;

/**
 * The BitArrayReverseIterator class implements a reverse iterator of a bit array.
 */
public final class BitArrayReverseIterator implements IReverseIterator<Boolean> {
    private final IBitArray bitArray;
    private int currIndex;

    /**
     * Creates a reverse iterator of a bit array.
     */
    public static IReverseIterator<Boolean> make(IBitArray bitArray) {
        return new BitArrayReverseIterator(bitArray);
    }

    /**
     * The BitArrayReverseIterator constructor.
     */
    private BitArrayReverseIterator(IBitArray bitArray) {
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
