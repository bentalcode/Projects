package base.core;

/**
 * The UnixPathBuilder class implements a builder of a unix path.
 */
public final class UnixPathBuilder extends AbstractPathBuilder {
    private static final String ROOT_DIRECTORY = UnixPath.ROOT_DIRECTORY;
    private static final String SEPARATOR = UnixPath.DIRECTORY_SEPARATOR;

    /**
     * The UnixPathBuilder constructor.
     */
    public UnixPathBuilder() {
        super(
            ROOT_DIRECTORY,
            SEPARATOR);
    }

    /**
     * The UnixPathBuilder constructor.
     */
    public UnixPathBuilder(String rootDirectory) {
        super(
            rootDirectory,
            SEPARATOR);
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
