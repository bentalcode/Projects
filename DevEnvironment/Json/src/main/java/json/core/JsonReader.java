package json.core;

import base.core.Conditions;
import base.core.Conversion;
import json.interfaces.IJsonReader;
import java.util.Collection;

/**
 * The JsonReader class implements a json reader.
 */
public final class JsonReader implements IJsonReader {
    private final IJsonTree jsonTree;
    private final IJsonObject jsonRoot;

    /**
     * The JsonReader constructor.
     */
    public JsonReader(IJsonTree jsonTree) {
        Conditions.validateNotNull(
            jsonTree,
            "The json tree.");

        this.jsonTree = jsonTree;
        this.jsonRoot = this.jsonTree.getRoot();
    }

    /**
     * Reads a boolean property.
     */
    @Override
    public boolean readBooleanProperty(String name) {
        return this.jsonRoot.readBooleanProperty(name);
    }

    /**
     * Reads a byte property.
     */
    @Override
    public byte readByteProperty(String name) {
        int value = this.jsonRoot.readIntegerProperty(name);

        byte result = Conversion.longConversion().toByte(value);

        return result;
    }

    /**
     * Reads a short property.
     */
    @Override
    public short readShortProperty(String name) {
        int value = this.jsonRoot.readIntegerProperty(name);

        short result = Conversion.longConversion().toShort(value);

        return result;
    }

    /**
     * Reads an integer property.
     */
    @Override
    public int readIntegerProperty(String name) {
        int result = this.jsonRoot.readIntegerProperty(name);

        return result;
    }

    /**
     * Reads a long property.
     */
    @Override
    public long readLongProperty(String name) {
        long result = this.jsonRoot.readLongProperty(name);

        return result;
    }

    /**
     * Reads a float property.
     */
    @Override
    public float readFloatProperty(String name) {
        float result = this.jsonRoot.readFloatProperty(name);

        return result;
    }

    /**
     * Reads a double property.
     */
    @Override
    public double readDoubleProperty(String name) {
        double result = this.jsonRoot.readDoubleProperty(name);

        return result;
    }

    /**
     * Reads a character property.
     */
    @Override
    public char readCharacterProperty(String name) {
        String value = this.jsonRoot.readStringProperty(name);

        char result = Conversion.stringConversion().toCharacter(value);

        return result;
    }

    /**
     * Reads a string property.
     */
    @Override
    public String readStringProperty(String name) {
        String result = this.jsonRoot.readStringProperty(name);

        return result;
    }

    /**
     * Reads a boolean array property.
     */
    @Override
    public boolean[] readBooleanArrayProperty(String name) {
        IJsonArray<Boolean> array = this.jsonRoot.readArrayProperty(name);

        int size = array.size();
        boolean[] result = new boolean[size];

        for (int i = 0; i < size; ++i) {
            result[i] = array.get(i);
        }

        return result;
    }

    /**
     * Reads a byte array property.
     */
    @Override
    public byte[] readByteArrayProperty(String name) {
        IJsonArray<Byte> array = this.jsonRoot.readArrayProperty(name);

        int size = array.size();
        byte[] result = new byte[size];

        for (int i = 0; i < size; ++i) {
            result[i] = array.get(i);
        }

        return result;
    }

    /**
     * Reads a short array property.
     */
    @Override
    public short[] readShortArrayProperty(String name) {
        IJsonArray<Short> array = this.jsonRoot.readArrayProperty(name);

        int size = array.size();
        short[] result = new short[size];

        for (int i = 0; i < size; ++i) {
            result[i] = array.get(i);
        }

        return result;
    }

    /**
     * Reads an integer array property.
     */
    @Override
    public int[] readIntegerArrayProperty(String name) {
        IJsonArray<Integer> array = this.jsonRoot.readArrayProperty(name);

        int size = array.size();
        int[] result = new int[size];

        for (int i = 0; i < size; ++i) {
            result[i] = array.get(i);
        }

        return result;
    }

    /**
     * Reads a float array property.
     */
    @Override
    public float[] readFloatArrayProperty(String name) {
        IJsonArray<Float> array = this.jsonRoot.readArrayProperty(name);

        int size = array.size();
        float[] result = new float[size];

        for (int i = 0; i < size; ++i) {
            result[i] = array.get(i);
        }

        return result;
    }

    /**
     * Reads a double array property.
     */
    @Override
    public double[] readDoubleArrayProperty(String name) {
        IJsonArray<Double> array = this.jsonRoot.readArrayProperty(name);

        int size = array.size();
        double[] result = new double[size];

        for (int i = 0; i < size; ++i) {
            result[i] = array.get(i);
        }

        return result;
    }

    /**
     * Reads a character array property.
     */
    @Override
    public char[] readCharacterArrayProperty(String name) {
        IJsonArray<Character> array = this.jsonRoot.readArrayProperty(name);

        int size = array.size();
        char[] result = new char[size];

        for (int i = 0; i < size; ++i) {
            result[i] = array.get(i);
        }

        return result;
    }

    /**
     * Reads a string array property.
     */
    @Override
    public String[] readStringArrayProperty(String name) {
        IJsonArray<String> array = this.jsonRoot.readArrayProperty(name);

        int size = array.size();
        String[] result = new String[size];

        for (int i = 0; i < size; ++i) {
            result[i] = array.get(i);
        }

        return result;
    }

    /**
     * Reads a generic property.
     */
    @Override
    public void readGenericProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic array property.
     */
    @Override
    public <T> T[] readArrayProperty(String name) {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic collection property.
     */
    @Override
    public <T> Collection<T> readCollectionProperty(String name) {
        throw new UnsupportedOperationException();
    }
}
