package json.core;

/**
 * The IntegerValue class implements a json value of type integer.
 */
public final class IntegerValue implements IIntegerValue {
    private final int value;

    /**
     * The IntegerValue constructor.
     */
    public IntegerValue(int value) {
        this.value = value;
    }
}
