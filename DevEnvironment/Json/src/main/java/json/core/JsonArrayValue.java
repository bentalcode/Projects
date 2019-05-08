package json.core;

/**
 * The JsonArrayValue class implements a json value of an array.
 */
public final class JsonArrayValue implements IJsonArrayValue {
    private final IJsonArray value;

    /**
     * The JsonArrayValue constructor.
     */
    public JsonArrayValue(IJsonArray value) {
        this.value = value;
    }

    /**
     * Gets a value.
     */
    public IJsonArray getValue() {
        return this.value;
    }
}
