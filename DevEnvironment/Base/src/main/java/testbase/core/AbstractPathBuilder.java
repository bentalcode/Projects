package testbase.core;

import base.interfaces.IPathBuilder;
import java.util.ArrayList;
import java.util.List;

/**
 * The AbstractPathBuilder base class implements an abstract builder of a path.
 */
public abstract class AbstractPathBuilder implements IPathBuilder {
    private final char separator;
    private final List<String> components = new ArrayList<>();
    private String extension;

    /**
     * The AbstractPathBuilder constructor.
     */
    protected AbstractPathBuilder(char separator) {
        Conditions.validateNotNull(
            separator,
            "The separator of a path.");

        this.separator = separator;
    }

    /**
     * Gets a separator of a path.
     */
    @Override
    public char getSeparator() {
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

        for (String component : this.components) {
            if (result.length() > 0) {
                result.append(this.separator);
            }

            result.append(component);
        }

        if (!Strings.isNullOrEmpty(this.extension)) {
            result.append(this.extension);
        }

        return result.toString();
    }
}
