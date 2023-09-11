package problems.core;

import base.core.Conditions;
import problems.interfaces.IMultiplication;

/**
 * The Multiplication class implements a multiplication.
 */
public final class Multiplication implements IMultiplication {
    /**
     * The Multiplication constructor.
     */
    public Multiplication() {
    }

    /**
     * Multiplies numbers.
     */
    @Override
    public int[] multiply(int[] left, int[] right) {
        Conditions.validate(
            left != null && left.length > 0,
            "The left number is not defined.");

        Conditions.validate(
            right != null && right.length > 0,
            "The right number is not defined.");

        assert (left != null && left.length > 0);
        assert (right != null && right.length > 0);
        int[] result = new int[left.length + right.length];

        int leftInsertIndex = 0;

        for (int leftIndex = left.length - 1; leftIndex >= 0; --leftIndex) {
            int leftDigit = left[leftIndex];

            int carry = 0;
            int rightInsertIndex = 0;

            for (int rightIndex = right.length - 1; rightIndex >= 0; --rightIndex) {
                int rightDigit = right[rightIndex];

                int totalValue = result[leftInsertIndex + rightInsertIndex] + (leftDigit * rightDigit) + carry;

                int currValue = totalValue % 10;
                carry = totalValue / 10;

                result[leftInsertIndex + rightInsertIndex] = currValue;

                ++rightInsertIndex;
            }

            if (carry > 0) {
                result[leftInsertIndex + rightInsertIndex] = carry;
            }

            ++leftInsertIndex;
        }

        int resultEndIndex = result.length - 1;

        while (resultEndIndex >= 0) {
            int currDigit = result[resultEndIndex];

            if (currDigit > 0) {
                break;
            }

            --resultEndIndex;
        }

        if (resultEndIndex == -1) {
            result = new int[1];
            return result;
        }

        result = this.getResultNumber(result, resultEndIndex + 1);

        return result;
    }

    /**
     * Gets the number from the result.
     * The number is stored in reverse order.
     */
    private int[] getResultNumber(int[] number, int length) {
        int[] result = new int[length];
        int resultInsertIndex = 0;

        for (int i = length - 1; i >= 0; --i) {
            result[resultInsertIndex] = number[i];
            ++resultInsertIndex;
        }

        return result;
    }
}
