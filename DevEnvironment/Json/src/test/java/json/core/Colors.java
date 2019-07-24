package json.core;

import testbase.core.Casting;
import testbase.core.CompareToBuilder;
import testbase.core.EqualBuilder;
import testbase.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import json.interfaces.IColor;
import json.interfaces.IColors;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.List;

/**
 * The Colors class implements the properties of colors.
 */
public final class Colors implements IColors {
    private static final String PropertyCategory = "category";
    private static final String PropertyColors = "colors";
    
    private final String category;
    private final List<IColor> colors;

    private final IBinaryComparator<IColors> comparator = DefaultComparator();

    /**
     * The Colors constructor.
     */
    public Colors(String category, List<IColor> colors) {
        this.category = category;
        this.colors = colors;
    }
    
    /**
     * Gets the category of a color.
     */
    public String getCategory() {
        return this.category;
    }

    /**
     * Gets the colors.
     */
    public List<IColor> getColors() {
        return this.colors;
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(Colors.PropertyCategory, this.category);
        writer.writeListProperty(Colors.PropertyColors, this.colors);
    }

    /**
     * Reads a json.
     */
    public static IColors readJson(IJsonObjectReader reader) {
        String category = reader.readStringProperty(Colors.PropertyCategory);
        List<IColor> colors = reader.readListProperty(Colors.PropertyColors, Color.class);

        return new Colors(
            category,
            colors);
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
    public boolean isEqual(IColors other) {
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
    public int compareTo(IColors other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IColors> DefaultComparator() {
        return new Colors.Comparator();
    }

    /**
     * The Comparator class implements a comparator of a fruit.
     */
    public static final class Comparator implements IBinaryComparator<IColors> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IColors obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getCategory())
                .withCollection(obj.getColors(), Color.DefaultComparator())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IColors lhs, IColors rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getCategory(), rhs.getCategory())
                .withCollection(lhs.getColors(), rhs.getColors(), Color.DefaultComparator())
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
        public int compareTo(IColors lhs, IColors rhs) {
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
                .withString(lhs.getCategory(), rhs.getCategory())
                .withCollection(lhs.getColors(), rhs.getColors(), Color.DefaultComparator())
                .build();
        }
    }
}
