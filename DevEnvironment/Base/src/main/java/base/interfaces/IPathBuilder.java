package base.interfaces;

/**
 * The IPathBuilder interface defines a builder of a path.
 */
public interface IPathBuilder extends IBuilder<String> {
    /**
     * Gets a separator of a path.
     */
    char getSeparator();

    /**
     * Adds a new component to a path.
     */
    IPathBuilder addComponent(String component);

    /**
     * Sets an extension of a path.
     */
    void setExtension(String extension);

    /**
     * Builds the path.
     */
    String build();
}
