package base.core;

import base.interfaces.IIterator;

/**
 * The ArrayIterator class implements an iterator of an array.
 */
public class ArrayIterator<T> implements IIterator<T> {
    private final T[] array;
    private int position;

    /**
     * Creates a new iterator for an array.
     */
    public static <T> IIterator<T> of(T[] array) {
        return new ArrayIterator<>(array);
    }

    /**
     * The ArrayIterator constructor.
     */
    private ArrayIterator(T[] array) {
        this.array = array;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.array != null && this.position < this.array.length;
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
     * Resets the iterator.
     */
    @Override
    public void reset() {
        if (this.array != null) {
            this.position = 0;
        }
        else {
            this.position = -1;
        }
    }
}