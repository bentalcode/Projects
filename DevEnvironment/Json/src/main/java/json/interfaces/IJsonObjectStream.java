package json.interfaces;

/**
 * The IJsonObjectStream interface defines a json stream for an object.
 */
public interface IJsonObjectStream {
    /**
     * Serializes an object to a json string.
     */
    <T extends IJsonSerialization> String toJson(T obj);

    /**
     * De-Serializes an object from a json string.
     */
    <T extends IJsonSerialization> T fromJson(String json, Class<T> classType);
}
