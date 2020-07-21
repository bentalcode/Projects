package command.core;

import base.core.AbstractBinaryComparator;
import base.core.ArrayLists;
import base.core.Casting;
import base.core.CollectionIterator;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import command.interfaces.IIndexedParameterMetadata;
import command.interfaces.INamedParameterMetadata;
import command.interfaces.IParameterMetadata;
import command.interfaces.IParameterSetMetadata;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * The ParameterSet class implements a metadata of a parameter-set.
 */
public final class ParameterSetMetadata implements IParameterSetMetadata {
    private static final String propertyIndexedParameters = "indexedParameters";
    private static final String propertyNamedParameters = "namedParameters";

    private final List<IIndexedParameterMetadata> indexedParameters;
    private final List<INamedParameterMetadata> namedParameters;
    private final List<IParameterMetadata> parameters = new ArrayList<>();

    private final IBinaryComparator<IParameterSetMetadata> comparator = defaultComparator();
    private final int hashCode;

    /**
     * Creates help parameter-set.
     */
    public static IParameterSetMetadata createHelpParameterSet() {
        List<IIndexedParameterMetadata> indexedParameterMetadata = ArrayLists.newList();
        List<INamedParameterMetadata> namedParameters = ArrayLists.of(ParameterMetadata.createHelpParameter());

        return new ParameterSetMetadata(
            indexedParameterMetadata,
            namedParameters);
    }

    /**
     * The ParameterSetMetadata constructor.
     */
    public ParameterSetMetadata(
        List<IIndexedParameterMetadata> indexedParameters,
        List<INamedParameterMetadata> namedParameters) {

        Conditions.validateNotNull(
            indexedParameters,
            "The indexed parameters of a parameter-set.");

        Conditions.validateNotNull(
            namedParameters,
            "The named parameters of a parameter-set.");

        this.indexedParameters = indexedParameters;
        this.namedParameters = namedParameters;
        this.parameters.addAll(indexedParameters);
        this.parameters.addAll(namedParameters);

        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets the indexed parameters of a parameter-set.
     */
    public List<IIndexedParameterMetadata> getIndexedParameters() {
        return this.indexedParameters;
    }

    /**
     * Gets the named parameters of a parameter-set.
     */
    public List<INamedParameterMetadata> getNamedParameters() {
        return this.namedParameters;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<IParameterMetadata> getIterator() {
        return CollectionIterator.of(this.parameters);
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
    public static IParameterSetMetadata fromJson(String json) {
        return JsonObjectStream.deserialize(json, ParameterSetMetadata.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeCollectionProperty(propertyIndexedParameters, this.indexedParameters);
        writer.writeCollectionProperty(propertyNamedParameters, this.namedParameters);
    }

    /**
     * Reads a json.
     */
    public static IParameterSetMetadata readJson(IJsonObjectReader reader) {
        List<IIndexedParameterMetadata> indexedParameters = reader.hasProperty(propertyIndexedParameters) ?
            reader.readListProperty(
                propertyIndexedParameters,
                IndexedParameterMetadata.class) :
            new ArrayList<>();

        List<INamedParameterMetadata> namedParameters = reader.hasProperty(propertyNamedParameters) ?
            reader.readListProperty(
                propertyNamedParameters,
                NamedParameterMetadata.class) :
            new ArrayList<>();

        return new ParameterSetMetadata(
            indexedParameters,
            namedParameters);
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
    public boolean isEqual(IParameterSetMetadata other) {
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
    public int compareTo(IParameterSetMetadata other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IParameterSetMetadata> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a metadata of a parameter-set.
     */
    public static final class Comparator extends AbstractBinaryComparator<IParameterSetMetadata> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IParameterSetMetadata obj) {
            return new HashCodeBuilder(239, 241)
                .withCollection(obj.getIndexedParameters())
                .withCollection(obj.getNamedParameters())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IParameterSetMetadata lhs, IParameterSetMetadata rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withCollection(lhs.getIndexedParameters(), rhs.getIndexedParameters())
                .withCollection(lhs.getNamedParameters(), rhs.getNamedParameters())
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
        public int compareTo(IParameterSetMetadata lhs, IParameterSetMetadata rhs) {
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
                .withCollection(lhs.getIndexedParameters(), rhs.getIndexedParameters())
                .withCollection(lhs.getNamedParameters(), rhs.getNamedParameters())
                .build();
        }
    }
}
