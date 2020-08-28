package datastructures.matrix.core;

import base.BaseException;
import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.Collections;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.dimentions.interfaces.IPosition;
import datastructures.matrix.interfaces.IMatrix;
import java.util.ArrayList;
import java.util.List;

/**
 * The Matrix class implements a matrix.
 */
public final class Matrix<T extends Comparable<T>> implements IMatrix<T> {
    private final List<List<T>> data;
    private final int xSize;
    private final int ySize;

    private final IBinaryComparator<IMatrix<T>> comparator;
    private final int hashCode;

    /**
     * Validates data of a matrix.
     */
    public static <T extends Comparable<T>> void validate(List<List<T>> data) {
        if (!isValid(data)) {
            String errorMessage = "The data of a matrix is not valid.";
            throw new BaseException(errorMessage);
        }
    }

    /**
     * Checks whether data of a matrix is valid.
     */
    public static <T extends Comparable<T>> boolean isValid(List<List<T>> data) {
        if (data == null || data.isEmpty()) {
            return false;
        }

        int ySize = data.size();
        int xSize = data.get(0).size();

        if (xSize == 0) {
            return false;
        }

        for (int y = 1; y < ySize; ++y) {
            int currXSize = data.get(y).size();

            if (currXSize != xSize) {
                return false;
            }
        }

        return true;
    }

    /**
     * Creates a new matrix, with an initial sizes: xSize x ySize.
     */
    public static <T extends Comparable<T>> IMatrix<T> create(int xSize, int ySize) {
        return new Matrix<>(xSize, ySize);
    }

    /**
     * Creates a new matrix, with a two dimensional list.
     */
    public static <T extends Comparable<T>> IMatrix<T> create(List<List<T>> data) {
        return new Matrix<>(data);
    }

    /**
     * The Matrix constructor, with an initial sizes: rowSize x colSize.
     */
    public Matrix(
        int xSize,
        int ySize) {
        this(
            xSize,
            ySize,
            Matrix.defaultComparator());
    }

    /**
     * The Matrix constructor, with an initial sizes: rowSize x colSize.
     */
    public Matrix(
        int xSize,
        int ySize,
        IBinaryComparator<IMatrix<T>> comparator) {

        Conditions.validate(
            xSize > 0,
            "The size of X dimension of a matrix has to be positive.");

        Conditions.validate(
            ySize > 0,
            "The size of Y dimension of a matrix has to be positive.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a matrix.");

        this.data = new ArrayList<>(ySize);

        for (int y = 0; y < ySize; ++y) {
            List<T> xRow = new ArrayList<>(xSize);

            for (int x = 0; x < xSize; ++x) {
                xRow.add(null);
            }

            this.data.add(xRow);
        }

        this.xSize = xSize;
        this.ySize = ySize;

        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * The Matrix constructor, with a two dimensional list.
     */
    public Matrix(List<List<T>> data) {
        this(data, Matrix.defaultComparator());
    }

    /**
     * The Matrix constructor, with a two dimensional list.
     */
    public Matrix(
        List<List<T>> data,
        IBinaryComparator<IMatrix<T>> comparator) {

        Conditions.validateNotNull(
            data,
            "The data of a matrix.");

        Conditions.validate(
            data.size() > 0,
            "The Y dimension of a matrix has to be positive.");

        Conditions.validate(
            data.get(0).size() > 0,
            "The X dimension of a matrix has to be positive.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a matrix.");

        assert(isValid(data));

        this.data = data;
        this.xSize = data.get(0).size();
        this.ySize = data.size();

        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the origin.
     */
    @Override
    public T origin() {
        return this.data.get(0).get(0);
    }

    /**
     * Gets the X size.
     */
    @Override
    public int xSize() {
        return this.xSize;
    }

    /**
     * Gets the Y size.
     */
    @Override
    public int ySize() {
        return this.ySize;
    }

    /**
     * Gets an element at a specified position.
     */
    @Override
    public T get(int x, int y) {
        this.validateXCoordinate(x);
        this.validateYCoordinate(y);

        return this.data.get(y).get(x);
    }

    /**
     * Sets an element at a specified position.
     */
    @Override
    public void set(int x, int y, T element) {
        this.validateXCoordinate(x);
        this.validateYCoordinate(y);

        this.data.get(y).set(x, element);
    }

    /**
     * Gets an element at a specified position.
     */
    @Override
    public T get(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position.");

        return this.get(position.getX(), position.getY());
    }

    /**
     * Sets an element at a specified position.
     */
    @Override
    public void set(IPosition position, T element) {
        Conditions.validateNotNull(
            position,
            "The position.");

        this.set(position.getX(), position.getY(), element);
    }

    /**
     * Gets all elements.
     */
    @Override
    public List<List<T>> getData() {
        return this.data;
    }

    /**
     * Gets an X row.
     */
    @Override
    public List<T> getX(int y) {
        this.validateYCoordinate(y);

        return this.data.get(y);
    }

    /**
     * Sets an X row.
     */
    @Override
    public void setX(int y, List<T> data) {
        this.validateYCoordinate(y);

        Conditions.validate(
            data != null && data.size() == this.xSize,
            "The x dimension of a row is not in the correct size.");

        this.data.set(y, data);
    }

    /**
     * Checks if a specific position is inbound.
     */
    @Override
    public boolean inbound(int x, int y) {
        return this.isXCoordinateValid(x) && this.isYCoordinateValid(y);
    }

    /**
     * Checks if a specific position is inbound.
     */
    @Override
    public boolean inbound(IPosition position) {
        if(position == null) {
            return false;
        }

        return this.inbound(position.getX(), position.getY());
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
        return MatrixIterator.make(this);
    }

    /**
     * Gets a reverse iterator of elements.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return MatrixReverseIterator.make(this);
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
            return new HashCodeBuilder(619, 631)
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
                .withInteger(lhs.xSize(), rhs.xSize())
                .withInteger(lhs.ySize(), rhs.ySize())
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
                .withInteger(lhs.xSize(), rhs.xSize())
                .withInteger(lhs.ySize(), rhs.ySize())
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.elementComparator)
                .build();
        }
    }

    /**
     * Validates an X coordinate.
     */
    private void validateXCoordinate(int x) {
        if (!this.isXCoordinateValid(x)) {
            String errorMessage = "The X coordinate is out of bound.";
            throw new BaseException(errorMessage);
        }
    }

    /**
     * Validates a Y coordinate.
     */
    private void validateYCoordinate(int y) {
        if (!this.isYCoordinateValid(y)) {
            String errorMessage = "The Y coordinate is out of bound.";
            throw new BaseException(errorMessage);
        }
    }

    /**
     * Checks if an X coordinate is valid
     */
    private boolean isXCoordinateValid(int x) {
        return x >= 0 && x < this.xSize;
    }

    /**
     * Checks if a Y coordinate is valid
     */
    private boolean isYCoordinateValid(int y) {
        return y >= 0 && y < this.ySize;
    }
}
