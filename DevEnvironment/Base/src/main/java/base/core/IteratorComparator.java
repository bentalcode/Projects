package base.core;

import base.interfaces.IComparableComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IIterator;
import base.interfaces.IIteratorComparator;

/**
 * The IteratorComparator class implements a comparator for iterators.
 */
public final class IteratorComparator<T> implements IIteratorComparator<T> {
    /**
     * The IteratorComparator constructor.
     */
    public IteratorComparator() {
    }

    /**
     * Checks whether the iterators are equals with an element comparator.
     */
    @Override
    public boolean isEqual(IIterator<T> lhs, IIterator<T> rhs, IEquatableComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        while (lhs.hasNext() && rhs.hasNext()) {
            T lhsValue = lhs.next();
            T rhsValue = rhs.next();

            if (!comparator.isEqual(lhsValue, rhsValue)) {
                return false;
            }
        }

        return !lhs.hasNext() && !rhs.hasNext();
    }

    /**
     * Determines the relative order of iterators with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IIterator<T> lhs, IIterator<T> rhs, IComparableComparator<T> comparator) {
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

        while (lhs.hasNext() && rhs.hasNext()) {
            T lhsValue = lhs.next();
            T rhsValue = rhs.next();

            int status = comparator.compareTo(lhsValue, rhsValue);

            if (status != 0) {
                return status;
            }
        }

        if (!lhs.hasNext() && !rhs.hasNext()) {
            return 0;
        }

        if (!lhs.hasNext()) {
            return -1;
        }

        return 1;
    }
}
