package json.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import java.io.IOException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsonGenerator class implements a generator for json.
 */
public final class JsonGenerator implements IJsonGenerator, ICloseable {
    private final com.fasterxml.jackson.core.JsonGenerator generator;

    private final DestructorHandler destructorHandler = new DestructorHandler();
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonGenerator constructor.
     */
    public JsonGenerator(com.fasterxml.jackson.core.JsonGenerator generator) {
        Conditions.validateNotNull(
            generator,
            "The Jackson json generator.");

        this.generator = generator;
    }

    /**
     * Closes the generator.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Closes the generator.
     */
    @Override
    public void flush() {
        try {
            this.generator.flush();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json generator failed flushing the written content" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a start object.
     */
    @Override
    public void writeStartObject() {
        try {
            this.generator.writeStartObject();
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a start object" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes an end object.
     */
    @Override
    public void writeEndObject() {
        try {
            this.generator.writeEndObject();
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing an end object" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a start array.
     */
    @Override
    public void writeStartArray() {
        try {
            this.generator.writeStartArray();
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a start array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes an end array.
     */
    @Override
    public void writeEndArray() {
        try {
            this.generator.writeEndArray();
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing an end array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a property name.
     */
    @Override
    public void writePropertyName(String name) {
        try {
            this.generator.writeFieldName(name);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a property name: " + name +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a boolean.
     */
    @Override
    public void writeBoolean(boolean value) {
        try {
            this.generator.writeBoolean(value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a boolean: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a byte.
     */
    @Override
    public void writeByte(byte value) {
        try {
            short shortValue = value;
            this.generator.writeNumber(shortValue);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a byte: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a short.
     */
    @Override
    public void writeShort(short value) {
        try {
            this.generator.writeNumber(value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a short: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes an integer.
     */
    @Override
    public void writeInteger(int value) {
        try {
            this.generator.writeNumber(value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing an integer: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a long value.
     */
    @Override
    public void writeLong(long value) {
        try {
            this.generator.writeNumber(value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a long: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a float.
     */
    @Override
    public void writeFloat(float value) {
        try {
            this.generator.writeNumber(value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a float: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a double.
     */
    @Override
    public void writeDouble(double value) {
        try {
            this.generator.writeNumber(value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a double: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a character.
     */
    @Override
    public void writeCharacter(char value) {
        try {
            String valueToWrite = String.valueOf(value);
            this.generator.writeString(valueToWrite);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a character: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a string.
     */
    @Override
    public void writeString(String value) {
        try {
            this.generator.writeString(value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a string: " + value +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a boolean array.
     */
    @Override
    public void writeBooleanArray(boolean[] array) {
        try {
            for (boolean value : array) {
                this.generator.writeBoolean(value);
            }
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a boolean array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
        }
    }

    /**
     * Writes a byte array.
     */
    @Override
    public void writeByteArray(byte[] array) {
        try {
            this.generator.writeBinary(array);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a byte array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
        }
    }

    /**
     * Writes a short array.
     */
    @Override
    public void writeShortArray(short[] array) {
        try {
            for (short value : array) {
                this.generator.writeNumber(value);
            }
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a short array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
        }
    }

    /**
     * Writes an integer array.
     */
    @Override
    public void writeIntegerArray(int[] array) {
        try {
            this.generator.writeArray(array, 0, array.length);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing an integer array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a long array.
     */
    @Override
    public void writeLongArray(long[] array) {
        try {
            this.generator.writeArray(array, 0, array.length);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a long array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a float array.
     */
    @Override
    public void writeFloatArray(float[] array) {
        try {
            for (float value : array) {
                this.generator.writeNumber(value);
            }
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a float array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a double array.
     */
    @Override
    public void writeDoubleArray(double[] array) {
        try {
            this.generator.writeArray(array, 0, array.length);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a double array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a character array.
     */
    @Override
    public void writeCharacterArray(char[] array) {
        try {
            this.generator.writeRaw(array, 0, array.length);
        }
        catch (IOException e) {
            String errorMessage =
               "The JsonGenerator failed writing a character array" +
               ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
        }
    }

    /**
     * Writes a string array.
     */
    @Override
    public void writeStringArray(String[] array) {
        try {
            for (String value : array) {
                this.generator.writeString(value);
            }
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a string array" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
        }
    }
}
