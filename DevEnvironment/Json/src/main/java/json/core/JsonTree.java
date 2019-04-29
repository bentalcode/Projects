package json.core;

/**
 * The JsonTree class implements a json tree.
 */
public final class JsonTree implements IJsonTree {
    private int id;

    /**
     * The JsonTree constructor.
     */
    public JsonTree() {
    }

    /**
     * Creates a new json object.
     */
    public IJsonObject createObject() {
        ++this.id;
        return new JsonObject(this.id);
    }

    /**
     * Creates a new json array.
     */
    public IJsonArray createArray() {
        ++this.id;
        return new JsonArray(this.id);
    }
}
