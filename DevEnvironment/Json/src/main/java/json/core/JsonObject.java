package json.core;

import base.core.Casting;
import base.core.Conditions;
import base.core.Conversion;
import org.json.simple.JSONObject;

/**
 * The JsonObject class implements a json object.
 */
public final class JsonObject extends JsonElement implements IJsonObject {
    private final JSONObject object;

    /**
     * The JsonObject constructor.
     */
    public JsonObject(int id, JSONObject object) {
        super(id);

        Conditions.validateNotNull(
            object,
            "The json object.");

        this.object = object;
    }

    /**
     * Gets a boolean property.
     */
    @Override
    public Boolean getBooleanProperty(String name) {
        this.validatePropertyName(name);

        return Casting.cast(this.object.get(name));
    }

    /**
     * Gets a string property.
     */
    @Override
    public String getStringProperty(String name) {
        this.validatePropertyName(name);

        return Casting.cast(this.object.get(name));
    }

    /**
     * Gets an integer property.
     */
    @Override
    public int getIntegerProperty(String name) {
        Long value = this.getLongProperty(name);

        return Conversion.longConversion().toInteger(value);
    }

    /**
     * Gets a long property.
     */
    @Override
    public long getLongProperty(String name) {
        this.validatePropertyName(name);

        return Casting.cast(this.object.get(name));
    }

    /**
     * Gets a float property.
     */
    @Override
    public float getFloatProperty(String name) {
        Double value = this.getDoubleProperty(name);

        return Conversion.doubleConversion().toFloat(value);
    }

    /**
     * Gets a double property.
     */
    @Override
    public double getDoubleProperty(String name) {
        this.validatePropertyName(name);

        return Casting.cast(this.object.get(name));
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
