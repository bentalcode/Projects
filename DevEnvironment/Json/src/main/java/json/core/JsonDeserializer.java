package json.core;

import base.core.Conditions;
import com.jsoniter.JsonIterator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.util.Collection;

/**
 * The IJsonDeserializer class implements a json deserializer.
 */
public final class JsonDeserializer implements IJsonDeserializer{
    private final JsonIterator iterator;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonDeserializer constructor.
     */
    public JsonDeserializer(JsonIterator iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of json.");

        this.iterator = iterator;
    }

    /**
     * Reads a boolean.
     */
    @Override
    public boolean readBoolean() {
        boolean result;

        try {
            result = this.iterator.readBoolean();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Deserializer failed to read a boolean due to the following error: " +
                e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage);
        }
        return result;
    }

    /**
     * Reads a byte.
     */
    @Override
    public byte readByte() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a short.
     */
    @Override
    public short readShort() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads an integer.
     */
    @Override
    public int readInteger() {
        int result;

        try {
            result = this.iterator.readInt();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Deserializer failed to read an integer due to the following error: " +
                e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
        return result;
    }

    /**
     * Reads a long.
     */
    @Override
    public long readLong() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a float.
     */
    @Override
    public float readFloat() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a double.
     */
    @Override
    public double readDouble() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a character.
     */
    @Override
    public char readCharacter() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a string.
     */
    @Override
    public String readString() {
        String result;

        try {
            result = this.iterator.readString();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Deserializer failed to read a string due to the following error: " +
                e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
        return result;
    }

    /**
     * Reads a boolean array.
     */
    @Override
    public boolean[] readBooleanArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a byte array.
     */
    @Override
    public byte[] readByteArray(byte[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a short array.
     */
    @Override
    public short[] readShortArray(short[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads an integer array.
     */
    @Override
    public int[] readIntegerArray(int[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a float array.
     */
    @Override
    public float[] readFloatArray(float[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a double array.
     */
    @Override
    public double[] readDoubleArray(double[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a character array.
     */
    @Override
    public char[] readCharacterArray(char[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a string array.
     */
    @Override
    public String[] readStringArray(String[] value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic.
     */
    @Override
    public <T> void readGeneric(T value) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic array.
     */
    @Override
    public <T> T[] readArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic collection.
     */
    public <T> Collection<T> readCollection() {
        throw new UnsupportedOperationException();
    }
}
