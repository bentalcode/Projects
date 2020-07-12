package base.core;

import base.BaseException;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IMatrix;
import base.interfaces.IReverseIterator;
import java.util.ArrayList;
import java.util.List;

/**
 * The Matrix class implements a matrix.
 */
public final class Matrix<T extends Comparable<T>> implements IMatrix<T> {
    private final List<List<T>> data;
    private final int rows;
    private final int cols;

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

        int rowsSize = data.size();
        int colsSize = data.get(0).size();

        if (colsSize == 0) {
            return false;
        }

        for (int row = 1; row < rowsSize; ++row) {
            int currRowSize = data.get(row).size();

            if (currRowSize != colsSize) {
                return false;
            }
        }

        return true;
    }

    /**
     * Creates a new matrix, with an initial sizes: rowSize x colSize.
     */
    public static <T extends Comparable<T>> IMatrix<T> create(int rowsSize, int colsSize) {
        return new Matrix<>(rowsSize, colsSize);
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
        int rowsSize,
        int colsSize) {
        this(
            rowsSize,
            colsSize,
            Matrix.defaultComparator());
    }

    /**
     * The Matrix constructor, with an initial sizes: rowSize x colSize.
     */
    public Matrix(
        int rowsSize,
        int colsSize,
        IBinaryComparator<IMatrix<T>> comparator) {

        Conditions.validate(
            rowsSize > 0,
            "The size of rows of a matrix has to be positive.");

        Conditions.validate(
            colsSize > 0,
            "The size of columns of a matrix has to be positive.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a matrix.");

        this.data = new ArrayList<>(rowsSize);

        for (int rowIndex = 0; rowIndex < rowsSize; ++rowIndex) {
            List<T> row = new ArrayList<>(colsSize);

            for (int colIndex = 0; colIndex < colsSize; ++colIndex) {
                row.add(null);
            }

            this.data.add(row);
        }

        this.rows = rowsSize;
        this.cols = colsSize;

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
            "The number of rows has to be positive.");

        Conditions.validate(
            data.get(0).size() > 0,
            "The number of columns has to be positive.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a matrix.");

        assert(isValid(data));

        this.data = data;
        this.rows = data.size();
        this.cols = data.get(0).size();

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
     * Gets the number of rows.
     */
    @Override
    public int rowsSize() {
        return this.rows;
    }

    /**
     * Gets the number of columns.
     */
    @Override
    public int colsSize() {
        return this.cols;
    }

    /**
     * Gets an element at a specified position.
     */
    @Override
    public T get(int rowIndex, int colIndex) {
        this.validateRowIndex(rowIndex);
        this.validateColumnIndex(colIndex);

        return this.data.get(rowIndex).get(colIndex);
    }

    /**
     * Sets an element at a specified position.
     */
    @Override
    public void set(int rowIndex, int colIndex, T element) {
        this.validateRowIndex(rowIndex);
        this.validateColumnIndex(colIndex);

        this.data.get(rowIndex).set(colIndex, element);
    }

    /**
     * Gets all elements.
     */
    @Override
    public List<List<T>> getData() {
        return this.data;
    }

    /**
     * Gets a row.
     */
    @Override
    public List<T> getRow(int rowIndex) {
        this.validateRowIndex(rowIndex);

        return this.data.get(rowIndex);
    }

    /**
     * Sets a row.
     */
    @Override
    public void setRow(int rowIndex, List<T> data) {
        this.validateRowIndex(rowIndex);

        Conditions.validate(
            data != null && data.size() == this.rows,
            "The data of the row is not in the correct size.");

        this.data.set(rowIndex, data);
    }

    /**
     * Checks if a specific position is inbound.
     */
    @Override
    public boolean inbound(int rowIndex, int colIndex) {
        return this.isRowIndexValid(rowIndex) && this.isColumnIndexValid(colIndex);
    }

    /**
     * Gets the size of the matrix.
     */
    @Override
    public int size() {
        return this.rows * this.cols;
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
            return new HashCodeBuilder(19, 23)
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
                .withInteger(lhs.rowsSize(), rhs.rowsSize())
                .withInteger(lhs.colsSize(), rhs.colsSize())
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
                .withInteger(lhs.rowsSize(), rhs.rowsSize())
                .withInteger(lhs.colsSize(), rhs.colsSize())
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.elementComparator)
                .build();
        }
    }

    /**
     * Validates a row index
     */
    private void validateRowIndex(int index) {
        if (!this.isRowIndexValid(index)) {
            String errorMessage = "The index of a row is out of bound.";
            throw new BaseException(errorMessage);
        }
    }

    /**
     * Validates a column index
     */
    private void validateColumnIndex(int index) {
        if (!this.isColumnIndexValid(index)) {
            String errorMessage = "The index of a column is out of bound.";
            throw new BaseException(errorMessage);
        }
    }

    /**
     * Checks if an index of a row is valid
     */
    private boolean isRowIndexValid(int index) {
        return index >= 0 && index < this.rows;
    }

    /**
     * Checks if an index of a column is valid
     */
    private boolean isColumnIndexValid(int index) {
        return index >= 0 && index < this.cols;
    }
}
