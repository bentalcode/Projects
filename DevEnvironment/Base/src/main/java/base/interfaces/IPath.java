package base.interfaces;

/**
 * The IPath interface defines a path.
 */
public interface IPath {
    /**
     * Gets a path.
     */
    String getPath();

    /**
     * Gets an absolute path.
     */
    String getAbsolutePath();

    /**
     * Gets a canonical path.
     */
    String getCanonicalPath();
}
