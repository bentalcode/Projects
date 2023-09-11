package base.core;

import base.interfaces.IPath;

/**
 * The AbstractPath class implements an abstract path.
 */
public abstract class AbstractPath implements IPath {
    private final String path;

    /**
     * The AbstractPath constructor.
     */
    protected AbstractPath(String path) {
        this.validatePath(path);

        this.path = path;
    }

    /**
     * Gets an absolute path.
     */
    @Override
    public String getAbsolutePath() {
        return this.makeAbsolutePath(this.path);
    }

    /**
     * Gets a canonical path.
     */
    @Override
    public String getCanonicalPath() {
        return this.makeCanonicalPath(this.path);
    }

    /**
     * Gets a path.
     */
    public String getPath() {
        return this.path;
    }

    /**
     * Validates a path.
     */
    protected abstract void validatePath(String path);

    /**
     * Makes an absolute path.
     */
    protected abstract String makeAbsolutePath(String path);

    /**
     * Makes a canonical path.
     */
    protected abstract String makeCanonicalPath(String path);
}
