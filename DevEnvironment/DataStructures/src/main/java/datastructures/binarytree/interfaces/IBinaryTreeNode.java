package datastructures.binarytree.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IBinaryTreeNode interface defines a node of a binary tree.
 */
public interface IBinaryTreeNode<TKey extends Comparable<TKey>, TValue>
    extends IUnaryComparator<IBinaryTreeNode<TKey, TValue>> {

    /**
     * Gets the key of the node.
     */
    TKey getKey();

    /**
     * Sets the key of the node.
     */
    void setKey(TKey key);

    /**
     * Gets the value of the node.
     */
    TValue getValue();

    /**
     * Sets the value of the node.
     */
    void setValue(TValue value);

    /**
     * Gets the node of a left child.
     */
    IBinaryTreeNode<TKey, TValue> getLeftChild();

    /**
     * Sets the node of a left child.
     */
    void setLeftChild(IBinaryTreeNode<TKey, TValue> node);

    /**
     * Gets the node of a right child.
     */
    IBinaryTreeNode<TKey, TValue> getRightChild();

    /**
     * Sets the node of a right child.
     */
    void setRightChild(IBinaryTreeNode<TKey, TValue> node);

    /**
     * Checks whether there is a left child.
     */
    boolean hasLeftChild();

    /**
     * Checks whether there is a right child.
     */
    boolean hasRightChild();
}
