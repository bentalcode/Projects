package json.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import json.interfaces.IFruit;
import json.interfaces.IJsonReader;
import json.interfaces.IJsonWriter;

/**
 * The Fruit class implements properties of a fruit.
 */
public final class Fruit implements IFruit {
    private static final String Kind = "kind";
    private static final String Size = "size";
    private static final String Color = "color";
    private static final String Price = "price";

    private final String kind;
    private final int size;
    private final String color;
    private final double price;
    private final IBinaryComparator<IFruit> comparator = Fruit.DefaultComparator();

    /**
     * The Fruit constructor.
     */
    public Fruit(
        String kind,
        int size,
        String color,
        double price) {

        this.kind = kind;
        this.size = size;
        this.color = color;
        this.price = price;
    }

    /**
     * Gets the kind of a fruit.
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
    public void writeJson(IJsonWriter writer) {
        writer.writeStringProperty(Fruit.Kind, this.kind);
        writer.writeIntegerProperty(Fruit.Size, this.size);
        writer.writeStringProperty(Fruit.Color, this.color);
        writer.writeDoubleProperty(Fruit.Price, this.price);
    }

    /**
     * Reads a json.
     */
    public static IFruit readJson(IJsonReader reader) {
        String kind = reader.readStringProperty(Fruit.Kind);
        int size = reader.readIntegerProperty(Fruit.Size);
        String color = reader.readStringProperty(Fruit.Color);
        double price = reader.readDoubleProperty(Fruit.Price);

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
        return this.comparator.getHashCode(this);
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
    public static IBinaryComparator<IFruit> DefaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a fruit.
     */
    public static final class Comparator implements IBinaryComparator<IFruit> {
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
            return new HashCodeBuilder(3, 5)
                .withString(obj.getKind())
                .withInteger(obj.getSize())
                .withString(obj.getColor())
                .withDouble(obj.getPrice())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
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
