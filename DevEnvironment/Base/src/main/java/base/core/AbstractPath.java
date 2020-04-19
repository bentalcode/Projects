package base.core;

import base.interfaces.IPath;
import base.interfaces.IPathBuilder;

import java.util.Stack;

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
        return this.resolvePath(this.path);
    }

    /**
     * Gets a canonical path.
     */
    @Override
    public String getCanonicalPath() {
        String absolutePath = this.getAbsolutePath();
        return this.makeCanonicalPath(absolutePath);
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
     * Resolves a path.
     */
    protected abstract String resolvePath(String path);

    /**
     * Makes a canonical path.
     */
    protected abstract String makeCanonicalPath(String path);
}
