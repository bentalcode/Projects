package json.interfaces;

/**
 * The IJsonSerialization interface defines a json serialization object.
 */
public interface IJsonSerialization {
    /**
     * Writes an object to a json writer.
     */
    void writeJson(IJsonObjectWriter writer);
}
