package json.core;

/**
 * The FloatValue class implements a json value of type float.
 */
public final class FloatValue implements ILongValue {
    private final double value;

    /**
     * The FloatValue constructor.
     */
    public FloatValue(float value) {
        this.value = value;
    }
}
