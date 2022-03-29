package base.core;

import base.interfaces.IIterator;

/**
 * The TwoDimensionalArrayIterator class implements an iterator of a two-dimensional array.
 */
public final class TwoDimensionalArrayIterator<T> implements IIterator<T> {
    private final T[][] data;
    private final int rowsSize;
    private int rowIndex;
    private int columnIndex;

    /**
     * Creates a new iterator of a two-dimensional array.
     */
    public static <T> IIterator<T> make(T[][] data) {
        return new TwoDimensionalArrayIterator<>(data);
    }

    /**
     * The TwoDimensionalArrayIterator constructor.
     */
    private TwoDimensionalArrayIterator(T[][] data) {
        Conditions.validateNotNull(
            data,
            "The array to iterate.");

        this.data = data;
        this.rowsSize = data.length;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.rowIndex < this.rowsSize && this.columnIndex < this.columnSize(this.rowIndex);
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
        if (this.columnIndex < this.columnSize(this.rowIndex) - 1) {
            ++this.columnIndex;
        }
        else {
            this.columnIndex = 0;
            ++this.rowIndex;
        }
    }

    /**
     * Gets the column size of a specific row.
     */
    private int columnSize(int rowIndex) {
        return this.data[rowIndex].length;
    }

    /**
     * Gets a value of a specific position.
     */
    private T get(int rowIndex, int columnIndex) {
        assert(rowIndex >= 0 && rowIndex < this.rowsSize);
        assert(columnIndex >= 0 && columnIndex < this.data[rowIndex].length);

        return this.data[rowIndex][columnIndex];
    }
}