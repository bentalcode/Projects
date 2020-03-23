package problems.core;

import base.core.Strings;
import base.interfaces.IValidator;

/**
 * The NumberValidator class implements a validation logic for numbers.
 */
public final class NumberValidator implements IValidator {
    private final String value;

    /**
     * The NumberValidator constructor.
     */
    public NumberValidator(String value) {
        this.value = value;
    }

    /**
     * Validates a number.
     * Numbers 0-9
     * Exponent - "e"
     * Positive/negative sign - "+"/"-"
     * Decimal point - "."
     */
    public boolean validate() {
        if (Strings.isNullOrEmpty(this.value)) {
            return false;
        }

        String currValue = this.value.trim();
        char[] data = currValue.toCharArray();
        int startIndex = 0;
        int endIndex = data.length - 1;

        return this.validate(data, startIndex, endIndex);
    }

    /**
     * Checks whether a number is valid.
     */
    private boolean validate(char[] data, int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return false;
        }

        int eIndex = -1;

        for (int i = startIndex; i <= endIndex; ++i) {
            char currValue = data[i];

            if (!this.isValidCharacter(currValue)) {
                return false;
            }

            if (currValue == 'e') {
                if (eIndex != -1) {
                    return false;
                }

                eIndex = i;
            }
        }

        boolean status;

        if (eIndex != -1) {
            int firstSectionStartIndex = startIndex;
            int firstSectionEndIndex = eIndex - 1;

            int secondSectionStartIndex = eIndex + 1;
            int secondSectionEndIndex = endIndex;

            status =
                this.validateNumberSection(data, firstSectionStartIndex, firstSectionEndIndex, false) &&
                this.validateNumberSection(data, secondSectionStartIndex, secondSectionEndIndex, true);
        }
        else {
            status = this.validateNumberSection(data, startIndex, endIndex, false);
        }

        return status;
    }

    /**
     * Checks whether a number section is valid.
     */
    private boolean validateNumberSection(
        char[] data,
        int startIndex,
        int endIndex,
        boolean sectionAfterExponent) {

        if (startIndex > endIndex) {
            return false;
        }

        if (startIndex == endIndex) {
            char firstCharacter = data[startIndex];
            return this.isDigit(firstCharacter);
        }

        boolean foundDecimalPoint = false;

        for (int i = startIndex; i <= endIndex; ++i) {
            char currValue = data[i];

            if (currValue == '+' || currValue == '-') {
                if (i > startIndex) {
                    return false;
                }
            }
            else if (currValue == '.') {
                if (foundDecimalPoint || i == endIndex || sectionAfterExponent) {
                    return false;
                }

                foundDecimalPoint = true;
            }
            else {
                if (!this.isDigit(currValue)) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * Checks whether a character is valid.
     */
    private boolean isValidCharacter(char value) {
        return
            value == '.' ||
            value == '+' ||
            value == '-' ||
            value == 'e' ||
            this.isDigit(value);
    }

    /**
     * Checks whether a character is a digit.
     */
    private boolean isDigit(char value) {
        return value >= '0' && value <= '9';
    }
}
