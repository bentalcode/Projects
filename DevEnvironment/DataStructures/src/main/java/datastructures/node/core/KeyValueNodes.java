package datastructures.node.core;

import testbase.core.Conditions;
import base.interfaces.IBuilder;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import datastructures.node.interfaces.IKeyValueNodes;

import java.util.ArrayList;
import java.util.List;

/**
 * The KeyValueNodes class implements a list of generic key-value nodes.
 */
public final class KeyValueNodes<TKey extends Comparable<TKey>, TValue> implements IKeyValueNodes<TKey, TValue> {
    private final List<IKeyValueNode<TKey, TValue>> nodes;

    /**
     * The KeyValueNodes constructor.
     */
    public KeyValueNodes(List<IKeyValueNode<TKey, TValue>> nodes) {
        Conditions.validateNotNull(
            nodes,
            "The list of of nodes.");

        this.nodes = nodes;
    }

    /**
     * Gets an iterator of a generic node.
     */
    @Override
    public IKeyValueNodeIterator<TKey, TValue> getIterator() {
        return new KeyValueNodeIterator<>(this.nodes);
    }

    /**
     * Gets a list of generic nodes.
     */
    @Override
    public List<IKeyValueNode<TKey, TValue>> getNodes() {
        return this.nodes;
    }

    /**
     * The Builder class implements a builder for creating a list of key-value nodes.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IKeyValueNodes<TKey, TValue>> {
        private final List<IKeyValueNode<TKey, TValue>> nodes = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new node.
         */
        public Builder<TKey, TValue> addNode(IKeyValueNode<TKey, TValue> node) {
            Conditions.validateNotNull(
                node,
                "The node to add.");

            this.nodes.add(node);

            return this;
        }

        /**
         * Adds a new node by a key and a value.
         */
        public Builder<TKey, TValue> addNode(TKey key, TValue value) {
            IKeyValueNode<TKey, TValue> node = new KeyValueNode<>(key, value);
            return this.addNode(node);
        }

        /**
         * Builds the node list.
         */
        @Override
        public IKeyValueNodes<TKey, TValue> build() {
            IKeyValueNodes<TKey, TValue> nodes = new KeyValueNodes<>(this.nodes);
            return nodes;
        }
    }
}
