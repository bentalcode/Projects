package base.core;

import base.interfaces.IIterator;
import java.util.List;

/**
 * The ReverseIterator class implements a reverse iterator.
 */
public class ReverseIterator<T> implements IIterator<T> {
    private final List<T> list;
    private int position;

    /**
     * The ReverseIterator constructor.
     */
    public ReverseIterator(List<T> list) {
        Conditions.validateNotNull(
            list,
            "The list to iterate in reverse.");

        this.list = list;

        this.reset();
    }

    /**
     * Gets an iterator for iterating over a collection.
     */
    @Override
    public IIterator<T> iterator() {
        this.reset();
        return this;
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
        this.position = list.size() - 1;
    }
}