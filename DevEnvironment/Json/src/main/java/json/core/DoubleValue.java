package json.core;

/**
 * The DoubleValue class implements a json value of type double.
 */
public final class DoubleValue implements IDoubleValue {
    private final double value;

    /**
     * The DoubleValue constructor.
     */
    public DoubleValue(double value) {
        this.value = value;
    }
}
