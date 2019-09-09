package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.ITwoDimensionalList;
import java.util.List;

/**
 * The TwoDimensionalList class implements a generic two dimensional list.
 * The list can contains rows with different sizes.
 */
public final class TwoDimensionalList<T extends Comparable<T>> implements ITwoDimensionalList<T> {
    private final List<List<T>> elements;
    private final IBinaryComparator<ITwoDimensionalList<T>> comparator;
    private final int hashCode;
    
    /**
     * The TwoDimensionalList constructor.
     */
    public TwoDimensionalList(List<List<T>> elements) {
        this(
            elements,
            TwoDimensionalList.DefaultComparator());
    }

    /**
     * The TwoDimensionalList constructor.
     */
    public TwoDimensionalList(
        List<List<T>> elements,
        IBinaryComparator<ITwoDimensionalList<T>> comparator) {

        Conditions.validateNotNull(
            elements,
            "The elements of a two dimensional list.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a two dimensional list.");

        this.elements = elements;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }
    
    /**
     * Gets the number of rows.
     */
    @Override
    public int rowsSize() {
        return this.elements.size();
    }

    /**
     * Gets the number of columns in a specific row.
     */
    @Override
    public int columnSize(int rowIndex) {
        this.validateRowIndex(rowIndex);
        
        return this.elements.get(rowIndex).size();
    }

    /**
     * Gets an element at a specified position.
     */
    @Override
    public T get(int rowIndex, int columnIndex) {
        this.validateRowIndex(rowIndex);
        this.validateColumnIndex(rowIndex, columnIndex);
        
        return this.elements.get(rowIndex).get(columnIndex);
    }

    /**
     * Gets elements of a specified row.
     */
    @Override
    public List<T> getRow(int rowIndex) {
        this.validateRowIndex(rowIndex);
        
        return this.elements.get(rowIndex);
    }
    
    /**
     * Returns whether the collection is empty.
     */
    @Override
    public boolean empty() {
        return this.elements.isEmpty();
    }
    
    /**
     * Gets the size of the collection.
     */
    @Override
    public int size() {
        int size = 0;
        
        for (List<T> row : this.elements) {
            size += row.size();
        }
        
        return size;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<T> getIterator() {
        return TwoDimensionalListIterator.of(this.elements);
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
    public boolean isEqual(ITwoDimensionalList<T> other) {
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
    public int compareTo(ITwoDimensionalList<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<ITwoDimensionalList<T>> DefaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.DefaultComparator();
        return new Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of a generic two dimensional list.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<ITwoDimensionalList<T>> {
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
        public int getHashCode(ITwoDimensionalList<T> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ITwoDimensionalList<T> lhs, ITwoDimensionalList<T> rhs) {
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
        public int compareTo(ITwoDimensionalList<T> lhs, ITwoDimensionalList<T> rhs) {
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
     * Validates an index of a specific row.
     */
    private void validateRowIndex(int rowIndex) {
        Conditions.validateNotNull(
            rowIndex >= 0 && rowIndex < this.elements.size(),
            "The row index is out of range.");
    }

    /**
     * Validates an index of a specific column.
     */
    private void validateColumnIndex(int rowIndex, int columnIndex) {
        Conditions.validateNotNull(
            columnIndex >= 0 && columnIndex < this.elements.get(rowIndex).size(),
            "The column index is out of range.");
    }
}
