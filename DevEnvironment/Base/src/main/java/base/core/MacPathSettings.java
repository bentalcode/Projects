package base.core;

import base.interfaces.IOperatingSystemPathSettings;
import base.interfaces.IPath;
import base.interfaces.IPathBuilder;

/**
 * The MacPathSettings class implements' path settings of a Mac operating system.
 */
public final class MacPathSettings implements IOperatingSystemPathSettings {
    /**
     * The MacPathSettings constructor.
     */
    public MacPathSettings() {
    }

    /**
     * Gets a path separator.
     */
    @Override
    public String getPathSeparator() {
        throw new UnsupportedOperationException();
    }

    /**
     * Creates a path.
     */
    @Override
    public IPath createPath(String path) {
        throw new UnsupportedOperationException();
    }

    /**
     * Creates a path builder.
     */
    @Override
    public IPathBuilder createPathBuilder() {
        throw new UnsupportedOperationException();
    }
}
