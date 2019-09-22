package datastructures.node.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.collections.core.Collections;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The KeyValueNode class implements a generic key-value node.
 */
public final class KeyValueNode<TKey extends Comparable<TKey>, TValue> implements IKeyValueNode<TKey, TValue> {
    private final TKey key;
    private TValue value;
    private final IBinaryComparator<IKeyValueNode<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * Creates a new instance of a key-value node.
     */
    public static <TKey extends Comparable<TKey>, TValue> IKeyValueNode<TKey, TValue> of(TKey key, TValue value) {
        return new KeyValueNode<>(key, value);
    }

    /**
     * The KeyValueNode constructor.
     */
    private KeyValueNode(
        TKey key,
        TValue value) {
        this(
            key,
            value,
            KeyValueNode.defaultComparator());
    }

    /**
     * The KeyValueNode constructor.
     */
    private KeyValueNode(
        TKey key,
        TValue value,
        IBinaryComparator<IKeyValueNode<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            key,
            "The key of a node.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a node.");

        this.key = key;
        this.value = value;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets a key of a node.
     */
    @Override
    public TKey getKey() {
        return this.key;
    }

    /**
     * Gets a value of a node.
     */
    @Override
    public TValue getValue() {
        return this.value;
    }

    /**
     * Sets a value of a node.
     */
    @Override
    public void setValue(TValue value) {
        this.value = value;
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
    public boolean isEqual(IKeyValueNode<TKey, TValue> other) {
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
    public int compareTo(IKeyValueNode<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IKeyValueNode<TKey, TValue>> defaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a generic node.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IKeyValueNode<TKey, TValue>> {

        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TKey> keyComparator) {
            Conditions.validateNotNull(
                keyComparator,
                "The key comparator of a node.");

            this.keyComparator = keyComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IKeyValueNode<TKey, TValue> obj) {
            return this.keyComparator.getHashCode(obj.getKey());
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IKeyValueNode<TKey, TValue> lhs, IKeyValueNode<TKey, TValue> rhs) {
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
        public int compareTo(IKeyValueNode<TKey, TValue> lhs, IKeyValueNode<TKey, TValue> rhs) {
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
     * The Builder class implements a builder for creating data of a key-value node.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IKeyValueNode<TKey, TValue>> {
        private TKey key;
        private TValue value;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets the key of a node.
         */
        public Builder setKey(TKey key) {
            Conditions.validateNotNull(
                key,
                "The key of a node.");

            this.key = key;
            return this;
        }

        /**
         * Adds the value of a node.
         */
        public Builder setValue(TValue value) {
            this.value = value;
            return this;
        }

        /**
         * Builds the data of a node.
         */
        @Override
        public IKeyValueNode<TKey, TValue> build() {
            IKeyValueNode<TKey, TValue> node = new KeyValueNode<>(
                this.key,
                this.value,
                KeyValueNode.defaultComparator());

            return node;
        }
    }
}
