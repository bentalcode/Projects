package json.core;

import json.interfaces.IJsonSerialization;

/**
 * The IJsonWriter interface defines a writer for json.
 */
public interface IJsonWriter {
    /**
     * Flushes the writer.
     */
    void flush();

    /**
     * Writes a generic object.
     */
    <T extends IJsonSerialization> void writeObject(T obj);

    /**
     * Writes a string property.
     */
    void writeStringProperty(String name, String value);

    /**
     * Writes an integer property.
     */
    void writeIntegerProperty(String name, int value);

    /**
     * Writes a long property.
     */
    void writeLongProperty(String name, long value);

    /**
     * Writes a float property.
     */
    void writeFloatProperty(String name, float value);

    /**
     * Writes a double property.
     */
    void writeDoubleProperty(String name, double value);
}
