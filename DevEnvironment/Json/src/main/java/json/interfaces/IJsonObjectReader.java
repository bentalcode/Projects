package json.interfaces;

import base.interfaces.IFromString;
import java.text.DateFormat;
import java.time.Duration;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * The IJsonObjectReader interface defines a reader of a json object.
 */
public interface IJsonObjectReader {
    /**
     * Determines whether the property exists.
     */
    boolean hasProperty(String name);

    /**
     * Reads a boolean property.
     */
    boolean readBooleanProperty(String name);

    /**
     * Reads a short property.
     */
    short readShortProperty(String name);

    /**
     * Reads an integer property.
     */
    int readIntegerProperty(String name);

    /**
     * Reads a long property.
     */
    long readLongProperty(String name);

    /**
     * Reads a float property.
     */
    float readFloatProperty(String name);

    /**
     * Reads a double property.
     */
    double readDoubleProperty(String name);

    /**
     * Reads a string property.
     */
    String readStringProperty(String name);

    /**
     * Reads an enum property.
     */
    <T extends Enum<T>> T readEnumProperty(
        String name,
        IFromString<T> transformer);

    /**
     * Reads a generic property with a transformer.
     */
    <T> T readProperty(
        String name,
        IFromString<T> transformer);

    /**
     * Reads a boolean array property.
     */
    boolean[] readBooleanArrayProperty(String name);

    /**
     * Reads a short array property.
     */
    short[] readShortArrayProperty(String name);

    /**
     * Reads an integer array property.
     */
    int[] readIntegerArrayProperty(String name);

    /**
     * Reads a long array property.
     */
    long[] readLongArrayProperty(String name);

    /**
     * Reads a float array property.
     */
    float[] readFloatArrayProperty(String name);

    /**
     * Reads a double array property.
     */
    double[] readDoubleArrayProperty(String name);

    /**
     * Reads a string array property.
     */
    String[] readStringArrayProperty(String name);

    /**
     * Reads a string list property.
     */
    List<String> readStringListProperty(String name);

    /**
     * Reads a string set property.
     */
    Set<String> readStringSetProperty(String name);

    /**
     * Reads a string map property.
     */
    Map<String, String> readStringMapProperty(String name);

    /**
     * Reads a blob property.
     */
    byte[] readBlobProperty(String name);

    /**
     * Reads a date property.
     */
    Date readDateProperty(String name);

    /**
     * Reads a date property with a formatter.
     */
    Date readDateProperty(
        String name,
        DateFormat formatter);

    /**
     * Reads a duration property.
     */
    Duration readDurationProperty(String name);

    /**
     * Reads a duration property with a formatter.
     */
    Duration readDurationProperty(
        String name,
        String formatter);

    /**
     * Reads a generic object property.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType readObjectProperty(
        String name,
        Class<ClassType> classType);

    /**
     * Reads a generic array property.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType[] readArrayProperty(
        String name,
        Class<ClassType> classType);

    /**
     * Reads a generic list property.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> List<ResultType> readListProperty(
        String name,
        Class<ClassType> classType);

    /**
     * Reads a generic set property.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> Set<ResultType> readSetProperty(
        String name,
        Class<ClassType> classType);

    /**
     * Reads a generic list property with a transformer.
     */
    <T> List<T> readListProperty(
        String name,
        IFromString<T> transformer);

    /**
     * Reads a generic set property with a transformer.
     */
    <T> Set<T> readSetProperty(
        String name,
        IFromString<T> transformer);

    /**
     * Reads a generic map property with key and value transformers.
     */
    <TKey, TValue> Map<TKey, TValue> readMapProperty(
        String name,
        IFromString<TKey> keyTransformer,
        IFromString<TValue> valueTransformer);
}
