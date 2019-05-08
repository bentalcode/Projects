package json.core;

/**
 * The JsonLongValue class implements a json value of a long.
 */
public final class JsonLongValue implements IJsonLongValue {
    private final long value;

    /**
     * The JsonLongValue constructor.
     */
    public JsonLongValue(long value) {
        this.value = value;
    }

    /**
     * Gets a value.
     */
    public long getValue() {
        return this.value;
    }
}
