package json.core;

/**
 * The IJsonObject interface defines a json object.
 */
public interface IJsonObject {
    /**
     * Gets a boolean property.
     */
    Boolean getBooleanProperty(String name);

    /**
     * Gets a string property.
     */
    String getStringProperty(String name);

    /**
     * Gets an integer property.
     */
    int getIntegerProperty(String name);

    /**
     * Gets a long property.
     */
    long getLongProperty(String name);

    /**
     * Gets a float property.
     */
    float getFloatProperty(String name);

    /**
     * Gets a double property.
     */
    double getDoubleProperty(String name);
}
