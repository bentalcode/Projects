package base.core;

/**
 * The ResourcePathBuilder class implements a builder of a resource path.
 */
public final class ResourcePathBuilder extends AbstractPathBuilder {
    private static final String initialComponent = null;
    private static final String separator = "/";

    /**
     * The ResourcePathBuilder constructor.
     */
    public ResourcePathBuilder() {
        super(
            ResourcePathBuilder.initialComponent,
            ResourcePathBuilder.separator);
    }
}
