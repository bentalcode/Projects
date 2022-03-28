package base.core;

import base.interfaces.IPathBuilder;
import java.util.Stack;

/**
 * The WindowsPath class implements a windows path.
 */
public final class WindowsPath extends AbstractPath {
    public static final char SEPARATOR = '\\';

    public static final String DIRECTORY_SEPARATOR = String.valueOf(SEPARATOR);
    public static final String DIRECTORY_SEPARATOR_REGEX = "\\\\";
    public static final String CURRENT_DIRECTORY = Paths.CURRENT_DIRECTORY;
    public static final String PARENT_DIRECTORY = Paths.PARENT_DIRECTORY;

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
        return Paths.getDirectory(path, WindowsPath.DIRECTORY_SEPARATOR);
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
        String[] components = path.split(WindowsPath.DIRECTORY_SEPARATOR_REGEX);

        Stack<String> stack = new Stack<>();

        for (String component : components) {
            if (component.equals(WindowsPath.PARENT_DIRECTORY)) {
                stack.pop();
            }
            else if (!component.isEmpty() &&
                     !component.equals(WindowsPath.CURRENT_DIRECTORY)) {

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
