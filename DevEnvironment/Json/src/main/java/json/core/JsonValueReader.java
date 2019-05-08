package json.core;

import base.core.Arrays;
import base.core.Casting;
import base.core.Conditions;
import base.core.Conversion;
import base.core.ReflectionHandler;
import json.interfaces.IJsonObjectReader;
import java.util.ArrayList;
import java.util.List;
import json.interfaces.IJsonSerialization;

/**
 * The JsonValueReader class implements a reader of a json value.
 */
public final class JsonValueReader implements IJsonValueReader {
    private final IJsonValue jsonValue;

    /**
     * The JsonValueReader constructor.
     */
    public JsonValueReader(IJsonValue jsonValue) {
        Conditions.validateNotNull(
            jsonValue,
            "The json value to read from.");

        this.jsonValue = jsonValue;
    }
    
    /**
     * Reads a boolean.
     */
    @Override
    public boolean readBoolean() {
        IJsonBooleanValue value = Casting.cast(this.jsonValue);
        boolean result = value.getValue();
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
        long value = this.readLong();

        int result = Conversion.longConversion().toInteger(value);

        return result;
    }

    /**
     * Reads a long.
     */
    @Override
    public long readLong() {
        IJsonLongValue value = Casting.cast(this.jsonValue);

        long result = value.getValue();

        return result;
    }

    /**
     * Reads a float.
     */
    @Override
    public float readFloat() {
        double value = this.readDouble();
        float result = Conversion.doubleConversion().toFloat(value);

        return result;
    }

    /**
     * Reads a double.
     */
    @Override
    public double readDouble() {
        IJsonDoubleValue value = Casting.cast(this.jsonValue);

        double result = value.getValue();

        return result;
    }

    /**
     * Reads a string.
     */
    @Override
    public String readString() {
        IJsonStringValue value = Casting.cast(this.jsonValue);;

        String result = value.getValue();

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
    public byte[] readByteArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a short array.
     */
    @Override
    public short[] readShortArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads an integer array.
     */
    @Override
    public int[] readIntegerArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a float array.
     */
    @Override
    public float[] readFloatArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a double array.
     */
    @Override
    public double[] readDoubleArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a string array.
     */
    @Override
    public String[] readStringArray() {
        throw new UnsupportedOperationException();
    }

    /**
     * Reads a generic object.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType readObject(Class<ClassType> classType) {
        this.validateClassType(classType);

        IJsonObjectValue objectValue = Casting.cast(this.jsonValue);
        IJsonObjectReader reader = new JsonObjectReader(objectValue.getValue());

        ReflectionHandler reflectionHandler = new ReflectionHandler();
        ResultType result = reflectionHandler.invoke(classType, "readJson", IJsonObjectReader.class, reader);

        return result;
    }

    /**
     * Reads a generic array.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType[] readArray(Class<ClassType> classType) {
        this.validateClassType(classType);

        IJsonArray array = Casting.cast(this.jsonValue);
        int arraySize = array.size();

        ResultType[] result = Arrays.newInstance(classType, arraySize);

        for (int i = 0; i < arraySize; ++i) {
            IJsonValue currValue = array.get(i);

            IJsonValueReader currValueReader = new JsonValueReader(currValue);
            ResultType currItem = currValueReader.readObject(classType);

            result[i] = currItem;
        }

        return result;
    }

    /**
     * Reads a generic list.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> List<ResultType> readList(Class<ClassType> classType) {
        this.validateClassType(classType);

        IJsonArrayValue array = Casting.cast(this.jsonValue);

        List<ResultType> result = new ArrayList<>();

        for (IJsonValue currValue : array.getValue()) {
            IJsonValueReader currValueReader = new JsonValueReader(currValue);

            ResultType currItem = currValueReader.readObject(classType);

            result.add(currItem);
        }

        return result;
    }

    /**
     * Validates a class type.
     */
    private <T> void validateClassType(Class<T> classType) {
        Conditions.validateNotNull(
            classType,
            "The class type of an object to read from.");
    }
}
