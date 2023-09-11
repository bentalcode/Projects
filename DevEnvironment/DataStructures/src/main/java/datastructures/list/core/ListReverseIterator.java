package datastructures.list.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.list.interfaces.IList;

/**
 * The ListReverseIterator class implements a reverse iterator of a list.
 */
public class ListReverseIterator<T extends Comparable<T>> implements IReverseIterator<T> {
    private final IList<T> list;
    private int position;

    /**
     * Creates a new reverse iterator of a list.
     */
    public static <T extends Comparable<T>> IReverseIterator<T> make(IList<T> list) {
        return new ListReverseIterator<>(list);
    }

    /**
     * The ListReverseIterator constructor.
     */
    private ListReverseIterator(IList<T> list) {
        Conditions.validateNotNull(
            list,
            "The list to iterate in reverse.");

        this.list = list;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.position >= 0;
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.list.get(this.position);
        --this.position;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.position = this.list.size() - 1;
    }
}