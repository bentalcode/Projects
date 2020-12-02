package base.core;

/**
 * The PathBuilder class implements a builder of a path.
 */
public final class PathBuilder extends AbstractPathBuilder {
    private static final String defaultRootDirectory = null;
    private static final String defaultSeparator = WindowsPath.directorySeparator;

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder() {
        this(
            defaultRootDirectory,
            defaultSeparator);
    }

    /**
     * The PathBuilder constructor.
     */
    private PathBuilder(String rootDirectory) {
        super(
            rootDirectory,
            defaultSeparator);
    }

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder(String rootDirectory, String separator) {
        super(
            rootDirectory,
            separator);
    }
}
