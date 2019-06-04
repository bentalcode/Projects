package datastructures.bplustree.interfaces;

import datastructures.node.interfaces.INodes;

/**
 * The IBPlusTreeFactory interface defines a factory for creating B+ trees.
 */
public interface IBPlusTreeFactory<TKey extends Comparable<TKey>, TValue> {

    /**
     * Creates a new B+ tree.
     */
    IBPlusTree<TKey, TValue> create(INodes<TKey, TValue> treeData);

    /**
     * Creates a new B+ tree.
     */
    IBPlusTree<TKey, TValue> create(
        IBPlusTreeProperties<TKey, TValue> properties,
        INodes<TKey, TValue> treeData);
}
