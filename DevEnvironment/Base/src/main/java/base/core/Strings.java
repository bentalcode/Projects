package base.core;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * The Strings class implements complementary APIs for strings.
 */
public final class Strings {
    /**
     * Determines whether a string is not null or empty.
     */
    public static boolean isNullOrEmpty(String str) {
        return str == null || str.isEmpty();
    }

    /**
     * Converts the string to a list of characters.
     */
    public static List<Character> toList(String str) {
        Conditions.validateNotNull(
            str,
            "The input string for converting to a list.");

        List<Character> result = new ArrayList<>();

        for (int i = 0; i < str.length(); ++i) {
            result.add(str.charAt(i));
        }

        return result;
    }

    /**
     * Creates a string from a collection of values and a separator.
     */
    public static String create(
        Collection<String> values,
        char separator) {

        Conditions.validateNotNull(
            values,
            "The values.");

        StringBuilder stringBuilder = new StringBuilder();

        for (String value : values) {
            if (stringBuilder.length() > 0) {
                stringBuilder.append(separator);
            }

            stringBuilder.append(value);
        }

        return stringBuilder.toString();
    }

    /**
     * Clones a string.
     */
    public static char[] clone(
        char[] src,
        int startIndex,
        int length) {

        assert(src != null);
        assert(startIndex >= 0 && startIndex < src.length);
        assert(length >= 0);
        assert(startIndex + length - 1 < src.length);

        if (length <= 0) {
            return null;
        }

        char[] dest = new char[length];
        copy(src, startIndex, dest, 0, length);
        return dest;
    }

    /**
     * Copies a source string to a destination string.
     * Returns the number of characters copied.
     */
    public static int copy(
        char[] src, int srcStartIndex,
        char[] dest, int destStartIndex,
        int length) {

        assert(src != null);
        assert(dest != null);
        assert(length >= 0);

        assert(srcStartIndex >= 0 && srcStartIndex < src.length);
        assert(srcStartIndex + length - 1 < src.length);
        assert(src.length - srcStartIndex >= length);

        assert(destStartIndex >= 0 && destStartIndex < dest.length);
        assert(destStartIndex + length - 1 < dest.length);
        assert(dest.length - destStartIndex >= length);

        if (length <= 0) {
            return 0;
        }

        int numberOfCharactersWritten = 0;

        int srcIndex = srcStartIndex;
        int destIndex = destStartIndex;

        while (numberOfCharactersWritten < length && srcIndex < src.length && destIndex < dest.length) {
            char currCharacter = src[srcIndex];

            dest[destIndex] = currCharacter;
            ++numberOfCharactersWritten;

            ++srcIndex;
            ++destIndex;
        }

        return numberOfCharactersWritten;
    }

    /**
     * Wraps a string.
     */
    public static String wrap(String str, char start, char end) {
        return start + str + end;
    }

    /**
     * Wraps a string.
     */
    public static String wrap(String str, String start, String end) {
        return start + str + end;
    }

    /**
     * Wraps a string with parentheses.
     */
    public static String wrapWithParentheses(String str) {
        return '(' + str + ')';
    }

    /**
     * Wraps a string with curly brackets.
     */
    public static String wrapWithCurlyBracket(String str) {
        return '{' + str + '}';
    }

    /**
     * Wraps a string with square brackets.
     */
    public static String wrapWithSquareBracket(String str) {
        return '[' + str + ']';
    }

    /**
     * The Strings constructor - Disables the default constructor.
     */
    private Strings() {
    }
}
