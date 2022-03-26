package base.core;

import base.interfaces.IRandomGenerator;
import java.util.Random;

/**
 * The RandomGenerator class implements a random generator.
 */
public final class RandomGenerator implements IRandomGenerator {
    private static final int DEFAULT_STRING_MAX_LENGTH = 1000;

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
        char fromCharacter = Character.MIN_VALUE;
        char toCharacter = Character.MAX_VALUE;

        return this.nextCharacter(
            fromCharacter,
            toCharacter);
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
        int fromLength = 0;
        int toLength = RandomGenerator.DEFAULT_STRING_MAX_LENGTH;

        return this.nextString(
            fromLength,
            toLength);
    }

    /**
     * Generates a new string with a length between the specified lengths (inclusively).
     */
    @Override
    public String nextString(
        int fromLength,
        int toLength) {

        char fromCharacter = Character.MIN_VALUE;
        char toCharacter = Character.MAX_VALUE;

        return nextString(
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

        Range.validate(fromLength, toLength);

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
}
