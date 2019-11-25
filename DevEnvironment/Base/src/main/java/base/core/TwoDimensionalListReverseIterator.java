package base.core;

import base.interfaces.IReverseIterator;
import java.util.List;

/**
 * The TwoDimensionalListReverseIterator class implements a reverse iterator of a two dimensional list.
 */
public final class TwoDimensionalListReverseIterator<T> implements IReverseIterator<T> {
    private final List<List<T>> data;
    private final int rowsSize;
    private int rowIndex;
    private int columnIndex;

    /**
     * Creates a new reverse iterator of a two dimensional list.
     */
    public static <T> IReverseIterator<T> of(List<List<T>> data) {
        return new TwoDimensionalListReverseIterator<>(data);
    }

    /**
     * The TwoDimensionalListReverseIterator constructor.
     */
    private TwoDimensionalListReverseIterator(List<List<T>> data) {
        Conditions.validateNotNull(
            data,
            "The two dimensional list to iterate in reverse.");

        this.data = data;
        this.rowsSize = data.size();

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.rowIndex >= 0 && this.columnIndex < this.columnSize(this.rowIndex);
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
        int currRowIndex = this.rowsSize - 1;

        while (currRowIndex >= 0) {

            if (this.columnSize(currRowIndex) > 0) {
                this.rowIndex = currRowIndex;
                this.columnIndex = this.columnSize(currRowIndex) - 1;

                return;
            }

            --currRowIndex;
        }

        this.rowIndex = -1;
        this.columnIndex = -1;
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.columnIndex > 0) {
            --this.columnIndex;
        }
        else {
            this.columnIndex = 0;
            --this.rowIndex;
        }
    }

    /**
     * Gets the column size of a specific row.
     */
    private int columnSize(int rowIndex) {
        return this.data.get(rowIndex).size();
    }

    /**
     * Gets a value od a specific position.
     */
    private T get(int rowIndex, int columnIndex) {
        assert(rowIndex >= 0 && rowIndex < this.rowsSize);
        assert(columnIndex >= 0 && columnIndex < this.columnSize(rowIndex));

        return this.data.get(rowIndex).get(columnIndex);
    }
}