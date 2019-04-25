package base.core;

/**
 * The PathBuilder class implements a builder of a path.
 */
public final class PathBuilder extends AbstractPathBuilder {
    private static final char DefaultSeparator = '\\';

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder() {
        super(PathBuilder.DefaultSeparator);
    }
}
