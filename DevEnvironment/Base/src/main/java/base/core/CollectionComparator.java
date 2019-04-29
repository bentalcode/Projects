package base.core;

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

        Iterator<T> lhsIterator = lhs.iterator();
        Iterator<T> rhsIterator = rhs.iterator();

        while (lhsIterator.hasNext() && rhsIterator.hasNext()) {
            T lhsValue = lhsIterator.next();
            T rhsValue = rhsIterator.next();

            if (!comparator.isEqual(lhsValue, rhsValue)) {
                return false;
            }
        }

        assert(!lhsIterator.hasNext() && !rhsIterator.hasNext());

        return true;
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
            "The comparator of a list element.");

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

        Iterator<T> lhsIterator = lhs.iterator();
        Iterator<T> rhsIterator = rhs.iterator();

        while (lhsIterator.hasNext() && rhsIterator.hasNext()) {
            T lhsValue = lhsIterator.next();
            T rhsValue = rhsIterator.next();

            int status = comparator.compareTo(lhsValue, rhsValue);

            if (status != 0) {
                return status;
            }
        }

        assert(!lhsIterator.hasNext() && !rhsIterator.hasNext());

        return 0;
    }
}
