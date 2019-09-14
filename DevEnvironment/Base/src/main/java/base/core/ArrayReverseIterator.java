package base.core;

import base.interfaces.IReverseIterator;

/**
 * The ArrayReverseIterator class implements a reverse iterator of an array.
 */
public class ArrayReverseIterator<T> implements IReverseIterator<T> {
    private final T[] array;
    private int position;

    /**
     * Creates a new reverse iterator for an array.
     */
    public static <T> IReverseIterator<T> of(T[] array) {
        return new ArrayReverseIterator<>(array);
    }

    /**
     * The ArrayReverseIterator constructor.
     */
    private ArrayReverseIterator(T[] array) {
        Conditions.validateNotNull(
            array,
            "The array to iterate in reverse.");

        this.array = array;

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

        T currElement = this.array[this.position];
        --this.position;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.position = this.array.length - 1;
    }
}