package json.core;

/**
 * The LongValue class implements a json value of type long.
 */
public final class LongValue implements ILongValue {
    private final long value;

    /**
     * The LongValue constructor.
     */
    public LongValue(long value) {
        this.value = value;
    }
}
