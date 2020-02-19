package json.core;

/**
 * The JsonStringValue class implements a json value of a string.
 */
public final class JsonStringValue extends AbstractJsonValue {
    private final String value;

    /**
     * The JsonStringValue constructor.
     */
    public JsonStringValue(String value) {
        this.value = value;
    }

    /**
     * Gets a string value.
     */
    public String getStringValue() {
        return this.value;
    }
}
