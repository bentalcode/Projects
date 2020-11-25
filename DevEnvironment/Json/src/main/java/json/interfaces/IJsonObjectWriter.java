package json.interfaces;

import base.interfaces.IToString;
import java.text.DateFormat;
import java.time.Duration;
import java.util.Collection;
import java.util.Date;
import java.util.List;
import java.util.Map;

/**
 * The IJsonObjectWriter interface defines a writer of a json object.
 */
public interface IJsonObjectWriter {
    /**
     * Writes a boolean property.
     */
    void writeBooleanProperty(
        String name,
        boolean value);

    /**
     * Writes a byte property.
     */
    void writeByteProperty(
        String name,
        byte value);

    /**
     * Writes a short property.
     */
    void writeShortProperty(
        String name,
        short value);

    /**
     * Writes an integer property.
     */
    void writeIntegerProperty(
        String name,
        int value);

    /**
     * Writes a long property.
     */
    void writeLongProperty(
        String name,
        long value);

    /**
     * Writes a float property.
     */
    void writeFloatProperty(
        String name,
        float value);

    /**
     * Writes a double property.
     */
    void writeDoubleProperty(
        String name,
        double value);

    /**
     * Writes a string property.
     */
    void writeStringProperty(
        String name,
        String value);

    /**
     * Writes an enum property.
     */
    <T extends Enum<T>> void writeEnumProperty(
        String name,
        T value);

    /**
     * Writes a boolean array property.
     */
    void writeArrayProperty(
        String name,
        boolean[] array);

    /**
     * Writes a byte array property.
     */
    void writeArrayProperty(
        String name,
        byte[] array);

    /**
     * Writes a short array property.
     */
    void writeArrayProperty(
        String name,
        short[] array);

    /**
     * Writes an integer array property.
     */
    void writeArrayProperty(
        String name,
        int[] array);

    /**
     * Writes a long array property.
     */
    void writeArrayProperty(
        String name,
        long[] array);

    /**
     * Writes a float array property.
     */
    void writeArrayProperty(
        String name,
        float[] array);

    /**
     * Writes a double array property.
     */
    void writeArrayProperty(
        String name,
        double[] array);

    /**
     * Writes a string array property.
     */
    void writeArrayProperty(
        String name,
        String[] array);

    /**
     * Writes a string collection property.
     */
    void writeCollectionProperty(
        String name,
        Collection<String> collection);

    /**
     * Writes a blob property.
     */
    void writeBlobProperty(
        String name,
        byte[] blob);

    /**
     * Writes a date property.
     */
    void writeDateProperty(
        String name,
        Date date);

    /**
     * Writes a date property with a formatter.
     */
    void writeDateProperty(
        String name,
        Date dataTime,
        DateFormat formatter);

    /**
     * Writes a duration property.
     */
    void writeDurationProperty(
        String name,
        Duration duration);

    /**
     * Writes a duration property with a formatter.
     */
    void writeDurationProperty(
        String name,
        Duration duration,
        String formatter);

    /**
     * Writes a generic object property.
     */
    <T extends IJsonSerialization> void writeObjectProperty(
        String name,
        T object);

    /**
     * Writes a generic array property.
     */
    <T extends IJsonSerialization> void writeArrayProperty(
        String name,
        T[] array);

    /**
     * Writes a generic collection property.
     */
    <T extends IJsonSerialization> void writeCollectionProperty(
        String name,
        List<T> list);

    /**
     * Writes a generic collection property with a transformer.
     */
    <T> void writeCollectionProperty(
        String name,
        Collection<T> collection,
        IToString<T> transformer);

    /**
     * Writes a string map property.
     */
    void writeMapProperty(
        String name,
        Map<String, String> map);

    /**
     * Writes a map property with key and value transformers.
     */
    <TKey, TValue> void writeMapProperty(
        String name,
        Map<TKey, TValue> map,
        IToString<TKey> keyTransformer,
        IToString<TValue> valueTransformer);
}
