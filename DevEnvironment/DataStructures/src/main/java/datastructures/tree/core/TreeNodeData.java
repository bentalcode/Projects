package datastructures.tree.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.tree.interfaces.ITreeNodeData;

/**
 * The TreeNodeData class implements data of a node of a tree.
 */
public final class TreeNodeData<TKey extends Comparable<TKey>, TValue> implements ITreeNodeData<TKey, TValue> {
    private final TKey key;
    private final TValue value;
    private final IBinaryComparator<ITreeNodeData<TKey, TValue>> comparator;

    /**
     * The TreeNodeData constructor.
     */
    public TreeNodeData(
        TKey key,
        TValue value) {
        this(
            key,
            value,
            TreeNodeData.DefaultComparator());
    }

    /**
     * The TreeNodeData constructor.
     */
    private TreeNodeData(
        TKey key,
        TValue value,
        IBinaryComparator<ITreeNodeData<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            key,
            "The key of node of a tree.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of node of a tree.");

        this.key = key;
        this.value = value;
        this.comparator = comparator;
    }

    /**
     * Gets the key of the node.
     */
    @Override
    public TKey getKey() {
        return this.key;
    }

    /**
     * Gets the value of the node.
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
    public boolean isEqual(ITreeNodeData<TKey, TValue> other) {
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
    public int compareTo(ITreeNodeData<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ITreeNodeData<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.DefaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a node of a tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> implements IBinaryComparator<ITreeNodeData<TKey, TValue>> {
        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TKey> keyComparator) {
            Conditions.validateNotNull(
                keyComparator,
                "The key comparator of a tree.");

            this.keyComparator = keyComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITreeNodeData<TKey, TValue> obj) {
            return this.keyComparator.getHashCode(obj.getKey());
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ITreeNodeData<TKey, TValue> lhs, ITreeNodeData<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withGeneric(lhs.getKey(), rhs.getKey(), this.keyComparator)
                .build();
        }

        /**
         * Determines the relative order of two instances.
         * <p>
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(ITreeNodeData<TKey, TValue> lhs, ITreeNodeData<TKey, TValue> rhs) {
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
                .withGeneric(lhs.getKey(), rhs.getKey(), this.keyComparator)
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating data of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<ITreeNodeData<TKey, TValue>> {
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
                "The key of a node of a tree.");

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
        public ITreeNodeData<TKey, TValue> build() {
            ITreeNodeData<TKey, TValue> treeData = new TreeNodeData<>(
                this.key,
                this.value,
                TreeNodeData.DefaultComparator());

            return treeData;
        }
    }
}
