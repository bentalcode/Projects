package json.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Readers;
import java.io.Reader;
import java.io.StringWriter;
import base.core.Writers;
import json.interfaces.IJsonSerialization;
import json.interfaces.IJsonStream;

/**
 * The JsonObjectStream class implements a json stream for an object.
 */
public final class JsonObjectStream implements IJsonStream {
    private final IJsonFactory factory = new JsonFactory();

    /**
     * Serializes an object to a json string.
     */
    public static <T extends IJsonSerialization> String serialize(T obj) {
        IJsonStream stream = new JsonObjectStream();
        return stream.toJson(obj);
    }

    /**
     * De-Serializes an object from a json string.
     */
    public static <T extends IJsonSerialization> T deserialize(String json, Class<T> classType) {
        IJsonStream stream = new JsonObjectStream();
        return stream.fromJson(json, classType);
    }

    /**
     * The JsonObjectStream constructor.
     */
    public JsonObjectStream() {
    }

    /**
     * Serializes an object to a json string.
     */
    public <T extends IJsonSerialization> String toJson(T obj) {
        Conditions.validateNotNull(
            obj,
            "The object for serializing to a json string.");

        String json;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            StringWriter writer = Writers.createStringWriter();
            destructorHandler.register(writer);

            JsonGenerator generator = this.factory.createGenerator(writer);
            destructorHandler.register(generator);

            IJsonValueWriter valueWriter = new JsonValueWriter(generator);
            valueWriter.writeObject(obj);

            generator.flush();
            json = writer.toString();
        }

        return json;
    }

    /**
     * De-Serializes an object from a json string.
     */
    public <T extends IJsonSerialization> T fromJson(String json, Class<T> classType) {
        Conditions.validateNotNull(
            json,
            "The json string for de-serializing an object.");

        Conditions.validateNotNull(
            classType,
            "The class type of an object.");

        T instance;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {

            //
            // Create a reader to the json stream...
            //
            Reader reader = Readers.createStringReader(json);
            destructorHandler.register(reader);

            //
            // Parse the json stream into a json tree...
            //
            JsonParser parser = new JsonParser(this.factory, reader);
            destructorHandler.register(parser);

            IJsonTree tree = parser.parse();

            //
            // Read the corresponding object by using a reader...
            //
            IJsonValue value = new JsonObjectValue(tree.getRootObject());
            IJsonValueReader valueReader = new JsonValueReader(value);

            instance = valueReader.readObject(classType);
        }

        return instance;
    }
}
