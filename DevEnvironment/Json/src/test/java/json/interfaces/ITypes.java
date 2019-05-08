package json.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The ITypes interface defines properties of types.
 */
public interface ITypes extends IUnaryComparator<ITypes>, IJsonSerialization {
    /**
     * Gets a short value.
     */
    short getShortValue();

    /**
     * Gets an integer value.
     */
    int getIntegerValue();

    /**
     * Gets a long value.
     */
    long getLongValue();

    /**
     * Gets a float value.
     */
    float getFloatValue();

    /**
     * Gets a double value.
     */
    double getDoubleValue();

    /**
     * Gets a string value.
     */
    String getStringValue();

    /**
     * Gets a short array.
     */
    short[] getShortArray();

    /**
     * Gets an integer array.
     */
    int[] getIntegerArray();

    /**
     * Gets a long array.
     */
    long[] getLongArray();

    /**
     * Gets a float array.
     */
    float[] getFloatArray();

    /**
     * Gets a double array.
     */
    double[] getDoubleArray();

    /**
     * Gets a string array.
     */
    String[] getStringArray();

    /**
     * Gets a blob.
     */
    byte[] getBlob();
}
