package json.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import json.interfaces.IFruit;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

/**
 * The Fruit class implements properties of a fruit.
 */
public final class Fruit implements IFruit {
    private static final String PROPERTY_KIND = "kind";
    private static final String PROPERTY_SIZE = "size";
    private static final String PROPERTY_COLOR = "color";
    private static final String PROPERTY_PRICE = "price";

    private final String kind;
    private final int size;
    private final String color;
    private final double price;
    private final IBinaryComparator<IFruit> comparator;
    private final int hashCode;

    /**
     * The Fruit constructor.
     */
    public Fruit(
        String kind,
        int size,
        String color,
        double price) {

        this(kind, size, color, price, Fruit.defaultComparator());
    }

    /**
     * The Fruit constructor.
     */
    public Fruit(
        String kind,
        int size,
        String color,
        double price,
        IBinaryComparator<IFruit> comparator) {

        this.kind = kind;
        this.size = size;
        this.color = color;
        this.price = price;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the kind of fruit.
     */
    @Override
    public String getKind() {
        return this.kind;
    }

    /**
     * Gets size of a fruit.
     */
    @Override
    public int getSize() {
        return this.size;
    }

    /**
     * Gets color of a fruit.
     */
    @Override
    public String getColor() {
        return this.color;
    }

    /**
     * Gets price of a fruit.
     */
    @Override
    public double getPrice() {
        return this.price;
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(Fruit.PROPERTY_KIND, this.kind);
        writer.writeIntegerProperty(Fruit.PROPERTY_SIZE, this.size);
        writer.writeStringProperty(Fruit.PROPERTY_COLOR, this.color);
        writer.writeDoubleProperty(Fruit.PROPERTY_PRICE, this.price);
    }

    /**
     * Reads a json.
     */
    public static Fruit readJson(IJsonObjectReader reader) {
        String kind = reader.readStringProperty(Fruit.PROPERTY_KIND);
        int size = reader.readIntegerProperty(Fruit.PROPERTY_SIZE);
        String color = reader.readStringProperty(Fruit.PROPERTY_COLOR);
        double price = reader.readDoubleProperty(Fruit.PROPERTY_PRICE);

        return new Fruit(
            kind,
            size,
            color,
            price);
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
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
    public boolean isEqual(IFruit other) {
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
    public int compareTo(IFruit other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IFruit> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a fruit.
     */
    public static final class Comparator extends AbstractBinaryComparator<IFruit> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IFruit obj) {
            return new HashCodeBuilder(769, 773)
                .withString(obj.getKind())
                .withInteger(obj.getSize())
                .withString(obj.getColor())
                .withDouble(obj.getPrice())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IFruit lhs, IFruit rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getKind(), rhs.getKind())
                .withInteger(lhs.getSize(), rhs.getSize())
                .withString(lhs.getColor(), rhs.getColor())
                .withDouble(lhs.getPrice(), rhs.getPrice())
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
        public int compareTo(IFruit lhs, IFruit rhs) {
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
                .withString(lhs.getKind(), rhs.getKind())
                .withInteger(lhs.getSize(), rhs.getSize())
                .withString(lhs.getColor(), rhs.getColor())
                .withDouble(lhs.getPrice(), rhs.getPrice())
                .build();
        }
    }
}
