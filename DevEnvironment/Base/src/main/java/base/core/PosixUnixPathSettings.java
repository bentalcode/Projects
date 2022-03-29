package base.core;

import base.interfaces.IOperatingSystemPathSettings;
import base.interfaces.IPath;
import base.interfaces.IPathBuilder;

/**
 * The PosixUnixPathSettings class implements' path settings of a posix-unix operating system.
 */
public final class PosixUnixPathSettings implements IOperatingSystemPathSettings {
    /**
     * The PosixUnixPathSettings constructor.
     */
    public PosixUnixPathSettings() {
    }

    /**
     * Gets a path separator.
     */
    @Override
    public String getPathSeparator() {
        return UnixPath.DIRECTORY_SEPARATOR;
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
