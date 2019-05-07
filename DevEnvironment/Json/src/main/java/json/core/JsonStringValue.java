package json.core;

/**
 * The JsonStringValue class implements a json value of a string.
 */
public final class JsonStringValue implements IJsonStringValue {
    private final String value;

    /**
     * The JsonStringValue constructor.
     */
    public JsonStringValue(String value) {
        this.value = value;
    }

    /**
     * Gets a value.
     */
    public String getValue() {
        return this.value;
    }
}
