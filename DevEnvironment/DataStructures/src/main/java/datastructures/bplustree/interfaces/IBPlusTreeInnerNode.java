package datastructures.bplustree.interfaces;

import java.util.List;

/**
 * The IBPlusTreeInnerNode interface defines an inner node in a B+ Tree.
 */
public interface IBPlusTreeInnerNode<TKey extends Comparable<TKey>> extends IBPlusTreeNode<TKey> {
    /**
     * Gets a child by index.
     */
    IBPlusTreeNode<TKey> getChild(int index);

    /**
     * Gets the children.
     */
    List<IBPlusTreeNode<TKey>> getChildren();

    /**
     * Sets a child by index.
     */
    void setChild(int index, IBPlusTreeNode<TKey> child);

    /**
     * Inserts a node at specific index.
     */
    void insertAt(
        int index,
        TKey key,
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild);

    /**
     * Deletes at a specific index.
     */
    void deleteAt(int index);
}