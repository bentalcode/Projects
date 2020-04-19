package base.interfaces;

/**
 * The IPath interface defines a path.
 */
public interface IPath {
    /**
     * Gets the path.
     */
    String getPath();

    /**
     * Gets the absolute path.
     */
    String getAbsolutePath();

    /**
     * Gets the canonical path.
     */
    String getCanonicalPath();
}
