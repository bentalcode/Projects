package datastructures.bplustree.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.INullable;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.collections.interfaces.IValueIterator;

/**
 * The IBPlusTree interface defines a B+ tree.
 */
public interface IBPlusTree<TKey extends Comparable<TKey>, TValue> extends IIterable<IKeyValueNode<TKey, TValue>> {
    /**
     * Gets the properties of the B+ tree.
     * Complexity: O(1)
     */
    IBPlusTreeProperties<TKey, TValue> getProperties();

    /**
     * Inserts a new key and it's associated value into the B+ tree.
     * Complexity: O(LogN)
     */
    void insert(TKey key, TValue value);

    /**
     * Deletes a key and it's associated value from the tree.
     * Complexity: O(LogN)
     */
    void delete(TKey key);

    /**
     * Searches a key value on the tree and return it's associated value.
     * Complexity: O(LogN)
     */
    TValue search(TKey key);

    /**
     * Gets an iterator of data of a tree.
     * Complexity: O(LogN)
     */
    IIterator<IKeyValueNode<TKey, TValue>> getIterator();

    /**
     * Gets an iterator of keys of a tree.
     * Complexity: O(LogN)
     */
    IKeyIterator<TKey> getKeyIterator();

    /**
     * Gets an iterator of values of a tree.
     * Complexity: O(LogN)
     */
    IValueIterator<TValue> getValueIterator();

    /**
     * Gets the height of a tree.
     * Complexity: O(LogN)
     */
    int getHeight();

    /**
     * Gets levels of a tree.
     * Complexity: O(N)
     */
    IBlockTreeLevels<TKey, INullable> getTreeLevels();

    /**
     * Calculates metrics of a tree.
     * Complexity: O(N)
     */
    IBPlusTreeMetrics calculateMetrics();
}
