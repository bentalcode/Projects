package json.core;

/**
 * The JsonLongValue class implements a json value of a long.
 */
public final class JsonLongValue extends AbstractJsonValue {
    private final long value;

    /**
     * The JsonLongValue constructor.
     */
    public JsonLongValue(long value) {
        this.value = value;
    }

    /**
     * Gets a long value.
     */
    public long getLongValue() {
        return this.value;
    }
}
