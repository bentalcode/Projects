package base.core;

import base.interfaces.IComparableComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterableComparator;
import base.interfaces.IIteratorComparator;

/**
 * The IterableComparator class implements a comparator for iterables.
 */
public final class IterableComparator<T> implements IIterableComparator<T> {
    private final IIteratorComparator<T> iteratorComparator = new IteratorComparator<>();

    /**
     * The IterableComparator constructor.
     */
    public IterableComparator() {
    }

    /**
     * Checks whether the iterables are equals with an element comparator.
     */
    @Override
    public boolean isEqual(IIterable<T> lhs, IIterable<T> rhs, IEquatableComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        return this.iteratorComparator.isEqual(lhs.getIterator(), rhs.getIterator(), comparator);
    }

    /**
     * Determines the relative order of iterables with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IIterable<T> lhs, IIterable<T> rhs, IComparableComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        return this.iteratorComparator.compareTo(lhs.getIterator(), rhs.getIterator(), comparator);
    }
}
