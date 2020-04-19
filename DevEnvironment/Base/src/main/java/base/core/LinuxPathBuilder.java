package base.core;

/**
 * The LinuxPathBuilder class implements a builder of a linux path.
 */
public final class LinuxPathBuilder extends AbstractPathBuilder {
    private static final String initialComponent = "/";
    private static final String separator = "/";

    /**
     * The LinuxPathBuilder constructor.
     */
    public LinuxPathBuilder() {
        super(
            LinuxPathBuilder.initialComponent,
            LinuxPathBuilder.separator);
    }
}
