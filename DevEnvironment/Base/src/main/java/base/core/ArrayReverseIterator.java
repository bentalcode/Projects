package base.core;

import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;

/**
 * The ArrayReverseIterator class implements a reverse iterator of an array.
 */
public class ArrayReverseIterator<T> implements IReverseIterator<T> {
    private final T[] array;
    private final int startIndex;
    private final int endIndex;
    private int position;

    /**
     * Creates a new reverse iterator for an array.
     */
    public static <T> IReverseIterator<T> of(T[] array) {
        return new ArrayReverseIterator<>(array, 0, (array != null) ? array.length - 1 : -1);
    }

    /**
     * Creates a new reverse iterator for a sub array.
     */
    public static <T> IReverseIterator<T> of(T[] array, int startIndex, int endIndex) {
        return new ArrayReverseIterator<>(array, startIndex, endIndex);
    }

    /**
     * The ArrayReverseIterator constructor.
     */
    private ArrayReverseIterator(T[] array, int startIndex, int endIndex) {
        this.array = array;
        this.startIndex = startIndex;
        this.endIndex = endIndex;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.position >= 0 && this.position <= this.endIndex;
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
        if (this.array != null && startIndex <= endIndex) {
            this.position = endIndex;
        }
        else {
            this.position = -1;
        }
    }
}
