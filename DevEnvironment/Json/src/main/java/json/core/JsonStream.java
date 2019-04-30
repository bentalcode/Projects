package json.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Readers;
import base.core.ReflectionHandler;
import java.io.Reader;
import json.interfaces.IJsonReader;
import json.interfaces.IJsonSerialization;
import json.interfaces.IJsonStream;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsonStream class implements a json stream.
 */
public final class JsonStream implements IJsonStream {
    private final Logger log = LoggerFactory.getLogger(this.getClass());

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

        return "";
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

            IJsonObject rootObject = tree.getRoot();

            IJsonReader rootObjectReader = new JsonReader(rootObject);

            ReflectionHandler reflectionHandler = new ReflectionHandler();
            instance = reflectionHandler.invoke(classType, "readJson", IJsonReader.class, rootObjectReader);
        }

        return instance;
    }
}
