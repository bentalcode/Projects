package datastructures.bplustree.interfaces;

import base.interfaces.INullable;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.tree.interfaces.IKeyIterator;
import datastructures.tree.interfaces.ITreeDataIterator;
import datastructures.tree.interfaces.ITreeMetrics;
import datastructures.tree.interfaces.IValueIterator;

/**
 * The IBPlusTree interface defines a B+ tree.
 */
public interface IBPlusTree<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the properties of the B+ tree.
     */
    IBPlusTreeProperties<TKey, TValue> getProperties();

    /**
     * Inserts a new key and it's associated value into the B+ tree.
     */
    void insert(TKey key, TValue value);

    /**
     * Deletes a key and it's associated value from the tree.
     */
    void delete(TKey key);

    /**
     * Searches a key value on the tree and return it's associated value.
     */
    TValue search(TKey key);

    /**
     * Gets an iterator of keys of a tree.
     */
    IKeyIterator<TKey> getKeyIterator();

    /**
     * Gets an iterator of values of a tree.
     */
    IValueIterator<TValue> getValueIterator();

    /**
     * Gets an iterator of data of a tree.
     */
    ITreeDataIterator<TKey, TValue> getDataIterator();

    /**
     * Gets levels of a tree.
     */
    IBlockTreeLevels<TKey, INullable> getTreeLevels();

    /**
     * Gets metrics of a tree.
     */
    IBPlusTreeMetrics getMetrics();
}
