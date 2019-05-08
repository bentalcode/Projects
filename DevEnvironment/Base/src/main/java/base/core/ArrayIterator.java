package base.core;

import java.util.Iterator;

/**
 * The ArrayIterator class implements an iterator of an array.
 */
public class ArrayIterator<T> implements Iterator<T>, Iterable<T> {
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
        this.position = 0;
    }

    /**
     * Gets the iterator for iterating over the collection.
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

    /**
     * Removes the current element.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException();
    }
}