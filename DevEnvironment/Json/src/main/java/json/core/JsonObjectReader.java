package json.core;

import base.core.Casting;
import base.core.ClassTypes;
import base.core.Conditions;
import base.core.Conversion;
import json.interfaces.IJsonObjectReader;
import java.util.List;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsonObjectReader class implements a reader of a json object.
 */
public final class JsonObjectReader implements IJsonObjectReader {
    private final IJsonObject jsonObject;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonObjectReader constructor.
     */
    public JsonObjectReader(IJsonObject jsonObject) {
        Conditions.validateNotNull(
            jsonObject,
            "The json object to read from.");

        this.jsonObject = jsonObject;
    }
    
    /**
     * Reads a boolean property.
     */
    @Override
    public boolean readBooleanProperty(String name) {
        IJsonValue jsonValue = this.getPropertyValue(name);
        IJsonBooleanValue booleanValue = Casting.cast(jsonValue);

        boolean result = booleanValue.getValue();

        return result;
    }

    /**
     * Reads a byte property.
     */
    @Override
    public byte readByteProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a short property.
     */
    @Override
    public short readShortProperty(String name) {
        throw new UnsupportedOperationException();
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
        IJsonValue jsonValue = this.getPropertyValue(name);
        IJsonIntegerValue integerValue = Casting.cast(jsonValue);

        long result = integerValue.getValue();

        return result;
    }

    /**
     * Reads a float property.
     */
    @Override
    public float readFloatProperty(String name) {
        double value = this.readDoubleProperty(name);
        float result = Conversion.doubleConversion().toFloat(value);

        return result;
    }

    /**
     * Reads a double property.
     */
    @Override
    public double readDoubleProperty(String name) {
        IJsonValue jsonValue = this.getPropertyValue(name);
        IJsonDoubleValue doubleValue = Casting.cast(jsonValue);

        double result = doubleValue.getValue();

        return result;
    }

    /**
     * Reads a character property.
     */
    @Override
    public char readCharacterProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a string property.
     */
    @Override
    public String readStringProperty(String name) {
        IJsonValue jsonValue = this.getPropertyValue(name);
        IJsonStringValue stringValue = Casting.cast(jsonValue);

        String result = stringValue.getValue();

        return result;
    }

    /**
     * Reads a boolean array property.
     */
    @Override
    public boolean[] readBooleanArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a byte array property.
     */
    @Override
    public byte[] readByteArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a short array property.
     */
    @Override
    public short[] readShortArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads an integer array property.
     */
    @Override
    public int[] readIntegerArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a float array property.
     */
    @Override
    public float[] readFloatArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a double array property.
     */
    @Override
    public double[] readDoubleArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a character array property.
     */
    @Override
    public char[] readCharacterArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a string array property.
     */
    @Override
    public String[] readStringArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic property.
     */
    @Override
    public <T> T readGenericProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic array property.
     */
    @Override
    public <T> T[] readArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic list property.
     */
    @Override
    public <T> List<T> readListProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Get the property value.
     */
    private IJsonValue getPropertyValue(String name) {
        if (!this.jsonObject.propertyExists(name)) {
            String errorMessage =
                "The property: " + name + " for object: " + ClassTypes.getName(this.jsonObject.getClass()) +
                " is not defined.";

            this.log.error(errorMessage);
            throw new JsonException(errorMessage);
        }

        IJsonValue value = this.jsonObject.getPropertyValue(name);

        return value;
    }
}
