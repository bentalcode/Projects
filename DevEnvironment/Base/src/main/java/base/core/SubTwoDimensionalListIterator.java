package base.core;

import base.interfaces.IIterator;
import java.util.List;

/**
 * The SubTwoDimensionalListIterator class implements an iterator of a sub section of a two dimensional list.
 */
public final class SubTwoDimensionalListIterator<T> implements IIterator<T> {
    private final List<List<T>> data;
    private final int rowsSize;
    private final int fromRowIndex;
    private final int fromColumnIndex;
    private final int toRowIndex;
    private final int toColumnIndex;

    private int rowIndex;
    private int columnIndex;

    /**
     * Creates a new iterator of a two dimensional list.
     */
    public static <T> IIterator<T> of(
        List<List<T>> data,
        int fromRowIndex,
        int fromColumnIndex,
        int toRowIndex,
        int toColumnIndex) {

        return new SubTwoDimensionalListIterator<>(
            data,
            fromRowIndex,
            fromColumnIndex,
            toRowIndex,
            toColumnIndex);
    }

    /**
     * The TwoDimensionalListIterator constructor.
     */
    private SubTwoDimensionalListIterator(
        List<List<T>> data,
        int fromRowIndex,
        int fromColumnIndex,
        int toRowIndex,
        int toColumnIndex) {

        Conditions.validateNotNull(
            data,
            "The two dimensional list to iterate.");

        this.validateSubSection(
            data,
            fromRowIndex,
            fromColumnIndex,
            toRowIndex,
            toColumnIndex);

        this.data = data;
        this.rowsSize = data.size();
        this.fromRowIndex = fromRowIndex;
        this.fromColumnIndex = fromColumnIndex;
        this.toRowIndex = toRowIndex;
        this.toColumnIndex = toColumnIndex;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return
            this.rowIndex < this.toRowIndex ||
            this.rowIndex == this.toRowIndex && this.columnIndex <= this.toColumnIndex;
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
        this.rowIndex = this.fromRowIndex;
        this.columnIndex = this.fromColumnIndex;
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
        return columnSize(this.data, rowIndex);
    }

    /**
     * Gets a value od a specific position.
     */
    private T get(int rowIndex, int columnIndex) {
        assert(rowIndex >= 0 && rowIndex < this.rowsSize);
        assert(columnIndex >= 0 && columnIndex < this.columnSize(rowIndex));

        return this.data.get(rowIndex).get(columnIndex);
    }

    private void validateSubSection(
        List<List<T>> data,
        int fromRowIndex,
        int fromColumnIndex,
        int toRowIndex,
        int toColumnIndex) {

        Conditions.validate(
            rowIndexIsValid(data, fromRowIndex),
            "The from row index is out of range.");

        Conditions.validate(
            columnIndexIsValid(data, fromRowIndex, fromColumnIndex),
            "The from column index is out of range.");

        Conditions.validate(
            rowIndexIsValid(data, toRowIndex),
            "The to row index is out of range.");

        Conditions.validate(
            columnIndexIsValid(data, toRowIndex, toColumnIndex),
            "The to column index is out of range.");

        Conditions.validate(
            fromRowIndex <= toRowIndex && fromColumnIndex <= toColumnIndex,
            "The from and the to positions are inverted.");
    }

    /**
     * Gets the column size of a specific row.
     */
    private static <T> int columnSize(List<List<T>> data, int rowIndex) {
        return data.get(rowIndex).size();
    }

    /**
     * Checks whether a row index is valid.
     */
    private static <T> boolean rowIndexIsValid(List<List<T>> data, int rowIndex) {
        return (rowIndex == 0) || (rowIndex >= 0 && rowIndex < data.size());
    }

    /**
     * Checks whether a column index is valid.
     */
    private static <T> boolean columnIndexIsValid(List<List<T>> data, int rowIndex, int columnIndex) {
        return (columnIndex == 0) || (columnIndex >= 0 && columnIndex < columnSize(data, rowIndex));
    }
}