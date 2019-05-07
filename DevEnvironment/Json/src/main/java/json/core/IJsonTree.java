package json.core;

/**
 * The IJsonTree interface defines a json tree.
 */
public interface IJsonTree {
    /**
     * Gets the root object.
     */
    IJsonObject getRootObject();

    /**
     * Gets the root array.
     */
    IJsonArray getRootArray();

    /**
     * Creates a new json object.
     */
    IJsonObject createObject();

    /**
     * Creates a new json array.
     */
    IJsonArray createArray();
}
