package base.core;

import base.interfaces.IPathBuilder;
import java.util.Stack;

/**
 * The WindowsPath class implements a windows path.
 */
public final class WindowsPath extends AbstractPath {
    public static final char separator = '\\';

    public static final String directorySeparator = String.valueOf(separator);
    public static final String directorySeparatorRegex = "\\\\";
    public static final String currentDirectory = Paths.currentDirectory;
    public static final String parentDirectory = Paths.parentDirectory;

    /**
     * The WindowsPath constructor.
     */
    public WindowsPath(String path) {
        super(path);
    }

    /**
     * Gets the directory section of the path.
     */
    public static String getDirectory(String path) {
        return Paths.getDirectory(path, WindowsPath.directorySeparator);
    }

    /**
     * Makes an absolute path.
     */
    @Override
    protected String makeAbsolutePath(String path) {
        return WindowsPath.makeAbsolute(path);
    }

    /**
     * Makes a canonical path.
     */
    @Override
    protected String makeCanonicalPath(String path) {
        return WindowsPath.makeCanonical(path);
    }

    /**
     * Validates a path.
     */
    @Override
    protected void validatePath(String path) {
        WindowsPath.validate(path);
    }

    /**
     * Validates a unix path.
     */
    public static void validate(String path) {
        Conditions.validateStringNotNullOrEmpty(
            path,
            "The windows path.");
    }

    /**
     * Makes an absolute path.
     */
    private static String makeAbsolute(String path) {
        return makeCanonical(path);
    }

    /**
     * Makes a canonical path.
     */
    private static String makeCanonical(String path) {
        String[] components = path.split(WindowsPath.directorySeparatorRegex);

        Stack<String> stack = new Stack<>();

        for (String component : components) {
            if (component.isEmpty() || component.equals(WindowsPath.currentDirectory)) {
                continue;
            }
            else if (component.equals(WindowsPath.parentDirectory)) {
                if (!stack.empty()) {
                    stack.pop();
                }
            }
            else {
                stack.push(component);
            }
        }

        IPathBuilder pathBuilder = new PathBuilder();

        for (String component : stack) {
            pathBuilder.addComponent(component);
        }

        return pathBuilder.build();
    }
}
