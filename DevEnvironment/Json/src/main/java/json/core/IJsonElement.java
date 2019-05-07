package json.core;

/**
 * The IJsonElement interface defines a json element.
 */
public interface IJsonElement {
    /**
     * Gets an identifier of a json element.
     */
    int getId();

    /**
     * Sets a value.
     */
    void setValue(String name, IJsonValue value);
}
