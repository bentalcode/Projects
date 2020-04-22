package problems.core;

import base.core.Conditions;
import problems.interfaces.IInterleavingStrings;

/**
 * The InterleavingStrings class implements the interleaving strings problem.
 */
public final class InterleavingStrings implements IInterleavingStrings {
    /**
     * Checks whether the strings are interleaving with the following constraints:
     * Runtime: O(A+B)
     * Memory: O(A*B)
     * C is said to be interleaving A and B, if it contains all characters of A and B,
     * and order of all characters in individual strings is preserved.
     */
    @Override
    public boolean interleaving1(String left, String right, String interleaving) {
        Conditions.validateNotNull(left, "The left string.");
        Conditions.validateNotNull(right, "The right string.");
        Conditions.validateNotNull(interleaving, "The interleaving string.");

        if (left.length() + right.length() != interleaving.length()) {
            return false;
        }

        boolean status = interleaving1(
            left.toCharArray(),
            right.toCharArray(),
            interleaving.toCharArray());

        return status;
    }

    /**
     * Checks whether the strings are interleaving with the following constraints:
     * Runtime: O((A + B)^2)
     * Memory: O(1)
     * C is said to be interleaving A and B, if it contains all characters of A and B,
     * and order of all characters in individual strings is preserved.
     */
    @Override
    public boolean interleaving2(String left, String right, String interleaving) {
        Conditions.validateNotNull(left, "The left string.");
        Conditions.validateNotNull(right, "The right string.");
        Conditions.validateNotNull(interleaving, "The interleaving string.");

        if (left.length() + right.length() != interleaving.length()) {
            return false;
        }

        boolean status = interleaving2(
            left.toCharArray(), 0,
            right.toCharArray(), 0,
            interleaving.toCharArray());

        return status;
    }

    private boolean interleaving1(
        char[] left,
        char[] right,
        char[] interleaving) {

        if (left.length == 0 && right.length == 0) {
            return true;
        }

        int rowsSize = left.length + 1;
        int columnsSize = right.length + 1;

        boolean[][] lookup = new boolean[rowsSize][columnsSize];
        lookup[0][0] = true;

        for (int col = 1; col < columnsSize; ++col) {
            char rightValue = right[col - 1];

            int interleavingIndex = col - 1;
            char interleavingValue = interleaving[interleavingIndex];

            boolean rightMatching = rightValue == interleavingValue;

            lookup[0][col] = lookup[0][col - 1] && rightMatching;
        }

        for (int row = 1; row < rowsSize; ++row) {
            char leftValue = left[row - 1];

            int interleavingIndex = row - 1;
            char interleavingValue = interleaving[interleavingIndex];

            boolean leftMatching = leftValue == interleavingValue;

            lookup[row][0] = lookup[row - 1][0] && leftMatching;
        }

        for (int row = 1; row < rowsSize; ++row) {
            for (int col = 1; col < columnsSize; ++col) {

                char leftValue = left[row - 1];
                char rightValue = right[col - 1];

                int interleavingIndex = row + col - 1;
                char interleavingValue = interleaving[interleavingIndex];

                boolean leftMatching = leftValue == interleavingValue;
                boolean rightMatching = rightValue == interleavingValue;

                lookup[row][col] =
                    (lookup[row - 1][col] && leftMatching) ||
                    (lookup[row][col - 1] && rightMatching);
            }
        }

        return lookup[rowsSize - 1][columnsSize - 1];
    }

    private boolean interleaving2(
        char[] left, int leftIndex,
        char[] right, int rightIndex,
        char[] interleaving) {

        if (leftIndex > left.length || rightIndex > right.length) {
            return false;
        }

        if (leftIndex == left.length && rightIndex == right.length) {
            return true;
        }

        if (leftIndex == left.length) {
            char rightValue = right[rightIndex];

            int interleavingIndex = left.length + rightIndex;
            char interleavingValue = interleaving[interleavingIndex];

            if (rightValue != interleavingValue) {
                return false;
            }

            return this.interleaving2(left, leftIndex, right, rightIndex + 1, interleaving);
        }
        else if (rightIndex == right.length) {
            char leftValue = left[leftIndex];

            int interleavingIndex = right.length + leftIndex;

            char interleavingValue = interleaving[interleavingIndex];

            if (leftValue != interleavingValue) {
                return false;
            }

            return this.interleaving2(left, leftIndex + 1, right, rightIndex, interleaving);
        }
        else {
            char leftValue = left[leftIndex];
            char rightValue = right[rightIndex];
            int interleavingIndex = leftIndex + rightIndex;
            char interleavingValue = interleaving[interleavingIndex];

            if (leftValue == interleavingValue && rightValue == interleavingValue) {
                return
                    this.interleaving2(left, leftIndex + 1, right, rightIndex, interleaving) ||
                    this.interleaving2(left, leftIndex, right, rightIndex + 1, interleaving);
            }
            else if (leftValue == interleavingValue) {
                return this.interleaving2(left, leftIndex + 1, right, rightIndex, interleaving);
            }
            else if (rightValue == interleavingValue) {
                return this.interleaving2(left, leftIndex, right, rightIndex + 1, interleaving);
            }
            else {
                return false;
            }
        }
    }
}
