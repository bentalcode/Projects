package json.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import json.interfaces.IColor;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

/**
 * The Color class implements properties of a color.
 */
public final class Color implements IColor {
    private static final String PropertyName = "name";
    private static final String PropertyHex = "hex";
    private static final String PropertyRgb = "rgb";

    private final String name;
    private final String hex;
    private final String rgb;
    
    private final IBinaryComparator<IColor> comparator = Color.DefaultComparator();
    private final int hashCode;

    /**
     * The Color constructor.
     */
    public Color(
        String name,
        String hex,
        String rgb) {

        this.name = name;
        this.hex = hex;
        this.rgb = rgb;
        this.hashCode = this.comparator.getHashCode(this);
    }

    /**
     * Gets the name of a color.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the hex of a color.
     */
    @Override
    public String getHex() {
        return this.hex;
    }

    /**
     * Gets the rgb of a color.
     */
    @Override
    public String getRgb() {
        return this.rgb;
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(Color.PropertyName, this.name);
        writer.writeStringProperty(Color.PropertyHex, this.hex);
        writer.writeStringProperty(Color.PropertyRgb, this.rgb);
    }

    /**
     * Reads a json.
     */
    public static IColor readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(Color.PropertyName);
        String hex = reader.readStringProperty(Color.PropertyHex);
        String rgb = reader.readStringProperty(Color.PropertyRgb);

        return new Color(
            name,
            hex,
            rgb);
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
    public boolean isEqual(IColor other) {
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
    public int compareTo(IColor other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IColor> DefaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a fruit.
     */
    public static final class Comparator implements IBinaryComparator<IColor> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IColor obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getHex())
                .withString(obj.getRgb())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IColor lhs, IColor rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getName(), rhs.getName())
                .withString(lhs.getHex(), rhs.getHex())
                .withString(lhs.getRgb(), rhs.getRgb())
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
        public int compareTo(IColor lhs, IColor rhs) {
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
                .withString(lhs.getName(), rhs.getName())
                .withString(lhs.getHex(), rhs.getHex())
                .withString(lhs.getRgb(), rhs.getRgb())
                .build();
        }
    }

}
