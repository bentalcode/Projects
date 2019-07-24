package base.core;

/**
 * The ResourcePathBuilder class implements a builder of a resource path.
 */
public final class ResourcePathBuilder extends AbstractPathBuilder {
    private static final char DefaultSeparator = '/';

    /**
     * The ResourcePathBuilder constructor.
     */
    public ResourcePathBuilder() {
        super(ResourcePathBuilder.DefaultSeparator);
    }
}
