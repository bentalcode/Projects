package base.core;

/**
 * The UriBuilder class implements a builder of a uri.
 */
public final class UriBuilder extends AbstractPathBuilder {
    private static final char defaultSeparator = '/';

    /**
     * The UriBuilder constructor.
     */
    public UriBuilder() {
        super(UriBuilder.defaultSeparator);
    }
}
