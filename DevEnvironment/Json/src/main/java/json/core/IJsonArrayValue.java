package json.core;

/**
 * The IJsonArrayValue interface defines a json value of an array.
 */
public interface IJsonArrayValue extends IJsonValue {
    /**
     * Gets an array.
     */
    IJsonArray getValue();
}
