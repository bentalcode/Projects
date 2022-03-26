package clientserver.core;

import base.core.Conditions;
import clientserver.interfaces.ILogic;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectWriter;

/**
 * The BaseLogic class implements a base logic.
 */
public abstract class BaseLogic implements ILogic {
    private static final String PROPERTY_NAME = "name";

    private final String name;

    /**
     * The BaseLogic constructor.
     */
    protected BaseLogic(String name) {
        Conditions.validateStringNotNullOrEmpty(
            name,
            "The logic name");

        this.name = name;
    }

    /**
     * Gets the name of the logic.
     */
    @Override
    public String name() {
        return this.name;
    }

    /**
     * Gets string representation of this instance.
     */
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(BaseLogic.PROPERTY_NAME, this.name);
    }
}
