package json.core;

/**
 * The JsonDoubleValue class implements a json value of a double.
 */
public final class JsonDoubleValue implements IJsonDoubleValue {
    private final double value;

    /**
     * The JsonDoubleValue constructor.
     */
    public JsonDoubleValue(double value) {
        this.value = value;
    }

    /**
     * Gets a value.
     */
    public double getValue() {
        return this.value;
    }
}
