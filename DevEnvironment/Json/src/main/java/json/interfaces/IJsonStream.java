package json.interfaces;

/**
 * The IJsonStream interface defines a json stream.
 */
public interface IJsonStream {
    /**
     * Serializes an object to a json string.
     */
    <T extends IJsonSerialization> String toJson(T obj);

    /**
     * De-Serializes an object from a json string.
     */
    <T extends IJsonSerialization> T fromJson(String json, Class<T> classType);
}
