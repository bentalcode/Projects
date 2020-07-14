package datastructures.list.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import base.core.Collections;
import datastructures.list.interfaces.ICircularList;
import datastructures.list.interfaces.IList;

/**
 * The CircularList class implements a circular list.
 */
public final class CircularList<T extends Comparable<T>> implements ICircularList<T> {
    private final IList<T> data;
    private final int startIndex;
    private final IBinaryComparator<ICircularList<T>> comparator;
    private final int hashCode;

    /**
     * The CircularList constructor.
     */
    public CircularList(IList<T> data) {
        this(
            data,
            0,
            CircularList.defaultComparator());
    }

    /**
     * The CircularList constructor.
     */
    public CircularList(
        IList<T> data,
        int startIndex) {

        this(
            data,
            startIndex,
            CircularList.defaultComparator());
    }

    /**
     * The CircularList constructor.
     */
    public CircularList(
        IList<T> data,
        int startIndex,
        IBinaryComparator<ICircularList<T>> comparator) {

        Conditions.validateNotNull(
            data,
            "The data.");

        this.validateIndex(startIndex, 0, data.size() - 1);

        Conditions.validateNotNull(
            comparator,
            "The comparator of a circular list.");

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
        return this.data.get(actualIndex);
    }

    /**
     * Gets the size of the list.
     */
    @Override
    public int size() {
        return this.data.size();
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
        return CircularListIterator.of(this);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return CircularListReverseIterator.of(this);
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
    public boolean isEqual(ICircularList<T> other) {
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
    public int compareTo(ICircularList<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<ICircularList<T>> defaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of a circular array.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<ICircularList<T>> {
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
        public int getHashCode(ICircularList<T> obj) {
            return new HashCodeBuilder(601, 607)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICircularList<T> lhs, ICircularList<T> rhs) {
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
        public int compareTo(ICircularList<T> lhs, ICircularList<T> rhs) {
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
        int result = (this.startIndex + index) % this.data.size();
        return result;
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index) {
        this.validateIndex(index, 0, this.data.size() - 1);
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index, int startIndex, int endIndex) {
        Collections.validateIndex(startIndex, endIndex, index, "circular list");
    }
}
