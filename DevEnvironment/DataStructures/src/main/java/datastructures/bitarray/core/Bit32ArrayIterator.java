package datastructures.bitarray.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.bitarray.interfaces.IBit32Array;

/**
 * The Bit32ArrayIterator class implements an iterator of a bit 32 array.
 */
public final class Bit32ArrayIterator implements IIterator<Boolean> {
    private final IBit32Array bitArray;
    private int currIndex;

    /**
     * Creates an iterator of a bit 32 array.
     */
    public static IIterator<Boolean> make(IBit32Array bitArray) {
        return new Bit32ArrayIterator(bitArray);
    }

    /**
     * The BitArrayIterator constructor.
     */
    private Bit32ArrayIterator(IBit32Array bitArray) {
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
