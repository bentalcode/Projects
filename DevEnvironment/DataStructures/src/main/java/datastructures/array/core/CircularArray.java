package datastructures.array.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.array.interfaces.ICircularArray;
import base.core.Collections;

/**
 * The CircularArray class implements a circular array.
 */
public final class CircularArray<T extends Comparable<T>> implements ICircularArray<T> {
    private final T[] data;
    private final int startIndex;
    private final IBinaryComparator<ICircularArray<T>> comparator;
    private final int hashCode;

    /**
     * The CircularArray constructor.
     */
    public CircularArray(T[] data) {
        this(
            data,
            0,
            CircularArray.defaultComparator());
    }

    /**
     * The CircularArray constructor.
     */
    public CircularArray(
        T[] data,
        int startIndex) {

        this(
            data,
            startIndex,
            CircularArray.defaultComparator());
    }

    /**
     * The CircularArray constructor.
     */
    public CircularArray(
        T[] data,
        int startIndex,
        IBinaryComparator<ICircularArray<T>> comparator) {

        Conditions.validateNotNull(
            data,
            "The data.");

        this.validateIndex(startIndex, 0, data.length - 1);

        Conditions.validateNotNull(
            comparator,
            "The comparator of an array.");

        this.data = data;
        this.startIndex = startIndex;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the start index.
     */
    @Override
    public int getStartIndex() {
        return this.startIndex;
    }

    /**
     * Gets the value of an index.
     */
    @Override
    public T get(int index) {
        this.validateIndex(index);

        int actualIndex = this.indexOf(index);
        return this.data[actualIndex];
    }

    /**
     * Gets the size of an array.
     */
    @Override
    public int size() {
        return this.data.length;
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
        return CircularArrayIterator.of(this);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return CircularArrayReverseIterator.of(this);
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
    public boolean isEqual(ICircularArray<T> other) {
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
    public int compareTo(ICircularArray<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<ICircularArray<T>> defaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of a circular array.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<ICircularArray<T>> {
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
        public int getHashCode(ICircularArray<T> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICircularArray<T> lhs, ICircularArray<T> rhs) {
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
        public int compareTo(ICircularArray<T> lhs, ICircularArray<T> rhs) {
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
     * Gets the actual index of an index.
     */
    private int indexOf(int index) {
        int result = (this.startIndex + index) % this.data.length;
        return result;
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index) {
        this.validateIndex(index, 0, this.data.length - 1);
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index, int startIndex, int endIndex) {
        Collections.validateIndex(startIndex, endIndex, index, "circular array");
    }
}
