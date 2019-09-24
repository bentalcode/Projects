package base.core;

import base.interfaces.IIterator;
import java.util.List;

/**
 * The TwoDimensionalListIterator class implements an iterator of a two dimensional list.
 */
public final class TwoDimensionalListIterator<T> implements IIterator<T> {
    private final List<List<T>> data;
    private final int rows;
    private int rowIndex;
    private int columnIndex;

    /**
     * Creates a new iterator of an array.
     */
    public static <T> IIterator<T> of(List<List<T>> data) {
        return new TwoDimensionalListIterator<>(data);
    }

    /**
     * The TwoDimensionalArrayIterator constructor.
     */
    private TwoDimensionalListIterator(List<List<T>> data) {
        Conditions.validateNotNull(
            data,
            "The two dimensional list to iterate.");

        this.data = data;
        this.rows = data.size();

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
        return this.data.get(rowIndex).size();
    }

    /**
     * Gets a value od a specific position.
     */
    private T get(int rowIndex, int columnIndex) {
        assert(rowIndex >= 0 && rowIndex < this.rows);
        assert(columnIndex >= 0 && columnIndex < this.rowSize(rowIndex));

        List<T> row = this.data.get(rowIndex);

        return row.get(columnIndex);
    }
}