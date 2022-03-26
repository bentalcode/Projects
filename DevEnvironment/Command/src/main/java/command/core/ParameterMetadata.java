package command.core;

import base.core.Conditions;
import command.interfaces.IParameterMetadata;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectWriter;

/**
 * The ParameterMetadata abstract base class implements meta-data of a parameter.
 */
public abstract class ParameterMetadata implements IParameterMetadata {
    protected static final String PROPERTY_NAME = "name";
    protected static final String PROPERTY_DESCRIPTION = "description";

    private final String name;
    private final String description;

    /**
     * The ParameterMetadata constructor.
     */
    protected ParameterMetadata(
        String name,
        String description) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a parameter.");

        Conditions.validateStringNotNullOrEmpty(
            description,
            "The description of a parameter.");

        this.name = name;
        this.description = description;
    }

    /**
     * Gets name of a parameter.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets description of a parameter.
     */
    @Override
    public String getDescription() {
        return this.description;
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(PROPERTY_NAME, this.name);
        writer.writeStringProperty(PROPERTY_DESCRIPTION, this.description);
    }
}
