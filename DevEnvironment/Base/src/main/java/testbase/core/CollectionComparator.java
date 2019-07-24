package testbase.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.ICollectionComparator;
import java.util.Collection;
import java.util.Iterator;

/**
 * The CollectionComparator class implements a comparator for a collection.
 */
public final class CollectionComparator<T> implements ICollectionComparator<T> {
    /**
     * The CollectionComparator constructor.
     */
    public CollectionComparator() {
    }

    /**
     * Checks whether the collection are equals with an element comparator.
     */
    @Override
    public boolean isEqual(Collection<T> lhs, Collection<T> rhs, IBinaryComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a collection element.");

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        if (lhs.size() != rhs.size()) {
            return false;
        }

        return this.isEqual(lhs.iterator(), rhs.iterator(), comparator);
    }

    /**
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(Collection<T> lhs, Collection<T> rhs, IBinaryComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a collection element.");

        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        if (lhs.size() < rhs.size()) {
            return -1;
        }

        if (lhs.size() > rhs.size()) {
            return 1;
        }

        return this.compareTo(lhs.iterator(), rhs.iterator(), comparator);
    }

    /**
     * Checks whether the iterators of collections are equals with an element comparator.
     */
    @Override
    public boolean isEqual(Iterator<T> lhs, Iterator<T> rhs, IBinaryComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a collection element.");

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
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(Iterator<T> lhs, Iterator<T> rhs, IBinaryComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a collection element.");

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

        if (!lhs.hasNext() && rhs.hasNext()) {
            return -1;
        }

        if (lhs.hasNext() && !rhs.hasNext()) {
            return 1;
        }

        return 0;
    }
}
