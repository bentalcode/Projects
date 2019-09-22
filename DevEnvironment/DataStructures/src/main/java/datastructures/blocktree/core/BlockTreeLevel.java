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
import datastructures.blocktree.interfaces.IBlockTreeLevel;
import java.util.ArrayList;
import java.util.List;

/**
 * The BlockTreeLevel class implements a level of a tree.
 */
public final class BlockTreeLevel<TKey extends Comparable<TKey>, TValue> implements IBlockTreeLevel<TKey, TValue> {
    private final List<IBlockTreeNodeData<TKey, TValue>> nodesData;
    private final IBinaryComparator<IBlockTreeLevel<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * The TreeLevel constructor.
     */
    public BlockTreeLevel(List<IBlockTreeNodeData<TKey, TValue>> nodesData) {
        this(
            nodesData,
            BlockTreeLevel.defaultComparator());
    }

    /**
     * The TreeLevel constructor.
     */
    private BlockTreeLevel(
        List<IBlockTreeNodeData<TKey, TValue>> nodesData,
        IBinaryComparator<IBlockTreeLevel<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            nodesData,
            "The data of nodes in a level of a block tree.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a level of a block tree.");

        this.nodesData = nodesData;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the data of nodes.
     */
    @Override
    public List<IBlockTreeNodeData<TKey, TValue>> getNodesData() {
        return this.nodesData;
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
    public boolean isEqual(IBlockTreeLevel<TKey, TValue> other) {
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
    public int compareTo(IBlockTreeLevel<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IBlockTreeLevel<TKey, TValue>> defaultComparator() {
        IBinaryComparator<IBlockTreeNodeData<TKey, TValue>> nodeComparator = BlockTreeNodeData.defaultComparator();
        return new Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a level of a block tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IBlockTreeLevel<TKey, TValue>> {

        private final IBinaryComparator<IBlockTreeNodeData<TKey, TValue>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IBlockTreeNodeData<TKey, TValue>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The node comparator of a block tree.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IBlockTreeLevel<TKey, TValue> obj) {
            return new HashCodeBuilder(3, 5)
                .withCollection(obj.getNodesData(), this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IBlockTreeLevel<TKey, TValue> lhs, IBlockTreeLevel<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withCollection(lhs.getNodesData(), rhs.getNodesData(), this.nodeComparator)
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
        public int compareTo(IBlockTreeLevel<TKey, TValue> lhs, IBlockTreeLevel<TKey, TValue> rhs) {
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
                .withCollection(lhs.getNodesData(), rhs.getNodesData(), this.nodeComparator)
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating a level of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IBlockTreeLevel<TKey, TValue>> {
        private final List<IBlockTreeNodeData<TKey, TValue>> nodesData = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new node data.
         */
        public Builder<TKey, TValue> addNode(IBlockTreeNodeData<TKey, TValue> nodeData) {
            Conditions.validateNotNull(
                nodeData,
                "The data of a node of a block tree.");

            this.nodesData.add(nodeData);

            return this;
        }

        /**
         * Adds a new node data by keys and values.
         */
        public Builder<TKey, TValue> addNode(List<TKey> nodeKeys, List<TValue> nodeValues) {
            IBlockTreeNodeData<TKey, TValue> nodeData = new BlockTreeNodeData<>(nodeKeys, nodeValues);
            return this.addNode(nodeData);
        }

        /**
         * Adds a new node data by keys.
         */
        public Builder<TKey, TValue> addNode(List<TKey> nodeKeys) {
            return this.addNode(nodeKeys, null);
        }

        /**
         * Builds a level of a tree.
         */
        @Override
        public IBlockTreeLevel<TKey, TValue> build() {
            IBlockTreeLevel<TKey, TValue> level = new BlockTreeLevel<>(
                this.nodesData,
                BlockTreeLevel.defaultComparator());

            return level;
        }
    }
}
