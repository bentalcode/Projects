package base.core;

import base.interfaces.ICircularArray;
import base.interfaces.IIterator;

/**
 * The CircularArrayIterator class implements an iterator of a circular array.
 */
public final class CircularArrayIterator<T extends Comparable<T>> implements IIterator<T> {
    private final ICircularArray<T> circularArray;
    private int currIndex;

    /**
     * The CircularArrayIterator constructor.
     */
    public CircularArrayIterator(ICircularArray<T> circularArray) {
        Conditions.validateNotNull(
            circularArray,
            "The circular array.");

        this.circularArray = circularArray;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currIndex < this.circularArray.length();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.circularArray.get(this.currIndex);
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
