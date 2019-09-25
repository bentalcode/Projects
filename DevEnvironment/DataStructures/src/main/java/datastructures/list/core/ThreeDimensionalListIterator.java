package datastructures.list.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.list.interfaces.IList;

/**
 * The ThreeDimensionalListIterator class implements an iterator of a tree dimensional list.
 */
public final class ThreeDimensionalListIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IList<IList<IList<T>>> data;
    private final int rows;
    private int rowIndex;
    private int columnIndex;
    private int depthIndex;

    /**
     * Creates a new iterator of a tree dimensional list.
     */
    public static <T extends Comparable<T>> IIterator<T> of(IList<IList<IList<T>>> data) {
        return new ThreeDimensionalListIterator<>(data);
    }

    /**
     * The ThreeDimensionalListIterator constructor.
     */
    private ThreeDimensionalListIterator(IList<IList<IList<T>>> data) {
        Conditions.validateNotNull(
            data,
            "The tree dimensional list to iterate.");

        this.data = data;
        this.rows = data.size();

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return
            this.rowIndex < this.rows &&
            this.columnIndex < this.columnSize(this.rowIndex) &&
            this.depthIndex < this.depthSize(this.rowIndex, this.columnIndex);
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.get(this.rowIndex, this.columnIndex, this.depthIndex);

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
        this.depthIndex = 0;
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.depthIndex < this.depthSize(this.rowIndex, this.columnIndex) - 1) {
            ++this.depthIndex;
        }
        else if (this.columnIndex < this.columnSize(this.rowIndex) - 1) {
            this.depthIndex = 0;
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
     * Gets the depth size of a specific row and column.
     */
    private int depthSize(int rowIndex, int columnIndex) {
        return this.data.get(rowIndex).get(columnIndex).size();
    }

    /**
     * Gets a value of a specific position.
     */
    private T get(int rowIndex, int columnIndex, int deptIndex) {
        assert(rowIndex >= 0 && rowIndex < this.rows);
        assert(columnIndex >= 0 && columnIndex < this.columnSize(rowIndex));
        assert(deptIndex >= 0 && deptIndex < this.depthSize(rowIndex, columnIndex));

        return this.data.get(rowIndex).get(columnIndex).get(deptIndex);
    }
}