package json.core;

import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The IJsonValueReader interface defines a reader of a json value.
 */
interface IJsonValueReader {
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
    byte[] readByteArray();

    /**
     * Reads a short array.
     */
    short[] readShortArray();

    /**
     * Reads an integer array.
     */
    int[] readIntegerArray();

    /**
     * Reads a long array.
     */
    long[] readLongArray();

    /**
     * Reads a float array.
     */
    float[] readFloatArray();

    /**
     * Reads a double array.
     */
    double[] readDoubleArray();

    /**
     * Reads a character array.
     */
    char[] readCharacterArray();

    /**
     * Reads a string array.
     */
    String[] readStringArray();

    /**
     * Reads a generic object.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType readObject(Class<ClassType> classType);

    /**
     * Reads a generic array.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType[] readArray(Class<ClassType> classType);

    /**
     * Reads a generic list.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> List<ResultType> readList(Class<ClassType> classType);
}
