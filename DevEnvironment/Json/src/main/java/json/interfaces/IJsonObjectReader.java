package json.interfaces;

import java.util.List;

/**
 * The IJsonObjectReader interface defines a reader of a json object.
 */
public interface IJsonObjectReader {
    /**
     * Reads a boolean property.
     */
    boolean readBooleanProperty(String name);

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
     * Reads a string property.
     */
    String readStringProperty(String name);

    /**
     * Reads a boolean array property.
     */
    boolean[] readBooleanArrayProperty(String name);

    /**
     * Reads a short array property.
     */
    short[] readShortArrayProperty(String name);

    /**
     * Reads an integer array property.
     */
    int[] readIntegerArrayProperty(String name);

    /**
     * Reads a long array property.
     */
    long[] readLongArrayProperty(String name);

    /**
     * Reads a float array property.
     */
    float[] readFloatArrayProperty(String name);

    /**
     * Reads a double array property.
     */
    double[] readDoubleArrayProperty(String name);

    /**
     * Reads a string array property.
     */
    String[] readStringArrayProperty(String name);

    /**
     * Reads a generic object property.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType readObjectProperty(String name, Class<ClassType> classType);

    /**
     * Reads a generic array property.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType[] readArrayProperty(String name, Class<ClassType> classType);

    /**
     * Reads a generic list property.
     */
    <ResultType extends IJsonSerialization, ClassType extends ResultType> List<ResultType> readListProperty(String name, Class<ClassType> classType);
}
