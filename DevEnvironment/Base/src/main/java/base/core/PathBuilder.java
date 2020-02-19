package base.core;

/**
 * The PathBuilder class implements a builder of a path.
 */
public final class PathBuilder extends AbstractPathBuilder {
    private static final char defaultSeparator = '\\';

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder() {
        super(PathBuilder.defaultSeparator);
    }
}
