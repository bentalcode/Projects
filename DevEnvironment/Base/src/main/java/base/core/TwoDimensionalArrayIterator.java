package base.core;

import base.interfaces.IIterator;

/**
 * The TwoDimensionalArrayIterator class implements an iterator of a two dimensional array.
 */
public final class TwoDimensionalArrayIterator<T> implements IIterator<T> {
    private final T[][] array;
    private final int rows;
    private int rowIndex;
    private int columnIndex;

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
        return this.rowIndex < this.rows && this.columnIndex < this.rowSize(this.rowIndex);
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.get(this.rowIndex, this.columnIndex);

        this.moveNext();

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.rowIndex = 0;
        this.columnIndex = 0;
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.columnIndex < this.rowSize(this.rowIndex) - 1) {
            ++this.columnIndex;
        }
        else {
            this.columnIndex = 0;
            ++this.rowIndex;
        }
    }

    /**
     * Gets the size of a specific row.
     */
    private int rowSize(int rowIndex) {
        return this.array[rowIndex].length;
    }

    /**
     * Gets a value of a specific position.
     */
    private T get(int rowIndex, int columnIndex) {
        assert(rowIndex >= 0 && rowIndex < this.rows);
        assert(columnIndex >= 0 && columnIndex < this.array[rowIndex].length);

        T value = this.array[rowIndex][columnIndex];

        return value;
    }
}