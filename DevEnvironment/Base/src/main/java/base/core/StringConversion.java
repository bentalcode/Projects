package base.core;

import base.interfaces.IStringConversion;

/**
 * The StringConversion class implements conversions for a string.
 */
public final class StringConversion implements IStringConversion {
    /**
     * The StringConversion constructor.
     */
    public StringConversion() {
    }

    /**
     * Converts a string to a character.
     */
    @Override
    public char toCharacter(String value) {
        if (value == null || value.length() != 1) {
            String errorMessage =
                "Failed to convert a string: " + value + " to a character." +
                " The input string is not a single character long.";

            throw new BaseException(errorMessage);
        }

        return value.charAt(0);
    }

    /**
     * Converts a string to a string array.
     */
    @Override
    public String[] toArray(String value) {
        String separator = String.valueOf(",");
        return this.toArray(value, separator);
    }

    /**
     * Converts a string to a string array.
     */
    @Override
    public String[] toArray(String value, String separator) {
        Conditions.validateNotNull(
            value,
            "The array value.");

        String array = value.trim();
        String[] result = array.split(separator);

        return result;
    }
}
