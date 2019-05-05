package json.core;

import base.core.Casting;
import base.core.Conditions;
import base.core.Conversion;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

/**
 * The JsonObject class implements a json object.
 */
public final class JsonObject extends JsonElement implements IJsonObject {
    private final JSONObject object;

    /**
     * The JsonObject constructor.
     */
    public JsonObject(JSONObject object) {
        Conditions.validateNotNull(
            object,
            "The json object.");

        this.object = object;
    }

    /**
     * Reads a boolean property.
     */
    @Override
    public boolean readBooleanProperty(String name) {
        this.validatePropertyName(name);

        boolean result = Casting.cast(this.object.get(name));
        
        return result;
    }

    /**
     * Reads an integer property.
     */
    @Override
    public int readIntegerProperty(String name) {
        long value = this.readLongProperty(name);

        int result = Conversion.longConversion().toInteger(value);
        
        return result;
    }

    /**
     * Reads a long property.
     */
    @Override
    public long readLongProperty(String name) {
        this.validatePropertyName(name);

        long result = Casting.cast(this.object.get(name));
        
        return result;
    }

    /**
     * Reads a float property.
     */
    @Override
    public float readFloatProperty(String name) {
        Double value = this.readDoubleProperty(name);

        float result = Conversion.doubleConversion().toFloat(value);
        
        return result;
    }

    /**
     * Reads a double property.
     */
    @Override
    public double readDoubleProperty(String name) {
        this.validatePropertyName(name);

        double result = Casting.cast(this.object.get(name));
        
        return result;
    }

    /**
     * Reads a string property.
     */
    @Override
    public String readStringProperty(String name) {
        this.validatePropertyName(name);

        String result = Casting.cast(this.object.get(name));

        return result;
    }

    /**
     * Reads a generic object property.
     */
    @Override
    public IJsonObject readObjectProperty(String name) {
        this.validatePropertyName(name);
        
        JSONObject value = Casting.cast(this.object.get(name));
        IJsonObject result = new JsonObject(value);
        
        return result;
    }
    
    /**
     * Reads a generic array property.
     */
    @Override
    public IJsonArray readArrayProperty(String name) {
        this.validatePropertyName(name);

        JSONArray value = Casting.cast(this.object.get(name));
        IJsonArray result = new JsonArray(value);

        return result;
    }

    /**
     * Writes a boolean property.
     */
    public void writeBooleanProperty(String name, boolean value) {
        this.validatePropertyName(name);

        this.object.put(name, value);
    }

    /**
     * Writes a string property.
     */
    public void writeStringProperty(String name, String value) {
        this.validatePropertyName(name);

        this.object.put(name, value);
    }

    /**
     * Writes an integer property.
     */
    public void writeIntegerProperty(String name, int value) {
        long valueToWrite = value;
        this.writeLongProperty(name, valueToWrite);
    }

    /**
     * Writes a long property.
     */
    public void writeLongProperty(String name, long value) {
        this.validatePropertyName(name);

        this.object.put(name, value);
    }

    /**
     * Writes a float property.
     */
    public void writeFloatProperty(String name, float value) {
        double valueToWrite = value;
        this.writeDoubleProperty(name, valueToWrite);
    }

    /**
     * Writes a double property.
     */
    public void writeDoubleProperty(String name, double value) {
        this.validatePropertyName(name);

        this.object.put(name, value);
    }

    /**
     * Writes a generic object property.
     */
    public void writeObjectProperty(String name, IJsonObjectWriter value) {
        this.validatePropertyName(name);

        this.object.put(name, value);
    }

    /**
     * Writes a generic array property.
     */
    public void writeArrayProperty(String name, IJsonArray value) {
        this.validatePropertyName(name);

        this.object.put(name, value);
    }

    /**
     * Gets the string representation of the json object.
     */
    @Override
    public String toString() {
        return this.object.toJSONString();
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
