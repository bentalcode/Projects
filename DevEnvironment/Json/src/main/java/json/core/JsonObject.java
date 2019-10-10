package json.core;

import base.core.Conditions;
import java.util.HashMap;
import java.util.Map;

/**
 * The JsonObject class implements a json object.
 */
public final class JsonObject extends JsonElement implements IJsonObject {
    private final Map<String, IJsonValue> properties = new HashMap<>();

    /**
     * The JsonObject constructor.
     */
    public JsonObject(int id) {
        super(id);
    }

    /**
     * Sets a value.
     */
    @Override
    public void setValue(String name, IJsonValue value) {
        Conditions.validateNotNull(
            name,
            "The property name.");

        Conditions.validateNotNull(
            value,
            "The property value.");

        this.setPropertyValue(name, value);
    }

    /**
     * Gets a value of a property.
     */
    @Override
    public IJsonValue getPropertyValue(String name) {
        this.validatePropertyName(name);

        if (!this.properties.containsKey(name)) {
            String errorMessage = "The name of property: " + name + " is not defined in the json object.";
            throw new JsonException(errorMessage);
        }

        return this.properties.get(name);
    }

    /**
     * Sets a value of a property.
     */
    @Override
    public void setPropertyValue(String name, IJsonValue value) {
        Conditions.validateNotNull(
            name,
            "The name of a property.");

        this.properties.put(name, value);
    }

    /**
     * Checks whether a property exists.
     */
    @Override
    public boolean propertyExists(String name) {
        return this.properties.containsKey(name);
    }

    /**
     * Validates a name of a property.
     */
    private void validatePropertyName(String name) {
        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a property.");
    }
}
