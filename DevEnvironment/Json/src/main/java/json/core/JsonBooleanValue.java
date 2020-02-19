package json.core;

/**
 * The JsonBooleanValue class implements a json value of a boolean.
 */
public final class JsonBooleanValue extends AbstractJsonValue {
    private final boolean value;

    /**
     * The JsonBooleanValue constructor.
     */
    public JsonBooleanValue(boolean value) {
        this.value = value;
    }

    /**
     * Gets a boolean value.
     */
    public boolean getBooleanValue() {
        return this.value;
    }
}
