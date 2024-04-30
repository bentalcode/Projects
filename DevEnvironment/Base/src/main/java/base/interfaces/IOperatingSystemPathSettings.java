package base.interfaces;

/**
 * The IOperatingSystemPathSettings interface defines settings of paths of an operating system.
 */
public interface IOperatingSystemPathSettings {
    /**
     * Gets a path separator.
     */
    String getPathSeparator();

    /**
     * Creates a path.
     */
    IPath createPath(String path);

    /**
     * Creates a path builder.
     */
    IPathBuilder createPathBuilder();
}
