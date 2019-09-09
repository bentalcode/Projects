package json.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import json.interfaces.ITypes;

/**
 * The Types class implements properties of a type.
 */
public final class Types implements ITypes {
    private static final String BooleanProperty = "boolean";
    private static final String ShortProperty = "short";
    private static final String IntegerProperty = "integer";
    private static final String LongProperty = "long";
    private static final String FloatProperty = "float";
    private static final String DoubleProperty = "double";
    private static final String StringProperty = "string";

    private static final String BooleanArrayProperty = "booleanArray";
    private static final String ShortArrayProperty = "shortArray";
    private static final String IntegerArrayProperty = "integerArray";
    private static final String LongArrayProperty = "longArray";
    private static final String FloatArrayProperty = "floatArray";
    private static final String DoubleArrayProperty = "doubleArray";
    private static final String StringArrayProperty = "stringArray";
    private static final String BlobProperty = "blob";

    private final boolean booleanValue;
    private final short shortValue;
    private final int integerValue;
    private final long longValue;
    private final float floatValue;
    private final double doubleValue;
    private final String stringValue;

    private final boolean[] booleanArray;
    private final short[] shortArray;
    private final int[] integerArray;
    private final long[] longArray;
    private final float[] floatArray;
    private final double[] doubleArray;
    private final String[] stringArray;
    private final byte[] blob;
    private final IBinaryComparator<ITypes> comparator;
    private final int hashCode;

    /**
     * The Color constructor.
     */
    public Types(
        boolean booleanValue,
        short shortValue,
        int integerValue,
        long longValue,
        float floatValue,
        double doubleValue,
        String stringValue,
        boolean[] booleanArray,
        short[] shortArray,
        int[] integerArray,
        long[] longArray,
        float[] floatArray,
        double[] doubleArray,
        String[] stringArray,
        byte[] blob) {

        this(
            booleanValue,
            shortValue,
            integerValue,
            longValue,
            floatValue,
            doubleValue,
            stringValue,
            booleanArray,
            shortArray,
            integerArray,
            longArray,
            floatArray,
            doubleArray,
            stringArray,
            blob,
            Types.DefaultComparator());
    }
    /**
     * The Color constructor.
     */
    public Types(
        boolean booleanValue,
        short shortValue,
        int integerValue,
        long longValue,
        float floatValue,
        double doubleValue,
        String stringValue,
        boolean[] booleanArray,
        short[] shortArray,
        int[] integerArray,
        long[] longArray,
        float[] floatArray,
        double[] doubleArray,
        String[] stringArray,
        byte[] blob,
        IBinaryComparator<ITypes> comparator) {

        this.booleanValue = booleanValue;
        this.shortValue = shortValue;
        this.integerValue = integerValue;
        this.longValue = longValue;
        this.floatValue = floatValue;
        this.doubleValue = doubleValue;
        this.stringValue = stringValue;
        this.booleanArray = booleanArray;
        this.shortArray = shortArray;
        this.integerArray = integerArray;
        this.longArray = longArray;
        this.floatArray = floatArray;
        this.doubleArray = doubleArray;
        this.stringArray = stringArray;
        this.blob = blob;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets a boolean value.
     */
    @Override
    public boolean getBooleanValue() {
        return this.booleanValue;
    }

    /**
     * Gets a short value.
     */
    @Override
    public short getShortValue() {
        return this.shortValue;
    }

    /**
     * Gets an integer value.
     */
    @Override
    public int getIntegerValue() {
        return this.integerValue;
    }

    /**
     * Gets a long value.
     */
    @Override
    public long getLongValue() {
        return this.longValue;
    }

    /**
     * Gets a float value.
     */
    @Override
    public float getFloatValue() {
        return this.floatValue;
    }

    /**
     * Gets a double value.
     */
    @Override
    public double getDoubleValue() {
        return this.doubleValue;
    }

    /**
     * Gets a string value.
     */
    @Override
    public String getStringValue() {
        return this.stringValue;
    }

    /**
     * Gets a boolean array.
     */
    @Override
    public boolean[] getBooleanArray() {
        return this.booleanArray;
    }

    /**
     * Gets a short array.
     */
    @Override
    public short[] getShortArray() {
        return this.shortArray;
    }

    /**
     * Gets an integer array.
     */
    @Override
    public int[] getIntegerArray() {
        return this.integerArray;
    }

    /**
     * Gets a long array.
     */
    @Override
    public long[] getLongArray() {
        return this.longArray;
    }

    /**
     * Gets a float array.
     */
    @Override
    public float[] getFloatArray() {
        return this.floatArray;
    }

    /**
     * Gets a double array.
     */
    @Override
    public double[] getDoubleArray() {
        return this.doubleArray;
    }

    /**
     * Gets a string array.
     */
    @Override
    public String[] getStringArray() {
        return this.stringArray;
    }

    /**
     * Gets a blob.
     */
    @Override
    public byte[] getBlob() {
        return this.blob;
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeBooleanProperty(Types.BooleanProperty, this.getBooleanValue());
        writer.writeShortProperty(Types.ShortProperty, this.getShortValue());
        writer.writeIntegerProperty(Types.IntegerProperty, this.getIntegerValue());
        writer.writeLongProperty(Types.LongProperty, this.getLongValue());
        writer.writeFloatProperty(Types.FloatProperty, this.getFloatValue());
        writer.writeDoubleProperty(Types.DoubleProperty, this.getDoubleValue());
        writer.writeStringProperty(Types.StringProperty, this.getStringValue());

        writer.writeBooleanArrayProperty(Types.BooleanArrayProperty, this.getBooleanArray());
        writer.writeShortArrayProperty(Types.ShortArrayProperty, this.getShortArray());
        writer.writeIntegerArrayProperty(Types.IntegerArrayProperty, this.getIntegerArray());
        writer.writeLongArrayProperty(Types.LongArrayProperty, this.getLongArray());
        writer.writeFloatArrayProperty(Types.FloatArrayProperty, this.getFloatArray());
        writer.writeDoubleArrayProperty(Types.DoubleArrayProperty, this.getDoubleArray());
        writer.writeStringArrayProperty(Types.StringArrayProperty, this.getStringArray());
        writer.writeBlobProperty(Types.BlobProperty, this.getBlob());
    }

    /**
     * Reads a json.
     */
    public static Types readJson(IJsonObjectReader reader) {
        boolean booleanValue = reader.readBooleanProperty(Types.BooleanProperty);
        short shortValue = reader.readShortProperty(Types.ShortProperty);
        int integerValue = reader.readIntegerProperty(Types.IntegerProperty);
        long longValue = reader.readLongProperty(Types.LongProperty);
        float floatValue = reader.readFloatProperty(Types.FloatProperty);
        double doubleValue = reader.readDoubleProperty(Types.DoubleProperty);
        String stringValue = reader.readStringProperty(Types.StringProperty);

        boolean[] booleanArray = reader.readBooleanArrayProperty(Types.BooleanArrayProperty);
        short[] shortArray = reader.readShortArrayProperty(Types.ShortArrayProperty);
        int[] integerArray = reader.readIntegerArrayProperty(Types.IntegerArrayProperty);
        long[] longArray = reader.readLongArrayProperty(Types.LongArrayProperty);
        float[] floatArray = reader.readFloatArrayProperty(Types.FloatArrayProperty);
        double[] doubleArray = reader.readDoubleArrayProperty(Types.DoubleArrayProperty);
        String[] stringArray = reader.readStringArrayProperty(Types.StringArrayProperty);
        byte[] blob = reader.readBlobProperty(Types.BlobProperty);

        return new Types(
            booleanValue,
            shortValue,
            integerValue,
            longValue,
            floatValue,
            doubleValue,
            stringValue,
            booleanArray,
            shortArray,
            integerArray,
            longArray,
            floatArray,
            doubleArray,
            stringArray,
            blob);
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return hashCode;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(ITypes other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(ITypes other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ITypes> DefaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a fruit.
     */
    public static final class Comparator extends AbstractBinaryComparator<ITypes> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITypes obj) {
            return new HashCodeBuilder(3, 5)
                .withBoolean(obj.getBooleanValue())
                .withShort(obj.getShortValue())
                .withInteger(obj.getIntegerValue())
                .withLong(obj.getLongValue())
                .withFloat(obj.getFloatValue())
                .withDouble(obj.getDoubleValue())
                .withString(obj.getStringValue())
                .withBooleanArray(obj.getBooleanArray())
                .withShortArray(obj.getShortArray())
                .withIntegerArray(obj.getIntegerArray())
                .withLongArray(obj.getLongArray())
                .withFloatArray(obj.getFloatArray())
                .withDoubleArray(obj.getDoubleArray())
                .withStringArray(obj.getStringArray())
                .withByteArray(obj.getBlob())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ITypes lhs, ITypes rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withBoolean(lhs.getBooleanValue(), rhs.getBooleanValue())
                .withShort(lhs.getShortValue(), rhs.getShortValue())
                .withInteger(lhs.getIntegerValue(), rhs.getIntegerValue())
                .withLong(lhs.getLongValue(), rhs.getLongValue())
                .withFloat(lhs.getFloatValue(), rhs.getFloatValue())
                .withDouble(lhs.getDoubleValue(), rhs.getDoubleValue())
                .withString(lhs.getStringValue(), rhs.getStringValue())
                .withBooleanArray(lhs.getBooleanArray(), rhs.getBooleanArray())
                .withShortArray(lhs.getShortArray(), rhs.getShortArray())
                .withIntegerArray(lhs.getIntegerArray(), rhs.getIntegerArray())
                .withLongArray(lhs.getLongArray(), rhs.getLongArray())
                .withFloatArray(lhs.getFloatArray(), rhs.getFloatArray())
                .withDoubleArray(lhs.getDoubleArray(), rhs.getDoubleArray())
                .withStringArray(lhs.getStringArray(), rhs.getStringArray())
                .withByteArray(lhs.getBlob(), rhs.getBlob())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(ITypes lhs, ITypes rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withBoolean(lhs.getBooleanValue(), rhs.getBooleanValue())
                .withShort(lhs.getShortValue(), rhs.getShortValue())
                .withInteger(lhs.getShortValue(), rhs.getIntegerValue())
                .withLong(lhs.getLongValue(), rhs.getLongValue())
                .withFloat(lhs.getFloatValue(), rhs.getFloatValue())
                .withDouble(lhs.getDoubleValue(), rhs.getDoubleValue())
                .withString(lhs.getStringValue(), rhs.getStringValue())
                .withBooleanArray(lhs.getBooleanArray(), rhs.getBooleanArray())
                .withShortArray(lhs.getShortArray(), rhs.getShortArray())
                .withIntegerArray(lhs.getIntegerArray(), rhs.getIntegerArray())
                .withLongArray(lhs.getLongArray(), rhs.getLongArray())
                .withFloatArray(lhs.getFloatArray(), rhs.getFloatArray())
                .withDoubleArray(lhs.getDoubleArray(), rhs.getDoubleArray())
                .withStringArray(lhs.getStringArray(), rhs.getStringArray())
                .withByteArray(lhs.getBlob(), rhs.getBlob())
                .build();
        }
    }

}
