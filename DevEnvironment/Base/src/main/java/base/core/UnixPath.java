package base.core;
import base.interfaces.IPathBuilder;
import java.util.Stack;

/**
 * The UnixPath class implements a unix path.
 */
public final class UnixPath extends AbstractPath {
    public static final char separator = '/';

    public static final String rootDirectory = "/";
    public static final String directorySeparator = "/";
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
     * Resolves a path.
     * To be implemented...
     */
    @Override
    protected String resolvePath(String path) {
        return path;
    }

    /**
     * Makes a canonical path.
     */
    @Override
    protected String makeCanonicalPath(String path) {
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

        IPathBuilder pathBuilder = new LinuxPathBuilder();

        for (String component : stack) {
            pathBuilder.addComponent(component);
        }

        return pathBuilder.build();
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

        String initialComponent = String.valueOf(path.charAt(0));

        Conditions.validate(
            initialComponent.equals(UnixPath.directorySeparator),
            "A unix path starts with an initial forward slash.");
    }
}
