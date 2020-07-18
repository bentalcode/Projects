package base.core;

import base.interfaces.IPathBuilder;
import java.util.Stack;

/**
 * The UnixPath class implements a unix path.
 */
public final class UnixPath extends AbstractPath {
    public static final char separator = '/';

    public static final String rootDirectory = "/";
    public static final String directorySeparator = String.valueOf(separator);
    public static final String currentDirectory = Paths.currentDirectory;
    public static final String parentDirectory = Paths.parentDirectory;
    public static final String homeDirectory = "~";

    /**
     * The UnixPath constructor.
     */
    public UnixPath(String path) {
        super(path);
    }

    /**
     * Gets the directory section of the path.
     */
    public static String getDirectory(String path) {
        return Paths.getDirectory(path, UnixPath.directorySeparator);
    }

    /**
     * Makes an absolute path.
     */
    @Override
    protected String makeAbsolutePath(String path) {
        return UnixPath.makeAbsolute(path);
    }

    /**
     * Makes a canonical path.
     */
    @Override
    protected String makeCanonicalPath(String path) {
        return UnixPath.makeCanonical(path);
    }

    /**
     * Validates a path.
     */
    @Override
    protected void validatePath(String path) {
        UnixPath.validate(path);
    }

    /**
     * Validates a unix path.
     */
    public static void validate(String path) {
        Conditions.validateStringNotNullOrEmpty(
            path,
            "The unix path.");
    }

    /**
     * Makes an absolute path.
     */
    private static String makeAbsolute(String path) {
        String homeDirectory;
        String reminder;

        if (path.startsWith(UnixPath.homeDirectory)) {
            homeDirectory = System.getProperty("user.home");
            reminder = path.substring(UnixPath.homeDirectory.length());
        }
        else {
            homeDirectory = "";
            reminder = path;
        }

        String canonicalPath = makeCanonical(reminder);

        IPathBuilder pathBuilder = new UnixPathBuilder();

        if (!homeDirectory.isEmpty()) {
            pathBuilder.addComponent(homeDirectory);
        }

        pathBuilder.addComponent(canonicalPath);

        return pathBuilder.build();
    }

    /**
     * Makes a canonical path.
     */
    private static String makeCanonical(String path) {
        String[] components = path.split(UnixPath.directorySeparator);

        Stack<String> stack = new Stack<>();

        for (String component : components) {
            if (component.isEmpty() || component.equals(UnixPath.currentDirectory)) {
                continue;
            }
            else if (component.equals(UnixPath.parentDirectory)) {
                if (!stack.empty()) {
                    stack.pop();
                }
            }
            else {
                stack.push(component);
            }
        }

        IPathBuilder pathBuilder = new UnixPathBuilder();

        for (String component : stack) {
            pathBuilder.addComponent(component);
        }

        return pathBuilder.build();
    }
}
