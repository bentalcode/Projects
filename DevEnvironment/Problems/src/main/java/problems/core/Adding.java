package problems.core;

import base.core.Conditions;
import problems.interfaces.IAdding;

/**
 * The Adding class implements adding numbers.
 */
public final class Adding implements IAdding {
    /**
     * The Adding constructor.
     */
    public Adding() {
    }

    /**
     * Adding numbers.
     */
    @Override
    public int[] add(int[] left, int[] right) {
        Conditions.validate(
            left != null && left.length > 0,
            "The left number is not defined.");

        Conditions.validate(
            right != null && left.length > 0,
            "The right number is not defined.");

        int[] result = new int[Math.max(left.length, right.length) + 1];

        if (left.length >= right.length) {
            this.add(
                left, 0, left.length - 1,
                right, 0, right.length - 1,
                result, 0, result.length - 1);
        }
        else {
            this.add(
                right, 0, right.length - 1,
                left, 0, left.length - 1,
                result, 0, result.length - 1);
        }

        int resultLastIndex = result.length - 1;

        while (resultLastIndex >= 0) {
            int currDigit = result[resultLastIndex];

            if (currDigit != 0) {
                break;
            }

            --resultLastIndex;
        }

        if (resultLastIndex == -1) {
            result = new int[1];
            result[0] = 0;
            return result;
        }

        result = this.getResultNumber(result, 0, resultLastIndex);

        return result;
    }

    /**
     * Adds numbers.
     */
    private void add(
        int[] left, int leftStartIndex, int leftEndIndex,
        int[] right, int rightStartIndex, int rightEndIndex,
        int[] result, int resultStartIndex, int resultEndIndex) {

        int leftIndex = leftEndIndex;
        int rightIndex = rightEndIndex;
        int resultIndex = resultStartIndex;

        int carry = 0;

        while (leftIndex >= leftStartIndex && rightIndex >= rightStartIndex) {
            int leftDigit = left[leftIndex];
            int rightDigit = right[rightIndex];

            int totalValue = leftDigit + rightDigit + carry;

            int currValue = totalValue % 10;
            carry = totalValue / 10;

            assert(resultIndex >= resultStartIndex && resultIndex <= resultEndIndex);
            result[resultIndex] = currValue;

            --leftIndex;
            --rightIndex;
            ++resultIndex;
        }

        while (leftIndex >= leftStartIndex) {
            int currDigit = left[leftIndex];
            int currSum = currDigit + carry;

            int currValue = currSum % 10;
            carry = currSum / 10;

            assert(resultIndex >= resultStartIndex && resultIndex <= resultEndIndex);
            result[resultIndex] = currValue;

            --leftIndex;
            ++resultIndex;
        }

        if (carry > 0) {
            result[resultIndex] = carry;
        }
    }

    /**
     * Gets the number from the result.
     * The number is stored in reverse order.
     */
    private int[] getResultNumber(int[] number, int startIndex, int endIndex) {
        int length = endIndex - startIndex + 1;

        int[] result = new int[length];
        int resultInsertIndex = 0;

        for (int i = endIndex; i >= startIndex; --i) {
            result[resultInsertIndex] = number[i];

            ++resultInsertIndex;
        }

        return result;
    }
}
