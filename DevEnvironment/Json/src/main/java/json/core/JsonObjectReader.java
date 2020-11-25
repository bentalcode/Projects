package json.core;

import base.core.ArrayLists;
import base.core.ClassTypes;
import base.core.Conditions;
import base.core.Dates;
import base.core.Durations;
import base.interfaces.IFromString;
import json.interfaces.IJsonObjectReader;
import java.text.DateFormat;
import java.time.Duration;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import json.interfaces.IJsonSerialization;
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
     * Determines whether the property exists.
     */
    public boolean hasProperty(String name) {
        return this.jsonObject.propertyExists(name);
    }

    /**
     * Reads a boolean property.
     */
    @Override
    public boolean readBooleanProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readBoolean();
    }

    /**
     * Reads a short property.
     */
    @Override
    public short readShortProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readShort();
    }

    /**
     * Reads an integer property.
     */
    @Override
    public int readIntegerProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readInteger();
    }

    /**
     * Reads a long property.
     */
    @Override
    public long readLongProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readLong();
    }

    /**
     * Reads a float property.
     */
    @Override
    public float readFloatProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readFloat();
    }

    /**
     * Reads a double property.
     */
    @Override
    public double readDoubleProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readDouble();
    }

    /**
     * Reads a string property.
     */
    @Override
    public String readStringProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readString();
    }

    /**
     * Reads an enum property.
     */
    public <T extends Enum<T>> T readEnumProperty(
        String name,
        IFromString<T> transformer) {

        return this.readProperty(name, transformer);
    }

    /**
     * Reads a generic property with a transformer.
     */
    @Override
    public <T> T readProperty(
        String name,
        IFromString<T> transformer) {

        validateTransformer(transformer);

        String value = this.readStringProperty(name);
        return transformer.fromString(value);
    }

    /**
     * Reads a boolean array property.
     */
    @Override
    public boolean[] readBooleanArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readBooleanArray();
    }

    /**
     * Reads a short array property.
     */
    @Override
    public short[] readShortArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readShortArray();
    }

    /**
     * Reads an integer array property.
     */
    @Override
    public int[] readIntegerArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readIntegerArray();
    }

    /**
     * Reads a long array property.
     */
    @Override
    public long[] readLongArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readLongArray();
    }

    /**
     * Reads a float array property.
     */
    @Override
    public float[] readFloatArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readFloatArray();
    }

    /**
     * Reads a double array property.
     */
    @Override
    public double[] readDoubleArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readDoubleArray();
    }

    /**
     * Reads a string array property.
     */
    @Override
    public String[] readStringArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readStringArray();
    }

    /**
     * Reads a string list property.
     */
    @Override
    public List<String> readStringListProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readStringList();
    }

    /**
     * Reads a string set property.
     */
    @Override
    public Set<String> readStringSetProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readStringSet();
    }

    /**
     * Reads a string map property.
     */
    @Override
    public Map<String, String> readStringMapProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readStringMap();
    }

    /**
     * Reads a blob property.
     */
    @Override
    public byte[] readBlobProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        return reader.readBlob();
    }

    /**
     * Reads a date property.
     */
    @Override
    public Date readDateProperty(String name) {
        String value = this.readStringProperty(name);
        return Dates.parse(value);
    }

    /**
     * Reads a date property.
     */
    @Override
    public Date readDateProperty(
        String name,
        DateFormat formatter) {

        String value = this.readStringProperty(name);
        return Dates.parse(value, formatter);
    }

    /**
     * Reads a duration property.
     */
    @Override
    public Duration readDurationProperty(String name) {
        String value = this.readStringProperty(name);
        return Durations.parse(value);
    }

    /**
     * Reads a duration property.
     */
    @Override
    public Duration readDurationProperty(
        String name,
        String formatter) {

        String value = this.readStringProperty(name);
        return Durations.parse(value, formatter);
    }

    /**
     * Reads a generic object property.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType readObjectProperty(
        String name,
        Class<ClassType> classType) {

        IJsonValue value = this.getPropertyValue(name);
        IJsonValueReader reader = new JsonValueReader(value);

        return reader.readObject(classType);
    }

    /**
     * Reads a generic array property.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType[] readArrayProperty(
        String name,
        Class<ClassType> classType) {

        IJsonValue value = this.getPropertyValue(name);
        IJsonValueReader reader = new JsonValueReader(value);

        return reader.readArray(classType);
    }

    /**
     * Reads a generic list property.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> List<ResultType> readListProperty(
        String name,
        Class<ClassType> classType) {

        IJsonValue value = this.getPropertyValue(name);
        IJsonValueReader reader = new JsonValueReader(value);

        return reader.readList(classType);
    }

    /**
     * Reads a generic set property.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> Set<ResultType> readSetProperty(
        String name,
        Class<ClassType> classType) {

        IJsonValue value = this.getPropertyValue(name);
        IJsonValueReader reader = new JsonValueReader(value);

        return reader.readSet(classType);
    }

    /**
     * Reads a generic list property with a transformer.
     */
    @Override
    public <T> List<T> readListProperty(
        String name,
        IFromString<T> transformer) {

        validateTransformer(transformer);

        IJsonValue value = this.getPropertyValue(name);
        IJsonValueReader reader = new JsonValueReader(value);

        String[] stringList = reader.readStringArray();

        if (stringList == null) {
            return ArrayLists.make();
        }

        List<T> result = new ArrayList<>(stringList.length);

        for (String item : stringList) {
            result.add(transformer.fromString(item));
        }

        return result;
    }

    /**
     * Reads a generic set property with a transformer.
     */
    @Override
    public <T> Set<T> readSetProperty(
        String name,
        IFromString<T> transformer) {

        validateTransformer(transformer);

        IJsonValue value = this.getPropertyValue(name);
        IJsonValueReader reader = new JsonValueReader(value);

        String[] stringList = reader.readStringArray();

        Set<T> result = new HashSet<>();

        if (stringList == null) {
            return result;
        }

        for (String item : stringList) {
            result.add(transformer.fromString(item));
        }

        return result;
    }

    /**
     * Reads a generic map property with key and value transformers.
     */
    @Override
    public <TKey, TValue> Map<TKey, TValue> readMapProperty(
        String name,
        IFromString<TKey> keyTransformer,
        IFromString<TValue> valueTransformer) {

        validateTransformer(keyTransformer);
        validateTransformer(valueTransformer);

        Map<String, String> stringMap = this.readStringMapProperty(name);

        Map<TKey, TValue> result = new HashMap<>();

        for (Map.Entry<String, String> stringEntry : stringMap.entrySet()) {
            TKey key = keyTransformer.fromString(stringEntry.getKey());
            TValue value = valueTransformer.fromString(stringEntry.getValue());

            result.put(key, value);
        }

        return result;
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

        return this.jsonObject.getPropertyValue(name);
    }

    /**
     * Validates a transformer.
     */
    private static <T> void validateTransformer(IFromString<T> transformer) {
        Conditions.validateNotNull(
            transformer,
            "The transformer.");
    }
}
