package datastructures.node.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.node.interfaces.INode;

/**
 * The Node class implements data of a generic node.
 */
public final class Node<TKey extends Comparable<TKey>, TValue> implements INode<TKey, TValue> {
    private final TKey key;
    private final TValue value;
    private final IBinaryComparator<INode<TKey, TValue>> comparator;

    /**
     * The Node constructor.
     */
    public Node(
        TKey key,
        TValue value) {
        this(
            key,
            value,
            Node.DefaultComparator());
    }

    /**
     * The Node constructor.
     */
    private Node(
        TKey key,
        TValue value,
        IBinaryComparator<INode<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            key,
            "The key of a node.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a node.");

        this.key = key;
        this.value = value;
        this.comparator = comparator;
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
    public boolean isEqual(INode<TKey, TValue> other) {
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
    public int compareTo(INode<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<INode<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.DefaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a generic node.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> implements IBinaryComparator<INode<TKey, TValue>> {
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
        public int getHashCode(INode<TKey, TValue> obj) {
            return this.keyComparator.getHashCode(obj.getKey());
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(INode<TKey, TValue> lhs, INode<TKey, TValue> rhs) {
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
        public int compareTo(INode<TKey, TValue> lhs, INode<TKey, TValue> rhs) {
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
     * The Builder class implements a builder for creating data of a node.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<INode<TKey, TValue>> {
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
        public INode<TKey, TValue> build() {
            INode<TKey, TValue> nodeData = new Node<>(
                this.key,
                this.value,
                Node.DefaultComparator());

            return nodeData;
        }
    }
}
