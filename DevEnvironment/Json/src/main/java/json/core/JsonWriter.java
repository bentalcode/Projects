package json.core;

import base.core.Conditions;
import json.interfaces.IJsonWriter;
import java.util.Collection;

/**
 * The JsonWriter class implements a Json writer.
 */
public final class JsonWriter implements IJsonWriter {
    private final IJsonTree jsonTree;
    private final IJsonObject jsonRoot;

    /**
     * The JsonWriter constructor.
     */
    public JsonWriter(IJsonTree jsonTree) {
        Conditions.validateNotNull(
            jsonTree,
            "The json tree.");

        this.jsonTree = jsonTree;
        this.jsonRoot = this.jsonTree.getRoot();
    }

    /**
     * Writes a boolean property.
     */
    public void writeBooleanProperty(String name, boolean value) {
        this.jsonRoot.writeBooleanProperty(name, value);
    }

    /**
     * Writes a byte property.
     */
    public void writeByteProperty(String name, byte value) {
        int valueToWrite = value;
        this.writeIntegerProperty(name, valueToWrite);
    }

    /**
     * Writes a short property.
     */
    public void writeShortProperty(String name, short value) {
        int valueToWrite = value;
        this.writeIntegerProperty(name, valueToWrite);
    }

    /**
     * Writes an integer property.
     */
    public void writeIntegerProperty(String name, int value) {
        this.jsonRoot.writeIntegerProperty(name, value);
    }

    /**
     * Writes a long property.
     */
    public void writeLongProperty(String name, long value) {
        this.jsonRoot.writeLongProperty(name, value);
    }

    /**
     * Writes a float property.
     */
    public void writeFloatProperty(String name, float value) {
        this.jsonRoot.writeFloatProperty(name, value);
    }

    /**
     * Writes a double property.
     */
    public void writeDoubleProperty(String name, double value) {
        this.jsonRoot.writeDoubleProperty(name, value);
    }

    /**
     * Writes a character property.
     */
    public void writeCharacterProperty(String name, char value) {
        String valueToWrite = String.valueOf(value);
        this.writeStringProperty(name, valueToWrite);
    }

    /**
     * Writes a string property.
     */
    public void writeStringProperty(String name, String value) {
        this.jsonRoot.writeStringProperty(name, value);
    }

    /**
     * Writes a boolean array property.
     */
    public void writeBooleanArrayProperty(String name, boolean[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a byte array property.
     */
    public void writeByteArrayProperty(String name, byte[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a short array property.
     */
    public void writeShortArrayProperty(String name, short[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes an integer array property.
     */
    public void writeIntegerArrayProperty(String name, int[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a float array property.
     */
    public void writeFloatArrayProperty(String name, float[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a double array property.
     */
    public void writeDoubleArrayProperty(String name, double[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a character array property.
     */
    public void writeCharacterArrayProperty(String name, char[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Writes a string array property.
     */
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
     * Writes a generic collection property.
     */
    @Override
    public <T> void writeCollectionProperty(String name, Collection<T> value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Gets the string representation of the json tree.
     */
    @Override
    public String toString() {
        return this.jsonTree.getRoot().toString();
    }
}
