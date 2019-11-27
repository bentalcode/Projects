package datastructures.matrix.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.TwoDimensionalListReverseIterator;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.collections.core.Collections;
import datastructures.dimentions.core.Position;
import datastructures.dimentions.core.RectanglePositions;
import datastructures.dimentions.interfaces.IPosition;
import datastructures.dimentions.interfaces.IRectanglePositions;
import datastructures.matrix.interfaces.IMatrix;
import java.util.List;

/**
 * The Matrix class implements a matrix.
 * A matrix is a rectangular array of numbers or other mathematical objects for which operations such as addition
 * and multiplication are defined.
 */
public final class Matrix<T extends Comparable<T>> implements IMatrix<T> {
    private final List<List<T>> data;
    private final int xSize;
    private final int ySize;
    private final IBinaryComparator<IMatrix<T>> comparator;
    private final int hashCode;

    /**
     * Validates the data of a matrix.
     */
    public static <T extends Comparable<T>> void validate(List<List<T>> data) {
        Conditions.validateNotNull(
            data,
            "The data of a matrix.");

        Conditions.validate(
            data.size() > 0,
            "The number of rows has to be positive.");

        int columnsSize = data.get(0).size();

        Conditions.validate(
            columnsSize > 0,
            "The number of columns has to be positive.");

        for (List<T> row : data) {
            Conditions.validateNotNull(
                row,
                "The row of a matrix.");

            Conditions.validate(
                row.size() == columnsSize,
                "The matrix is not a rectangle.");
        }
    }

    /**
     * Creates a new matrix.
     */
    public static <T extends Comparable<T>> IMatrix<T> create(List<List<T>> data) {
        return new Matrix<>(data);
    }

    /**
     * The Matrix constructor.
     */
    public Matrix(List<List<T>> data) {
        this(data, Matrix.defaultComparator());
    }

    /**
     * The Matrix constructor.
     */
    public Matrix(
        List<List<T>> data,
        IBinaryComparator<IMatrix<T>> comparator) {

        Conditions.validateNotNull(
            data,
            "The data of a matrix.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a matrix.");

        this.data = data;

        Conditions.validate(
            data.size() > 0,
            "The number of rows has to be positive.");

        Conditions.validate(
            data.get(0).size() > 0,
            "The number of columns has to be positive.");

        this.xSize = data.get(0).size();
        this.ySize = data.size();

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
        IPosition upperLeftPosition = new Position(0, this.ySize - 1);
        IPosition upperRightPosition = new Position(this.xSize - 1, this.ySize - 1);
        IPosition bottomLeftPosition = new Position(0, 0);
        IPosition bottomRightPosition = new Position(this.xSize - 1, 0);

        return new RectanglePositions(
            upperLeftPosition,
            upperRightPosition,
            bottomLeftPosition,
            bottomRightPosition);
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
        return MatrixIterator.of(this);
    }

    /**
     * Gets a reverse iterator of elements.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return MatrixReverseIterator.of(this);
    }

    /**
     * Checks whether the matrix contains a specific position.
     */
    @Override
    public boolean contains(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position in the matrix.");

        return
            (position.getX() >= 0 && position.getX() < this.xSize) &&
            (position.getY() >= 0 && position.getY() < this.ySize);
    }

    /**
     * Gets the element of a specific position in a matrix.
     */
    @Override
    public T get(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position.");

        assert(this.contains(position));

        T element = this.data.get(position.getY()).get(position.getX());

        return element;
    }

    /**
     * Gets the data of the matrix.
     */
    @Override
    public List<List<T>> getData() {
        return this.data;
    }

    /**
     * Converts the array to a native array.
     */
    @Override
    public T[][] toArray() {
        throw new UnsupportedOperationException();
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
                .withInteger(lhs.size(), rhs.size())
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
                .withInteger(lhs.size(), rhs.size())
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.elementComparator)
                .build();
        }
    }
}
