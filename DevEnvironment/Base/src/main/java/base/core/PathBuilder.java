package base.core;

/**
 * The PathBuilder class implements a builder of a path.
 */
public final class PathBuilder extends AbstractPathBuilder {
    private static final String defaultInitialComponent = null;
    private static final String defaultSeparator = "\\";

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder() {
        this(
            PathBuilder.defaultInitialComponent,
            PathBuilder.defaultSeparator);
    }

    /**
     * The PathBuilder constructor.
     */
    public PathBuilder(String initialComponent, String separator) {
        super(
            initialComponent,
            separator);
    }
}
