package datastructures.binarytree.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IBinaryTree interface defines a binary tree.
 */
public interface IBinaryTree<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<IBinaryTree<TKey, TValue>> {
    /**
     * Gets a root of a tree.
     */
    IBinaryTreeNode<TKey, TValue> getRoot();

    /**
     * Sets a root of a tree.
     */
    void setRoot(IBinaryTreeNode<TKey, TValue> root);

    /**
     * Gets an interface of a tree traversal.
     */
    IBinaryTreeTraversal<TKey , TValue> getTreeTraversal();
}
