package testbase.core;

import java.util.Iterator;

/**
 * The ArrayIterator class implements an iterator of an array.
 */
public class ArrayIterator<T> implements Iterable<T>, Iterator<T> {
    private final T[] array;
    private int position;

    /**
     * The ReverseIterator constructor.
     */
    public ArrayIterator(T[] array) {
        Conditions.validateNotNull(
            array,
            "The array to iterate.");

        this.array = array;
    }

    /**
     * Gets an iterator for iterating over a collection.
     */
    @Override
    public Iterator<T> iterator() {
        this.position = 0;
        return this;
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.position < this.array.length;
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.array[this.position];
        ++this.position;

        return currElement;
    }
}