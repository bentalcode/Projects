package datastructures.tree.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.tree.interfaces.ITreeLevel;
import datastructures.tree.interfaces.ITreeNodeData;
import java.util.ArrayList;
import java.util.List;

/**
 * The TreeLevel class implements a level of a tree.
 */
public final class TreeLevel<TKey extends Comparable<TKey>, TValue> implements ITreeLevel<TKey, TValue> {
    private final List<ITreeNodeData<TKey, TValue>> nodesData;
    private final IBinaryComparator<ITreeLevel<TKey, TValue>> comparator;

    /**
     * The TreeLevel constructor.
     */
    public TreeLevel(List<ITreeNodeData<TKey, TValue>> nodesData) {
        this(
            nodesData,
            TreeLevel.DefaultComparator());
    }

    /**
     * The TreeLevel constructor.
     */
    private TreeLevel(
        List<ITreeNodeData<TKey, TValue>> nodesData,
        IBinaryComparator<ITreeLevel<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            nodesData,
            "The data of nodes in a level of a tree can not be null.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a level of a tree can not be null.");

        this.nodesData = nodesData;
        this.comparator = comparator;
    }

    /**
     * Gets the data of nodes.
     */
    @Override
    public List<ITreeNodeData<TKey, TValue>> getNodesData() {
        return this.nodesData;
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
    public boolean isEqual(ITreeLevel<TKey, TValue> other) {
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
    public int compareTo(ITreeLevel<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ITreeLevel<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<ITreeNodeData<TKey, TValue>> nodeComparator = TreeNodeData.DefaultComparator();
        return new Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a level of a block tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> implements IBinaryComparator<ITreeLevel<TKey, TValue>> {
        private final IBinaryComparator<ITreeNodeData<TKey, TValue>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<ITreeNodeData<TKey, TValue>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The node comparator of a tree can not be null.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITreeLevel<TKey, TValue> obj) {
            return new HashCodeBuilder(3, 5)
                .withCollection(obj.getNodesData(), this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ITreeLevel<TKey, TValue> lhs, ITreeLevel<TKey, TValue> rhs) {
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
        public int compareTo(ITreeLevel<TKey, TValue> lhs, ITreeLevel<TKey, TValue> rhs) {
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
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<ITreeLevel<TKey, TValue>> {
        private final List<ITreeNodeData<TKey, TValue>> nodesData = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new node data.
         */
        public Builder<TKey, TValue> addNode(ITreeNodeData<TKey, TValue> nodeData) {
            Conditions.validateNotNull(
                nodeData,
                "The data of a node of a tree can not be null.");

            this.nodesData.add(nodeData);

            return this;
        }

        /**
         * Adds a new node data by key and value.
         */
        public Builder<TKey, TValue> addNode(TKey nodeKey, TValue nodeValue) {
            ITreeNodeData<TKey, TValue> nodeData = new TreeNodeData<>(nodeKey, nodeValue);
            return this.addNode(nodeData);
        }

        /**
         * Adds a new node data by key.
         */
        public Builder<TKey, TValue> addNode(TKey nodeKey) {
            return this.addNode(nodeKey, null);
        }

        /**
         * Builds a level of a tree.
         */
        @Override
        public ITreeLevel<TKey, TValue> build() {
            ITreeLevel<TKey, TValue> level = new TreeLevel<>(
                this.nodesData,
                TreeLevel.DefaultComparator());

            return level;
        }
    }
}
