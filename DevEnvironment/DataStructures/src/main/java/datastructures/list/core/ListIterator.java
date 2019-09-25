package datastructures.list.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.list.interfaces.IList;

/**
 * The ListIterator class implements an iterator of a list.
 */
public class ListIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IList<T> list;
    private int index;

    /**
     * Creates a new iterator of a list.
     */
    public static <T extends Comparable<T>> IIterator<T> of(IList<T> list) {
        return new ListIterator<>(list);
    }

    /**
     * The ListIterator constructor.
     */
    private ListIterator(IList<T> list) {
        Conditions.validateNotNull(
            list,
            "The list to iterate.");

        this.list = list;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.index < this.list.size();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.list.get(this.index);
        ++this.index;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.index = 0;
    }
}