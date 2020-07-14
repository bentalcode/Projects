package datastructures.tree.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.tree.interfaces.ITreeLevel;
import java.util.ArrayList;
import java.util.List;

/**
 * The TreeLevel class implements a level of a tree.
 */
public final class TreeLevel<TKey extends Comparable<TKey>, TValue> implements ITreeLevel<TKey, TValue> {
    private final List<IKeyValueNode<TKey, TValue>> nodesData;
    private final IBinaryComparator<ITreeLevel<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * The TreeLevel constructor.
     */
    public TreeLevel(List<IKeyValueNode<TKey, TValue>> nodesData) {
        this(
            nodesData,
            TreeLevel.defaultComparator());
    }

    /**
     * The TreeLevel constructor.
     */
    private TreeLevel(
        List<IKeyValueNode<TKey, TValue>> nodesData,
        IBinaryComparator<ITreeLevel<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            nodesData,
            "The data of nodes in a level of a tree.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a level of a tree.");

        this.nodesData = nodesData;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the data of nodes.
     */
    @Override
    public List<IKeyValueNode<TKey, TValue>> getNodesData() {
        return this.nodesData;
    }

    /**
     * Gets the size of the level.
     */
    @Override
    public int size() {
        return this.nodesData.size();
    }

    /**
     * Checks whether the level is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<IKeyValueNode<TKey, TValue>> getIterator() {
        return ListIterator.of(this.nodesData);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<IKeyValueNode<TKey, TValue>> getReverseIterator() {
        return ListReverseIterator.of(this.nodesData);
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
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ITreeLevel<TKey, TValue>> defaultComparator() {
        IBinaryComparator<IKeyValueNode<TKey, TValue>> nodeComparator = KeyValueNode.defaultComparator();
        return new Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a level of a block tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<ITreeLevel<TKey, TValue>> {

        private final IBinaryComparator<IKeyValueNode<TKey, TValue>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IKeyValueNode<TKey, TValue>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The node comparator of a tree.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITreeLevel<TKey, TValue> obj) {
            return new HashCodeBuilder(683, 691)
                .withIterable(obj, this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ITreeLevel<TKey, TValue> lhs, ITreeLevel<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withIterable(lhs, rhs, this.nodeComparator)
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
                .withIterable(lhs, rhs, this.nodeComparator)
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating a level of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<ITreeLevel<TKey, TValue>> {
        private final List<IKeyValueNode<TKey, TValue>> nodesData = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new node data.
         */
        public Builder<TKey, TValue> addNode(IKeyValueNode<TKey, TValue> nodeData) {
            Conditions.validateNotNull(
                nodeData,
                "The data of a node of a tree.");

            this.nodesData.add(nodeData);

            return this;
        }

        /**
         * Adds a new node data by key and value.
         */
        public Builder<TKey, TValue> addNode(TKey nodeKey, TValue nodeValue) {
            IKeyValueNode<TKey, TValue> nodeData = KeyValueNode.of(nodeKey, nodeValue);
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
                TreeLevel.defaultComparator());

            return level;
        }
    }
}
