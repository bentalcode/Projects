package json.core;

import java.util.Map;

/**
 * The IJsonObject interface defines a json object.
 */
public interface IJsonObject extends IJsonElement {
    /**
     * Gets properties.
     */
    Map<String, IJsonValue> getProperties();

    /**
     * Gets a value of a property.
     */
    IJsonValue getPropertyValue(String name);

    /**
     * Sets a value of a property.
     */
    void setPropertyValue(String name, IJsonValue value);

    /**
     * Checks whether a property exists.
     */
    boolean propertyExists(String name);
}
