package base.interfaces;

/**
 * The IStringConversion interface defines conversions for a string.
 */
public interface IStringConversion {
    /**
     * Converts a string to a character.
     */
    char toCharacter(String value);

    /**
     * Converts a string to a string array.
     */
    String[] toArray(String value);

    /**
     * Converts a string to a string array.
     */
    String[] toArray(String value, String separator);
}
