package base.core;

import java.nio.file.Path;

/**
 * The Paths class implements complementary APIs for paths.
 */
public final class Paths {
    public static final String currentDirectory = ".";
    public static final String parentDirectory = "..";

    private final static String separator = System.getProperty("file.separator");

    /**
     * Creates a new file path.
     */
    public static Path create(String path) {
        return java.nio.file.Paths.get(path);
    }

    /**
     * Determines whether a path is not null or empty.
     */
    public static boolean isNullOrEmpty(Path path) {
        return path == null || path.toString().isEmpty();
    }

    /**
     * Gets the directory section of the path.
     */
    public static String getDirectory(String path) {
        return getDirectory(path, separator);
    }

    /**
     * Gets the directory section of the path.
     * Returns null if no directory is found.
     */
    public static String getDirectory(String path, String separator) {
        Paths.validateSeparator(separator);

        if (path == null) {
            return null;
        }

        char[] directory = getDirectory(path.toCharArray(), separator.toCharArray());

        return (directory != null) ? new String(directory) : null;
    }

    /**
     * Checks whether paths are equivalent.
     */
    public static boolean pathsEquivalent(
        String path1,
        String path2) {

        return pathsEquivalent(path1, path2, Paths.separator);
    }

    /**
     * Checks whether paths are equivalent.
     */
    public static boolean pathsEquivalent(
        String path1,
        String path2,
        String separator) {

        validateSeparator(separator);

        if (path1 == null && path2 == null) {
            return true;
        }

        if (path1 == null || path2 == null) {
            return false;
        }

        return pathsEquivalent(
            path1.toCharArray(),
            path2.toCharArray(),
            separator.toCharArray());
    }

    /**
     * Gets a relative path.
     * Returns null if a relative path is not found.
     */
    public static String getRelativePath(String path, String rootPath) {
        return getRelativePath(path, rootPath, separator);
    }

    /**
     * Gets a relative path.
     * Returns null if a relative path is not found.
     */
    public static String getRelativePath(String path, String rootPath, String separator) {
        Paths.validateSeparator(separator);

        if (path == null || rootPath == null) {
            return null;
        }

        char[] relativePath = getRelativePath(
            path.toCharArray(),
            rootPath.toCharArray(),
            separator.toCharArray());

        return (relativePath != null) ? new String(relativePath) : null;
    }

    /**
     * Finds the end index of the common root path.
     * The common root path does not include a last separator.
     *
     * Return -1 if no common root path is found.
     */
    public static int findCommonRootPathEndIndex(String path1, String path2) {
        return findCommonRootPathEndIndex(path1, path2, separator);
    }

    /**
     * Finds the end index of the common root path.
     * The common root path does not include a last separator.
     *
     * Return -1 if no common root path is found.
     */
    public static int findCommonRootPathEndIndex(
        String path1,
        String path2,
        String separator) {

        Paths.validateSeparator(separator);

        if (path1 == null || path2 == null) {
            return -1;
        }

        return findCommonRootPathEndIndex(
            path1.toCharArray(),
            path2.toCharArray(),
            separator.toCharArray());
    }

    /**
     * Converts separators of the path to Windows.
     */
    public static String separatorToWindows(String path) {
        return convertSeparators(path, UnixPath.separator, WindowsPath.separator);
    }

    /**
     * Converts separators of the path to Unix.
     */
    public static String separatorToUnix(String path) {
        return convertSeparators(path, WindowsPath.separator, UnixPath.separator);
    }

    /**
     * Gets the directory section of the path.
     */
    private static char[] getDirectory(char[] path, char[] separator) {
        assert(path != null);
        assert(separator != null);

        if (path.length < separator.length) {
            return null;
        }

        int currIndex = path.length - 1;

        int directoryStartIndex = 0;
        int directoryEndIndex = -1;

        while (currIndex >= separator.length - 1) {
            if (StringSearch.endsWith(path, currIndex, separator)) {
                directoryEndIndex = currIndex - separator.length;
                break;
            }

            --currIndex;
        }

        int directoryLength = pathLength(directoryStartIndex, directoryEndIndex);

        return (directoryLength > 0) ?
            Strings.clone(path, directoryStartIndex, directoryLength) :
            null;
    }

    /**
     * Checks whether paths are equivalent.
     */
    private static boolean pathsEquivalent(
        char[] path1,
        char[] path2,
        char[] separator) {

        assert(path1 != null);
        assert(path2 != null);
        assert(separator != null);

        return pathsEquivalent(
            path1, path1.length - 1,
            path2, path2.length - 1,
            separator);
    }

    /**
     * Checks whether paths are equivalent.
     */
    private static boolean pathsEquivalent(
        char[] path1,
        int endIndex1,
        char[] path2,
        int endIndex2,
        char[] separator) {

        assert(path1 != null);
        assert(endIndex1 >= 0 && endIndex1 < path1.length);

        assert(path2 != null);
        assert(endIndex2 >= 0 && endIndex2 < path2.length);

        assert(separator != null);

        int effectiveEndIndex1 = pathEffectiveEndIndex(path1, endIndex1, separator);
        int pathLength1 = pathLength(0, effectiveEndIndex1);

        int effectiveEndIndex2 = pathEffectiveEndIndex(path2, endIndex2, separator);
        int pathLength2 = pathLength(0, effectiveEndIndex2);

        if (pathLength1 != pathLength2) {
            return false;
        }

        int length = pathLength1;

        return StringEquality.equals(path1, 0, path2, 0, length);
    }

    /**
     * Gets a relative path.
     * Returns null if no relative path is found.
     */
    private static char[] getRelativePath(
        char[] path,
        char[] rootPath,
        char[] separator) {

        assert(path != null);
        assert(rootPath != null);
        assert(separator != null);

        return getRelativePath(
            path, path.length - 1,
            rootPath, rootPath.length - 1,
            separator);
    }

    /**
     * Gets a relative path.
     * Returns null if no relative path is found.
     */
    private static char[] getRelativePath(
        char[] path,
        int pathEndIndex,
        char[] rootPath,
        int rootPathEndIndex,
        char[] separator) {

        assert(path != null);
        assert(pathEndIndex >= 0 && pathEndIndex < path.length);
        assert(rootPath != null);
        assert(rootPathEndIndex >= 0 && rootPathEndIndex < rootPath.length);
        assert(separator != null);

        //
        // Find the end index of the common root path...
        //
        int commonRootPathEndIndex = findCommonRootPathEndIndex(
            path, pathEndIndex,
            rootPath, rootPathEndIndex,
            separator);

        if (commonRootPathEndIndex == -1) {
            return null;
        }

        Conditions.validate(
            !StringSearch.endsWith(path, commonRootPathEndIndex, separator) &&
            !StringSearch.endsWith(rootPath, commonRootPathEndIndex, separator),
            "Failed finding the end index of the common root path." +
            " The common root path can not end with a separator.");

        //
        // Calculate the relative path length of the root path...
        //
        int rootPathEffectiveStartIndex = commonRootPathEndIndex;
        int rootPathEffectiveEndIndex = rootPathEndIndex;

        int numberOfSubDirectories = getNumberOfSubDirectories(
            rootPath,
            rootPathEffectiveStartIndex,
            rootPathEffectiveEndIndex,
            separator);

        int relativePathLengthOfRootPath =
            (numberOfSubDirectories > 0) ?
            numberOfSubDirectories * (Paths.parentDirectory.length() + separator.length) :
            Paths.currentDirectory.length() + separator.length;

        //
        // Calculate the relative path length of the path...
        //
        int pathEffectiveStartIndex = commonRootPathEndIndex + separator.length + 1;
        int pathEffectiveEndIndex = pathEffectiveEndIndex(path, pathEndIndex, separator);

        int relativePathLengthOfPath = pathLength(pathEffectiveStartIndex, pathEffectiveEndIndex);

        if (relativePathLengthOfPath == 0) {
            pathEffectiveStartIndex = -1;
            pathEffectiveEndIndex = -1;
        }

        //
        // Create the relative path...
        //
        int resultLength = relativePathLengthOfRootPath + relativePathLengthOfPath;
        char[] result = new char[resultLength];

        int insertIndex = 0;
        int numberOfWrittenCharacters = 0;

        //
        // Add the relative path of the root path...
        //
        if (numberOfSubDirectories > 0) {
            char[] parentDirectory = Paths.parentDirectory.toCharArray();

            for (int i = 0; i < numberOfSubDirectories; ++i) {
                //
                // Add the parent directory of the relative path of the root path...
                //
                numberOfWrittenCharacters = Strings.copy(
                    parentDirectory, 0,
                    result, insertIndex,
                    parentDirectory.length);

                Conditions.validate(
                    numberOfWrittenCharacters == parentDirectory.length,
                    "Failed copying a parent directory of the relative path of the root path.");

                insertIndex += numberOfWrittenCharacters;

                //
                // Add the separator of the relative path of the root path...
                //
                numberOfWrittenCharacters = Strings.copy(
                    separator, 0,
                    result, insertIndex,
                    separator.length);

                Conditions.validate(
                    numberOfWrittenCharacters == separator.length,
                    "Failed copying a separator of the relative path of the root path.");

                insertIndex += numberOfWrittenCharacters;
            }
        } else {
            char[] currentDirectory = Paths.currentDirectory.toCharArray();

            //
            // Add the current directory of the relative path of the root path...
            //
            numberOfWrittenCharacters = Strings.copy(
                currentDirectory, 0,
                result, insertIndex,
                currentDirectory.length);

            Conditions.validate(
                numberOfWrittenCharacters == currentDirectory.length,
                "Failed copying a current directory of the relative path of the root path.");

            insertIndex += numberOfWrittenCharacters;

            //
            // Add the separator of the relative path of the root path...
            //
            numberOfWrittenCharacters = Strings.copy(
                separator, 0,
                result, insertIndex,
                separator.length);

            Conditions.validate(
                numberOfWrittenCharacters == separator.length,
                "Failed copying a separator of the relative path of the root path.");

            insertIndex += numberOfWrittenCharacters;
        }

        //
        // Add the relative path of the path...
        //
        if (relativePathLengthOfPath > 0) {
            numberOfWrittenCharacters = Strings.copy(
                path, pathEffectiveStartIndex,
                result, insertIndex,
                relativePathLengthOfPath);

            Conditions.validate(
                numberOfWrittenCharacters == relativePathLengthOfPath,
                "Failed copying the relative path of the path.");

            insertIndex += numberOfWrittenCharacters;
        }

        assert(insertIndex == result.length);

        return result;
    }

    /**
     * Finds the end index of the common root path.
     * The common root path does not include a last separator.
     *
     * Return -1 if no common root path is found.
     */
    private static int findCommonRootPathEndIndex(
        char[] path1,
        char[] path2,
        char[] separator) {

        assert(path1 != null);
        assert(path2 != null);
        assert(separator != null);

        return findCommonRootPathEndIndex(
            path1,
            path1.length - 1,
            path2,
            path2.length - 1,
            separator);
    }

    /**
     * Finds the end index of the common root path.
     * The common root path does not include a last separator.
     *
     * Return -1 if no common root path is found.
     */
    private static int findCommonRootPathEndIndex(
        char[] path1,
        int endIndex1,
        char[] path2,
        int endIndex2,
        char[] separator) {

        assert(path1 != null);
        assert(endIndex1 >= 0 && endIndex1 < path1.length);

        assert(path2 != null);
        assert(endIndex2 >= 0 && endIndex2 < path2.length);

        assert(separator != null);

        int effectiveEndIndex1 = pathEffectiveEndIndex(path1, endIndex1, separator);
        int length1 = pathLength(0, effectiveEndIndex1);

        int effectiveEndIndex2 = pathEffectiveEndIndex(path2, endIndex2, separator);
        int length2 = pathLength(0, effectiveEndIndex2);

        if (length1 == 0 || length2 == 0) {
            return -1;
        }

        int pathIndex = 0;

        while (pathIndex <= effectiveEndIndex1 && pathIndex <= effectiveEndIndex2) {
            char pathCharacter1 = path1[pathIndex];
            char pathCharacter2 = path2[pathIndex];

            if (pathCharacter1 != pathCharacter2) {
                break;
            }

            ++pathIndex;
        }

        int commonEndIndex = pathIndex - 1;

        if (commonEndIndex < 0) {
            return -1;
        }

        if (commonEndIndex == effectiveEndIndex1 && commonEndIndex == effectiveEndIndex2) {
            return commonEndIndex;
        }

        if (commonEndIndex == effectiveEndIndex1 &&
            commonEndIndex + separator.length <= effectiveEndIndex2 &&
            StringSearch.startsWith(path2, commonEndIndex + 1, separator)) {

            return commonEndIndex;
        }

        if (commonEndIndex == effectiveEndIndex2 &&
            commonEndIndex + separator.length <= effectiveEndIndex1 &&
            StringSearch.startsWith(path1, commonEndIndex + 1, separator)) {

            return commonEndIndex;
        }

        int lastSeparatorIndex = findLastSeparatorIndex(path1, 0, commonEndIndex, separator);

        if (lastSeparatorIndex == -1) {
            return -1;
        }

        return lastSeparatorIndex - separator.length;
    }

    /**
     * Finds an index of the last separator.
     *
     * Return -1 if no separator is found.
     */
    private static int findLastSeparatorIndex(
        char[] path,
        int startIndex, int endIndex,
        char[] separator) {

        assert(path != null);
        assert(startIndex >= 0 && startIndex < path.length);
        assert(endIndex >= startIndex && endIndex < path.length);
        assert(separator != null);

        if (startIndex > endIndex) {
            return -1;
        }

        int currIndex = endIndex;
        int currSeparatorIndex = separator.length - 1;

        while (currIndex >= startIndex && currSeparatorIndex >= 0) {
            char currCharacter = path[currIndex];
            char currSeparatorCharacter = separator[currSeparatorIndex];

            if (currCharacter == currSeparatorCharacter) {
                if (currSeparatorIndex == 0) {
                    return currIndex;
                }

                --currSeparatorCharacter;
            } else {
                currSeparatorIndex = separator.length - 1;
            }

            --currIndex;
        }

        return -1;
    }

    /**
     * Gets the number of sub directories.
     */
    private static int getNumberOfSubDirectories(
        char[] path,
        int startIndex,
        int endIndex,
        char[] separator) {

        assert(path != null);
        assert(startIndex >= 0 && startIndex < path.length);
        assert(endIndex >= startIndex && endIndex < path.length);
        assert(separator != null);

        int pathStartIndex = startIndex;
        int pathEndIndex = pathEffectiveEndIndex(path, endIndex, separator);

        int counter = StringSearch.countSubStringFromEnd(
            path,
            pathStartIndex, pathEndIndex,
            separator, 0, separator.length,
            false);

        return counter;
    }

    /**
     * Converts separators of a path.
     */
    private static String convertSeparators(String path, char fromSeparator, char toSeparator) {
        if (path == null || path.isEmpty()) {
            return path;
        }

        char[] pathBuffer = path.toCharArray();
        char[] resultPathBuffer = Strings.clone(pathBuffer, 0, pathBuffer.length);
        convertSeparators(resultPathBuffer, fromSeparator, toSeparator);

        return new String(resultPathBuffer);
    }

    /**
     * Converts separators of a path.
     */
    public static void convertSeparators(char[] path, char fromSeparator, char toSeparator) {
        assert(path != null);

        for (int i = 0; i < path.length; ++i) {
            char currCharacter = path[i];

            if (currCharacter == fromSeparator) {
                path[i] = toSeparator;
            }
        }
    }

    /**
     * Gets the effective start index of a path.
     */
    private static int pathEffectiveStartIndex(char[] path, int startIndex, char[] separator) {
        assert(path != null);
        assert(startIndex >= 0 && startIndex < path.length);
        assert(separator != null);

        return StringSearch.startsWith(path, startIndex, separator) ? startIndex + separator.length : startIndex;
    }

    /**
     * Gets an effective end index of a path.
     */
    private static int pathEffectiveEndIndex(char[] path, int endIndex, char[] separator) {
        assert(path != null);
        assert(endIndex >= 0 && endIndex < path.length);
        assert(separator != null);

        return StringSearch.endsWith(path, endIndex, separator) ? endIndex - separator.length : endIndex;
    }

    /**
     * Calculates length of a path.
     */
    private static int pathLength(int startIndex, int endIndex) {
        return startIndex <= endIndex ? endIndex - startIndex + 1 : 0;
    }

    /**
     * Validates a separator.
     */
    private static void validateSeparator(String separator) {
        Conditions.validateStringNotNullOrEmpty(
            separator,
            "The separator of a path can not be null or empty.");
    }

    /**
     * The Paths constructor - Disables the default constructor.
     */
    private Paths() {
    }
}
