package base.core;

import base.interfaces.IIterator;

/**
 * The IntegerArrayIterator class implements an iterator of an integer array.
 */
public class IntegerArrayIterator implements IIterator<Integer> {
    private final int[] array;
    private final int startIndex;
    private final int endIndex;
    private int position;

    /**
     * Creates a new iterator for an array.
     */
    public static IIterator<Integer> of(int[] array) {
        return new IntegerArrayIterator(array, 0, (array != null) ? array.length - 1 : -1);
    }

    /**
     * Creates a new iterator for a sub array.
     */
    public static IIterator<Integer> of(int[] array, int startIndex, int endIndex) {
        return new IntegerArrayIterator(array, startIndex, endIndex);
    }

    /**
     * The IntegerArrayIterator constructor.
     */
    private IntegerArrayIterator(int[] array, int startIndex, int endIndex) {
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
    public Integer next() {
        assert(this.hasNext());

        int currElement = this.array[this.position];
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
