package json.core;

/**
 * The IJsonGenerator interface defines a generator for json.
 */
public interface IJsonGenerator {
    /**
     * Writes a start object.
     */
    void writeStartObject();

    /**
     * Writes an end object.
     */
    void writeEndObject();

    /**
     * Writes a start array.
     */
    void writeStartArray();

    /**
     * Writes an end array.
     */
    void writeEndArray();

    /**
     * Writes a property name.
     */
    void writePropertyName(String name);

    /**
     * Writes a boolean.
     */
    void writeBoolean(boolean value);

    /**
     * Writes a short value.
     */
    void writeShort(short value);

    /**
     * Writes an integer.
     */
    void writeInteger(int value);

    /**
     * Writes a long.
     */
    void writeLong(long value);

    /**
     * Writes a float.
     */
    void writeFloat(float value);

    /**
     * Writes a double.
     */
    void writeDouble(double value);

    /**
     * Writes a string.
     */
    void writeString(String value);

    /**
     * Writes a boolean array.
     */
    void writeBooleanArray(boolean[] array);

    /**
     * Writes a short array.
     */
    void writeShortArray(short[] array);

    /**
     * Writes an integer array.
     */
    void writeIntegerArray(int[] array);

    /**
     * Writes a long array.
     */
    void writeLongArray(long[] array);

    /**
     * Writes a float array.
     */
    void writeFloatArray(float[] array);

    /**
     * Writes a double array.
     */
    void writeDoubleArray(double[] array);

    /**
     * Writes a string array.
     */
    void writeStringArray(String[] array);

    /**
     * Flushes the writer.
     */
    void flush();
}
