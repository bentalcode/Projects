package json.core;

import json.interfaces.IJsonReader;
import java.util.Collection;

/**
 * The JsonReader class implements a json reader.
 */
public final class JsonReader implements IJsonReader {
    private final IJsonObject jsonObject;

    /**
     * The JsonReader constructor.
     */
    public JsonReader(IJsonObject jsonObject) {
        this.jsonObject = jsonObject;
    }

    /**
     * Reads a boolean.
     */
    @Override
    public boolean readBoolean(String name) {
        return this.jsonObject.getBooleanProperty(name);
    }

    /**
     * Reads a byte.
     */
    @Override
    public byte readByte(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a short.
     */
    @Override
    public short readShort(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads an integer.
     */
    @Override
    public int readInteger(String name) {
        return this.jsonObject.getIntegerProperty(name);
    }

    /**
     * Reads a long.
     */
    @Override
    public long readLong(String name) {
        return this.jsonObject.getLongProperty(name);
    }

    /**
     * Reads a float.
     */
    @Override
    public float readFloat(String name) {
        return this.jsonObject.getFloatProperty(name);
    }

    /**
     * Reads a double.
     */
    @Override
    public double readDouble(String name) {
        return this.jsonObject.getDoubleProperty(name);
    }

    /**
     * Reads a character.
     */
    @Override
    public char readCharacter(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a string.
     */
    @Override
    public String readString(String name) {
        return this.jsonObject.getStringProperty(name);
    }

    /**
     * Reads a boolean array.
     */
    @Override
    public boolean[] readBooleanArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a byte array.
     */
    @Override
    public byte[] readByteArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a short array.
     */
    @Override
    public short[] readShortArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads an integer array.
     */
    @Override
    public int[] readIntegerArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a float array.
     */
    @Override
    public float[] readFloatArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a double array.
     */
    @Override
    public double[] readDoubleArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a character array.
     */
    @Override
    public char[] readCharacterArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a string array.
     */
    @Override
    public String[] readStringArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic.
     */
    @Override
    public <T> void readGeneric(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic array.
     */
    @Override
    public <T> T[] readArray(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic collection.
     */
    @Override
    public <T> Collection<T> readCollection(String name) {
        throw new UnsupportedOperationException();
    }
}
