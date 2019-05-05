package json.core;

/**
 * The IJsonObjectWriter interface defines a writer of a json object.
 */
public interface IJsonObjectWriter {
    /**
     * Writes a boolean property.
     */
    void writeBooleanProperty(String name, boolean value);

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

    /**
     * Writes a generic object property.
     */
    void writeObjectProperty(String name, IJsonObjectWriter value);

    /**
     * Writes a generic array property.
     */
    void writeArrayProperty(String name, IJsonArray value);
}
