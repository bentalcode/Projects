package datastructures.graph.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.collections.core.Collections;
import datastructures.graph.interfaces.IVertex;

/**
 * The Vertex class implements a vertex of a graph.
 */
public final class Vertex<TKey extends Comparable<TKey>, TValue> implements IVertex<TKey, TValue> {
    private final TKey key;
    private TValue value;
    private final IBinaryComparator<IVertex<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * Creates a new instance of a vertex.
     */
    public static <TKey extends Comparable<TKey>, TValue> IVertex<TKey, TValue> of(TKey key) {
        return new Vertex<>(key, null);
    }

    /**
     * Creates a new instance of a vertex.
     */
    public static <TKey extends Comparable<TKey>, TValue> IVertex<TKey, TValue> of(TKey key, TValue value) {
        return new Vertex<>(key, value);
    }

    /**
     * The Vertex constructor.
     */
    public Vertex(TKey key, TValue value) {
        this(
            key,
            value,
            Vertex.defaultComparator());
    }

    /**
     * The Vertex constructor.
     */
    private Vertex(
        TKey key,
        TValue value,
        IBinaryComparator<IVertex<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            key,
            "The key of a vertex.");
        
        Conditions.validateNotNull(
            comparator,
            "The comparator of a vertex.");

        this.key = key;
        this.value = value;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Creates a new instance of a directed edge.
     */
    public static <TKey extends Comparable<TKey>, TValue> IVertex<TKey, TValue> copy(IVertex<TKey, TValue> other) {
        Conditions.validateNotNull(
            other,
            "The vertex for copying.");

        return new Vertex<>(other.getKey(), other.getValue());
    }

    /**
     * Gets a key of a vertex.
     */
    @Override
    public TKey getKey() {
        return this.key;
    }
    
    /**
     * Gets a value of a vertex.
     */
    @Override
    public TValue getValue() {
        return this.value;
    }

    /**
     * Gets the comparator.
     */
    public IBinaryComparator<IVertex<TKey, TValue>> getComparator() {
        return this.comparator;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return "[Key = " + this.key + ", Value = " + this.value + "]";
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
    public boolean isEqual(IVertex<TKey, TValue> other) {
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
    public int compareTo(IVertex<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IVertex<TKey, TValue>> defaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a generic vertex.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IVertex<TKey, TValue>> {

        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TKey> keyComparator) {
            Conditions.validateNotNull(
                keyComparator,
                "The comparator of a key.");

            this.keyComparator = keyComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IVertex<TKey, TValue> obj) {
            return this.keyComparator.getHashCode(obj.getKey());
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IVertex<TKey, TValue> lhs, IVertex<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getKey(), rhs.getKey(), this.keyComparator)
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
        public int compareTo(IVertex<TKey, TValue> lhs, IVertex<TKey, TValue> rhs) {
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
                .withObject(lhs.getKey(), rhs.getKey(), this.keyComparator)
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating a vertex.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IVertex<TKey, TValue>> {
        private TKey key;
        private TValue value;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets the key of a vertex.
         */
        public Builder setKey(TKey key) {
            this.key = key;
            return this;
        }

        /**
         * Sets the value of a vertex.
         */
        public Builder setValue(TValue value) {
            this.value = value;
            return this;
        }

        /**
         * Builds the a vertex.
         */
        @Override
        public IVertex<TKey, TValue> build() {
            IVertex<TKey, TValue> vertex = new Vertex<>(
                this.key,
                this.value,
                Vertex.defaultComparator());

            return vertex;
        }
    }
}
