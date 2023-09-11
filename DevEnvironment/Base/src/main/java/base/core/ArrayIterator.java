package base.core;

import base.interfaces.IIterator;

/**
 * The ArrayIterator class implements an iterator of an array.
 */
public class ArrayIterator<T> implements IIterator<T> {
    private final T[] array;
    private final int startIndex;
    private final int endIndex;
    private int position;

    /**
     * Creates a new iterator for an array.
     */
    public static <T> IIterator<T> make(T[] array) {
        return new ArrayIterator<>(array, 0, (array != null) ? array.length - 1 : -1);
    }

    /**
     * Creates a new iterator for a sub array.
     */
    public static <T> IIterator<T> make(T[] array, int startIndex, int endIndex) {
        return new ArrayIterator<>(array, startIndex, endIndex);
    }

    /**
     * The ArrayIterator constructor.
     */
    private ArrayIterator(T[] array, int startIndex, int endIndex) {
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
        ++this.position;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        if (this.array != null && startIndex <= endIndex) {
            this.position = startIndex;
        }
        else {
            this.position = -1;
        }
    }
}
