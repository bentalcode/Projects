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
     * Adding numbers with a specified base.
     */
    @Override
    public int[] add(int[] left, int[] right, int base) {
        Conditions.validate(
            left != null && left.length > 0,
            "The left number is not defined.");

        Conditions.validate(
            right != null && right.length > 0,
            "The right number is not defined.");

        assert(left != null && left.length > 0);
        assert(right != null && right.length > 0);

        this.validateBase(base);

        int[] result = new int[Math.max(left.length, right.length) + 1];

        if (left.length >= right.length) {
            this.add(
                left, 0, left.length - 1,
                right, 0, right.length - 1,
                result, 0, result.length - 1,
                base);
        }
        else {
            this.add(
                right, 0, right.length - 1,
                left, 0, left.length - 1,
                result, 0, result.length - 1,
                base);
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

        result = this.getResultNumber(result, 0, resultLastIndex, base);

        return result;
    }

    /**
     * Adding string numbers with a specified base.
     */
    @Override
    public String addStringNumbers(String left, String right, int base) {
        Conditions.validate(
            left != null && left.length() > 0,
            "The left number string is not defined");

        Conditions.validateNotNull(
            right != null && right.length() > 0,
            "The right number string is not defined");

        assert(left != null && left.length() > 0);
        assert(right != null && right.length() > 0);

        this.validateBase(base);

        int[] result = new int[Math.max(left.length(), right.length()) + 1];

        if (left.length() >= right.length()) {
            this.add(
                left.toCharArray(), 0, left.length() - 1,
                right.toCharArray(), 0, right.length() - 1,
                result, 0, result.length - 1,
                base);
        }
        else {
            this.add(
                right.toCharArray(), 0, right.length() - 1,
                left.toCharArray(), 0, left.length() - 1,
                result, 0, result.length - 1,
                base);
        }

        int resultLastIndex = result.length - 1;

        while (resultLastIndex >= 0) {
            int currValue = result[resultLastIndex];

            if (currValue != 0) {
                break;
            }

            --resultLastIndex;
        }

        if (resultLastIndex == -1) {
            return "0";
        }

        return this.getResultStringNumber(result, 0, resultLastIndex, base);
    }

    /**
     * Adds numbers.
     */
    private void add(
        int[] left, int leftStartIndex, int leftEndIndex,
        int[] right, int rightStartIndex, int rightEndIndex,
        int[] result, int resultStartIndex, int resultEndIndex,
        int base) {

        int leftIndex = leftEndIndex;
        int rightIndex = rightEndIndex;
        int resultIndex = resultStartIndex;

        int carry = 0;

        while (leftIndex >= leftStartIndex && rightIndex >= rightStartIndex) {
            int leftDigit = left[leftIndex];
            int rightDigit = right[rightIndex];

            int totalValue = leftDigit + rightDigit + carry;

            int currValue = totalValue % base;
            carry = totalValue / base;

            assert(resultIndex >= resultStartIndex && resultIndex <= resultEndIndex);
            result[resultIndex] = currValue;

            --leftIndex;
            --rightIndex;
            ++resultIndex;
        }

        while (leftIndex >= leftStartIndex) {
            int currDigit = left[leftIndex];
            int currSum = currDigit + carry;

            int currValue = currSum % base;
            carry = currSum / base;

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
     * Adds string numbers.
     */
    private void add(
        char[] left, int leftStartIndex, int leftEndIndex,
        char[] right, int rightStartIndex, int rightEndIndex,
        int[] result, int resultStartIndex, int resultEndIndex,
        int base) {

        int leftIndex = leftEndIndex;
        int rightIndex = rightEndIndex;
        int resultInsertIndex = resultStartIndex;

        int carry = 0;

        while (leftIndex >= leftStartIndex && rightIndex >= rightStartIndex) {
            int leftValue = Character.digit(left[leftIndex], base);
            int rightValue = Character.digit(right[rightIndex], base);

            int totalValue = leftValue + rightValue + carry;
            int currValue = totalValue % base;
            carry = totalValue / base;

            assert(resultInsertIndex >= resultStartIndex && resultInsertIndex <= resultEndIndex);
            result[resultInsertIndex] = currValue;

            --leftIndex;
            --rightIndex;
            ++resultInsertIndex;
        }

        while (leftIndex >= leftStartIndex) {
            int leftValue = Character.digit(left[leftIndex], base);

            int totalValue = leftValue + carry;

            int currValue = totalValue % base;
            carry = totalValue / base;

            assert(resultInsertIndex >= resultStartIndex && resultInsertIndex <= resultEndIndex);
            result[resultInsertIndex] = currValue;

            --leftIndex;
            ++resultInsertIndex;
        }

        if (carry > 0) {
            assert(resultInsertIndex >= resultStartIndex && resultInsertIndex <= resultEndIndex);
            result[resultInsertIndex] = carry;
        }
    }

    /**
     * Gets the number from the result.
     * The number is stored in reverse order.
     */
    private int[] getResultNumber(int[] number, int startIndex, int endIndex, int base) {
        int length = endIndex - startIndex + 1;

        int[] result = new int[length];
        int resultInsertIndex = 0;

        for (int i = endIndex; i >= startIndex; --i) {
            result[resultInsertIndex] = number[i] % base;

            ++resultInsertIndex;
        }

        return result;
    }

    /**
     * Gets the string number from the result.
     * The number is stored in reverse order.
     */
    private String getResultStringNumber(int[] number, int startIndex, int endIndex, int base) {
        int length = endIndex - startIndex + 1;

        char[] result = new char[length];
        int resultInsertIndex = 0;

        for (int i = endIndex; i >= startIndex; --i) {
            result[resultInsertIndex] = Character.forDigit(number[i], base);

            ++resultInsertIndex;
        }

        return new String(result);
    }

    /**
     * Validates that the base is supported.
     */
    private void validateBase(int base) {
        Conditions.validate(
            base == 2 || base == 8 || base == 10 || base == 16,
            "The supported base are: 2, 8, 10 and 16.");
    }
}
