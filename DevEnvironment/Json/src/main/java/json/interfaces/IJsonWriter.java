package json.interfaces;

import java.util.Collection;

/**
 * The IJsonWriter interface defines a json writer.
 */
public interface IJsonWriter {
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
     * Writes a character.
     */
    void writeCharacter(char value);

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
     * Writes a character array.
     */
    void writeCharacterArray(char[] value);

    /**
     * Writes a string array.
     */
    void writeStringArray(String[] value);

    /**
     * Writes a generic.
     */
    <T> void writeGeneric(T value);

    /**
     * Writes a generic array.
     */
    <T> void writeArray(T[] value);

    /**
     * Writes a generic collection.
     */
    <T> void writeCollection(Collection<T> value);
}
