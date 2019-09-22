package datastructures.blocktree.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.blocktree.interfaces.IBlockTreeNodeData;
import java.util.ArrayList;
import java.util.List;

/**
 * The BlockTreeNodeData class implements data of a block node of a tree.
 */
public final class BlockTreeNodeData<TKey extends Comparable<TKey>, TValue> implements IBlockTreeNodeData<TKey, TValue> {
    private final List<TKey> keys;
    private final List<TValue> values;
    private final IBinaryComparator<IBlockTreeNodeData<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * The BlockTreeNodeData constructor.
     */
    public BlockTreeNodeData(
        List<TKey> keys,
        List<TValue> values) {

        this(
            keys,
            values,
            BlockTreeNodeData.defaultComparator());
    }

    /**
     * The BlockTreeNodeData constructor.
     */
    private BlockTreeNodeData(
        List<TKey> keys,
        List<TValue> values,
        IBinaryComparator<IBlockTreeNodeData<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            keys,
            "The keys of block node of a tree.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of block node of a tree.");

        this.keys = keys;
        this.values = values;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the keys of the node.
     */
    @Override
    public List<TKey> getKeys() {
        return this.keys;
    }

    /**
     * Gets the values of the node.
     */
    @Override
    public List<TValue> getValues() {
        return this.values;
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
    public boolean isEqual(IBlockTreeNodeData<TKey, TValue> other) {
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
    public int compareTo(IBlockTreeNodeData<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IBlockTreeNodeData<TKey, TValue>> defaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a node of a block tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IBlockTreeNodeData<TKey, TValue>> {

        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TKey> keyComparator) {
            Conditions.validateNotNull(
                keyComparator,
                "The key comparator of a block tree.");

            this.keyComparator = keyComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IBlockTreeNodeData<TKey, TValue> obj) {
            return new HashCodeBuilder(3, 5)
                .withCollection(obj.getKeys(), this.keyComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IBlockTreeNodeData<TKey, TValue> lhs, IBlockTreeNodeData<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withCollection(lhs.getKeys(), rhs.getKeys(), this.keyComparator)
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
        public int compareTo(IBlockTreeNodeData<TKey, TValue> lhs, IBlockTreeNodeData<TKey, TValue> rhs) {
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
                .withCollection(lhs.getKeys(), rhs.getKeys(), this.keyComparator)
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating data of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IBlockTreeNodeData<TKey, TValue>> {
        private final List<TKey> keys = new ArrayList<>();
        private final List<TValue> values = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new key.
         */
        public Builder<TKey, TValue> addKey(TKey key) {
            Conditions.validateNotNull(
                key,
                "The key of a block node of a tree.");

            this.keys.add(key);
            return this;
        }

        /**
         * Adds a new value.
         */
        public Builder<TKey, TValue> addValue(TValue value) {
            this.values.add(value);
            return this;
        }

        /**
         * Builds the data of a node.
         */
        @Override
        public IBlockTreeNodeData<TKey, TValue> build() {
            IBlockTreeNodeData<TKey, TValue> treeData = new BlockTreeNodeData<>(
                this.keys,
                this.values,
                BlockTreeNodeData.defaultComparator());

            return treeData;
        }
    }
}
