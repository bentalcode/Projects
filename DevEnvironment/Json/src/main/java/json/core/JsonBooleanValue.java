package json.core;

/**
 * The JsonBooleanValue class implements a json value of a boolean.
 */
public final class JsonBooleanValue implements IJsonBooleanValue {
    private final boolean value;

    /**
     * The JsonBooleanValue constructor.
     */
    public JsonBooleanValue(boolean value) {
        this.value = value;
    }

    /**
     * Gets a value.
     */
    public boolean getValue() {
        return this.value;
    }
}
