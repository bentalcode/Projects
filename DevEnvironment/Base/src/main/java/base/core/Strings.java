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
     * Checks whether strings are equals.
     */
    public static boolean equals(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex,
        int length) {

        assert(left != null);
        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(leftStartIndex + length - 1 < left.length);

        assert(right != null);
        assert(rightStartIndex >= 0 && rightStartIndex < right.length);
        assert(rightStartIndex + length - 1 < right.length);

        int leftIndex = leftStartIndex;
        int rightIndex = rightStartIndex;

        int counter = 0;
        while (counter < length && leftIndex < left.length && rightIndex < right.length) {
            char leftValue = left[leftIndex];
            char rightValue = right[rightIndex];

            if (leftValue != rightValue) {
                return false;
            }

            ++leftIndex;
            ++rightIndex;
            ++counter;
        }

        return counter == length;
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
     * Counts the number of instances of a substring.
     */
    public static int countSubString(
        char[] str,
        int startIndex,
        int endIndex,
        char[] subString,
        int subStringStartIndex,
        int subStringLength) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length);
        assert(subStringLength >= 0 && subStringLength < subString.length);
        assert(subStringStartIndex + subStringLength - 1 < subString.length);

        if (subStringLength <= 0) {
            return 0;
        }

        int counter = 0;

        int currIndex = startIndex;
        int currIndexEnd = endIndex - subStringLength + 1;

        while (currIndex <= currIndexEnd) {
            if (equals(str, currIndex, subString, subStringStartIndex, subStringLength)) {
                ++counter;
            }

            ++currIndex;
        }

        return counter;
    }

    /**
     * Checks whether a string starts with a prefix.
     */
    public static boolean startsWith(char[] str, char[] postfix) {
        return startsWith(str, 0, postfix);
    }

    /**
     * Checks whether a string starts with a prefix.
     */
    public static boolean startsWith(char[] str, int startIndex, char[] prefix) {
        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(prefix != null);

        int strLength = str.length - startIndex;

        if (strLength < prefix.length) {
            return false;
        }

        int counter = 0;

        int strIndex = startIndex;
        int prefixIndex = 0;

        while (counter < prefix.length && strIndex < str.length && prefixIndex < prefix.length) {
            char strCharacter = str[strIndex];
            char prefixCharacter = prefix[prefixIndex];

            if (strCharacter != prefixCharacter) {
                return false;
            }

            ++counter;

            ++strIndex;
            ++prefixIndex;
        }

        return strIndex == startIndex + counter;
    }

    /**
     * Checks whether the string ends with a postfix.
     */
    public static boolean endsWith(char[] str, char[] postfix) {
        return endsWith(str, str.length - 1, postfix);
    }

    /**
     * Checks whether the string ends with a postfix.
     */
    public static boolean endsWith(char[] str, int endIndex, char[] postfix) {
        assert(str != null);
        assert(endIndex >= 0 && endIndex < str.length);
        assert(postfix != null);

        int strLength = endIndex + 1;

        if (strLength < postfix.length) {
            return false;
        }

        int counter = 0;

        int strIndex = endIndex;
        int postfixIndex = postfix.length - 1;

        while (counter < postfix.length && strIndex >= 0 && postfixIndex >= 0) {
            char strCharacter = str[strIndex];
            char postfixCharacter = postfix[postfixIndex];

            if (strCharacter != postfixCharacter) {
                return false;
            }

            ++counter;

            --strIndex;
            --postfixIndex;
        }

        return strIndex == endIndex - counter;
    }

    /**
     * The Strings constructor - Disables the default constructor.
     */
    private Strings() {
    }
}
