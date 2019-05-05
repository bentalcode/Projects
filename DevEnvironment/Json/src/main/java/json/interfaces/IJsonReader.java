package json.interfaces;

import java.util.Collection;

/**
 * The IJsonReader interface defines a json reader.
 */
public interface IJsonReader {
    /**
     * Reads a boolean property.
     */
    boolean readBooleanProperty(String name);

    /**
     * Reads a byte property.
     */
    byte readByteProperty(String name);

    /**
     * Reads a short property.
     */
    short readShortProperty(String name);

    /**
     * Reads an integer property.
     */
    int readIntegerProperty(String name);

    /**
     * Reads a long property.
     */
    long readLongProperty(String name);

    /**
     * Reads a float property.
     */
    float readFloatProperty(String name);

    /**
     * Reads a double property.
     */
    double readDoubleProperty(String name);

    /**
     * Reads a character property.
     */
    char readCharacterProperty(String name);

    /**
     * Reads a string property.
     */
    String readStringProperty(String name);

    /**
     * Reads a boolean array property.
     */
    boolean[] readBooleanArrayProperty(String name);

    /**
     * Reads a byte array property.
     */
    byte[] readByteArrayProperty(String name);

    /**
     * Reads a short array property.
     */
    short[] readShortArrayProperty(String name);

    /**
     * Reads an integer array property.
     */
    int[] readIntegerArrayProperty(String name);

    /**
     * Reads a float array property.
     */
    float[] readFloatArrayProperty(String name);

    /**
     * Reads a double array property.
     */
    double[] readDoubleArrayProperty(String name);

    /**
     * Reads a character array property.
     */
    char[] readCharacterArrayProperty(String name);

    /**
     * Reads a string array property.
     */
    String[] readStringArrayProperty(String name);

    /**
     * Reads a generic property.
     */
    <T> void readGenericProperty(String name);

    /**
     * Reads a generic array property.
     */
    <T> T[] readArrayProperty(String name);

    /**
     * Reads a generic collection property.
     */
    <T> Collection<T> readCollectionProperty(String name);
}
