package base.core;

import base.interfaces.IIterator;
import base.interfaces.IMatrix;

/**
 * The MatrixIterator class implements an iterator of a matrix.
 */
public final class MatrixIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IMatrix<T> data;
    private int currRow;
    private int currCol;

    /**
     * Creates a new iterator of a matrix.
     */
    public static <T extends Comparable<T>> IIterator<T> of(IMatrix<T> data) {
        return new MatrixIterator<>(data);
    }

    /**
     * The MatrixIterator constructor.
     */
    private MatrixIterator(IMatrix<T> data) {
        Conditions.validateNotNull(
            data,
            "The matrix to iterate.");

        this.data = data;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currRow < this.data.rowsSize();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.data.get(this.currRow, this.currCol);
        this.moveNext();

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currRow = 0;
        this.currCol = 0;
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.currCol < this.data.colsSize() - 1) {
            ++this.currCol;
        }
        else {
            ++this.currRow;
            this.currCol = 0;
        }
    }
}
