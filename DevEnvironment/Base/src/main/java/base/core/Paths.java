package base.core;

import java.nio.file.Path;

/**
 * The Paths class implements complementary APIs for paths.
 */
public final class Paths {
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
        if (path == null || separator == null) {
            return null;
        }

        char[] directory = getDirectory(path.toCharArray(), separator.toCharArray());

        return (directory != null) ? new String(directory) : null;
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
     * Converts the separator of the path to Windows.
     */
    public static String separatorToWindows(String path) {
        return convertSeparator(path, UnixPath.separator, WindowsPath.separator);
    }

    /**
     * Converts the separators of the path to Unix.
     */
    public static String separatorToUnix(String path) {
        return convertSeparator(path, WindowsPath.separator, UnixPath.separator);
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
            if (Strings.endsWith(path, currIndex, separator)) {
                directoryEndIndex = currIndex - separator.length;
                break;
            }

            --currIndex;
        }

        return (directoryEndIndex >= directoryStartIndex) ?
            Strings.clone(path, directoryStartIndex, directoryEndIndex - directoryStartIndex + 1) :
            null;
    }

    /**
     * Gets a relative path.
     * Avoiding using additional stack data structure for processing components of a path.
     * Returns null if no relative path is found.
     */
    private static char[] getRelativePath(
        char[] path,
        char[] rootPath,
        char[] separator) {

        if (path.length < rootPath.length) {
            return null;
        }

        int pathIndex = 0;
        int rootPathIndex = 0;

        while (pathIndex < path.length && rootPathIndex < rootPath.length) {
            char pathCharacter = path[pathIndex];
            char rootPathCharacter = rootPath[rootPathIndex];

            if (pathCharacter != rootPathCharacter) {
                return null;
            }

            ++pathIndex;
            ++rootPathIndex;
        }

        int reminderLength = path.length - pathIndex;

        if (reminderLength == 0) {
            char[] result = new char[1];
            result[0] = '.';
            return result;
        }

        int subPathStartIndex = Strings.startsWith(path, pathIndex, separator) ?
            pathIndex + separator.length :
            pathIndex;

        int subPathEndIndex = Strings.endsWith(path, separator) ?
            path.length - 1 - separator.length :
            path.length - 1;

        int subPathLength = subPathEndIndex - subPathStartIndex + 1;

        int resultLength = 1 + separator.length + subPathLength;
        char[] result = new char[resultLength];

        result[0] = '.';
        int insertIndex = 1;

        int numberOfWrittenCharacters = Strings.copy(separator, 0, result, insertIndex, separator.length);

        Conditions.validate(
            numberOfWrittenCharacters == separator.length,
            "Failed copying the initial separator of the relative path.");

        insertIndex += numberOfWrittenCharacters;

        numberOfWrittenCharacters = Strings.copy(path, subPathStartIndex, result, insertIndex, subPathLength);

        Conditions.validate(
            numberOfWrittenCharacters == subPathLength,
            "Failed copying the initial separator of the relative path.");

        return result;
    }

    /**
     * Converts separators of a path.
     */
    private static String convertSeparator(String path, char fromSeparator, char toSeparator) {
        if (path == null || path.isEmpty()) {
            return path;
        }

        char[] pathBuffer = path.toCharArray();
        char[] resultPathBuffer = Strings.clone(pathBuffer, 0, pathBuffer.length);
        convertSeparator(resultPathBuffer, fromSeparator, toSeparator);

        return new String(resultPathBuffer);
    }

    /**
     * Converts separators of a path.
     */
    public static void convertSeparator(char[] path, char fromSeparator, char toSeparator) {
        for (int i = 0; i < path.length; ++i) {
            char currCharacter = path[i];

            if (currCharacter == fromSeparator) {
                path[i] = toSeparator;
            }
        }
    }

    /**
     * The Paths constructor - Disables the default constructor.
     */
    private Paths() {
    }
}
