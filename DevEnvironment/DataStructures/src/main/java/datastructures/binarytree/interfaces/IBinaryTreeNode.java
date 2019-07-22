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
     * Gets the value of the node.
     */
    TValue getValue();

    /**
     * Sets the value of the node.
     */
    void setValue(TValue value);

    /**
     * Gets the left node.
     */
    IBinaryTreeNode<TKey, TValue> getLeftChild();

    /**
     * Gets the right node.
     */
    IBinaryTreeNode<TKey, TValue> getRightChild();

    /**
     * Sets the left node.
     */
    void setLeftChild(IBinaryTreeNode<TKey, TValue> node);

    /**
     * Sets the right node.
     */
    void setRightChild(IBinaryTreeNode<TKey, TValue> node);
}
