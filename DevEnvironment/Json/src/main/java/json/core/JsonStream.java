package json.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Readers;
import base.core.ReflectionHandler;

import java.io.IOException;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import base.core.Writers;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonSerialization;
import json.interfaces.IJsonStream;

/**
 * The JsonStream class implements a json stream.
 */
public final class JsonStream implements IJsonStream {
    private final IJsonFactory factory = new JsonFactory();

    /**
     * The JsonStream constructor.
     */
    public JsonStream() {
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

            JsonWriter jsonWriter = new JsonWriter(this.factory, writer);
            destructorHandler.register(jsonWriter);

            jsonWriter.writeObject(obj);
            jsonWriter.flush();
            json = writer.toString();
        }

        return json;
    }

    /**
     * De-Serializes an object from a json string.
     */
    public <T extends IJsonSerialization> T fromJson(String json, Class<?> classType) {
        Conditions.validateNotNull(
            json,
            "The json string for de-serializing an object.");

        Conditions.validateNotNull(
            classType,
            "The class type of an object.");

        T instance;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {

            Reader reader = Readers.createStringReader(json);
            destructorHandler.register(reader);

            JsonParser parser = new JsonParser(this.factory, reader);
            destructorHandler.register(parser);

            IJsonTree tree = parser.parse();

            IJsonObjectReader objectReader = new JsonObjectReader(tree.getRootObject());

            ReflectionHandler reflectionHandler = new ReflectionHandler();
            instance = reflectionHandler.invoke(classType, "readJson", IJsonObjectReader.class, objectReader);
        }

        return instance;
    }
}
