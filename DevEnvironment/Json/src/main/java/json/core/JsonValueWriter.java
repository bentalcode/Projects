package json.core;

import base.core.ArrayIterator;
import base.core.Conditions;
import base.core.Iterator;
import base.interfaces.IIterator;
import base.interfaces.IToString;
import json.interfaces.IJsonObjectWriter;
import json.interfaces.IJsonSerialization;

import java.util.Collection;
import java.util.Map;

/**
 * The JsonValueWriter class implements a writer of a json value.
 */
public final class JsonValueWriter implements IJsonValueWriter {
    private final IJsonGenerator generator;

    /**
     * The JsonValueWriter constructor.
     */
    public JsonValueWriter(IJsonGenerator generator) {
        Conditions.validateNotNull(
            generator,
            "The json generator to write into.");

        this.generator = generator;
    }

    /**
     * Writes a boolean.
     */
    @Override
    public void writeBoolean(boolean value) {
        this.generator.writeBoolean(value);
    }

    /**
     * Writes a byte.
     */
    @Override
    public void writeByte(byte value) {
        this.generator.writeByte(value);
    }

    /**
     * Writes a short.
     */
    @Override
    public void writeShort(short value) {
        this.generator.writeShort(value);
    }

    /**
     * Writes an integer.
     */
    @Override
    public void writeInteger(int value) {
        this.generator.writeInteger(value);
    }

    /**
     * Writes a long.
     */
    @Override
    public void writeLong(long value) {
        this.generator.writeLong(value);
    }

    /**
     * Writes a float.
     */
    @Override
    public void writeFloat(float value) {
        this.generator.writeFloat(value);
    }

    /**
     * Writes a double.
     */
    @Override
    public void writeDouble(double value) {
        this.generator.writeDouble(value);
    }

    /**
     * Writes a string.
     */
    @Override
    public void writeString(String value) {
        this.generator.writeString(value);
    }

    /**
     * Writes a boolean array.
     */
    @Override
    public void writeBooleanArray(boolean[] array) {
        if (array == null) {
            return;
        }

        this.generator.writeBooleanArray(array);
    }

    /**
     * Writes a byte array.
     */
    @Override
    public void writeByteArray(byte[] array) {
        if (array == null) {
            return;
        }

        this.generator.writeByteArray(array);
    }

    /**
     * Writes a short array.
     */
    @Override
    public void writeShortArray(short[] array) {
        if (array == null) {
            return;
        }

        this.generator.writeShortArray(array);
    }

    /**
     * Writes an integer array.
     */
    @Override
    public void writeIntegerArray(int[] array) {
        if (array == null) {
            return;
        }

        this.generator.writeIntegerArray(array);
    }

    /**
     * Writes a float array.
     */
    @Override
    public void writeFloatArray(float[] array) {
        if (array == null) {
            return;
        }

        this.generator.writeFloatArray(array);
    }

    /**
     * Writes a double array.
     */
    @Override
    public void writeDoubleArray(double[] array) {
        if (array == null) {
            return;
        }

        this.generator.writeDoubleArray(array);
    }

    /**
     * Writes a string array.
     */
    @Override
    public void writeStringArray(String[] array) {
        if (array == null) {
            return;
        }

        this.generator.writeStringArray(array);
    }

    /**
     * Writes a generic object.
     */
    @Override
    public <T extends IJsonSerialization> void writeObject(T object) {
        if (object == null) {
            return;
        }

        this.generator.writeStartObject();

        IJsonObjectWriter writer = new JsonObjectWriter(this.generator);
        object.writeJson(writer);

        this.generator.writeEndObject();
    }

    /**
     * Writes a generic array.
     */
    @Override
    public <T extends IJsonSerialization> void writeArray(T[] array) {
        if (array == null) {
            return;
        }

        this.writeCollection(ArrayIterator.of(array));
    }

    /**
     * Writes a generic collection.
     */
    @Override
    public <T extends IJsonSerialization> void writeCollection(Collection<T> collection) {
        if (collection == null || collection.isEmpty()) {
            return;
        }

        this.writeCollection(Iterator.of(collection));
    }

    /**
     * Writes a generic collection.
     */
    @Override
    public <T> void writeCollection(Collection<T> collection, IToString<T> transformer) {
        if (collection == null || collection.isEmpty()) {
            return;
        }

        String[] collectionToWrite = new String[collection.size()];

        int insertIndex = 0;

        for (T item : collection) {
            collectionToWrite[insertIndex] = transformer.toString(item);
            ++insertIndex;
        }

        this.writeStringArray(collectionToWrite);
    }

    /**
     * Writes a map.
     */
    @Override
    public void writeMapProperty(Map<String, String> map) {
        if (map == null || map.isEmpty()) {
            return;
        }

        this.generator.writeStartObject();

        for (Map.Entry<String, String> entry : map.entrySet()) {
            String key = entry.getKey();
            String value = entry.getValue();

            this.generator.writePropertyName(key);
            this.generator.writeString(value);
        }

        this.generator.writeEndObject();
    }

    /**
     * Writes a map property with key and value transformers.
     */
    @Override
    public <TKey, TValue> void writeMapProperty(
        Map<TKey, TValue> map,
        IToString<TKey> keyTransformer,
        IToString<TValue> valueTransformer) {

        if (map == null || map.isEmpty()) {
            return;
        }

        this.generator.writeStartObject();

        for (Map.Entry<TKey, TValue> entry : map.entrySet()) {
            String key = keyTransformer.toString(entry.getKey());
            String value = valueTransformer.toString(entry.getValue());

            this.generator.writePropertyName(key);
            this.generator.writeString(value);
        }

        this.generator.writeEndObject();
    }

    /**
     * Writes a generic collection.
     */
    private <T extends IJsonSerialization> void writeCollection(IIterator<T> iterator) {
        this.generator.writeStartArray();

        while (iterator.hasNext()) {
            T item = iterator.next();
            this.writeObject(item);
        }

        this.generator.writeEndArray();
    }
}
