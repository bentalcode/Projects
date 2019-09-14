package datastructures.array.core;

import base.core.AbstractBinaryComparator;
import base.core.ArrayIterator;
import base.core.ArrayReverseIterator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Range;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.array.interfaces.IArray;

/**
 * The Array class implements an array.
 */
public final class Array<T extends Comparable<T>> implements IArray<T> {
    private final T[] array;
    private final IBinaryComparator<IArray<T>> comparator;
    private final int hashCode;

    /**
     * The Array constructor.
     */
    public Array(T[] array) {
        this(
            array,
            Array.DefaultComparator());
    }

    /**
     * The Array constructor.
     */
    public Array(
        T[] array,
        IBinaryComparator<IArray<T>> comparator) {
        
        Conditions.validateNotNull(
            array,
            "The array.");
        
        this.array = array;
        this.comparator = comparator;
        this.hashCode = this.comparator.getHashCode(this);
    }
    
    /**
     * Gets the value of an index.
     */
    @Override
    public T get(int index) {
        this.validateIndex(index);
        
        return this.array[index];
    }

    /**
     * Gets the value of an index.
     */
    @Override
    public void set(int index, T value) {
        this.validateIndex(index);
        
        this.array[index] = value;
    }

    /**
     * Gets the size of an array.
     */
    @Override
    public int size() {
        return this.array.length;
    }

    /**
     * Checks whether an array is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;   
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<T> getIterator() {
        return ArrayIterator.of(this.array);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return ArrayReverseIterator.of(this.array);
    }

    /**
     * Converts the array to a native array.
     */
    @Override
    public T[] toArray() {
        return this.array;
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
    public boolean isEqual(IArray<T> other) {
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
    public int compareTo(IArray<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IArray<T>> DefaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.DefaultComparator();
        return new Array.Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of an array.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<IArray<T>> {
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
        public int getHashCode(IArray<T> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IArray<T> lhs, IArray<T> rhs) {
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
        public int compareTo(IArray<T> lhs, IArray<T> rhs) {
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
     * Validates an index.
     */
    private void validateIndex(int index) {
        this.validateIndex(index, this.array.length);
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index, int length) {
        Conditions.validate(
            index >= 0 && index < length,
            "The index is out of range. Index: " + index + ", Range: " + Range.of(0, length - 1));
    }
}
