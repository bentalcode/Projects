package base.core;

import base.interfaces.IOperatingSystemPathSettings;
import base.interfaces.IPath;
import base.interfaces.IPathBuilder;

/**
 * The WindowsPathSettings class implements path settings of a windows operating system.
 */
public final class WindowsPathSettings implements IOperatingSystemPathSettings {
    /**
     * The WindowsPathSettings constructor.
     */
    public WindowsPathSettings() {
    }

    /**
     * Gets a path separator.
     */
    @Override
    public String getPathSeparator() {
        return WindowsPath.DIRECTORY_SEPARATOR;
    }

    /**
     * Creates a path.
     */
    @Override
    public IPath createPath(String path) {
        return new WindowsPath(path);
    }

    /**
     * Creates a path builder.
     */
    @Override
    public IPathBuilder createPathBuilder() {
        return new PathBuilder();
    }
}
