package json.core;

/**
 * The JsonIntegerValue class implements a json value of an integer.
 */
public final class JsonIntegerValue implements IJsonIntegerValue {
    private final long value;

    /**
     * The JsonIntegerValue constructor.
     */
    public JsonIntegerValue(long value) {
        this.value = value;
    }

    /**
     * Gets a value.
     */
    public long getValue() {
        return this.value;
    }
}
