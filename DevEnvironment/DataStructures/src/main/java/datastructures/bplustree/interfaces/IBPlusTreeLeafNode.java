package datastructures.bplustree.interfaces;

/**
 * The IBPlusTreeLeafNode interface defines a leaf node in a B+ Tree.
 */
public interface IBPlusTreeLeafNode<TKey extends Comparable<TKey>, TValue> extends IBPlusTreeNode<TKey> {
    /**
     * Gets a value of the node.
     */
    TValue getValue(int index);

    /**
     * Sets a value of the node.
     */
    void setValue(int index, TValue value);

    /**
     * Inserts a key at specific index.
     */
    void insert(TKey key, TValue value);

    /**
     * Deletes the key.
     */
    boolean delete(TKey key);

    /**
     * Inserts a node at specific index.
     */
    void insertAt(
        int index,
        TKey key,
        TValue value);

    /**
     * Deletes the node at specific index.
     */
    void deleteAt(int index);
}