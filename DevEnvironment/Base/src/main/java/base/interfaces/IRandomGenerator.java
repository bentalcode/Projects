package base.interfaces;

/**
 * The IRandomGenerator interface defines a random generator.
 */
public interface IRandomGenerator {
    /**
     * Generates a new boolean.
     */
    boolean nextBoolean();

    /**
     * Generates a new integer.
     */
    int nextInteger();

    /**
     * Generates a new integer between the following specified values (inclusively).
     */
    int nextInteger(int from, int to);

    /**
     * Generates a new long.
     */
    long nextLong();

    /**
     * Generates a new double.
     */
    double nextDouble();

    /**
     * Generates a new double between the following specified values (inclusively).
     */
    double nextDouble(double from, double to);

    /**
     * Generates a new character.
     */
    char nextCharacter();

    /**
     * Generates a new character between the following specified values (inclusively).
     */
    char nextCharacter(char from, char to);

    /**
     * Generates a new string.
     */
    String nextString();

    /**
     * Generates a new string ignore case with a length between the specified lengths (inclusively).
     */
    String nextString(int fromLength, int toLength);

    /**
     * Generates a new string with characters between the specified range (inclusively),
     * and length between the specified lengths (inclusively).
     */
    String nextString(
        char fromCharacter,
        char toCharacter,
        int fromLength,
        int toLength);
}
