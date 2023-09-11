package base.core;

import base.interfaces.IReverseIterator;
import java.util.List;

/**
 * The ListReverseIterator class implements a reverse iterator of a list.
 */
public class ListReverseIterator<T> implements IReverseIterator<T> {
    private final List<T> data;
    private int position;

    /**
     * Creates a new reverse iterator of a list.
     */
    public static <T> IReverseIterator<T> make(List<T> data) {
        return new ListReverseIterator<>(data);
    }

    /**
     * The ListReverseIterator constructor.
     */
    private ListReverseIterator(List<T> data) {
        Conditions.validateNotNull(
            data,
            "The list to iterate in reverse.");

        this.data = data;

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

        T currElement = this.data.get(this.position);
        --this.position;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.position = this.data.size() - 1;
    }
}