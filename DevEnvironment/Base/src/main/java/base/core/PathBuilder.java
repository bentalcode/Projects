package base.core;

/**
 * The PathBuilder class implements a builder of a path.
 */
public final class PathBuilder extends AbstractPathBuilder {
    private static final String defaultRootDirectory = null;
    private static final String defaultSeparator = "\\";

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder() {
        this(
            PathBuilder.defaultRootDirectory,
            PathBuilder.defaultSeparator);
    }

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder(String separator) {
        super(
            PathBuilder.defaultRootDirectory,
            separator);
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
