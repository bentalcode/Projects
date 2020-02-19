package base.interfaces;

/**
 * The IJsonStream interface defines a json stream.
 */
public interface IJsonStream {
    /**
     * Serializes an object to a json string.
     */
    <T> String toJson(T obj);

    /**
     * De-Serializes an object from a json string.
     */
    <T> T fromJson(String json, Class<T> classType);
}
