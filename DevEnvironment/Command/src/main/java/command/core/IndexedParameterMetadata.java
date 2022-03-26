package command.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import command.interfaces.IIndexedParameterMetadata;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;

/**
 * The IndexedParameterMetadata class implements meta-data of an indexed parameter.
 */
public final class IndexedParameterMetadata extends ParameterMetadata implements IIndexedParameterMetadata {
    private final IBinaryComparator<IIndexedParameterMetadata> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The IndexedParameterMetadata constructor.
     */
    public IndexedParameterMetadata(
        String name,
        String description) {
        super(
            name,
            description);

        this.hashCode = this.comparator.hashCode();
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
    public static IIndexedParameterMetadata fromJson(String json) {
        return JsonObjectStream.deserialize(json, IndexedParameterMetadata.class);
    }

    /**
     * Reads a json.
     */
    public static IIndexedParameterMetadata readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(PROPERTY_NAME);
        String description = reader.readStringProperty(PROPERTY_DESCRIPTION);

        return new IndexedParameterMetadata(
            name,
            description);
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
    public boolean isEqual(IIndexedParameterMetadata other) {
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
    public int compareTo(IIndexedParameterMetadata other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IIndexedParameterMetadata> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a meta-data of a parameter of a command.
     */
    public static final class Comparator extends AbstractBinaryComparator<IIndexedParameterMetadata> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IIndexedParameterMetadata obj) {
            return new HashCodeBuilder(223, 227)
                .withString(obj.getDescription())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IIndexedParameterMetadata lhs, IIndexedParameterMetadata rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getDescription(), rhs.getDescription())
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
        public int compareTo(IIndexedParameterMetadata lhs, IIndexedParameterMetadata rhs) {
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
                .withString(lhs.getDescription(), rhs.getDescription())
                .build();
        }
    }
}
