package base.core;

import java.util.Iterator;
import java.util.List;

/**
 * The ReverseIterator class implements a reverse iterator.
 */
public class ReverseIterator<T> implements Iterable<T>, Iterator<T> {
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
        this.position = list.size() - 1;
    }

    /**
     * Gets an iterator for iterating over a collection.
     */
    @Override
    public Iterator<T> iterator() {
        this.position = list.size() - 1;
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
     * Removes the current element.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException();
    }
}