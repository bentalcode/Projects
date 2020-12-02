package base.core;

/**
 * The UnixPathBuilder class implements a builder of a unix path.
 */
public final class UnixPathBuilder extends AbstractPathBuilder {
    private static final String defaultRootDirectory = UnixPath.rootDirectory;
    private static final String defaultSeparator = UnixPath.directorySeparator;

    /**
     * The UnixPathBuilder constructor.
     */
    public UnixPathBuilder() {
        super(
            defaultRootDirectory,
            defaultSeparator);
    }

    /**
     * The UnixPathBuilder constructor.
     */
    public UnixPathBuilder(String rootDirectory) {
        super(
            rootDirectory,
            defaultSeparator);
    }

    /**
     * The UnixPathBuilder constructor.
     */
    public UnixPathBuilder(String rootDirectory, String separator) {
        super(
            rootDirectory,
            separator);
    }
}
