package json.core;

/**
 * The ShortValue class implements a json value of type short.
 */
public final class ShortValue implements IShortValue {
    private final short value;

    /**
     * The ShortValue constructor.
     */
    public ShortValue(short value) {
        this.value = value;
    }
}
