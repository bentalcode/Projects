package base.core;

import base.interfaces.IArrayComparator;
import base.interfaces.IComparableComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IIteratorComparator;

/**
 * The ArrayComparator class implements a comparator for an array.
 */
public final class ArrayComparator<T> implements IArrayComparator<T> {
    private final IIteratorComparator<T> iteratorComparator = new IteratorComparator<>();

    /**
     * The ArrayComparator constructor.
     */
    public ArrayComparator() {
    }

    /**
     * Checks whether the arrays are equals with an element comparator.
     */
    @Override
    public boolean isEqual(T[] lhs, T[] rhs, IEquatableComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of an array element.");

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        if (lhs.length != rhs.length) {
            return false;
        }

        return this.iteratorComparator.isEqual(ArrayIterator.of(lhs), ArrayIterator.of(rhs), comparator);
    }

    /**
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(T[] lhs, T[] rhs, IComparableComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of an array element.");

        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        if (lhs.length < rhs.length) {
            return -1;
        }

        if (lhs.length > rhs.length) {
            return 1;
        }

        return this.iteratorComparator.compareTo(ArrayIterator.of(lhs), ArrayIterator.of(rhs), comparator);
    }
}
