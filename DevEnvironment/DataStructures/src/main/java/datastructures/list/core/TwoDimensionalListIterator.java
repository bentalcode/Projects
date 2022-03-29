package datastructures.list.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.list.interfaces.IList;

/**
 * The TwoDimensionalListIterator class implements an iterator of a two-dimensional list.
 */
public class TwoDimensionalListIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IList<IList<T>> data;
    private final int rows;
    private int rowIndex;
    private int columnIndex;

    /**
     * Creates a new iterator of a two-dimensional list.
     */
    public static <T extends Comparable<T>> IIterator<T> make(IList<IList<T>> data) {
        return new TwoDimensionalListIterator<>(data);
    }

    /**
     * The TwoDimensionalArrayIterator constructor.
     */
    private TwoDimensionalListIterator(IList<IList<T>> data) {
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
        return this.rowIndex < this.rows && this.columnIndex < this.columnSize(this.rowIndex);
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
     * Gets the size of a specific column.
     */
    private int columnSize(int rowIndex) {
        return this.data.get(rowIndex).size();
    }

    /**
     * Gets a value od a specific position.
     */
    private T get(int rowIndex, int columnIndex) {
        assert(rowIndex >= 0 && rowIndex < this.rows);
        assert(columnIndex >= 0 && columnIndex < this.columnSize(rowIndex));

        return this.data.get(rowIndex).get(columnIndex);
    }
}