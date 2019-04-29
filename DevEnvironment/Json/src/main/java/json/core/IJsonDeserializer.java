package json.core;

import java.util.Collection;

/**
 * The IJsonDeserializer interface defines a json deserializer.
 */
public interface IJsonDeserializer {

    /**
     * Reads a boolean.
     */
    boolean readBoolean();

    /**
     * Reads a byte.
     */
    byte readByte();

    /**
     * Reads a short.
     */
    short readShort();

    /**
     * Reads an integer.
     */
    int readInteger();

    /**
     * Reads a long.
     */
    long readLong();

    /**
     * Reads a float.
     */
    float readFloat();

    /**
     * Reads a double.
     */
    double readDouble();

    /**
     * Reads a character.
     */
    char readCharacter();

    /**
     * Reads a string.
     */
    String readString();

    /**
     * Reads a boolean array.
     */
    boolean[] readBooleanArray();

    /**
     * Reads a byte array.
     */
    byte[] readByteArray(byte[] value);

    /**
     * Reads a short array.
     */
    short[] readShortArray(short[] value);

    /**
     * Reads an integer array.
     */
    int[] readIntegerArray(int[] value);

    /**
     * Reads a float array.
     */
    float[] readFloatArray(float[] value);

    /**
     * Reads a double array.
     */
    double[] readDoubleArray(double[] value);

    /**
     * Reads a character array.
     */
    char[] readCharacterArray(char[] value);

    /**
     * Reads a string array.
     */
    String[] readStringArray(String[] value);

    /**
     * Reads a generic.
     */
    <T> void readGeneric(T value);

    /**
     * Reads a generic array.
     */
    <T> T[] readArray();

    /**
     * Reads a generic collection.
     */
    <T> Collection<T> readCollection();
}
