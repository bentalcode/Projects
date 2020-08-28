package datastructures.list.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.list.interfaces.ICircularList;

/**
 * The CircularListReverseIterator class implements a reverse iterator of a circular list.
 */
public final class CircularListReverseIterator<T extends Comparable<T>> implements IReverseIterator<T> {
    private final ICircularList<T> circularList;
    private int currIndex;

    /**
     * Creates a reverse iterator of a circular list.
     */
    public static <T extends Comparable<T>> IReverseIterator<T> make(ICircularList<T> circularList) {
        return new CircularListReverseIterator<>(circularList);
    }

    /**
     * The CircularListReverseIterator constructor.
     */
    private CircularListReverseIterator(ICircularList<T> circularList) {
        Conditions.validateNotNull(
            circularList,
            "The circular list.");

        this.circularList = circularList;

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

        T currElement = this.circularList.get(this.currIndex);
        --this.currIndex;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currIndex = this.circularList.size() - 1;
    }
}
