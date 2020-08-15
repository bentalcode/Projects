package base.core;

/**
 * The StringSearch class implements complementary APIs for string search.
 */
public final class StringSearch {
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

        int strLength = Dimensions.length(0, endIndex);

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

        int stringLength = Dimensions.length(startIndex, endIndex);
        int subStringLength = Dimensions.length(subStringStartIndex, subStringEndIndex);

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

        int stringLength = Dimensions.length(startIndex, endIndex);
        int subStringLength = Dimensions.length(subStringStartIndex, subStringEndIndex);

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

        int strLength = Dimensions.length(strStartIndex, strEndIndex);
        int subStringLength = Dimensions.length(subStringStartIndex, subStringEndIndex);

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

        int strLength = Dimensions.length(startIndex, endIndex);

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
     * The StringSearch constructor - Disables the default constructor.
     */
    private StringSearch() {
    }
}
