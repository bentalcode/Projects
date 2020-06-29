package command.core;

import base.core.Conditions;
import command.interfaces.INamedParameterMetadata;
import command.interfaces.IParameterMetadata;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectWriter;

/**
 * The ParameterMetadata abstract base class implements meta-data of a parameter.
 */
public abstract class ParameterMetadata implements IParameterMetadata {
    protected static final String propertyName = "name";
    protected static final String propertyDescription = "description";

    private final String name;
    private final String description;

    /**
     * Creates meta-data of a help parameter.
     */
    public static INamedParameterMetadata createHelpParameter() {
        return new NamedParameterMetadata(
            "Help",
            ICommandConstants.helpShortName,
            ICommandConstants.helpLongName,
            "The help of the command",
            false);
    }

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
        writer.writeStringProperty(propertyName, this.name);
        writer.writeStringProperty(propertyDescription, this.description);
    }
}
