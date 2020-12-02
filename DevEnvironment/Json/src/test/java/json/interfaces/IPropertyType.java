package json.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IPropertyType interface defines various types of a property.
 */
public interface IPropertyType extends IUnaryComparator<IPropertyType>, IJsonSerialization {
    /**
     * Gets a boolean property.
     */
    boolean getBooleanProperty();

    /**
     * Gets a short property.
     */
    short getShortProperty();

    /**
     * Gets an integer property.
     */
    int getIntegerProperty();

    /**
     * Gets a long property.
     */
    long getLongProperty();

    /**
     * Gets a float value.
     */
    float getFloatProperty();

    /**
     * Gets a double property.
     */
    double getDoubleProperty();

    /**
     * Gets a string property.
     */
    String getStringProperty();

    /**
     * Gets a boolean array property.
     */
    boolean[] getBooleanArrayProperty();

    /**
     * Gets a short array property.
     */
    short[] getShortArrayProperty();

    /**
     * Gets an integer array property.
     */
    int[] getIntegerArrayProperty();

    /**
     * Gets a long array property.
     */
    long[] getLongArrayProperty();

    /**
     * Gets a float array property.
     */
    float[] getFloatArrayProperty();

    /**
     * Gets a double array property.
     */
    double[] getDoubleArrayProperty();

    /**
     * Gets a string array property.
     */
    String[] getStringArrayProperty();

    /**
     * Gets a blob property.
     */
    byte[] getBlobProperty();
}
