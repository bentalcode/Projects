package json.core;

/**
 * The JsonObjectValue class implements a json value of an object.
 */
public final class JsonObjectValue extends AbstractJsonValue {
    private final IJsonObject value;

    /**
     * The JsonObjectValue constructor.
     */
    public JsonObjectValue(IJsonObject value) {
        this.value = value;
    }

    /**
     * Gets an object.
     */
    public IJsonObject getObject() {
        return this.value;
    }
}
