package base.core;

import base.interfaces.IPathBuilder;
import java.nio.file.Path;
import java.util.LinkedList;
import java.util.Stack;

/**
 * The Paths class implements complementary APIs for paths.
 */
public final class Paths {
    public static final String CURRENT_DIRECTORY = ".";
    public static final String PARENT_DIRECTORY = "..";

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
        return getDirectory(
            path,
            Environment.getOperatingSystemControlSettings().pathSettings().getPathSeparator());
    }

    /**
     * Gets the directory section of the path.
     * Returns null if no directory is found.
     */
    public static String getDirectory(String path, String separator) {
        Conditions.validateNotNull(
            path,
            "The path.");

        Paths.validateSeparator(separator);

        char[] directory = getDirectory(path.toCharArray(), separator.toCharArray());

        return (directory != null) ? new String(directory) : null;
    }

    /**
     * Gets a file extension of a path.
     */
    public String getFileExtension(String path) {
        Conditions.validateNotNull(
            path,
            "The path.");

        return FileNames.getExtension(path);
    }

    /**
     * Gets an file name of a path.
     */
    public static String getFileName(String path) {
        return getFileName(
            path,
            Environment.getOperatingSystemControlSettings().pathSettings().getPathSeparator());
    }

    /**
     * Gets an file name of a path.
     */
    public static String getFileName(
        String path,
        String separator) {

        Conditions.validateStringNotNullOrEmpty(
            path,
            "The path.");

        Conditions.validateNotNull(
            separator,
            "The separator.");

        char[] pathArray = path.toCharArray();
        int extensionIndex = FileNames.getFileExtensionIndex(pathArray);
        int separatorStartIndex = StringSearch.lastIndexOf(
            pathArray,
            0,
            extensionIndex - 1,
            separator.toCharArray());

        if (separatorStartIndex == -1) {
            return "";
        }

        int fileNameStartIndex = (separatorStartIndex == -1) ? 0 : separatorStartIndex + separator.length();
        int fileNameEndIndex = extensionIndex - 1;

        return path.substring(fileNameStartIndex, fileNameEndIndex + 1);
    }

    /**
     * Checks whether paths are equivalent.
     */
    public static boolean pathsEquivalent(
        String path1,
        String path2) {

        return pathsEquivalent(
            path1,
            path2,
            Environment.getOperatingSystemControlSettings().pathSettings().getPathSeparator());
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
        return getRelativePath(
            path,
            rootPath,
            Environment.getOperatingSystemControlSettings().pathSettings().getPathSeparator());
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
     * Normalizes a path.
     */
    public static String normalizePath(String path) {
        return normalizePath(
            path,
            Environment.getOperatingSystemControlSettings().pathSettings().getPathSeparator());
    }

    /**
     * Normalizes a path.
     */
    public static String normalizePath(String path, String separator) {
        Conditions.validateNotNull(
            path,
            "The path.");

        Conditions.validateStringNotNullOrEmpty(
            separator,
            "The separator.");

        String effectiveSeparator = Strings.replace(separator, "\\", "\\\\");

        String[] tokens = path.split(effectiveSeparator);

        Stack<String> tokenStack = new Stack<>();

        for (String token : tokens) {
            tokenStack.push(token);
        }

        LinkedList<String> components = new LinkedList<>();

        while (!tokenStack.empty()) {
            String currComponent = tokenStack.pop();

            if (currComponent.equals(Paths.CURRENT_DIRECTORY)) {
                continue;
            }

            if (currComponent.equals(Paths.PARENT_DIRECTORY)) {
                tokenStack.pop();
            }

            components.addFirst(currComponent);
        }

        IPathBuilder pathBuilder = Environment.getOperatingSystemControlSettings().pathSettings().createPathBuilder();

        for (String component : components) {
            pathBuilder.addComponent(component);
        }

        return pathBuilder.build();
    }

    /**
     * Finds the end index of the common root path.
     * The common root path does not include a last separator.
     *
     * Return -1 if no common root path is found.
     */
    public static int findCommonRootPathEndIndex(String path1, String path2) {
        return findCommonRootPathEndIndex(
            path1,
            path2,
            Environment.getOperatingSystemControlSettings().pathSettings().getPathSeparator());
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
        return convertSeparators(path, UnixPath.SEPARATOR, WindowsPath.SEPARATOR);
    }

    /**
     * Converts separators of the path to Unix.
     */
    public static String separatorToUnix(String path) {
        return convertSeparators(path, WindowsPath.SEPARATOR, UnixPath.SEPARATOR);
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

        return StringEquality.equals(path1, 0, path2, 0, pathLength1);
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
        int numberOfSubDirectories = getNumberOfSubDirectories(
            rootPath,
            commonRootPathEndIndex,
            rootPathEndIndex,
            separator);

        int relativePathLengthOfRootPath =
            (numberOfSubDirectories > 0) ?
            numberOfSubDirectories * (Paths.PARENT_DIRECTORY.length() + separator.length) :
            Paths.CURRENT_DIRECTORY.length() + separator.length;

        //
        // Calculate the relative path length of the path...
        //
        int pathEffectiveStartIndex = commonRootPathEndIndex + separator.length + 1;
        int pathEffectiveEndIndex = pathEffectiveEndIndex(path, pathEndIndex, separator);

        int relativePathLengthOfPath = pathLength(pathEffectiveStartIndex, pathEffectiveEndIndex);

        if (relativePathLengthOfPath == 0) {
            pathEffectiveStartIndex = -1;
        }

        //
        // Create the relative path...
        //
        int resultLength = relativePathLengthOfRootPath + relativePathLengthOfPath;
        char[] result = new char[resultLength];

        int insertIndex = 0;
        int numberOfWrittenCharacters;

        //
        // Add the relative path of the root path...
        //
        if (numberOfSubDirectories > 0) {
            char[] parentDirectory = Paths.PARENT_DIRECTORY.toCharArray();

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
            char[] currentDirectory = Paths.CURRENT_DIRECTORY.toCharArray();

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

        int pathEndIndex = pathEffectiveEndIndex(path, endIndex, separator);

        return StringSearch.countSubStringFromEnd(
            path,
            startIndex, pathEndIndex,
            separator, 0, separator.length - 1,
            false);
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
