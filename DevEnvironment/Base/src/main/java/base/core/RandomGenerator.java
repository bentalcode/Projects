package base.core;

import base.interfaces.IRandomGenerator;
import base.interfaces.StringCaseSensitiveType;
import java.util.Random;

/**
 * The RandomGenerator class implements a random generator.
 */
public final class RandomGenerator implements IRandomGenerator {
    private static final int defaultStringMaxLength = 1000;

    private final Random random = new Random();

    /**
     * The RandomGenerator constructor.
     */
    public RandomGenerator() {
    }

    /**
     * Generates a new boolean.
     */
    @Override
    public boolean nextBoolean() {
        return this.random.nextBoolean();
    }

    /**
     * Generates a new integer.
     */
    @Override
    public int nextInteger() {
        return this.random.nextInt();
    }

    /**
     * Generates a new integer between the following specified values (inclusively).
     */
    @Override
    public int nextInteger(int from, int to) {
        Conditions.validate(
            from >= 0 && from <= to,
            "Invalid range of characters.");

        int range = to - from;

        if (range < Integer.MAX_VALUE) {
            ++range;
        }

        int randomRange = this.random.nextInt(range);

        int result = from + randomRange;

        assert(result >= from && result <= to);

        return result;
    }

    /**
     * Generates a new long.
     */
    @Override
    public long nextLong() {
        return this.random.nextLong();
    }

    /**
     * Generates a new double.
     */
    @Override
    public double nextDouble() {
        return this.random.nextDouble();
    }

    /**
     * Generates a new double between the following specified values (inclusively).
     */
    @Override
    public double nextDouble(double from, double to) {
        Conditions.validate(
            from <= to,
            "Invalid range of characters.");

        double range = to - from;

        // The generated double is a value between 0.0 (inclusively) and 1.0 (exclusively).
        double randomDouble = this.random.nextDouble();

        return range * randomDouble;
    }

    /**
     * Generates a new character.
     */
    @Override
    public char nextCharacter() {
        return this.nextCharacter(StringCaseSensitiveType.Sensitive);
    }

    /**
     * Generates a new character ignore case.
     */
    @Override
    public char nextCharacterIgnoreCase() {
        return this.nextCharacter(StringCaseSensitiveType.Insensitive);
    }

    /**
     * Generates a new character.
     */
    @Override
    public char nextCharacter(StringCaseSensitiveType sensitiveType) {
        char from = Character.MIN_VALUE;
        char to = Character.MAX_VALUE;

        char result =  this.nextCharacter(
            from,
            to);

        if (this.nextStringCaseSensitiveType() == StringCaseSensitiveType.Sensitive) {
            result = Character.toUpperCase(result);
        }
        
        return result;
    }

    /**
     * Generates a new character between the following specified values (inclusively).
     */
    @Override
    public char nextCharacter(char from, char to) {
        Conditions.validate(
            from <= to,
            "Invalid range of characters.");

        int range = to - from;
        int randomRange = this.nextInteger(0, range);

        int randomResult = from + randomRange;
        char result = Conversion.integerConversion().toCharacter(randomResult);

        assert(result >= from && result <= to);

        return result;
    }

    /**
     * Generates a new string.
     */
    @Override
    public String nextString() {
        return this.nextString(StringCaseSensitiveType.Sensitive);
    }

    /**
     * Generates a new string ignore case.
     */
    @Override
    public String nextStringIgnoreCase() {
        return this.nextString(StringCaseSensitiveType.Insensitive);
    }

    /**
     * Generates a new string.
     */
    @Override
    public String nextString(StringCaseSensitiveType sensitiveType) {
        int fromLength = 0;
        int toLength = RandomGenerator.defaultStringMaxLength;

        return this.nextString(
            fromLength,
            toLength,
            sensitiveType);
    }

    /**
     * Generates a new string with a length between the specified lengths (inclusively).
     */
    @Override
    public String nextString(int fromLength, int toLength) {
        return this.nextString(
            fromLength,
            toLength,
            StringCaseSensitiveType.Sensitive);
    }

    /**
     * Generates a new string ignore case with a length between the specified lengths (inclusively).
     */
    @Override
    public String nextStringIgnoreCase(int fromLength, int toLength) {
        return this.nextString(
            fromLength,
            toLength,
            StringCaseSensitiveType.Insensitive);
    }

    /**
     * Generates a new string with a length between the specified lengths (inclusively).
     */
    @Override
    public String nextString(
        int fromLength,
        int toLength,
        StringCaseSensitiveType sensitiveType) {

        Conditions.validate(
            fromLength <= toLength,
            "Invalid range of a length.");

        int length = this.nextInteger(fromLength, toLength);

        if (length == 0) {
            return "";
        }

        char[] data = new char[length];

        for (int i = 0; i < length; ++i) {
            data[i] = this.nextCharacter(sensitiveType);
        }

        String result = new String(data);
        assert(result.length() >= fromLength && result.length() <= toLength);

        return result;
    }

    /**
     * Generates a new string with characters between the specified range (inclusively).
     */
    @Override
    public String nextString(char fromCharacter, char toCharacter) {
        int fromLength = 0;
        int toLength = RandomGenerator.defaultStringMaxLength;

        return this.nextString(
            fromCharacter,
            toCharacter,
            fromLength,
            toLength);
    }

    /**
     * Generates a new string with characters between the specified range (inclusively),
     * and length between the specified lengths (inclusively).
     */
    @Override
    public String nextString(
        char fromCharacter,
        char toCharacter,
        int fromLength,
        int toLength) {

        Conditions.validate(
            fromCharacter <= toCharacter,
            "Invalid range of characters.");

        Conditions.validate(
            fromLength <= toLength,
            "Invalid range of a length.");

        int length = this.nextInteger(fromLength, toLength);

        if (length == 0) {
            return "";
        }

        char[] data = new char[length];

        for (int i = 0; i < length; ++i) {
            data[i] = this.nextCharacter(fromCharacter, toCharacter);
        }

        String result = new String(data);
        assert(result.length() >= fromLength && result.length() <= toLength);

        return result;
    }

    /**
     * Generates a new case sensitive type for a string.
     */
    private StringCaseSensitiveType nextStringCaseSensitiveType() {
        return this.nextBoolean() ? StringCaseSensitiveType.Sensitive : StringCaseSensitiveType.Insensitive;
    }
}
