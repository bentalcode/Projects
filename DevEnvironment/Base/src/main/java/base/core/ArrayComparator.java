package base.core;

import base.interfaces.IArrayComparator;
import base.interfaces.IBinaryComparator;

/**
 * The ArrayComparator class implements a comparator for an array.
 */
public final class ArrayComparator<T> implements IArrayComparator<T> {
    /**
     * The ArrayComparator constructor.
     */
    public ArrayComparator() {
    }

    /**
     * Checks whether the arrays are equals with an element comparator.
     */
    @Override
    public boolean isEqual(T[] lhs, T[] rhs, IBinaryComparator<T> comparator) {
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

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            if (!comparator.isEqual(lhs[i], rhs[i])) {
                return false;
            }
        }

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
    public int compareTo(T[] lhs, T[] rhs, IBinaryComparator<T> comparator) {
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

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            int status = comparator.compareTo(lhs[i], rhs[i]);

            if (status != 0) {
                return status;
            }
        }

        return 0;
    }
}
