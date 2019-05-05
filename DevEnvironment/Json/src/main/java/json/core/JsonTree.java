package json.core;

import base.core.Conditions;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

/**
 * The JsonTree class implements a json tree.
 */
public final class JsonTree implements IJsonTree {
    private final IJsonObject rootObject;

    /**
     * The JsonTree constructor.
     */
    public JsonTree() {
        this(new JSONObject());
    }

    /**
     * The JsonTree constructor.
     */
    public JsonTree(JSONObject rootObject) {
        Conditions.validateNotNull(
            rootObject,
            "The root object.");

        this.rootObject = this.createObject(rootObject);
    }

    /**
     * Gets the root object.
     */
    @Override
    public IJsonObject getRoot() {
        return this.rootObject;
    }

    /**
     * Creates a new json object.
     */
    public IJsonObject createObject(JSONObject object) {
        return new JsonObject(object);
    }

    /**
     * Creates a new json array.
     */
    public IJsonArray createArray(JSONArray array) {
        return new JsonArray(array);
    }

    /**
     * Gets the string representation of the json object.
     */
    @Override
    public String toString() {
        return this.rootObject.toString();
    }
}
