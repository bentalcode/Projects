package base.core;

import base.interfaces.IIterator;

/**
 * The TwoDimensionalArrayIterator class implements an iterator of two dimensional array.
 */
public class TwoDimensionalArrayIterator<T> implements IIterator<T> {
    private final T[][] array;
    private final int rows;
    private final int columns;
    private int rowPosition;
    private int columnPosition;

    /**
     * Creates a new array iterator.
     */
    public static <T> IIterator<T> of(T[][] array) {
        return new TwoDimensionalArrayIterator<>(array);
    }

    /**
     * The TwoDimensionalArrayIterator constructor.
     */
    private TwoDimensionalArrayIterator(T[][] array) {
        Conditions.validateNotNull(
            array,
            "The array to iterate.");

        this.array = array;
        this.rows = array.length;
        this.columns = array[0].length;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.rowPosition < this.rows && this.columnPosition < this.columns;
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.array[this.rowPosition][this.columnPosition];

        this.moveNext();

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.rowPosition = 0;
        this.columnPosition = 0;
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.columnPosition < this.columns - 1) {
            ++this.columnPosition;
        }
        else {
            this.columnPosition = 0;
            ++this.rowPosition;
        }
    }
}