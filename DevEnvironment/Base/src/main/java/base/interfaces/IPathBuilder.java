package base.interfaces;

/**
 * The IPathBuilder interface defines a builder of a path.
 */
public interface IPathBuilder extends IBuilder<String> {
    /**
     * Gets a root directory.
     */
    String getRootDirectory();

    /**
     * Gets a separator of a path.
     */
    String getSeparator();

    /**
     * Adds a new component to a path.
     */
    IPathBuilder addComponent(String component);

    /**
     * Sets an extension of a path.
     */
    IPathBuilder setExtension(String extension);
}
