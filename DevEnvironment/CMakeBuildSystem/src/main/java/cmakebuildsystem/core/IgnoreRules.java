package cmakebuildsystem.core;

import base.core.AbstractBinaryComparator;
import base.core.ArrayLists;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import cmakebuildsystem.interfaces.IIgnoreRules;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.List;

/**
 * The IgnoreRules class implements ignore rules.
 */
public final class IgnoreRules implements IIgnoreRules {
    private static final String propertyPathPatterns = "pathPatterns";

    private static final List<String> defaultPathPatterns = ArrayLists.make("glob:**\\\\*build*\\\\**");
    
    private final List<String> pathPatterns;

    private final IBinaryComparator<IIgnoreRules> comparator = defaultComparator();
    private final int hashCode;

    /**
     * Gets the default ignore rules.
     */
    public static IIgnoreRules defaultIgnoreRules() {
        return new IgnoreRules(defaultPathPatterns);
    }

    /**
     * The IgnoreRules constructor.
     */
    public IgnoreRules(List<String> pathPatterns) {
        Conditions.validateNotNull(
            pathPatterns,
            "The path patterns of the ignore rules.");

        this.pathPatterns = pathPatterns;
        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets the path patterns.
     */
    @Override
    public List<String> getPathPatterns() {
        return this.pathPatterns;
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Serializes an object from a json.
     */
    public static IIgnoreRules fromJson(String json) {
        return JsonObjectStream.deserialize(json, IgnoreRules.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeCollectionProperty(propertyPathPatterns, this.pathPatterns);
    }

    /**
     * Reads a json.
     */
    public static IIgnoreRules readJson(IJsonObjectReader reader) {
        List<String> pathPatterns = reader.hasProperty(propertyPathPatterns) ?
            reader.readStringListProperty(propertyPathPatterns) :
            defaultPathPatterns;

        return new IgnoreRules(pathPatterns);
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
    public boolean isEqual(IIgnoreRules other) {
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
    public int compareTo(IIgnoreRules other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IIgnoreRules> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of an ignore rules.
     */
    public static final class Comparator extends AbstractBinaryComparator<IIgnoreRules> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IIgnoreRules obj) {
            return new HashCodeBuilder(181, 191)
                .withCollection(obj.getPathPatterns())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IIgnoreRules lhs, IIgnoreRules rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withCollection(lhs.getPathPatterns(), rhs.getPathPatterns())
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
        public int compareTo(IIgnoreRules lhs, IIgnoreRules rhs) {
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
                .withCollection(lhs.getPathPatterns(), rhs.getPathPatterns())
                .build();
        }
    }
}
