package json.core;

import base.core.Conditions;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

/**
 * The JsonTree class implements a json tree.
 */
public final class JsonTree implements IJsonTree {
    private final IJsonObject rootObject;
    private int id;

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
        ++this.id;
        return new JsonObject(this.id, object);
    }

    /**
     * Creates a new json array.
     */
    public IJsonArray createArray(JSONArray array) {
        ++this.id;
        return new JsonArray(this.id, array);
    }
}
