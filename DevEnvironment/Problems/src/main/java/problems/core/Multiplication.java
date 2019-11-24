package problems.core;

import base.core.Conditions;
import problems.interfaces.IMultiplication;

/**
 * The Multiplication class implements a multiplication.
 */
public final class Multiplication implements IMultiplication {
    /**
     * Multiply strings.
     */
    @Override
    public String multiply(String left, String right) {
        Conditions.validateStringNotNullOrEmpty(
            left,
            "The multiply left argument.");

        Conditions.validateStringNotNullOrEmpty(
            right,
            "The multiply right argument.");

        int[] result = new int[left.length() + right.length() + 1];

        int leftInsertIndex = 0;

        for (int leftIndex = left.length() - 1; leftIndex >= 0; --leftIndex) {
            char leftValue = left.charAt(leftIndex);
            int leftDigit = Character.digit(leftValue, 10);

            int rightInsertIndex = 0;
            int carry = 0;

            for (int rightIndex = right.length() - 1; rightIndex >= 0; --rightIndex) {
                char rightValue = right.charAt(rightIndex);
                int rightDigit = Character.digit(rightValue, 10);

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

        int resultLastIndex = result.length - 1;

        while (resultLastIndex >= 0) {
            int currDigit = result[resultLastIndex];

            if (currDigit > 0) {
                break;
            }

            --resultLastIndex;
        }

        if (resultLastIndex == -1) {
            return "0";
        }

        StringBuilder stringResult = new StringBuilder();

        while (resultLastIndex >= 0) {
            int currDigit = result[resultLastIndex];
            char currCharacter = Character.forDigit(currDigit, 10);

            stringResult.append(currCharacter);

            --resultLastIndex;
        }

        return stringResult.toString();
    }
}
