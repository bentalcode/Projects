package json.core;

/**
 * The JsonTree class implements a json tree.
 */
public final class JsonTree implements IJsonTree {
    private static final int RootId = 0;

    private IJsonObject rootObject;
    private IJsonArray rootArray;
    private int id = RootId;

    /**
     * Creates a json tree from a root object.
     */
    public static IJsonTree createWithRootObject() {
        IJsonTree tree = new JsonTree(new JsonObject(RootId));
        return tree;
    }

    /**
     * Creates a json tree from a root array.
     */
    public static IJsonTree createWithRootArray() {
        IJsonTree tree = new JsonTree(new JsonArray(RootId));
        return tree;
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
