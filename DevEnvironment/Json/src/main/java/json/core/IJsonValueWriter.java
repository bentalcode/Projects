package json.core;

import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The IJsonValueWriter interface defines a writer of a json value.
 */
public interface IJsonValueWriter {
    /**
     * Writes a boolean.
     */
    void writeBoolean(boolean value);

    /**
     * Writes a byte.
     */
    void writeByte(byte value);

    /**
     * Writes a short.
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
    void writeBooleanArray(boolean[] value);

    /**
     * Writes a byte array.
     */
    void writeByteArray(byte[] value);

    /**
     * Writes a short array.
     */
    void writeShortArray(short[] value);

    /**
     * Writes an integer array.
     */
    void writeIntegerArray(int[] value);

    /**
     * Writes a float array.
     */
    void writeFloatArray(float[] value);

    /**
     * Writes a double array.
     */
    void writeDoubleArray(double[] value);

    /**
     * Writes a string array.
     */
    void writeStringArray(String[] value);

    /**
     * Writes a generic object.
     */
    <T extends IJsonSerialization> void writeObject(T value);

    /**
     * Writes a generic array.
     */
    <T extends IJsonSerialization> void writeArray(T[] value);

    /**
     * Writes a generic list.
     */
    <T extends IJsonSerialization> void writeList(List<T> value);
}
