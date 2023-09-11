package base.core;

import base.interfaces.IMatrix;
import base.interfaces.IReverseIterator;

/**
 * The MatrixReverseIterator class implements a reverse iterator of a matrix.
 */
public final class MatrixReverseIterator<T extends Comparable<T>> implements IReverseIterator<T> {
    private final IMatrix<T> data;
    private int currRow;
    private int currCol;

    /**
     * Creates a new reverse iterator of a matrix.
     */
    public static <T extends Comparable<T>> IReverseIterator<T> make(IMatrix<T> data) {
        return new MatrixReverseIterator<>(data);
    }

    /**
     * The MatrixIterator constructor.
     */
    private MatrixReverseIterator(IMatrix<T> data) {
        Conditions.validateNotNull(
            data,
            "The matrix to iterate in reverse.");

        this.data = data;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currRow >= 0;
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
        this.currRow = this.data.rowsSize() - 1;
        this.currCol = this.data.colsSize() - 1;
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.currCol > 0) {
            --this.currCol;
        }
        else {
            --this.currRow;
            this.currCol = this.data.colsSize() - 1;
        }
    }
}
