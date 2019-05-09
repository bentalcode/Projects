package json.core;

/**
 * The IJsonValue interface defines a json value.
 */
public interface IJsonValue {
    /**
     * Gets a boolean value.
     */
    boolean getBooleanValue();

    /**
     * Gets a long value.
     */
    long getLongValue();

    /**
     * Gets a double value.
     */
    double getDoubleValue();

    /**
     * Gets a string value.
     */
    String getStringValue();

    /**
     * Gets an object.
     */
    IJsonObject getObject();

    /**
     * Gets an array.
     */
    IJsonArray getArray();
}
