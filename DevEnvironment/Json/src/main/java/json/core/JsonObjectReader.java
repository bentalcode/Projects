package json.core;

import base.core.ClassTypes;
import base.core.Conditions;
import base.core.IFromString;
import base.core.TimeConstants;
import json.interfaces.IJsonObjectReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import json.interfaces.IJsonSerialization;
import org.joda.time.DateTime;
import org.joda.time.Duration;
import org.joda.time.Period;
import org.joda.time.format.DateTimeFormatter;
import org.joda.time.format.PeriodFormatter;
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
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        boolean result = reader.readBoolean();

        return result;
    }

    /**
     * Reads a short property.
     */
    @Override
    public short readShortProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        short result = reader.readShort();

        return result;
    }

    /**
     * Reads an integer property.
     */
    @Override
    public int readIntegerProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        int result = reader.readInteger();

        return result;
    }

    /**
     * Reads a long property.
     */
    @Override
    public long readLongProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        long result = reader.readLong();

        return result;
    }

    /**
     * Reads a float property.
     */
    @Override
    public float readFloatProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        float result = reader.readFloat();

        return result;
    }

    /**
     * Reads a double property.
     */
    @Override
    public double readDoubleProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        double result = reader.readDouble();

        return result;
    }

    /**
     * Reads a string property.
     */
    @Override
    public String readStringProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        String result = reader.readString();

        return result;
    }

    /**
     * Reads a boolean array property.
     */
    @Override
    public boolean[] readBooleanArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        boolean[] result = reader.readBooleanArray();

        return result;
    }

    /**
     * Reads a short array property.
     */
    @Override
    public short[] readShortArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        short[] result = reader.readShortArray();

        return result;
    }

    /**
     * Reads an integer array property.
     */
    @Override
    public int[] readIntegerArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        int[] result = reader.readIntegerArray();

        return result;
    }

    /**
     * Reads a long array property.
     */
    @Override
    public long[] readLongArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        long[] result = reader.readLongArray();

        return result;
    }

    /**
     * Reads a float array property.
     */
    @Override
    public float[] readFloatArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        float[] result = reader.readFloatArray();

        return result;
    }

    /**
     * Reads a double array property.
     */
    @Override
    public double[] readDoubleArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        double[] result = reader.readDoubleArray();

        return result;
    }

    /**
     * Reads a string array property.
     */
    @Override
    public String[] readStringArrayProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        String[] result = reader.readStringArray();

        return result;
    }

    /**
     * Reads a string list property.
     */
    @Override
    public List<String> readStringListProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        List<String> result = reader.readStringList();

        return result;
    }

    /**
     * Reads a string set property.
     */
    @Override
    public Set<String> readStringSetProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        Set<String> result = reader.readStringSet();

        return result;
    }

    /**
     * Reads a blob property.
     */
    @Override
    public byte[] readBlobProperty(String name) {
        IJsonValue value = this.getPropertyValue(name);

        IJsonValueReader reader = new JsonValueReader(value);
        byte[] result = reader.readBlob();

        return result;
    }

    /**
     * Reads a date-time property.
     */
    @Override
    public DateTime readDateTimeProperty(String name) {
        DateTimeFormatter formatter = TimeConstants.defaultDateTimeFormatter();
        return this.readDateTimeProperty(name, formatter);
    }

    /**
     * Reads a date-time property.
     */
    @Override
    public DateTime readDateTimeProperty(String name, DateTimeFormatter formatter) {
        String value = this.readStringProperty(name);
        DateTime result = DateTime.parse(value, formatter);
        return result;
    }

    /**
     * Reads a duration property.
     */
    @Override
    public Duration readDurationProperty(String name) {
        PeriodFormatter formatter = TimeConstants.defaultDurationFormatter();
        return this.readDurationProperty(name, formatter);
    }

    /**
     * Reads a duration property.
     */
    @Override
    public Duration readDurationProperty(String name, PeriodFormatter formatter) {
        String value = this.readStringProperty(name);
        Period period = formatter.parsePeriod(value);
        Duration result = period.toStandardDuration();
        return result;
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

        ResultType result = reader.readObject(classType);

        return result;
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

        ResultType[] result = reader.readArray(classType);

        return result;
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

        List<ResultType> result = reader.readList(classType);

        return result;
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

        Set<ResultType> result = reader.readSet(classType);

        return result;
    }

    /**
     * Reads a generic list property with a transformer.
     */
    @Override
    public <T> List<T> readListProperty(String name, IFromString<T> transformer) {
        IJsonValue value = this.getPropertyValue(name);
        IJsonValueReader reader = new JsonValueReader(value);

        String[] stringList = reader.readStringArray();
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
    public <T> Set<T> readSetProperty(String name, IFromString<T> transformer) {
        IJsonValue value = this.getPropertyValue(name);
        IJsonValueReader reader = new JsonValueReader(value);

        String[] stringList = reader.readStringArray();
        Set<T> result = new HashSet<>();

        for (String item : stringList) {
            result.add(transformer.fromString(item));
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

        IJsonValue value = this.jsonObject.getPropertyValue(name);

        return value;
    }
}
