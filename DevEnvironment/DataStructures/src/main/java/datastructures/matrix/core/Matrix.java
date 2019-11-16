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
import datastructures.dimentions.interfaces.IPosition;
import datastructures.matrix.interfaces.IMatrix;

/**
 * The Matrix class implements a matrix.
 */
public final class Matrix<T extends Comparable<T>> implements IMatrix<T> {
    private final T[][] data;
    private final int xSize;
    private final int ySize;
    private final IBinaryComparator<IMatrix<T>> comparator;
    private final int hashCode;

    /**
     * The Matrix constructor.
     */
    public static <T extends Comparable<T>> IMatrix<T> create(T[][] data) {
        return new Matrix(data);
    }

    /**
     * Validates the data of a matrix.
     */
    public static <T extends Comparable<T>> void validate(T[][] data) {
        Conditions.validateNotNull(
            data,
            "The data of a matrix.");

        Conditions.validate(
            data.length > 0,
            "The matrix does not contains rows.");

        int rowSize = data[0].length;

        for (T[] row : data) {
            Conditions.validateNotNull(
                row,
                "The row of a matrix.");

            Conditions.validate(
                row.length  == rowSize,
                "The matrix is not square.");
        }
    }

    /**
     * The Matrix constructor.
     */
    public Matrix(T[][] data) {
        this(data, Matrix.defaultComparator());
    }

    /**
     * The Matrix constructor.
     */
    public Matrix(
        T[][] data,
        IBinaryComparator<IMatrix<T>> comparator) {

        Conditions.validateNotNull(
            data,
            "The data of a matrix");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element");

        Conditions.validate(
            data.length > 0,
            "The matrix does not contains rows.");

        this.data = data;
        this.xSize = data[0].length;
        this.ySize = data.length;
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
        return ySize;
    }

    /**
     * Gets a sub-matrix.
     */
    @Override
    public IMatrix getSubMatrix(IPosition bottomLeftPosition, IPosition upperRightPosition) {
        int xSize = upperRightPosition.getX() - bottomLeftPosition.getX();
        int ySize = upperRightPosition.getY() - bottomLeftPosition.getY();

        return this.getSubMatrix(bottomLeftPosition, xSize, ySize);
    }

    /**
     * Gets a sub-matrix.
     */
    @Override
    public IMatrix getSubMatrix(IPosition bottomLeftPosition, int xSize, int ySize) {
        Conditions.validateNotNull(
            bottomLeftPosition,
            "The bottom left position in a matrix.");

        return null;
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
        return this.data;
    }
}
