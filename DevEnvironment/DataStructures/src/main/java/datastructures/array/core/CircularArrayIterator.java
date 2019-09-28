package datastructures.array.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.array.interfaces.ICircularArray;

/**
 * The CircularArrayIterator class implements an iterator of a circular array.
 */
public final class CircularArrayIterator<T extends Comparable<T>> implements IIterator<T> {
    private final ICircularArray<T> circularArray;
    private int currIndex;

    /**
     * Creates an iterator of a circular array.
     */
    public static <T extends Comparable<T>> IIterator<T> of(ICircularArray<T> circularArray) {
        return new CircularArrayIterator<>(circularArray);
    }

    /**
     * The CircularArrayIterator constructor.
     */
    private CircularArrayIterator(ICircularArray<T> circularArray) {
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
        return this.currIndex < this.circularArray.size();
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
