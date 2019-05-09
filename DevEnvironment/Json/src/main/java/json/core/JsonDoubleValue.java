package json.core;

/**
 * The JsonDoubleValue class implements a json value of a double.
 */
public final class JsonDoubleValue extends AbstractJsonValue {
    private final double value;

    /**
     * The JsonDoubleValue constructor.
     */
    public JsonDoubleValue(double value) {
        this.value = value;
    }

    /**
     * Gets a double value.
     */
    public double getDoubleValue() {
        return this.value;
    }
}
