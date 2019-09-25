package datastructures.list.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.list.interfaces.IList;

/**
 * The TwoDimensionalListIterator class implements an iterator of a two dimensional list.
 */
public class TwoDimensionalListIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IList<IList<T>> data;
    private final int rows;
    private int rowPosition;
    private int columnPosition;

    /**
     * Creates a new iterator of a two dimensional list.
     */
    public static <T extends Comparable<T>> IIterator<T> of(IList<IList<T>> data) {
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
        return this.rowPosition < this.rows && this.columnPosition < this.rowSize(this.rowPosition);
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.data.get(this.rowPosition).get(this.columnPosition);

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
        return this.data.get(rowIndex).size();
    }
}