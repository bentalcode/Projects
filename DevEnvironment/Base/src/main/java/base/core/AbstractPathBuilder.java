package base.core;

import base.interfaces.IPathBuilder;
import java.util.ArrayList;
import java.util.List;

/**
 * The AbstractPathBuilder base class implements an abstract builder of a path.
 */
public abstract class AbstractPathBuilder implements IPathBuilder {
    private final String rootDirectory;
    private final String separator;
    private final List<String> components = new ArrayList<>();
    private String extension;

    /**
     * The AbstractPathBuilder constructor.
     */
    protected AbstractPathBuilder(String rootDirectory, String separator) {
        Conditions.validateNotNull(
            separator,
            "The separator of a path.");

        this.rootDirectory = rootDirectory;
        this.separator = separator;
    }

    /**
     * Gets a root directory of a path.
     */
    @Override
    public String getRootDirectory() {
        return this.rootDirectory;
    }

    /**
     * Gets a separator of a path.
     */
    @Override
    public String getSeparator() {
        return this.separator;
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

        if (component.startsWith(this.separator)) {
            startIndex += this.separator.length();
        }

        if (component.endsWith(this.separator)) {
            endIndex -= this.separator.length();
        }

        int effectiveComponentLength = Indexes.size(startIndex, endIndex);

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

        boolean addDirectorySeparator = this.rootDirectory != null;
        for (String component : this.components) {
            if (addDirectorySeparator) {
                result.append(this.separator);
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
