package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.ITwoDimensionalArrayComparator;

/**
 * The TwoDimensionalArrayComparator class implements a comparator for a two dimensional array.
 */
public final class TwoDimensionalArrayComparator<T> implements ITwoDimensionalArrayComparator<T> {
    /**
     * The TwoDimensionalArrayComparator constructor.
     */
    public TwoDimensionalArrayComparator() {
    }

    /**
     * Checks whether the arrays are equals with an element comparator.
     */
    @Override
    public boolean isEqual(T[][] lhs, T[][] rhs, IBinaryComparator<T> comparator) {
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

        if (lhs[0].length != rhs[0].length) {
            return false;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {
                if (!comparator.isEqual(lhs[row][column], rhs[row][column])) {
                    return false;
                }
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
    public int compareTo(T[][] lhs, T[][] rhs, IBinaryComparator<T> comparator) {
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

        if (lhs[0].length < rhs[0].length) {
            return -1;
        }

        if (lhs[0].length > rhs[0].length) {
            return 1;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                int status = comparator.compareTo(lhs[row][column], rhs[row][column]);

                if (status != 0) {
                    return status;
                }
            }
        }

        return 0;
    }
}
