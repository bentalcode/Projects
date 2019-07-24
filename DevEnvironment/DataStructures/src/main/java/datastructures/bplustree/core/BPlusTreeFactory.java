package datastructures.bplustree.core;

import base.core.Conditions;
import datastructures.bplustree.interfaces.IBPlusTree;
import datastructures.bplustree.interfaces.IBPlusTreeFactory;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodes;

/**
 * The BPlusTreeFactory class implements a factory for creating B+ trees.
 */
public final class BPlusTreeFactory<TKey extends Comparable<TKey>, TValue> implements IBPlusTreeFactory<TKey, TValue> {
    private IBPlusTreeProperties<TKey, TValue> properties;

    /**
     * The BPlusTree constructor.
     */
    public BPlusTreeFactory(IBPlusTreeProperties<TKey, TValue> properties) {
        Conditions.validateNotNull(
            properties,
            "The properties of a B+ tree.");

        this.properties = properties;
    }

    /**
     * Creates a new B+ tree.
     */
    @Override
    public IBPlusTree<TKey, TValue> create(IKeyValueNodes<TKey, TValue> treeData) {
        return this.create(this.properties, treeData);
    }

    /**
     * Creates a new B+ tree.
     */
    @Override
    public IBPlusTree<TKey, TValue> create(
        IBPlusTreeProperties<TKey, TValue> properties,
        IKeyValueNodes<TKey, TValue> treeData) {

        Conditions.validateNotNull(
            properties,
            "The properties of a B+ tree.");

        Conditions.validateNotNull(
            treeData,
            "The data of a B+ tree.");

        IBPlusTree<TKey, TValue> tree = new BPlusTree<>(this.properties);

        for (IKeyValueNode<TKey, TValue> node : treeData.getNodes()) {
            tree.insert(node.getKey(), node.getValue());
        }

        return tree;
    }
}
