package datastructures.list.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.list.interfaces.ICircularList;

/**
 * The CircularListIterator class implements an iterator of a circular list.
 */
public final class CircularListIterator<T extends Comparable<T>> implements IIterator<T> {
    private final ICircularList<T> circularList;
    private int currIndex;

    /**
     * Creates an iterator of a circular list.
     */
    public static <T extends Comparable<T>> IIterator<T> of(ICircularList<T> circularList) {
        return new CircularListIterator<>(circularList);
    }

    /**
     * The CircularListIterator constructor.
     */
    private CircularListIterator(ICircularList<T> circularList) {
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
        return this.currIndex < this.circularList.size();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.circularList.get(this.currIndex);
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
