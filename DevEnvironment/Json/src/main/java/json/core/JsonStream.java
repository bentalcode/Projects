package json.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Readers;
import base.core.ReflectionHandler;
import java.io.Reader;
import json.interfaces.IJsonReader;
import json.interfaces.IJsonSerialization;
import json.interfaces.IJsonStream;
import json.interfaces.IJsonWriter;

/**
 * The JsonStream class implements a json stream.
 */
public final class JsonStream implements IJsonStream {
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

        IJsonTree tree = new JsonTree();
        IJsonWriter treeWriter = new JsonWriter(tree);

        obj.writeJson(treeWriter);

        return treeWriter.toString();
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
            Reader reader = Readers.createStringReader(json);
            destructorHandler.register(reader);

            IJsonParser parser = new JsonParser();
            IJsonTree tree = parser.parse(reader);

            IJsonReader treeReader = new JsonReader(tree);

            ReflectionHandler reflectionHandler = new ReflectionHandler();
            instance = reflectionHandler.invoke(classType, "readJson", IJsonReader.class, treeReader);
        }

        return instance;
    }
}
