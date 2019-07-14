package datastructures.bplustree.interfaces;

import datastructures.node.interfaces.IKeyValueNodes;

/**
 * The IBPlusTreeFactory interface defines a factory for creating B+ trees.
 */
public interface IBPlusTreeFactory<TKey extends Comparable<TKey>, TValue> {

    /**
     * Creates a new B+ tree.
     */
    IBPlusTree<TKey, TValue> create(IKeyValueNodes<TKey, TValue> treeData);

    /**
     * Creates a new B+ tree.
     */
    IBPlusTree<TKey, TValue> create(
        IBPlusTreeProperties<TKey, TValue> properties,
        IKeyValueNodes<TKey, TValue> treeData);
}
