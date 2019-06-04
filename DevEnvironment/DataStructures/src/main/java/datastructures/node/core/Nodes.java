package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IBuilder;
import datastructures.node.interfaces.INode;
import datastructures.node.interfaces.INodeIterator;
import datastructures.node.interfaces.INodes;

import java.util.ArrayList;
import java.util.List;

/**
 * The Nodes class implements a list of generic nodes.
 */
public final class Nodes<TKey extends Comparable<TKey>, TValue> implements INodes<TKey, TValue> {
    private final List<INode<TKey, TValue>> nodes;

    /**
     * The Nodes constructor.
     */
    public Nodes(List<INode<TKey, TValue>> nodes) {
        Conditions.validateNotNull(
            nodes,
            "The list of of nodes.");

        this.nodes = nodes;
    }

    /**
     * Gets an iterator of a generic node.
     */
    @Override
    public INodeIterator<TKey, TValue> getIterator() {
        return new NodeIterator<>(this.nodes);
    }

    /**
     * Gets a list of generic nodes.
     */
    @Override
    public List<INode<TKey, TValue>> getNodes() {
        return this.nodes;
    }

    /**
     * The Builder class implements a builder for creating a node list.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<INodes<TKey, TValue>> {
        private final List<INode<TKey, TValue>> nodes = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new node.
         */
        public Builder<TKey, TValue> addNode(INode<TKey, TValue> node) {
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
            INode<TKey, TValue> node = new Node<>(key, value);
            return this.addNode(node);
        }

        /**
         * Builds the node list.
         */
        @Override
        public INodes<TKey, TValue> build() {
            INodes<TKey, TValue> nodes = new Nodes<>(this.nodes);
            return nodes;
        }
    }
}
