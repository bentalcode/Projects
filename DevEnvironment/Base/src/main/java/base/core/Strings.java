package base.core;

import base.interfaces.IPair;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * The Strings class implements complementary APIs for strings.
 */
public final class Strings {
    private static final List<IPair<Character, Character>> PARENTHESES_START_END_TOKENS = ArrayLists.make(
        Pair.make('(', ')'),
        Pair.make('[', ']'),
        Pair.make('{', '}'));

    private static final List<IPair<Character, Character>> QUOTATION_START_END_TOKENS = ArrayLists.make(
        Pair.make('\'', '\''),
        Pair.make('\"', '\"'));

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
     * Replaces the token in a string.
     */
    public static String replace(String src, String token, String newToken) {
        Conditions.validateNotNull(
            src,
            "The source string.");

        Conditions.validateNotNull(
            token,
            "The current token for replacing.");

        Conditions.validateNotNull(
            newToken,
            "The new token for replacing.");

        if (src.isEmpty() ||
            token.isEmpty() ||
            token.length() > src.length()) {

            return src;
        }

        return replace(
            src.toCharArray(),
            token.toCharArray(),
            newToken.toCharArray());
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
     * Replaces the token in a string.
     */
    public static String replace(
        char[] src,
        char[] token,
        char[] newToken) {

        assert(src != null);
        assert(token != null);
        assert(newToken != null);

        if (token.length > src.length || token.length == 0) {
            return new String(src);
        }

        //
        // Calculate the new size of the string...
        //
        int newSize = 0;
        boolean tokenExist = false;

        int index = 0;
        int endIndex = src.length - token.length;

        while (index <= endIndex) {
            if (StringEquality.equals(
                    src,
                    index,
                    token,
                    0,
                    token.length)) {

                newSize += newToken.length;
                tokenExist = true;
            }
            else {
                ++newSize;
            }

            ++index;
        }

        if (!tokenExist) {
            return new String(src);
        }

        char[] result = new char[newSize];

        index = 0;
        int resultInsertIndex = 0;

        while (index < src.length) {
            if (StringEquality.equals(
                    src,
                    index,
                    token,
                    0,
                    token.length)) {

                int numberOfCopiedCharacters = Strings.copy(
                    newToken,
                    0,
                    result,
                    resultInsertIndex,
                    newToken.length);

                resultInsertIndex += numberOfCopiedCharacters;
            }
            else {
                result[resultInsertIndex] = src[index];
                ++resultInsertIndex;
            }

            ++index;
        }

        assert(resultInsertIndex == result.length);
        return new String(result);
    }

    /**
     * Removes outer parentheses from the string.
     */
    public static String removeParentheses(String str) {
        return removeStartAndEndCharacters(str, PARENTHESES_START_END_TOKENS);
    }

    /**
     * Removes quotation marks.
     */
    public static String removeQuotationMarks(String str) {
        return removeStartAndEndCharacters(str, QUOTATION_START_END_TOKENS);
    }

    /**
     * Removes the first character of a string only if it is matching the specified character.
     */
    public static String removeFirstCharacter(String str, char characterToRemove) {
        if (Strings.isNullOrEmpty(str)) {
            return str;
        }

        char firstCharacter = str.charAt(0);

        if (firstCharacter == characterToRemove) {
            return str.substring(1);
        }

        return str;
    }

    /**
     * Removes the last character of a string only if it is matching the specified character.
     */
    public static String removeLastCharacter(String str, char characterToRemove) {
        if (Strings.isNullOrEmpty(str)) {
            return str;
        }

        char lastCharacter = str.charAt(str.length() - 1);

        if (lastCharacter == characterToRemove) {
            return str.substring(0, str.length() - 1);
        }

        return str;
    }

    /**
     * Removes the first character of a string only if it is matching one of the specified characters.
     */
    public static String removeFirstCharacter(String str, List<Character> charactersToRemove) {
        if (Strings.isNullOrEmpty(str) || charactersToRemove.isEmpty()) {
            return str;
        }

        char firstCharacter = str.charAt(0);

        for (char characterToRemove : charactersToRemove) {
            if (firstCharacter == characterToRemove) {
                return str.substring(1);
            }
        }

        return str;
    }

    /**
     * Removes the last character of a string only if it is matching one of the specified characters.
     */
    public static String removeLastCharacter(String str, List<Character> charactersToRemove) {
        if (Strings.isNullOrEmpty(str) || charactersToRemove.isEmpty()) {
            return str;
        }

        char lastCharacter = str.charAt(str.length() - 1);

        for (char characterToRemove : charactersToRemove) {
            if (lastCharacter == characterToRemove) {
                return str.substring(0, str.length() - 1);
            }
        }

        return str;
    }

    /**
     * Removes the start and end tokens correspondingly.
     */
    private static String removeStartAndEndCharacters(
        String str,
        List<IPair<Character, Character>> startEndTokens) {

        if (str.length() < 2) {
            return str;
        }

        int startIndex = 0;
        int endIndex = str.length() - 1;

        while (startIndex < endIndex) {
            char firstCharacter = str.charAt(startIndex);
            char lastCharacter = str.charAt(endIndex);

            boolean foundStartEndTokens = false;

            for (IPair<Character, Character> startEndToken : startEndTokens) {
                char startToken = startEndToken.first();
                char endToken = startEndToken.second();

                if (firstCharacter == startToken && lastCharacter == endToken) {
                    foundStartEndTokens = true;
                    break;
                }
            }

            if (foundStartEndTokens) {
                ++startIndex;
                --endIndex;
            }
            else {
                break;
            }
        }

        int length = Indexes.size(startIndex, endIndex);
        return length > 0 ? str.substring(startIndex, endIndex + 1) : "";
    }

    /**
     * Wraps a string with a character.
     */
    public static String wrap(String str, char start, char end) {
        return start + str + end;
    }

    /**
     * Wraps a string with a string.
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
     * Wraps a string with quotes.
     */
    public static String wrapWithQuotes(String str) {
        return '"' + str + '"';
    }

    /**
     * The Strings constructor - Disables the default constructor.
     */
    private Strings() {
    }
}
