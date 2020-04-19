package base.core;

import base.interfaces.IPathBuilder;
import java.util.ArrayList;
import java.util.List;

/**
 * The AbstractPathBuilder base class implements an abstract builder of a path.
 */
public abstract class AbstractPathBuilder implements IPathBuilder {
    private final String rootDirectory;
    private final String directorySeparator;
    private final List<String> components = new ArrayList<>();
    private String extension;

    /**
     * The AbstractPathBuilder constructor.
     */
    protected AbstractPathBuilder(String initialComponent, String separator) {
        Conditions.validateNotNull(
            separator,
            "The separator of a path.");

        this.rootDirectory = initialComponent;
        this.directorySeparator = separator;
    }

    /**
     * Gets a root directory of a path.
     */
    @Override
    public String getRootDirectory() {
        return this.rootDirectory;
    }

    /**
     * Gets a directory separator of a path.
     */
    @Override
    public String getDirectorySeparator() {
        return this.directorySeparator;
    }

    /**
     * Adds a new component to a path.
     */
    @Override
    public IPathBuilder addComponent(String component) {
        Conditions.validateNotNull(
            component,
            "The component of a path.");

        this.components.add(component);

        return this;
    }

    /**
     * Sets an extension of a path.
     */
    @Override
    public void setExtension(String extension) {
        Conditions.validateNotNull(
            extension,
            "The extension of a path.");

        this.extension = extension;
    }

    /**
     * Builds the resultant path.
     */
    @Override
    public String build() {
        StringBuilder result = new StringBuilder();

        if (!Strings.isNullOrEmpty(this.rootDirectory)) {
            result.append(this.rootDirectory);
        }

        boolean addDirectorySeparator = false;
        for (String component : this.components) {
            if (addDirectorySeparator) {
                result.append(this.directorySeparator);
            }

            result.append(component);
            addDirectorySeparator = true;
        }

        if (!Strings.isNullOrEmpty(this.extension)) {
            result.append(this.extension);
        }

        return result.toString();
    }
}
