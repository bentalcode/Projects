package json.core;

import base.core.Conditions;
import json.interfaces.IJsonSerialization;
import json.interfaces.IJsonStream;

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

        String json = obj.toJson();

        return json;
    }

    /**
     * De-Serializes an object from a json string.
     */
    public <T extends IJsonSerialization> T fromJson(String json, Class<T> classType) {
        Conditions.validateNotNull(
            json,
            "The json string for deserializing an object.");

        Conditions.validateNotNull(
            classType,
            "The class type of an object.");

        return null;
    }
}
