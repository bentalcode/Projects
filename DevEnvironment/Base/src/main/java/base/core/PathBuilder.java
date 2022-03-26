package base.core;

/**
 * The PathBuilder class implements a builder of a path.
 */
public final class PathBuilder extends AbstractPathBuilder {
    private static final String ROOT_DIRECTORY = null;
    private static final String SEPARATOR = WindowsPath.DIRECTORY_SEPARATOR;

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder() {
        this(
            ROOT_DIRECTORY,
            SEPARATOR);
    }

    /**
     * The PathBuilder constructor.
     */
    private PathBuilder(String rootDirectory) {
        super(
            rootDirectory,
            SEPARATOR);
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
