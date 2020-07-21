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

        int startIndex = 0;
        int endIndex = component.length() - 1;

        if (component.startsWith(this.directorySeparator)) {
            startIndex += this.directorySeparator.length();
        }

        if (component.endsWith(this.directorySeparator)) {
            endIndex -= this.directorySeparator.length();
        }

        int effectiveComponentLength = Dimensions.length(startIndex, endIndex);

        if (effectiveComponentLength > 0) {
            String effectiveComponent = component.substring(startIndex, endIndex + 1);
            this.components.add(effectiveComponent);
        }

        return this;
    }

    /**
     * Sets an extension of a path.
     */
    @Override
    public IPathBuilder setExtension(String extension) {
        Conditions.validateNotNull(
            extension,
            "The extension of a path.");

        this.extension = extension;

        return this;
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
            result.append("." + this.extension);
        }

        return result.toString();
    }
}
