package base.core;

import base.interfaces.IOperatingSystemPathSettings;
import base.interfaces.IPath;
import base.interfaces.IPathBuilder;

/**
 * The UnixPathSettings class implements path settings of a unix operating system.
 */
public final class UnixPathSettings implements IOperatingSystemPathSettings {
    /**
     * The UnixPathSettings constructor.
     */
    public UnixPathSettings() {
    }

    /**
     * Gets a path separator.
     */
    @Override
    public String getPathSeparator() {
        return UnixPath.directorySeparator;
    }

    /**
     * Creates a path.
     */
    @Override
    public IPath createPath(String path) {
        return new UnixPath(path);
    }

    /**
     * Creates a path builder.
     */
    @Override
    public IPathBuilder createPathBuilder() {
        return new UnixPathBuilder();
    }
}
