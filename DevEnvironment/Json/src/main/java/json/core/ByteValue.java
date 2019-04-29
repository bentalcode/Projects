package json.core;

/**
 * The ByteValue class implements a json value of type byte.
 */
public final class ByteValue implements IByteValue {
    private final byte value;

    /**
     * The ByteValue constructor.
     */
    public ByteValue(byte value) {
        this.value = value;
    }
}
