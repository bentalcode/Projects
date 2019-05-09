package json.core;

import base.core.Conditions;
import json.interfaces.IJsonObjectWriter;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The JsonObjectWriter class implements a writer of a json object.
 */
public final class JsonObjectWriter implements IJsonObjectWriter {
    private final IJsonGenerator generator;

    /**
     * The JsonObjectWriter constructor.
     */
    public JsonObjectWriter(IJsonGenerator generator) {
        Conditions.validateNotNull(
            generator,
            "The json generator to write into.");

        this.generator = generator;
    }

    /**
     * Writes a boolean property.
     */
    @Override
    public void writeBooleanProperty(String name, boolean value) {
        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeBoolean(value);
    }

    /**
     * Writes a byte property.
     */
    @Override
    public void writeByteProperty(String name, byte value) {
        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeByte(value);
    }

    /**
     * Writes a short property.
     */
    @Override
    public void writeShortProperty(String name, short value) {
        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeShort(value);
    }

    /**
     * Writes an integer property.
     */
    @Override
    public void writeIntegerProperty(String name, int value) {
        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeInteger(value);
    }

    /**
     * Writes a long property.
     */
    @Override
    public void writeLongProperty(String name, long value) {
        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeLong(value);
    }

    /**
     * Writes a float property.
     */
    @Override
    public void writeFloatProperty(String name, float value) {
        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeFloat(value);
    }

    /**
     * Writes a double property.
     */
    @Override
    public void writeDoubleProperty(String name, double value) {
        this.validatePropertyName(name);

        this.generator.writePropertyName(name);
        this.generator.writeDouble(value);
    }

    /**
     * Writes a string property.
     */
    @Override
    public void writeStringProperty(String name, String value) {
        this.validatePropertyName(name);

        if (value == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeString(value);
    }

    /**
     * Writes a boolean array property.
     */
    @Override
    public void writeBooleanArrayProperty(String name, boolean[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeBooleanArray(array);
    }

    /**
     * Writes a byte array property.
     */
    @Override
    public void writeByteArrayProperty(String name, byte[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeByteArray(array);
    }

    /**
     * Writes a short array property.
     */
    @Override
    public void writeShortArrayProperty(String name, short[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeShortArray(array);
    }

    /**
     * Writes an integer array property.
     */
    @Override
    public void writeIntegerArrayProperty(String name, int[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeIntegerArray(array);
    }

    /**
     * Writes a long array property.
     */
    @Override
    public void writeLongArrayProperty(String name, long[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeLongArray(array);
    }

    /**
     * Writes a float array property.
     */
    @Override
    public void writeFloatArrayProperty(String name, float[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeFloatArray(array);
    }

    /**
     * Writes a double array property.
     */
    @Override
    public void writeDoubleArrayProperty(String name, double[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeDoubleArray(array);
    }

    /**
     * Writes a string array property.
     */
    @Override
    public void writeStringArrayProperty(String name, String[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);
        this.generator.writeStringArray(array);
    }

    /**
     * Writes a generic object property.
     */
    @Override
    public <T extends IJsonSerialization> void writeObjectProperty(String name, T object) {
        this.validatePropertyName(name);

        if (object == null) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);
        writer.writeObject(object);
    }

    /**
     * Writes a generic array property.
     */
    @Override
    public <T extends IJsonSerialization> void writeArrayProperty(String name, T[] array) {
        this.validatePropertyName(name);

        if (array == null) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);
        writer.writeArray(array);
    }

    /**
     * Writes a generic list property.
     */
    @Override
    public <T extends IJsonSerialization> void writeListProperty(String name, List<T> list) {
        this.validatePropertyName(name);

        if (list == null) {
            return;
        }

        this.generator.writePropertyName(name);

        IJsonValueWriter writer = new JsonValueWriter(this.generator);
        writer.writeList(list);
    }

    /**
     * Validates a name of a property.
     */
    private void validatePropertyName(String name) {
        Conditions.validateNotNull(
            name,
            "The name of a property.");
    }
}
