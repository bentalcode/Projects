package json.core;

/**
 * The JsonElement abstract base class implements a json element.
 */
public abstract class JsonElement implements IJsonElement {
    private final int id;

    /**
     * The JsonElement constructor.
     */
    protected JsonElement(int id) {
        this.id = id;
    }

    /**
     * Gets an identifier of a json element.
     */
    @Override
    public int getId() {
        return this.id;
    }
}
