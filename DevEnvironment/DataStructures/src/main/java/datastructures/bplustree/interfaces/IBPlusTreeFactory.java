package datastructures.bplustree.interfaces;

import datastructures.tree.interfaces.ITreeData;

/**
 * The IBPlusTreeFactory interface defines a factory for creating B+ trees.
 */
public interface IBPlusTreeFactory<TKey extends Comparable<TKey>, TValue> {

    /**
     * Creates a new B+ tree.
     */
    IBPlusTree<TKey, TValue> create(ITreeData<TKey, TValue> treeData);

    /**
     * Creates a new B+ tree.
     */
    IBPlusTree<TKey, TValue> create(
        IBPlusTreeProperties<TKey, TValue> properties,
        ITreeData<TKey, TValue> treeData);
}
