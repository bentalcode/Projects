package json.core;

/**
 * The IJsonObjectValue interface defines a json value of an object.
 */
public interface IJsonObjectValue extends IJsonValue {
    /**
     * Gets an object.
     */
    IJsonObject getValue();
}
