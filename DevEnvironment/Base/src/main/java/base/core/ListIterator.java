package base.core;

import base.interfaces.IIterator;
import java.util.List;

/**
 * The ListIterator class implements an iterator of a list.
 */
public class ListIterator<T> implements IIterator<T> {
    private final List<T> list;
    private int position;

    /**
     * Creates a new iterator of a list.
     */
    public static <T> IIterator<T> make(List<T> list) {
        return new ListIterator<>(list);
    }

    /**
     * The ListIterator constructor.
     */
    private ListIterator(List<T> list) {
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
        return this.position < this.list.size();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.list.get(this.position);
        ++this.position;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.position = 0;
    }
}