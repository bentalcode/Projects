package base.core;

import base.interfaces.IIterator;

/**
 * The TwoDimensionalArrayIterator class implements an iterator of a two dimensional array.
 */
public class TwoDimensionalArrayIterator<T> implements IIterator<T> {
    private final T[][] array;
    private final int rows;
    private int rowPosition;
    private int columnPosition;

    /**
     * Creates a new iterator of an array.
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

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.rowPosition < this.rows && this.columnPosition < this.rowSize(this.rowPosition);
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
        if (this.columnPosition < this.rowSize(this.rowPosition) - 1) {
            ++this.columnPosition;
        }
        else {
            this.columnPosition = 0;
            ++this.rowPosition;
        }
    }

    /**
     * Gets the size of a specific row.
     */
    private int rowSize(int rowIndex) {
        return this.array[rowIndex].length;
    }
}