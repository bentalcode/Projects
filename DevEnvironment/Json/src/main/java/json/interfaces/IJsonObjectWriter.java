package json.interfaces;

import java.util.List;

/**
 * The IJsonObjectWriter interface defines a writer of a json object.
 */
public interface IJsonObjectWriter {
    /**
     * Writes a boolean property.
     */
    void writeBooleanProperty(String name, boolean value);

    /**
     * Writes a byte property.
     */
    void writeByteProperty(String name, byte value);

    /**
     * Writes a short property.
     */
    void writeShortProperty(String name, short value);

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
     * Writes a string property.
     */
    void writeStringProperty(String name, String value);

    /**
     * Writes a boolean array property.
     */
    void writeBooleanArrayProperty(String name, boolean[] array);

    /**
     * Writes a byte array property.
     */
    void writeByteArrayProperty(String name, byte[] array);

    /**
     * Writes a short array property.
     */
    void writeShortArrayProperty(String name, short[] array);

    /**
     * Writes an integer array property.
     */
    void writeIntegerArrayProperty(String name, int[] array);

    /**
     * Writes a long array property.
     */
    void writeLongArrayProperty(String name, long[] array);

    /**
     * Writes a float array property.
     */
    void writeFloatArrayProperty(String name, float[] array);

    /**
     * Writes a double array property.
     */
    void writeDoubleArrayProperty(String name, double[] array);

    /**
     * Writes a string array property.
     */
    void writeStringArrayProperty(String name, String[] array);

    /**
     * Writes a blob property.
     */
    void writeBlobProperty(String name, byte[] blob);

    /**
     * Writes a generic object property.
     */
    <T extends IJsonSerialization> void writeObjectProperty(String name, T object);

    /**
     * Writes a generic array property.
     */
    <T extends IJsonSerialization> void writeArrayProperty(String name, T[] array);

    /**
     * Writes a generic list property.
     */
    <T extends IJsonSerialization> void writeListProperty(String name, List<T> list);
}
