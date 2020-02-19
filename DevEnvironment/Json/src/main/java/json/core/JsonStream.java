package json.core;

import base.BaseException;
import base.core.ClassTypes;
import base.core.Conditions;
import base.interfaces.IJsonStream;
import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.IOException;

/**
 * The JsonStream class implements a json stream.
 */
public final class JsonStream implements IJsonStream {
    /**
     * Serializes an object to a json string.
     */
    public static <T> String serialize(T obj) {
        IJsonStream stream = new JsonStream();
        return stream.toJson(obj);
    }

    /**
     * De-Serializes an object from a json string.
     */
    public static <T> T deserialize(String json, Class<T> classType) {
        IJsonStream stream = new JsonStream();
        return stream.fromJson(json, classType);
    }

    /**
     * The JsonStream constructor.
     */
    public JsonStream() {
    }

    /**
     * Serialize an object to a json.
     */
    @Override
    public <T> String toJson(T obj) {
        Conditions.validateNotNull(
            obj,
            "The object to stream.");

        ObjectMapper mapper = new ObjectMapper();

        String result;

        try {
            result = mapper.writeValueAsString(obj);
        }
        catch (IOException e) {
            String errorMessage =
                "Failed serializing to json"  +
                " object type: " + ClassTypes.getName(obj) +
                ", due to the following error: " + e.getMessage();

            throw new BaseException(errorMessage);
        }

        return result;
    }

    /**
     * Deserializes an object from a json.
     */
    @Override
    public <T> T fromJson(String json, Class<T> classType) {
        Conditions.validateNotNull(
            json,
            "The json to stream.");

        Conditions.validateNotNull(
            classType,
            "The class type of the json.");

        ObjectMapper mapper = new ObjectMapper();

        T result;

        try {
            result = mapper.readValue(
                json,
                classType);
        }
        catch (IOException e) {
            String errorMessage =
                "Failed de-serializing object from json: " + json +
                " of class: " + classType.getSimpleName() +
                ", due to the following error: " + e.getMessage();

            throw new BaseException(errorMessage);
        }

        return result;
    }
}
