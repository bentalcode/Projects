package base.core;

import base.interfaces.IIterator;
import java.util.List;

/**
 * The TwoDimensionalListIterator class implements an iterator of a two dimensional list.
 */
public class TwoDimensionalListIterator<T> implements IIterator<T> {
    private final List<List<T>> list;
    private final int rows;
    private int rowPosition;
    private int columnPosition;

    /**
     * Creates a new list iterator.
     */
    public static <T> IIterator<T> of(List<List<T>> list) {
        return new TwoDimensionalListIterator<>(list);
    }

    /**
     * The TwoDimensionalArrayIterator constructor.
     */
    private TwoDimensionalListIterator(List<List<T>> list) {
        Conditions.validateNotNull(
            list,
            "The list to iterate.");

        this.list = list;
        this.rows = list.size();

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

        T currElement = this.list.get(this.rowPosition).get(this.columnPosition);

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
        return this.list.get(rowIndex).size();
    }
}