package base.core;

import base.BaseException;
import base.interfaces.FileNameType;
import java.util.Set;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The FileNames class implements complementary APIs for file-names.
 */
public final class FileNames {
    public static final char EXTENSION_SEPARATOR = '.';
    public static final char KABAB_CASED_SEPARATOR = '-';
    public static final char SNAKE_CASED_SEPARATOR = '_';

    public static final Set<Character> INVALID_CHARACTERS = HashSets.make(
        ':',
        '\\',
        '/',
        '*',
        '?',
        '|',
        '<',
        '>');

    private final static Logger LOG = LoggerFactory.getLogger(FileNameType.class);

    /**
     * Gets a type of a file name.
     */
    public static FileNameType getFileNameType(String fileName) {
        if (isCamelCased(fileName)) {
            return FileNameType.Camel;
        }
        else if (isPascalCased(fileName)) {
            return FileNameType.Pascal;
        }
        else if (isKababCased(fileName)) {
            return FileNameType.Kabab;
        }
        else if (isSnakeCased(fileName)) {
            return FileNameType.Snake;
        }
        else {
            String errorMessage = "The type of file name: " + fileName + " is not supported.";

            LOG.error(errorMessage);
            throw new BaseException(errorMessage);
        }
    }

    /**
     * Gets an extension of a file name.
     */
    public static String getExtension(String fileName) {
        Conditions.validateStringNotNullOrEmpty(
            fileName,
            "The name of a file.");

        int extensionIndex = getFileExtensionIndex(fileName.toCharArray());

        if (extensionIndex == -1 || extensionIndex == 0) {
            return "";
        }

        int extensionStartIndex = extensionIndex + 1;
        int extensionEndIndex = fileName.length() - 1;

        return fileName.substring(extensionStartIndex, extensionEndIndex + 1);
    }

    /**
     * Determines whether a file name is a Camel cased: fileName.h
     */
    public static boolean isCamelCased(String fileName) {
        Conditions.validateStringNotNullOrEmpty(
            fileName,
            "The name of a file.");

        char[] characters = fileName.toCharArray();

        if (Character.isUpperCase(characters[0])) {
            return false;
        }

        int endIndex = getNameEndIndex(characters);
        int currIndex = 0;

        while (currIndex <= endIndex) {
            char currCharacter = characters[currIndex];

            if (INVALID_CHARACTERS.contains(currCharacter) ||
                currCharacter == KABAB_CASED_SEPARATOR ||
                currCharacter == SNAKE_CASED_SEPARATOR) {

                return false;
            }

            ++currIndex;
        }

        return true;
    }

    /**
     * Determines whether a file name is a Pascal cased: FileName.h
     */
    public static boolean isPascalCased(String fileName) {
        Conditions.validateStringNotNullOrEmpty(
            fileName,
            "The name of a file.");

        char[] characters = fileName.toCharArray();

        if (Character.isLowerCase(characters[0])) {
            return false;
        }

        int endIndex = getNameEndIndex(characters);
        int currIndex = 0;

        while (currIndex <= endIndex) {
            char currCharacter = characters[currIndex];

            if (INVALID_CHARACTERS.contains(currCharacter) ||
                currCharacter == KABAB_CASED_SEPARATOR ||
                currCharacter == SNAKE_CASED_SEPARATOR) {

                return false;
            }

            ++currIndex;
        }

        return true;
    }

    /**
     * Determines whether a file name is a Kabab cased: file-name.h
     */
    public static boolean isKababCased(String fileName) {
        Conditions.validateStringNotNullOrEmpty(
            fileName,
            "The name of a file.");

        char[] characters = fileName.toCharArray();

        boolean lowercase = Character.isLowerCase(characters[0]);

        int endIndex = getNameEndIndex(characters);
        int currIndex = 0;

        while (currIndex <= endIndex) {
            char currCharacter = characters[currIndex];

            if (INVALID_CHARACTERS.contains(currCharacter) ||
                currCharacter == SNAKE_CASED_SEPARATOR ||
                Character.isLowerCase(currCharacter) != lowercase) {

                return false;
            }

            ++currIndex;
        }

        return true;
    }

    /**
     * Determines whether a file name is a Snake cased: file_name.h
     */
    public static boolean isSnakeCased(String fileName) {
        Conditions.validateStringNotNullOrEmpty(
            fileName,
            "The name of a file.");

        char[] characters = fileName.toCharArray();

        boolean lowercase = Character.isLowerCase(characters[0]);

        int endIndex = getNameEndIndex(characters);
        int currIndex = 0;

        while (currIndex <= endIndex) {
            char currCharacter = characters[currIndex];

            if (INVALID_CHARACTERS.contains(currCharacter) ||
                currCharacter == KABAB_CASED_SEPARATOR ||
                Character.isLowerCase(currCharacter) != lowercase) {

                return false;
            }

            ++currIndex;
        }

        return true;
    }

    /**
     * Gets tokens of a Camel cased: fileName.h
     */
    public static String[] getCamelCasedTokens(String fileName) {
        assert(isCamelCased(fileName));
        return getCamelOrPascalCasedTokens(fileName);
    }

    /**
     * Gets tokens of a Pascal cased: FileName.h
     */
    public static String[] getPascalCasedTokens(String fileName) {
        assert(isPascalCased(fileName));
        return getCamelOrPascalCasedTokens(fileName);
    }

    /**
     * Gets tokens of a Kabab cased: File-Name.h
     */
    public static String[] getKababCasedTokens(String fileName) {
        Conditions.validateStringNotNullOrEmpty(
            fileName,
            "The name of a file.");

        assert(isKababCased(fileName));

        return fileName.split(String.valueOf(KABAB_CASED_SEPARATOR));
    }

    /**
     * Gets tokens of a Snake cased: File_Name.h
     */
    public static String[] getSnakeCasedTokens(String fileName) {
        Conditions.validateStringNotNullOrEmpty(
            fileName,
            "The name of a file.");

        assert(isSnakeCased(fileName));

        return fileName.split(String.valueOf(SNAKE_CASED_SEPARATOR));
    }

    /**
     * Gets tokens of a Camel/Pascal cased: {fileName, FileName}
     */
    private static String[] getCamelOrPascalCasedTokens(String fileName) {
        Conditions.validateStringNotNullOrEmpty(
            fileName,
            "The name of a file.");

        assert(isCamelCased(fileName) || isPascalCased(fileName));

        char[] characters = fileName.toCharArray();
        int endIndex = getNameEndIndex(characters);

        //
        // Calculate the resultant number of tokens...
        //
        int numberOfTokens = 1;
        int currIndex = 1;

        while (currIndex <= endIndex) {
            char currCharacter = fileName.charAt(currIndex);

            if (Character.isUpperCase(currCharacter)) {
                ++numberOfTokens;
            }

            ++currIndex;
        }

        //
        // Get the tokens...
        //
        String[] tokens = new String[numberOfTokens];

        int tokenStartIndex = 0;
        int insertTokenIndex = 0;

        while (tokenStartIndex <= endIndex) {
            int tokenEndIndex = findCamelOrPascalCasedTokenEndIndex(
                characters,
                tokenStartIndex,
                endIndex);

            if (tokenEndIndex == -1) {
                break;
            }

            String currToken = fileName.substring(tokenStartIndex, tokenEndIndex + 1);
            tokens[insertTokenIndex] = currToken;
            ++insertTokenIndex;

            tokenStartIndex = tokenEndIndex + 1;
        }

        assert(insertTokenIndex == numberOfTokens);

        return tokens;
    }

    /**
     * Finds an end index of a camel/pascal cased token. {fileName, FileName}
     */
    private static int findCamelOrPascalCasedTokenEndIndex(
        char[] characters,
        int tokenStartIndex,
        int endIndex) {

        assert(characters != null);
        assert(tokenStartIndex >= 0 && tokenStartIndex < characters.length);
        assert(endIndex >= tokenStartIndex && endIndex < characters.length);

        if (tokenStartIndex > endIndex) {
            return -1;
        }

        if (tokenStartIndex == endIndex) {
            return tokenStartIndex;
        }

        int currIndex = tokenStartIndex + 1;

        while (currIndex <= endIndex) {
            char currCharacter = characters[currIndex];

            if (Character.isUpperCase(currCharacter)) {
                return currIndex - 1;
            }

            ++currIndex;
        }

        return endIndex;
    }

    /**
     * Gets an end index of a name of a file (with out it's extension).
     * Returns -1 if the name is empty.
     */
    private static int getNameEndIndex(char[] fileName) {
        assert(fileName != null);
        int endIndex = getFileExtensionIndex(fileName);

        if (endIndex == -1 || endIndex == 0) {
            return -1;
        }

        return endIndex - 1;
    }

    /**
     * Gets an end index of a name of a file (with out it's extension).
     * Returns -1 if the name is empty.
     */
    public static int getFileExtensionIndex(char[] fileName) {
        assert(fileName != null);
        int endIndex = StringSearch.lastIndexOf(fileName, 0, fileName.length - 1, EXTENSION_SEPARATOR);
        return endIndex - 1;
    }

    /**
     * The FileNames constructor - Disables the default constructor.
     */
    private FileNames() {
    }
}
