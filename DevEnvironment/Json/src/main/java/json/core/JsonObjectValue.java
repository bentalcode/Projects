package json.core;

/**
 * The JsonObjectValue class implements a json value of an object.
 */
public final class JsonObjectValue implements IJsonObjectValue {
    private final IJsonObject value;

    /**
     * The JsonObjectValue constructor.
     */
    public JsonObjectValue(IJsonObject value) {
        this.value = value;
    }

    /**
     * Gets a value.
     */
    public IJsonObject getValue() {
        return this.value;
    }
}
