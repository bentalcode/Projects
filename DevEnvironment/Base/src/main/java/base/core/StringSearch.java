package base.core;

/**
 * The StringSearch class implements complementary APIs for string search.
 */
public final class StringSearch {
    /**
     * Gets an index of a character by searching from start.
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
     * Gets an index of a character by searching from start. (Ignore Case.)
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
     * Gets an index of a sub string by searching from start.
     * Returns -1 if the character is not found.
     */
    public static int firstIndexOf(
        char[] str,
        int startIndex,
        int endIndex,
        char[] subStr) {

        if (startIndex > endIndex) {
            return -1;
        }

        return firstIndexOf(str, startIndex, endIndex, subStr, false);
    }

    /**
     * Gets an index of a sub string by searching from start. (Ignore Case.)
     * Returns -1 if the character is not found.
     */
    public static int firstIndexOfIgnoreCase(
        char[] str,
        int startIndex,
        int endIndex,
        char[] subStr) {

        if (startIndex > endIndex) {
            return -1;
        }

        return firstIndexOf(str, startIndex, endIndex, subStr, true);
    }

    /**
     * Gets an index of a character by searching from end.
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
     * Gets an index of a character by searching from end. (Ignore Case.)
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
     * Gets an index of a sub string by searching from end.
     * Returns -1 if the character is not found.
     */
    public static int lastIndexOf(
        char[] str,
        int startIndex,
        int endIndex,
        char[] subStr) {

        if (startIndex > endIndex) {
            return -1;
        }

        return lastIndexOf(str, startIndex, endIndex, subStr, false);
    }

    /**
     * Gets an index of a sub string by searching from end. (Ignore Case.)
     * Returns -1 if the character is not found.
     */
    public static int lastIndexOfIgnoreCase(
        char[] str,
        int startIndex,
        int endIndex,
        char[] subString) {

        if (startIndex > endIndex) {
            return -1;
        }

        return lastIndexOf(str, startIndex, endIndex, subString, true);
    }

    /**
     * Gets an index of a character by searching from start.
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
     * Gets an index of a sub string by searching from start.
     * Returns -1 if the sub-string is not found.
     */
    private static int firstIndexOf(
        char[] str,
        int startIndex,
        int endIndex,
        char[] subStr,
        boolean ignoreCase) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);
        assert(subStr != null);

        if (subStr.length > str.length || subStr.length == 0) {
            return -1;
        }

        int currIndex = startIndex;
        int effectiveEndIndex = endIndex - subStr.length + 1;

        while (currIndex <= effectiveEndIndex) {
            if (ignoreCase) {
                if (StringEquality.equalsIgnoreCase(
                        str,
                        currIndex,
                        subStr,
                        0,
                        subStr.length - 1)) {

                    return currIndex;
                }
            } else {
                if (StringEquality.equals(
                        str,
                        currIndex,
                        subStr,
                        0,
                        subStr.length - 1)) {

                    return currIndex;
                }
            }

            ++currIndex;
        }

        return -1;
    }

    /**
     * Gets an index of a character by searching from end.
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
     * Gets an index of a sub string by searching from end.
     * Returns -1 if the character is not found.
     */
    private static int lastIndexOf(
        char[] str,
        int startIndex,
        int endIndex,
        char[] subStr,
        boolean ignoreCase) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);
        assert(subStr != null);

        int currIndex = endIndex;

        while (currIndex >= startIndex) {
            if (StringEquality.equals(
                str,
                currIndex,
                subStr,
                0,
                subStr.length,
                ignoreCase)) {

                return currIndex;
            }

            --currIndex;
        }

        return -1;
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

        int strLength = Indexes.size(0, endIndex);

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
     * Counts the number of instances of a substring.
     */
    public static int countSubString(
        String str,
        String subString) {

        boolean allowOverlapping = true;
        return countSubString(str, subString, allowOverlapping);
    }

    /**
     * Counts the number of instances of a substring.
     */
    public static int countSubString(
        String str,
        String subString,
        boolean allowOverlapping) {

        if (str == null || str.isEmpty() || subString == null || subString.isEmpty()) {
            return 0;
        }

        int startIndex = 0;
        int endIndex = str.length() - 1;
        int subStringStartIndex = 0;
        int subStringEndIndex = subString.length() - 1;

        return countSubString(
            str,
            startIndex,
            endIndex,
            subString,
            subStringStartIndex,
            subStringEndIndex,
            allowOverlapping);
    }

    /**
     * Counts the number of instances of a substring.
     */
    public static int countSubString(
        String str,
        int startIndex,
        int endIndex,
        String subString,
        int subStringStartIndex,
        int subStringEndIndex,
        boolean allowOverlapping) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length());
        assert(endIndex >= startIndex && endIndex < str.length());

        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length());
        assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.length());

        return countSubString(
            str.toCharArray(),
            startIndex,
            endIndex,
            subString.toCharArray(),
            subStringStartIndex,
            subStringEndIndex,
            allowOverlapping);
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
        int subStringEndIndex,
        boolean allowOverlapping) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length);
        assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.length);

        int stringLength = Indexes.size(startIndex, endIndex);
        int subStringLength = Indexes.size(subStringStartIndex, subStringEndIndex);

        if (subStringLength == 0 || subStringLength > stringLength) {
            return 0;
        }

        int counter = 0;

        int currIndex = startIndex;
        int effectiveEndIndex = endIndex - subStringLength + 1;

        while (currIndex <= effectiveEndIndex) {
            if (StringEquality.equals(str, currIndex, subString, subStringStartIndex, subStringLength)) {
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
        int subStringEndIndex,
        boolean allowOverlapping) {

        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length);
        assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.length);

        int stringLength = Indexes.size(startIndex, endIndex);
        int subStringLength = Indexes.size(subStringStartIndex, subStringEndIndex);

        if (subStringLength == 0 || subStringLength > stringLength) {
            return 0;
        }

        int counter = 0;

        int currIndex = endIndex - subStringLength + 1;

        while (currIndex >= startIndex) {
            if (StringEquality.equals(str, currIndex, subString, subStringStartIndex, subStringLength)) {
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
     * The StringSearch constructor - Disables the default constructor.
     */
    private StringSearch() {
    }
}
