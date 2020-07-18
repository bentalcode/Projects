package base.core;

/**
 * The UnixPathBuilder class implements a builder of a unix path.
 */
public final class UnixPathBuilder extends AbstractPathBuilder {
    /**
     * The UnixPathBuilder constructor.
     */
    public UnixPathBuilder() {
        super(
            UnixPath.rootDirectory,
            UnixPath.directorySeparator);
    }
}
