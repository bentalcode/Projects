package json.core;

/**
 * The BooleanValue class implements a json value of type boolean.
 */
public final class BooleanValue implements IBooleanValue {
    private final boolean value;

    /**
     * The BooleanValue constructor.
     */
    public BooleanValue(boolean value) {
        this.value = value;
    }
}
