package json.core;

import base.core.Conditions;
import json.interfaces.IJsonObjectWriter;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The JsonObjectWriter class implements a writer of a json object.
 */
public final class JsonObjectWriter implements IJsonObjectWriter {
    private final IJsonWriter jsonWriter;

    /**
     * The JsonObjectWriter constructor.
     */
    public JsonObjectWriter(IJsonWriter jsonWriter) {
        Conditions.validateNotNull(
            jsonWriter,
            "The json writer to write into.");

        this.jsonWriter = jsonWriter;
    }

    /**
     * Writes a boolean property.
     */
    @Override
    public void writeBooleanProperty(String name, boolean value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a byte property.
     */
    @Override
    public void writeByteProperty(String name, byte value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a short property.
     */
    @Override
    public void writeShortProperty(String name, short value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes an integer property.
     */
    @Override
    public void writeIntegerProperty(String name, int value) {
        this.jsonWriter.writeIntegerProperty(name, value);
    }

    /**
     * Writes a long property.
     */
    @Override
    public void writeLongProperty(String name, long value) {
        this.jsonWriter.writeLongProperty(name, value);
    }

    /**
     * Writes a float property.
     */
    @Override
    public void writeFloatProperty(String name, float value) {
        this.jsonWriter.writeFloatProperty(name, value);
    }

    /**
     * Writes a double property.
     */
    @Override
    public void writeDoubleProperty(String name, double value) {
        this.jsonWriter.writeDoubleProperty(name, value);
    }

    /**
     * Writes a character property.
     */
    @Override
    public void writeCharacterProperty(String name, char value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a string property.
     */
    @Override
    public void writeStringProperty(String name, String value) {
        this.jsonWriter.writeStringProperty(name, value);
    }

    /**
     * Writes a boolean array property.
     */
    @Override
    public void writeBooleanArrayProperty(String name, boolean[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a byte array property.
     */
    @Override
    public void writeByteArrayProperty(String name, byte[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a short array property.
     */
    @Override
    public void writeShortArrayProperty(String name, short[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes an integer array property.
     */
    @Override
    public void writeIntegerArrayProperty(String name, int[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a float array property.
     */
    @Override
    public void writeFloatArrayProperty(String name, float[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a double array property.
     */
    @Override
    public void writeDoubleArrayProperty(String name, double[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a character array property.
     */
    @Override
    public void writeCharacterArrayProperty(String name, char[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a string array property.
     */
    @Override
    public void writeStringArrayProperty(String name, String[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a generic property.
     */
    @Override
    public <T> void writeGenericProperty(String name, T value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a generic array property.
     */
    @Override
    public <T> void writeArrayProperty(String name, T[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a generic list property.
     */
    @Override
    public <T extends IJsonSerialization> void writeListProperty(String name, List<T> value) {
        throw new UnsupportedOperationException();
    }
}
