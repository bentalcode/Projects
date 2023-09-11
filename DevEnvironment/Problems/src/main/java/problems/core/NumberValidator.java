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

        int exponentIndex = -1;

        for (int i = startIndex; i <= endIndex; ++i) {
            char currValue = data[i];

            if (!this.isValidCharacter(currValue)) {
                return false;
            }

            if (this.isExponent(currValue)) {
                if (exponentIndex != -1) {
                    return false;
                }

                exponentIndex = i;
            }
        }

        if (exponentIndex != -1) {
            return
                this.validateNumberComponent(data, startIndex, exponentIndex - 1, false) &&
                this.validateNumberComponent(data, exponentIndex + 1, endIndex, true);
        }
        else {
            return this.validateNumberComponent(data, startIndex, endIndex, false);
        }
    }

    /**
     * Checks whether a number component is valid.
     */
    private boolean validateNumberComponent(
        char[] data,
        int startIndex,
        int endIndex,
        boolean componentAfterExponent) {

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

            if (this.isPlus(currValue) || this.isMinus(currValue)) {
                if (i > startIndex) {
                    return false;
                }
            }
            else if (this.isDecimalPoint(currValue)) {
                if (foundDecimalPoint || i == endIndex || componentAfterExponent) {
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
            this.isDigit(value) ||
            this.isPlus(value) ||
            this.isMinus(value) ||
            this.isExponent(value) ||
            this.isDecimalPoint(value);
    }

    /**
     * Checks whether a character is a digit.
     */
    private boolean isDigit(char value) {
        return value >= '0' && value <= '9';
    }

    /**
     * Checks whether a character is a plus.
     */
    private boolean isPlus(char value) {
        return value == '+';
    }

    /**
     * Checks whether a character is a minus.
     */
    private boolean isMinus(char value) {
        return value == '-';
    }

    /**
     * Checks whether a character is an exponent.
     */
    private boolean isExponent(char value) {
        return value == 'e';
    }

    /**
     * Checks whether a character is a decimal point.
     */
    private boolean isDecimalPoint(char value) {
        return value == '.';
    }
}
