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
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex) {

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Checks whether strings are equals ignore case.
     */
    public static boolean equalsIgnoreCase(
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex) {

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Checks whether strings are equals.
     */
    private static boolean equals(
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex,
        boolean ignoreCase) {

        if (left == null && right == null) {
            return true;
        }

        if (left == null || right == null) {
            return false;
        }

        return equals(
            left.toCharArray(), leftStartIndex, leftEndIndex,
            right.toCharArray(), rightStartIndex, rightEndIndex,
            ignoreCase);
    }

    /**
     * Checks whether strings are equals.
     */
    public static boolean equals(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length) {

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            false);
    }

    /**
     * Checks whether strings are equals ignore case.
     */
    public static boolean equalsIgnoreCase(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length) {

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            true);
    }

    /**
     * Checks whether strings are equals.
     */
    private static boolean equals(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length,
        boolean ignoreCase) {

        if (left == null && right == null) {
            return true;
        }

        if (left == null || right == null) {
            return false;
        }

        return equals(
            left.toCharArray(), leftStartIndex,
            right.toCharArray(), rightStartIndex,
            length,
            ignoreCase);
    }

    /**
     * Checks whether strings are equals.
     */
    public static boolean equals(
        char[] left,
        int leftStartIndex,
        int leftEndIndex,
        char[] right,
        int rightStartIndex,
        int rightEndIndex) {

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Checks whether strings are equals ignore case.
     */
    public static boolean equalsIgnoreCase(
        char[] left,
        int leftStartIndex,
        int leftEndIndex,
        char[] right,
        int rightStartIndex,
        int rightEndIndex) {

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Checks whether strings are equals.
     */
    public static boolean equals(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex) {

        assert(left != null);
        assert(right != null);
        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(rightStartIndex >= 0 && rightStartIndex < right.length);

        int leftEndIndex = left.length - 1;
        int rightEndIndex = right.length - 1;

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Checks whether strings are equals ignore case.
     */
    public static boolean equalsIgnoreCase(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex) {

        assert(left != null);
        assert(right != null);
        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(rightStartIndex >= 0 && rightStartIndex < right.length);

        int leftEndIndex = left.length - 1;
        int rightEndIndex = right.length - 1;

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Checks whether strings are equals.
     */
    private static boolean equals(
        char[] left,
        int leftStartIndex,
        int leftEndIndex,
        char[] right,
        int rightStartIndex,
        int rightEndIndex,
        boolean ignoreCase) {

        assert(left != null);
        assert(right != null);
        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(leftEndIndex >= leftStartIndex && leftEndIndex < left.length);
        assert(rightStartIndex >= 0 && rightStartIndex < right.length);
        assert(rightEndIndex >= rightStartIndex && rightEndIndex < right.length);

        int leftLength = length(leftStartIndex, leftEndIndex);
        int rightLength = length(rightStartIndex, rightEndIndex);

        if (leftLength != rightLength) {
            return false;
        }

        int length = leftLength;

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            ignoreCase);
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

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            false);
    }

    /**
     * Checks whether strings are equals ignore case.
     */
    public static boolean equalsIgnoreCase(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex,
        int length) {

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            true);
    }

    /**
     * Checks whether strings are equals.
     */
    private static boolean equals(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex,
        int length,
        boolean ignoreCase) {

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

            if (ignoreCase) {
                leftValue = Character.toLowerCase(leftValue);
                rightValue = Character.toLowerCase(rightValue);
            }

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
     * Gets first index of a character.
     * Returns -1 if the character is not found.
     */
    public static int firstIndexOf(
        char[] str,
        int startIndex,
        int endIndex,
        char character) {

        if (startIndex > endIndex) {
            return -1;
        }

        return firstIndexOf(str, startIndex, endIndex, character, false);
    }

    /**
     * Gets first index of a character.
     * Returns -1 if the character is not found.
     */
    public static int firstIndexOfIgnoreCase(
        char[] str,
        int startIndex,
        int endIndex,
        char character) {

        if (startIndex > endIndex) {
            return -1;
        }

        return firstIndexOf(str, startIndex, endIndex, character, true);
    }

    /**
     * Gets last index of a character.
     * Returns -1 if the character is not found.
     */
    public static int lastIndexOf(
        char[] str,
        int startIndex,
        int endIndex,
        char character) {

        if (startIndex > endIndex) {
            return -1;
        }

        return lastIndexOf(str, startIndex, endIndex, character, false);
    }

    /**
     * Gets last index of a character.
     * Returns -1 if the character is not found.
     */
    public static int lastIndexOfIgnoreCase(
        char[] str,
        int startIndex,
        int endIndex,
        char character) {

        if (startIndex > endIndex) {
            return -1;
        }

        return lastIndexOf(str, startIndex, endIndex, character, true);
    }

    /**
     * Gets first index of a character.
     * Returns -1 if the character is not found.
     */
    private static int firstIndexOf(
        char[] str,
        int startIndex,
        int endIndex,
        char character,
        boolean ignoreCase) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        int currIndex = startIndex;

        while (currIndex <= endIndex) {
            char currCharacter = str[currIndex];

            if (ignoreCase) {
                currCharacter = Character.toLowerCase(currCharacter);
            }

            if (currCharacter == character) {
                return currIndex;
            }

            ++currIndex;
        }

        return -1;
    }

    /**
     * Gets end index of a character.
     * Returns -1 if the character is not found.
     */
    private static int lastIndexOf(
        char[] str,
        int startIndex,
        int endIndex,
        char character,
        boolean ignoreCase) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        int currIndex = endIndex;

        while (currIndex >= startIndex) {
            char currCharacter = str[currIndex];

            if (ignoreCase) {
                currCharacter = Character.toLowerCase(currCharacter);
            }

            if (currCharacter == character) {
                return currIndex;
            }

            --currIndex;
        }

        return -1;
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
     * Finds an index of a substring in a string with KMP Algorithm.
     * Return -1 if the subString is not found.
     */
    public static int findSubStringKmp(String str, String subString) {
        if (str == null || str.isEmpty() ||
            subString == null || subString.isEmpty() ||
            str.length() < subString.length()) {

            return -1;
        }

        return findSubStringKmp(
            str.toCharArray(), 0, str.length() - 1,
            subString.toCharArray(), 0, subString.length() - 1);
    }

    /**
     * Finds an index of a substring in a string with KMP Algorithm.
     * Return -1 if the subString is not found.
     */
    public static int findSubStringKmp(
        String str, int strStartIndex, int strEndIndex,
        String subString, int subStringStartIndex, int subStringEndIndex) {

        if (str == null || str.isEmpty() || subString == null || subString.isEmpty()) {
            return -1;
        }

        return findSubStringKmp(
            str.toCharArray(), strStartIndex, strEndIndex,
            subString.toCharArray(), subStringStartIndex, subStringEndIndex);
    }

    /**
     * Finds an index of a substring in a string with KMP Algorithm.
     * Return -1 if the subString is not found.
     */
    public static int findSubStringKmp(
        char[] str, int strStartIndex, int strEndIndex,
        char[] subString, int subStringStartIndex, int subStringEndIndex) {

        assert(str != null);
        assert(strStartIndex >= 0 && strStartIndex < str.length);
        assert(strEndIndex >= strStartIndex && strEndIndex < str.length);
        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length);
        assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.length);

        int strLength = length(strStartIndex, strEndIndex);
        int subStringLength = length(subStringStartIndex, subStringEndIndex);

        if (strLength < subStringLength) {
            return -1;
        }

        //
        // Create the longest prefix suffix...
        //
        int[] lps = createLongestPrefixSuffix(subString, subStringStartIndex, subStringEndIndex);

        int strIndex = strStartIndex;
        int subStringIndex = subStringStartIndex;

        while (strIndex <= strEndIndex && subStringIndex <= subStringEndIndex) {
            char strCharacter = str[strIndex];
            char subStringCharacter = subString[subStringIndex];

            if (strCharacter == subStringCharacter) {
                if (subStringIndex == subStringEndIndex) {
                    return strIndex - subStringLength + 1;
                }

                ++strIndex;
                ++subStringIndex;
            }
            else {
                if (subStringIndex == subStringStartIndex) {
                    ++strIndex;
                }
                else {
                    int lpsIndex = subStringIndex - subStringStartIndex;
                    subStringIndex = subStringStartIndex + lps[lpsIndex - 1];
                }
            }
        }

        return -1;
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
        int subStringLength,
        boolean allowOverlapping) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length);
        assert(subStringLength >= 0);
        assert(subStringStartIndex + subStringLength - 1 < subString.length);

        int stringLength = length(startIndex, endIndex);

        if (subStringLength == 0 || subStringLength > stringLength) {
            return 0;
        }

        int counter = 0;

        int currIndex = startIndex;
        int effectiveEndIndex = endIndex - subStringLength + 1;

        while (currIndex <= effectiveEndIndex) {
            if (equals(str, currIndex, subString, subStringStartIndex, subStringLength)) {
                ++counter;

                currIndex = (allowOverlapping) ? currIndex + 1 : currIndex + subStringLength;
            }
            else {
                ++currIndex;
            }
        }

        return counter;
    }

    /**
     * Counts the number of instances of a substring from end.
     * Avoid overlapping.
     */
    public static int countSubStringFromEnd(
        char[] str,
        int startIndex,
        int endIndex,
        char[] subString,
        int subStringStartIndex,
        int subStringLength,
        boolean allowOverlapping) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length);
        assert(subStringLength >= 0);
        assert(subStringStartIndex + subStringLength - 1 < subString.length);

        int stringLength = length(startIndex, endIndex);

        if (subStringLength == 0 || subStringLength > stringLength) {
            return 0;
        }

        int counter = 0;

        int currIndex = endIndex;
        int effectiveStartIndex = startIndex + subStringLength - 1;

        while (currIndex >= effectiveStartIndex) {
            int currStrStartIndex = currIndex - subStringLength + 1;
            int currSubStringStartIndex = 0;

            if (equals(str, currStrStartIndex, subString, currSubStringStartIndex, subStringLength)) {
                ++counter;

                currIndex = (allowOverlapping) ? currIndex - 1 : currIndex - subStringLength;
            }
            else {
                --currIndex;
            }
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

        int strLength = length(0, endIndex);

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
     * Creates the longest prefix suffix (lps) of a string.
     *
     * For instance,
     * String str = "AAACAAAAAC";
     * Prefixes = {{}, {A}, {AA}, {AAA}, {AAAC}, {AAACA}, {AAACAA}, {AAACAAA}, {AAACAAAA}, {AAACAAAAA}, {AAACAAAAAC}};
     * Postfixes = {{}, {C}, {AC}, {AAC}, {AAAC}, {AAAAC}, {AAAAAC}, {CAAAAAC}, {ACAAAAAC}, {AACAAAAAC}, {AAACAAAAAC}};
     *
     * In this case, Prefix{AAAC} == Postfix{AAAC}, Therefore, lps[9] = 4;
     *
     * lps = {0, 1, 2, 0, 1, 2, 3, 3, 3, 4}
     */
    private static int[] createLongestPrefixSuffix(char[] str, int startIndex, int endIndex) {
        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        int strLength = length(startIndex, endIndex);

        int[] lps = new int[strLength];
        lps[0] = 0;

        int index = 1;
        int length = 0;

        while (index < strLength) {
            char currCharacter = str[startIndex + index];
            char patternCharacter = str[startIndex + length];

            if (currCharacter == patternCharacter) {
                ++length;
                lps[index] = length;
                ++index;
            }
            else {
                if (length == 0) {
                    lps[index] = 0;
                    ++index;
                }
                else {
                    length = lps[length - 1];
                }
            }
        }

        return lps;
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
     * Calculates length of a string.
     */
    public static int length(int startIndex, int endIndex) {
        return startIndex <= endIndex ? endIndex - startIndex + 1 : 0;
    }

    /**
     * The Strings constructor - Disables the default constructor.
     */
    private Strings() {
    }
}
