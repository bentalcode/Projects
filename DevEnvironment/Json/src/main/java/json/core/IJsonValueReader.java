package json.core;

import json.interfaces.IJsonSerialization;
import java.util.List;
import java.util.Set;

/**
 * The IJsonValueReader interface defines a reader of a json value.
 */
interface IJsonValueReader {
    /**
     * Reads a boolean.
     */
    boolean readBoolean();

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
     * Reads a string.
     */
    String readString();

    /**
     * Reads a boolean array.
     */
    boolean[] readBooleanArray();

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
     * Reads a string array.
     */
    String[] readStringArray();

    /**
     * Reads a string list.
     */
    List<String> readStringList();

    /**
     * Reads a string set.
     */
    Set<String> readStringSet();

    /**
     * Reads a blob.
     */
    byte[] readBlob();

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

    /**
     * Reads a generic set.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> Set<ResultType> readSet(Class<ClassType> classType);
}
