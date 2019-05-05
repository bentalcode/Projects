package json.core;

/**
 * The IJsonObjectReader interface defines a reader of a json object.
 */
public interface IJsonObjectReader {
    /**
     * Reads a boolean property.
     */
    boolean readBooleanProperty(String name);

    /**
     * Reads a string property.
     */
    String readStringProperty(String name);

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
     * Reads a generic object property.
     */
    IJsonObjectReader readObjectProperty(String name);

    /**
     * Reads a generic array property.
     */
    IJsonArray readArrayProperty(String name);
}
