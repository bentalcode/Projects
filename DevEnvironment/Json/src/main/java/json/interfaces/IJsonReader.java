package json.interfaces;

import java.util.Collection;

/**
 * The IJsonReader interface defines a json reader.
 */
public interface IJsonReader {
    /**
     * Reads a boolean.
     */
    boolean readBoolean(String name);

    /**
     * Reads a byte.
     */
    byte readByte(String name);

    /**
     * Reads a short.
     */
    short readShort(String name);

    /**
     * Reads an integer.
     */
    int readInteger(String name);

    /**
     * Reads a long.
     */
    long readLong(String name);

    /**
     * Reads a float.
     */
    float readFloat(String name);

    /**
     * Reads a double.
     */
    double readDouble(String name);

    /**
     * Reads a character.
     */
    char readCharacter(String name);

    /**
     * Reads a string.
     */
    String readString(String name);

    /**
     * Reads a boolean array.
     */
    boolean[] readBooleanArray(String name);

    /**
     * Reads a byte array.
     */
    byte[] readByteArray(String name);

    /**
     * Reads a short array.
     */
    short[] readShortArray(String name);

    /**
     * Reads an integer array.
     */
    int[] readIntegerArray(String name);

    /**
     * Reads a float array.
     */
    float[] readFloatArray(String name);

    /**
     * Reads a double array.
     */
    double[] readDoubleArray(String name);

    /**
     * Reads a character array.
     */
    char[] readCharacterArray(String name);

    /**
     * Reads a string array.
     */
    String[] readStringArray(String name);

    /**
     * Reads a generic.
     */
    <T> void readGeneric(String name);

    /**
     * Reads a generic array.
     */
    <T> T[] readArray(String name);

    /**
     * Reads a generic collection.
     */
    <T> Collection<T> readCollection(String name);
}
