package datastructures.matrix.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.collections.core.Collections;
import datastructures.dimentions.core.Position;
import datastructures.dimentions.core.RectanglePositions;
import datastructures.dimentions.interfaces.IPosition;
import datastructures.dimentions.interfaces.IRectanglePositions;
import datastructures.matrix.MatrixException;
import datastructures.matrix.interfaces.IMatrix;

/**
 * The SubMatrix class implements a sub matrix.
 */
public final class SubMatrix<T extends Comparable<T>> implements IMatrix<T> {
    private final IMatrix<T> data;
    private final IPosition bottomLeftPosition;
    private final int xSize;
    private final int ySize;
    private final IBinaryComparator<IMatrix<T>> comparator;
    private final int hashCode;

    /**
     * The SubMatrix constructor.
     */
    public SubMatrix(
        IMatrix<T> data,
        IPosition bottomLeftPosition,
        int xSize,
        int ySize) {

        this(
            data,
            bottomLeftPosition,
            xSize,
            ySize,
            Matrix.defaultComparator());
    }

    /**
     * The SubMatrix constructor.
     */
    public SubMatrix(
        IMatrix<T> data,
        IPosition bottomLeftPosition,
        int xSize,
        int ySize,
        IBinaryComparator<IMatrix<T>> comparator) {

        Conditions.validateNotNull(
            data,
            "The data of a matrix.");

        Conditions.validateNotNull(
            bottomLeftPosition,
            "The bottom left position of a sub matrix.");

        Conditions.validate(
            xSize >= 0,
            "The xSize of a sub matrix has to be positive.");

        Conditions.validate(
            ySize >= 0,
            "The ySize of a sub matrix has to be positive.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a matrix.");

        SubMatrix.validateSubMatrix(data, bottomLeftPosition, xSize, ySize);

        this.data = data;
        this.bottomLeftPosition = bottomLeftPosition;
        this.xSize = xSize;
        this.ySize = ySize;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the x size.
     */
    @Override
    public int xSize() {
        return this.xSize;
    }

    /**
     * Gets the y size.
     */
    @Override
    public int ySize() {
        return this.ySize;
    }

    /**
     * Gets a frame of the matrix.
     */
    @Override
    public IRectanglePositions getFrame() {
        IPosition upperLeftPosition = Position.add(this.bottomLeftPosition, 0, this.ySize - 1);
        IPosition upperRightPosition = Position.add(this.bottomLeftPosition, this.xSize - 1, this.ySize - 1);
        IPosition bottomLeftPosition = this.bottomLeftPosition;
        IPosition bottomRightPosition = Position.add(this.bottomLeftPosition, this.xSize - 1, 0);

        return new RectanglePositions(
            upperLeftPosition,
            upperRightPosition,
            bottomLeftPosition,
            bottomRightPosition);
    }

    /**
     * Gets a sub-matrix.
     */
    @Override
    public IMatrix getSubMatrix(IPosition bottomLeftPosition, IPosition upperRightPosition) {
        Conditions.validateNotNull(
            bottomLeftPosition,
            "The bottom left position of a sub matrix.");

        Conditions.validateNotNull(
            upperRightPosition,
            "The upper right position of a sub matrix.");

        int xSize = upperRightPosition.getX() - bottomLeftPosition.getX() + 1;
        int ySize = upperRightPosition.getY() - bottomLeftPosition.getY() + 1;

        return this.getSubMatrix(bottomLeftPosition, xSize, ySize);
    }

    /**
     * Gets a sub-matrix.
     */
    @Override
    public IMatrix getSubMatrix(IPosition bottomLeftPosition, int xSize, int ySize) {
        return new SubMatrix(this.data, bottomLeftPosition, xSize, ySize);
    }

    /**
     * Gets the size of the matrix.
     */
    @Override
    public int size() {
        return this.xSize * this.ySize;
    }

    /**
     * Checks whether the matrix is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Gets an iterator of elements.
     */
    @Override
    public IIterator<T> getIterator() {
        return null;
    }

    /**
     * Gets a reverse iterator of elements.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return null;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getIterator());
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IMatrix<T> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IMatrix<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IMatrix<T>> defaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of a matrix.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<IMatrix<T>> {
        private final IBinaryComparator<T> elementComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<T> elementComparator) {
            Conditions.validateNotNull(
                elementComparator,
                "The comparator of an element.");

            this.elementComparator = elementComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IMatrix<T> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IMatrix<T> lhs, IMatrix<T> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IMatrix<T> lhs, IMatrix<T> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.elementComparator)
                .build();
        }
    }

    /**
     * Converts the array to a native array.
     */
    @Override
    public T[][] toArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Checks whether the matrix contains a specific position.
     */
    @Override
    public boolean contains(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position.");

        return
            (position.getX() >= this.bottomLeftPosition.getX() && position.getX() < this.bottomLeftPosition.getX() + this.xSize) &&
            (position.getY() >= this.bottomLeftPosition.getY() && position.getY() < this.bottomLeftPosition.getY() + this.ySize);
    }

    /**
     * Validates that the root matrix contains the specified sub matrix.
     */
    private static void validateSubMatrix(
        IMatrix matrix,
        IPosition bottomLeftPosition,
        int xSize,
        int ySize) {

        if (!SubMatrix.contains(matrix, bottomLeftPosition, xSize, ySize)) {
            IRectanglePositions matrixFrame = matrix.getFrame();
            IRectanglePositions subMatrixFrame = RectanglePositions.create(bottomLeftPosition, xSize, ySize);

            String errorMessage = "The matrix: " + matrixFrame + " does not contain sub matrix: " + subMatrixFrame;
            throw new MatrixException(errorMessage);
        }
    }

    /**
     * Checks whether the root matrix contains the specified sub matrix.
     */
    private static boolean contains(
        IMatrix matrix,
        IPosition bottomLeftPosition,
        int xSize,
        int ySize) {

        if (!matrix.contains(bottomLeftPosition)) {
            return false;
        }

        IPosition upperRightPosition = Position.add(bottomLeftPosition, xSize - 1, ySize - 1);

        return matrix.contains(upperRightPosition);
    }
}
