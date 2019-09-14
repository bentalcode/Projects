package datastructures.array.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.array.interfaces.ICircularArray;

/**
 * The CircularArrayReverseIterator class implements a reverse iterator of a circular array.
 */
public final class CircularArrayReverseIterator<T extends Comparable<T>> implements IReverseIterator<T> {
    private final ICircularArray<T> circularArray;
    private int currIndex;

    /**
     * The CircularArrayReverseIterator constructor.
     */
    public CircularArrayReverseIterator(ICircularArray<T> circularArray) {
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
        return this.currIndex >= 0;
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.circularArray.get(this.currIndex);
        --this.currIndex;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currIndex = this.circularArray.size() - 1;
    }
}
