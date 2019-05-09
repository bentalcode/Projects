package json.core;

import base.core.Arrays;
import base.core.Casting;
import base.core.Conditions;
import base.core.Conversion;
import base.core.ReflectionHandler;
import json.interfaces.IJsonObjectReader;

import java.io.ObjectStreamException;
import java.util.ArrayList;
import java.util.List;
import json.interfaces.IJsonSerialization;

import javax.naming.OperationNotSupportedException;

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
        IJsonBooleanValue value = Casting.cast(this.jsonValue, IJsonBooleanValue.class);
        boolean result = value.getValue();
        return result;
    }

    /**
     * Reads a short.
     */
    @Override
    public short readShort() {
        long value = this.readLong();

        short result = Conversion.longConversion().toShort(value);

        return result;
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
        IJsonLongValue value = Casting.cast(this.jsonValue, IJsonLongValue.class);

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
        IJsonDoubleValue value = Casting.cast(this.jsonValue, IJsonDoubleValue.class);

        double result = value.getValue();

        return result;
    }

    /**
     * Reads a string.
     */
    @Override
    public String readString() {
        IJsonStringValue value = Casting.cast(this.jsonValue, IJsonStringValue.class);

        String result = value.getValue();

        return result;
    }

    /**
     * Reads a boolean array.
     */
    @Override
    public boolean[] readBooleanArray() {
        IJsonArrayValue value = Casting.cast(this.jsonValue, IJsonArrayValue.class);
        IJsonArray array = value.getValue();

        if (array.empty()) {
            return null;
        }

        boolean[] result = new boolean[array.size()];

        for (int i = 0; i < array.size(); ++i) {
            IJsonValueReader valueReader = new JsonValueReader(array.get(i));

            result[i] = valueReader.readBoolean();
        }

        return result;
    }

    /**
     * Reads a short array.
     */
    @Override
    public short[] readShortArray() {
        IJsonArrayValue value = Casting.cast(this.jsonValue, IJsonArrayValue.class);
        IJsonArray array = value.getValue();

        if (array.empty()) {
            return null;
        }

        short[] result = new short[array.size()];

        for (int i = 0; i < array.size(); ++i) {
            IJsonValueReader valueReader = new JsonValueReader(array.get(i));

            result[i] = valueReader.readShort();
        }

        return result;
    }

    /**
     * Reads an integer array.
     */
    @Override
    public int[] readIntegerArray() {
        IJsonArrayValue value = Casting.cast(this.jsonValue, IJsonArrayValue.class);
        IJsonArray array = value.getValue();

        if (array.empty()) {
            return null;
        }

        int[] result = new int[array.size()];

        for (int i = 0; i < array.size(); ++i) {
            IJsonValueReader valueReader = new JsonValueReader(array.get(i));

            result[i] = valueReader.readInteger();
        }

        return result;
    }

    /**
     * Reads a long array.
     */
    @Override
    public long[] readLongArray() {
        IJsonArrayValue value = Casting.cast(this.jsonValue, IJsonArrayValue.class);
        IJsonArray array = value.getValue();

        if (array.empty()) {
            return null;
        }

        long[] result = new long[array.size()];

        for (int i = 0; i < array.size(); ++i) {
            IJsonValueReader valueReader = new JsonValueReader(array.get(i));

            result[i] = valueReader.readLong();
        }

        return result;
    }

    /**
     * Reads a float array.
     */
    @Override
    public float[] readFloatArray() {
        IJsonArrayValue value = Casting.cast(this.jsonValue, IJsonArrayValue.class);
        IJsonArray array = value.getValue();

        if (array.empty()) {
            return null;
        }

        float[] result = new float[array.size()];

        for (int i = 0; i < array.size(); ++i) {
            IJsonValueReader valueReader = new JsonValueReader(array.get(i));

            result[i] = valueReader.readFloat();
        }

        return result;
    }

    /**
     * Reads a double array.
     */
    @Override
    public double[] readDoubleArray() {
        IJsonArrayValue value = Casting.cast(this.jsonValue, IJsonArrayValue.class);
        IJsonArray array = value.getValue();

        if (array.empty()) {
            return null;
        }

        double[] result = new double[array.size()];

        for (int i = 0; i < array.size(); ++i) {
            IJsonValueReader valueReader = new JsonValueReader(array.get(i));

            result[i] = valueReader.readDouble();
        }

        return result;
    }

    /**
     * Reads a string array.
     */
    @Override
    public String[] readStringArray() {
        IJsonArrayValue value = Casting.cast(this.jsonValue, IJsonArrayValue.class);
        IJsonArray array = value.getValue();

        if (array.empty()) {
            return null;
        }

        String[] result = new String[array.size()];

        for (int i = 0; i < array.size(); ++i) {
            IJsonValueReader valueReader = new JsonValueReader(array.get(i));

            result[i] = valueReader.readString();
        }

        return result;
    }

    /**
     * Reads a blob.
     */
    @Override
    public byte[] readBlob() {
        String value = this.readString();

        byte[] result = Conversion.stringConversion().toBytes(value);

        return result;
    }

    /**
     * Reads a generic object.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType readObject(Class<ClassType> classType) {
        this.validateClassType(classType);

        IJsonObjectValue objectValue = Casting.cast(this.jsonValue, IJsonObjectValue.class);
        IJsonObjectReader reader = new JsonObjectReader(objectValue.getValue());

        ReflectionHandler reflectionHandler = new ReflectionHandler();

        ResultType result = reflectionHandler.invoke(classType, "readJson", classType, IJsonObjectReader.class, reader);

        return result;
    }

    /**
     * Reads a generic array.
     */
    @Override
    public <ResultType extends IJsonSerialization, ClassType extends ResultType> ResultType[] readArray(Class<ClassType> classType) {
        this.validateClassType(classType);

        IJsonArray array = Casting.cast(this.jsonValue, IJsonArray.class);
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

        IJsonArrayValue array = Casting.cast(this.jsonValue, IJsonArrayValue.class);

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
