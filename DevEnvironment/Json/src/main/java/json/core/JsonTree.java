package json.core;

/**
 * The JsonTree class implements a json tree.
 */
public final class JsonTree implements IJsonTree {
    private static final int ROOT_ID = 0;

    private final IJsonObject rootObject;
    private final IJsonArray rootArray;
    private int id = ROOT_ID;

    /**
     * Creates a json tree from a root object.
     */
    public static IJsonTree createWithRootObject() {
        return new JsonTree(new JsonObject(ROOT_ID));
    }

    /**
     * Creates a json tree from a root array.
     */
    public static IJsonTree createWithRootArray() {
        return new JsonTree(new JsonArray(ROOT_ID));
    }

    /**
     * The JsonTree constructor.
     */
    private JsonTree(IJsonObject rootObject) {
        this.rootObject = rootObject;
        this.rootArray = null;
    }

    /**
     * The JsonTree constructor.
     */
    private JsonTree(IJsonArray rootArray) {
        this.rootObject = null;
        this.rootArray = rootArray;
    }

    /**
     * Gets the root object.
     */
    @Override
    public IJsonObject getRootObject() {
        return this.rootObject;
    }

    /**
     * Gets the root array.
     */
    @Override
    public IJsonArray getRootArray() {
        return this.rootArray;
    }

    /**
     * Creates a new json object.
     */
    public IJsonObject createObject() {
        int currId = this.nextId();
        return new JsonObject(currId);
    }

    /**
     * Creates a new json array.
     */
    public IJsonArray createArray() {
        int currId = this.nextId();
        return new JsonArray(currId);
    }

    /**
     * Returns the next identifier of a json object.
     */
    private int nextId() {
        ++this.id;
        return this.id;
    }
}
