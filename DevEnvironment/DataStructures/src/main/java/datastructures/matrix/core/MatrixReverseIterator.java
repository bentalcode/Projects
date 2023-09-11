package datastructures.matrix.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.dimentions.core.Position;
import datastructures.dimentions.interfaces.IPosition;
import datastructures.matrix.interfaces.IMatrix;

/**
 * The MatrixReverseIterator class implements a reverse iterator of a matrix.
 */
public final class MatrixReverseIterator<T extends Comparable<T>> implements IReverseIterator<T> {
    private final IMatrix<T> data;
    private IPosition position;

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
        return this.data.inbound(this.position);
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T currElement = this.get(this.position);
        this.moveNext();

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.position = new Position(this.data.xSize() - 1, this.data.ySize() - 1);
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.position.getX() > 0) {
            this.position.moveLeft();
        }
        else {
            this.position = new Position(this.data.xSize() - 1, this.position.getY() - 1);
        }
    }

    /**
     * Gets a value od a specific position.
     */
    private T get(IPosition position) {
        return this.data.get(position);
    }
}