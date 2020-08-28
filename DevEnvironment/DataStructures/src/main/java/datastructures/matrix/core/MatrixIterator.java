package datastructures.matrix.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.dimentions.core.Position;
import datastructures.dimentions.interfaces.IPosition;
import datastructures.matrix.interfaces.IMatrix;

/**
 * The MatrixIterator class implements an iterator of a matrix.
 */
public final class MatrixIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IMatrix<T> data;
    private IPosition position;

    /**
     * Creates a new iterator of a matrix.
     */
    public static <T extends Comparable<T>> IIterator<T> make(IMatrix<T> data) {
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
        this.position = new Position();
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.position.getX() < this.data.xSize() - 1) {
            this.position.moveRight();
        }
        else {
            this.position = new Position(0, this.position.getY() + 1);
        }
    }

    /**
     * Gets a value of a specific position.
     */
    private T get(IPosition position) {
        return this.data.get(position);
    }
}