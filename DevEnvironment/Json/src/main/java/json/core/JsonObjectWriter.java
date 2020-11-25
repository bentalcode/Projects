package json.core;

import base.core.Conditions;
import base.interfaces.IToString;
import json.interfaces.IJsonObjectWriter;
import json.interfaces.IJsonSerialization;
import java.text.DateFormat;
import java.time.Duration;
import java.util.Collection;
import java.util.Date;
import java.util.List;
import java.util.Map;

/**
 * The JsonObjectWriter class implements a writer of a json object.
 */
public final class JsonObjectWriter implements IJsonObjectWriter {
    private final IJsonGenerator generator;

    /**
     * The JsonObjectWriter constructor.
     */
    public JsonObjectWriter(IJsonGenerator generator) {
        Conditions.validateNotNull(
            generator,
            "The json generator to write into.");

        this.generator = generator;
    }

    /**
     * Writes a boolean property.
     */
    @Override
    public void writeBooleanProperty(
        String name,
        boolean value) {

        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeBoolean(value);
    }

    /**
     * Writes a byte property.
     */
    @Override
    public void writeByteProperty(
        String name,
        byte value) {

        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeByte(value);
    }

    /**
     * Writes a short property.
     */
    @Override
    public void writeShortProperty(
        String name,
        short value) {

        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeShort(value);
    }

    /**
     * Writes an integer property.
     */
    @Override
    public void writeIntegerProperty(
        String name,
        int value) {

        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeInteger(value);
    }

    /**
     * Writes a long property.
     */
    @Override
    public void writeLongProperty(
        String name,
        long value) {

        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeLong(value);
    }

    /**
     * Writes a float property.
     */
    @Override
    public void writeFloatProperty(
        String name,
        float value) {

        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeFloat(value);
    }

    /**
     * Writes a double property.
     */
    @Override
    public void writeDoubleProperty(
        String name,
        double value) {

        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeDouble(value);
    }

    /**
     * Writes a string property.
     */
    @Override
    public void writeStringProperty(
        String name,
        String value) {

        this.validatePropertyName(name);

        if (value == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeString(value);
    }

    /**
     * Writes an enum property.
     */
    public <T extends Enum<T>> void writeEnumProperty(
        String name,
        T value) {

        if (value == null) {
            return;
        }

        this.writeStringProperty(name, value.toString());
    }

    /**
     * Writes a boolean array property.
     */
    @Override
    public void writeArrayProperty(
        String name,
        boolean[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeBooleanArray(array);
    }

    /**
     * Writes a byte array property.
     */
    @Override
    public void writeArrayProperty(
        String name,
        byte[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeByteArray(array);
    }

    /**
     * Writes a short array property.
     */
    @Override
    public void writeArrayProperty(
        String name,
        short[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeShortArray(array);
    }

    /**
     * Writes an integer array property.
     */
    @Override
    public void writeArrayProperty(
        String name,
        int[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeIntegerArray(array);
    }

    /**
     * Writes a long array property.
     */
    @Override
    public void writeArrayProperty(
        String name,
        long[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeLongArray(array);
    }

    /**
     * Writes a float array property.
     */
    @Override
    public void writeArrayProperty(
        String name,
        float[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeFloatArray(array);
    }

    /**
     * Writes a double array property.
     */
    @Override
    public void writeArrayProperty(
        String name,
        double[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeDoubleArray(array);
    }

    /**
     * Writes a string array property.
     */
    @Override
    public void writeArrayProperty(
        String name,
        String[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeStringArray(array);
    }

    /**
     * Writes a string collection property.
     */
    @Override
    public void writeCollectionProperty(
        String name,
        Collection<String> collection) {

        this.validatePropertyName(name);

        if (collection == null || collection.isEmpty()) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeStringCollection(collection);
    }

    /**
     * Writes a blob property.
     */
    @Override
    public void writeBlobProperty(
        String name,
        byte[] blob) {

        this.validatePropertyName(name);

        if (blob == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeBlob(blob);
    }

    /**
     * Writes a date property.
     */
    @Override
    public void writeDateProperty(
        String name,
        Date date) {

        this.validatePropertyName(name);

        if (date == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeDate(date);
    }

    /**
     * Writes a date property with a formatter.
     */
    @Override
    public void writeDateProperty(
        String name,
        Date date,
        DateFormat formatter) {

        this.validatePropertyName(name);

        if (date == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeDate(date, formatter);
    }

    /**
     * Writes a duration property.
     */
    @Override
    public void writeDurationProperty(
        String name,
        Duration duration) {

        this.validatePropertyName(name);

        if (duration == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeDuration(duration);
    }

    /**
     * Writes a duration property with a formatter.
     */
    @Override
    public void writeDurationProperty(
        String name,
        Duration duration,
        String formatter) {

        this.validatePropertyName(name);

        if (duration == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeDuration(duration, formatter);
    }

    /**
     * Writes a generic object property.
     */
    @Override
    public <T extends IJsonSerialization> void writeObjectProperty(
        String name,
        T object) {

        this.validatePropertyName(name);

        if (object == null) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);
        writer.writeObject(object);
    }

    /**
     * Writes a generic array property.
     */
    @Override
    public <T extends IJsonSerialization> void writeArrayProperty(
        String name,
        T[] array) {

        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);
        writer.writeArray(array);
    }

    /**
     * Writes a generic collection property.
     */
    @Override
    public <T extends IJsonSerialization> void writeCollectionProperty(
        String name,
        List<T> collection) {

        this.validatePropertyName(name);

        if (collection == null || collection.isEmpty()) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);
        writer.writeCollection(collection);
    }

    /**
     * Writes a generic collection property with a transformer.
     */
    @Override
    public <T> void writeCollectionProperty(
        String name,
        Collection<T> collection,
        IToString<T> transformer) {

        this.validatePropertyName(name);
        this.validateTransformer(transformer);

        if (collection == null || collection.isEmpty()) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);
        writer.writeCollection(collection, transformer);
    }

    /**
     * Writes a map property.
     */
    @Override
    public void writeMapProperty(
        String name,
        Map<String, String> map) {

        this.validatePropertyName(name);

        if (map == null || map.isEmpty()) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);
        writer.writeMapProperty(map);
    }

    /**
     * Writes a map property with key and value transformers.
     */
    @Override
    public <TKey, TValue> void writeMapProperty(
        String name,
        Map<TKey, TValue> map,
        IToString<TKey> keyTransformer,
        IToString<TValue> valueTransformer) {

        this.validatePropertyName(name);

        if (map == null || map.isEmpty()) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);

        writer.writeMapProperty(
            map,
            keyTransformer,
            valueTransformer);
    }

    /**
     * Validates a name of a property.
     */
    private void validatePropertyName(String name) {
        Conditions.validateNotNull(
            name,
            "The name of a property.");
    }

    /**
     * Validates a name of a property.
     */
    private <T> void validateTransformer(IToString<T> transformer) {
        Conditions.validateNotNull(
            transformer,
            "The string transformer.");
    }
}
