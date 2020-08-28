package datastructures.list.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import datastructures.list.interfaces.IList;
import datastructures.list.interfaces.ITwoDimensionalList;

/**
 * The TwoDimensionalList class implements a generic two dimensional list.
 * The dimensional of a list can contains different sizes.
 */
public final class TwoDimensionalList<T extends Comparable<T>> implements ITwoDimensionalList<T> {
    private final IList<IList<T>> data;
    private final IBinaryComparator<ITwoDimensionalList<T>> comparator;
    private final int hashCode;
    
    /**
     * The TwoDimensionalList constructor.
     */
    public TwoDimensionalList(IList<IList<T>> data) {
        this(
            data,
            TwoDimensionalList.defaultComparator());
    }

    /**
     * The TwoDimensionalList constructor.
     */
    public TwoDimensionalList(
        IList<IList<T>> data,
        IBinaryComparator<ITwoDimensionalList<T>> comparator) {

        Conditions.validateNotNull(
            data,
            "The data of a two dimensional list.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a two dimensional list.");

        this.data = data;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }
    
    /**
     * Gets the number of rows.
     */
    @Override
    public int rowsSize() {
        return this.data.size();
    }

    /**
     * Gets the number of columns in a specific row.
     */
    @Override
    public int columnSize(int rowIndex) {
        this.validateRowIndex(rowIndex);
        
        return this.data.get(rowIndex).size();
    }

    /**
     * Gets an element at a specified position.
     */
    @Override
    public T get(int rowIndex, int columnIndex) {
        this.validateRowIndex(rowIndex);
        this.validateColumnIndex(rowIndex, columnIndex);
        
        return this.data.get(rowIndex).get(columnIndex);
    }

    /**
     * Gets elements of a specified row.
     */
    @Override
    public IList<T> getRow(int rowIndex) {
        this.validateRowIndex(rowIndex);
        
        return this.data.get(rowIndex);
    }
    
    /**
     * Returns whether the collection is empty.
     */
    @Override
    public boolean empty() {
        return this.data.empty();
    }
    
    /**
     * Gets the size of the collection.
     */
    @Override
    public int size() {
        int size = 0;
        
        for (IList<T> row : this.data) {
            size += row.size();
        }
        
        return size;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<T> getIterator() {
        return TwoDimensionalListIterator.make(this.data);
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
    public static <T extends Comparable<T>> IBinaryComparator<ITwoDimensionalList<T>> defaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.defaultComparator();
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
            return new HashCodeBuilder(613, 617)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
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
        Conditions.validate(
            rowIndex >= 0 && rowIndex < this.data.size(),
            "The row index is out of range.");
    }

    /**
     * Validates an index of a specific column.
     */
    private void validateColumnIndex(int rowIndex, int columnIndex) {
        Conditions.validate(
            columnIndex >= 0 && columnIndex < this.data.get(rowIndex).size(),
            "The column index is out of range.");
    }
}
