package base.core;

import base.BaseException;
import base.interfaces.IStringConversion;

/**
 * The StringConversion class implements conversions for a string.
 */
public final class StringConversion implements IStringConversion {
    private static final String separator = ",";

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
     * Converts a string to a long.
     */
    @Override
    public long toLong(String value) {
        return Long.parseLong(value);
    }

    /**
     * Converts a string to a string array.
     */
    @Override
    public String[] toArray(String value) {
        return this.toArray(value, StringConversion.separator);
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
        return array.split(separator);
    }

    /**
     * Converts a string to bytes.
     */
    @Override
    public byte[] toBytes(String value) {
        return Bytes.fromString(value);
    }
}
