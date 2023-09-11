package json.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import json.interfaces.IPropertyType;

/**
 * The Types class implements various types of a property.
 */
public final class PropertyType implements IPropertyType {
    private static final String BOOLEAN_PROPERTY = "boolean";
    private static final String SHORT_PROPERTY = "short";
    private static final String INTEGER_PROPERTY = "integer";
    private static final String LONG_PROPERTY = "long";
    private static final String FLOAT_PROPERTY = "float";
    private static final String DOUBLE_PROPERTY = "double";
    private static final String STRING_PROPERTY = "string";

    private static final String BOOLEAN_ARRAY_PROPERTY = "booleanArray";
    private static final String SHORT_ARRAY_PROPERTY = "shortArray";
    private static final String INTEGER_ARRAY_PROPERTY = "integerArray";
    private static final String LONG_ARRAY_PROPERTY = "longArray";
    private static final String FLOAT_ARRAY_PROPERTY = "floatArray";
    private static final String DOUBLE_ARRAY_PROPERTY = "doubleArray";
    private static final String STRING_ARRAY_PROPERTY = "stringArray";
    private static final String BLOB_PROPERTY = "blob";

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
    private final IBinaryComparator<IPropertyType> comparator;
    private final int hashCode;

    /**
     * The PropertyType constructor.
     */
    public PropertyType(
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
            PropertyType.defaultComparator());
    }
    /**
     * The PropertyType constructor.
     */
    public PropertyType(
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
        IBinaryComparator<IPropertyType> comparator) {

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
     * Gets a boolean property.
     */
    @Override
    public boolean getBooleanProperty() {
        return this.booleanValue;
    }

    /**
     * Gets a short property.
     */
    @Override
    public short getShortProperty() {
        return this.shortValue;
    }

    /**
     * Gets an integer property.
     */
    @Override
    public int getIntegerProperty() {
        return this.integerValue;
    }

    /**
     * Gets a long property.
     */
    @Override
    public long getLongProperty() {
        return this.longValue;
    }

    /**
     * Gets a float property.
     */
    @Override
    public float getFloatProperty() {
        return this.floatValue;
    }

    /**
     * Gets a double property.
     */
    @Override
    public double getDoubleProperty() {
        return this.doubleValue;
    }

    /**
     * Gets a string property.
     */
    @Override
    public String getStringProperty() {
        return this.stringValue;
    }

    /**
     * Gets a boolean array.
     */
    @Override
    public boolean[] getBooleanArrayProperty() {
        return this.booleanArray;
    }

    /**
     * Gets a short array.
     */
    @Override
    public short[] getShortArrayProperty() {
        return this.shortArray;
    }

    /**
     * Gets an integer array.
     */
    @Override
    public int[] getIntegerArrayProperty() {
        return this.integerArray;
    }

    /**
     * Gets a long array.
     */
    @Override
    public long[] getLongArrayProperty() {
        return this.longArray;
    }

    /**
     * Gets a float array.
     */
    @Override
    public float[] getFloatArrayProperty() {
        return this.floatArray;
    }

    /**
     * Gets a double array.
     */
    @Override
    public double[] getDoubleArrayProperty() {
        return this.doubleArray;
    }

    /**
     * Gets a string array.
     */
    @Override
    public String[] getStringArrayProperty() {
        return this.stringArray;
    }

    /**
     * Gets a blob.
     */
    @Override
    public byte[] getBlobProperty() {
        return this.blob;
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeBooleanProperty(PropertyType.BOOLEAN_PROPERTY, this.getBooleanProperty());
        writer.writeShortProperty(PropertyType.SHORT_PROPERTY, this.getShortProperty());
        writer.writeIntegerProperty(PropertyType.INTEGER_PROPERTY, this.getIntegerProperty());
        writer.writeLongProperty(PropertyType.LONG_PROPERTY, this.getLongProperty());
        writer.writeFloatProperty(PropertyType.FLOAT_PROPERTY, this.getFloatProperty());
        writer.writeDoubleProperty(PropertyType.DOUBLE_PROPERTY, this.getDoubleProperty());
        writer.writeStringProperty(PropertyType.STRING_PROPERTY, this.getStringProperty());

        writer.writeArrayProperty(PropertyType.BOOLEAN_ARRAY_PROPERTY, this.getBooleanArrayProperty());
        writer.writeArrayProperty(PropertyType.SHORT_ARRAY_PROPERTY, this.getShortArrayProperty());
        writer.writeArrayProperty(PropertyType.INTEGER_ARRAY_PROPERTY, this.getIntegerArrayProperty());
        writer.writeArrayProperty(PropertyType.LONG_ARRAY_PROPERTY, this.getLongArrayProperty());
        writer.writeArrayProperty(PropertyType.FLOAT_ARRAY_PROPERTY, this.getFloatArrayProperty());
        writer.writeArrayProperty(PropertyType.DOUBLE_ARRAY_PROPERTY, this.getDoubleArrayProperty());
        writer.writeArrayProperty(PropertyType.STRING_ARRAY_PROPERTY, this.getStringArrayProperty());
        writer.writeBlobProperty(PropertyType.BLOB_PROPERTY, this.getBlobProperty());
    }

    /**
     * Reads a json.
     */
    public static PropertyType readJson(IJsonObjectReader reader) {
        boolean booleanValue = reader.readBooleanProperty(PropertyType.BOOLEAN_PROPERTY);
        short shortValue = reader.readShortProperty(PropertyType.SHORT_PROPERTY);
        int integerValue = reader.readIntegerProperty(PropertyType.INTEGER_PROPERTY);
        long longValue = reader.readLongProperty(PropertyType.LONG_PROPERTY);
        float floatValue = reader.readFloatProperty(PropertyType.FLOAT_PROPERTY);
        double doubleValue = reader.readDoubleProperty(PropertyType.DOUBLE_PROPERTY);
        String stringValue = reader.readStringProperty(PropertyType.STRING_PROPERTY);

        boolean[] booleanArray = reader.readBooleanArrayProperty(PropertyType.BOOLEAN_ARRAY_PROPERTY);
        short[] shortArray = reader.readShortArrayProperty(PropertyType.SHORT_ARRAY_PROPERTY);
        int[] integerArray = reader.readIntegerArrayProperty(PropertyType.INTEGER_ARRAY_PROPERTY);
        long[] longArray = reader.readLongArrayProperty(PropertyType.LONG_ARRAY_PROPERTY);
        float[] floatArray = reader.readFloatArrayProperty(PropertyType.FLOAT_ARRAY_PROPERTY);
        double[] doubleArray = reader.readDoubleArrayProperty(PropertyType.DOUBLE_ARRAY_PROPERTY);
        String[] stringArray = reader.readStringArrayProperty(PropertyType.STRING_ARRAY_PROPERTY);
        byte[] blob = reader.readBlobProperty(PropertyType.BLOB_PROPERTY);

        return new PropertyType(
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
    public boolean isEqual(IPropertyType other) {
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
    public int compareTo(IPropertyType other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IPropertyType> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a fruit.
     */
    public static final class Comparator extends AbstractBinaryComparator<IPropertyType> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IPropertyType obj) {
            return new HashCodeBuilder(787, 797)
                .withBoolean(obj.getBooleanProperty())
                .withShort(obj.getShortProperty())
                .withInteger(obj.getIntegerProperty())
                .withLong(obj.getLongProperty())
                .withFloat(obj.getFloatProperty())
                .withDouble(obj.getDoubleProperty())
                .withString(obj.getStringProperty())
                .withBooleanArray(obj.getBooleanArrayProperty())
                .withShortArray(obj.getShortArrayProperty())
                .withIntegerArray(obj.getIntegerArrayProperty())
                .withLongArray(obj.getLongArrayProperty())
                .withFloatArray(obj.getFloatArrayProperty())
                .withDoubleArray(obj.getDoubleArrayProperty())
                .withStringArray(obj.getStringArrayProperty())
                .withByteArray(obj.getBlobProperty())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IPropertyType lhs, IPropertyType rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withBoolean(lhs.getBooleanProperty(), rhs.getBooleanProperty())
                .withShort(lhs.getShortProperty(), rhs.getShortProperty())
                .withInteger(lhs.getIntegerProperty(), rhs.getIntegerProperty())
                .withLong(lhs.getLongProperty(), rhs.getLongProperty())
                .withFloat(lhs.getFloatProperty(), rhs.getFloatProperty())
                .withDouble(lhs.getDoubleProperty(), rhs.getDoubleProperty())
                .withString(lhs.getStringProperty(), rhs.getStringProperty())
                .withBooleanArray(lhs.getBooleanArrayProperty(), rhs.getBooleanArrayProperty())
                .withShortArray(lhs.getShortArrayProperty(), rhs.getShortArrayProperty())
                .withIntegerArray(lhs.getIntegerArrayProperty(), rhs.getIntegerArrayProperty())
                .withLongArray(lhs.getLongArrayProperty(), rhs.getLongArrayProperty())
                .withFloatArray(lhs.getFloatArrayProperty(), rhs.getFloatArrayProperty())
                .withDoubleArray(lhs.getDoubleArrayProperty(), rhs.getDoubleArrayProperty())
                .withStringArray(lhs.getStringArrayProperty(), rhs.getStringArrayProperty())
                .withByteArray(lhs.getBlobProperty(), rhs.getBlobProperty())
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
        public int compareTo(IPropertyType lhs, IPropertyType rhs) {
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
                .withBoolean(lhs.getBooleanProperty(), rhs.getBooleanProperty())
                .withShort(lhs.getShortProperty(), rhs.getShortProperty())
                .withInteger(lhs.getShortProperty(), rhs.getIntegerProperty())
                .withLong(lhs.getLongProperty(), rhs.getLongProperty())
                .withFloat(lhs.getFloatProperty(), rhs.getFloatProperty())
                .withDouble(lhs.getDoubleProperty(), rhs.getDoubleProperty())
                .withString(lhs.getStringProperty(), rhs.getStringProperty())
                .withBooleanArray(lhs.getBooleanArrayProperty(), rhs.getBooleanArrayProperty())
                .withShortArray(lhs.getShortArrayProperty(), rhs.getShortArrayProperty())
                .withIntegerArray(lhs.getIntegerArrayProperty(), rhs.getIntegerArrayProperty())
                .withLongArray(lhs.getLongArrayProperty(), rhs.getLongArrayProperty())
                .withFloatArray(lhs.getFloatArrayProperty(), rhs.getFloatArrayProperty())
                .withDoubleArray(lhs.getDoubleArrayProperty(), rhs.getDoubleArrayProperty())
                .withStringArray(lhs.getStringArrayProperty(), rhs.getStringArrayProperty())
                .withByteArray(lhs.getBlobProperty(), rhs.getBlobProperty())
                .build();
        }
    }

}
