package base.core;

import base.interfaces.IPathBuilder;
import java.util.Stack;

/**
 * The UnixPath class implements a unix path.
 */
public final class UnixPath extends AbstractPath {
    public static final char SEPARATOR = '/';
    public static final String ROOT_DIRECTORY = "/";
    public static final String DIRECTORY_SEPARATOR = String.valueOf(SEPARATOR);
    public static final String CURRENT_DIRECTORY = Paths.CURRENT_DIRECTORY;
    public static final String PARENT_DIRECTORY = Paths.PARENT_DIRECTORY;
    public static final String HOME_DIRECTORY = "~";

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
        return Paths.getDirectory(path, UnixPath.DIRECTORY_SEPARATOR);
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

        if (path.startsWith(UnixPath.HOME_DIRECTORY)) {
            homeDirectory = System.getProperty("user.home");
            reminder = path.substring(UnixPath.HOME_DIRECTORY.length());
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
        String[] components = path.split(UnixPath.DIRECTORY_SEPARATOR);

        Stack<String> stack = new Stack<>();

        for (String component : components) {
            if (component.isEmpty() || component.equals(UnixPath.CURRENT_DIRECTORY)) {
            }
            else if (component.equals(UnixPath.PARENT_DIRECTORY)) {
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
