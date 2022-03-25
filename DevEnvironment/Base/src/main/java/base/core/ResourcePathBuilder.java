package base.core;

/**
 * The ResourcePathBuilder class implements a builder of a resource path.
 */
public final class ResourcePathBuilder extends AbstractPathBuilder {
    private static final String INITIAL_COMPONENT = null;
    private static final String SEPARATOR = "/";

    /**
     * The ResourcePathBuilder constructor.
     */
    public ResourcePathBuilder() {
        super(
            ResourcePathBuilder.INITIAL_COMPONENT,
            ResourcePathBuilder.SEPARATOR);
    }
}
