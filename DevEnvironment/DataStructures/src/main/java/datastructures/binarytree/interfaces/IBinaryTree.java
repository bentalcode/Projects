package datastructures.binarytree.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import base.interfaces.IUnaryComparator;

/**
 * The IBinaryTree interface defines a binary tree.
 */
public interface IBinaryTree<TKey extends Comparable<TKey>, TValue> extends
    IUnaryComparator<IBinaryTree<TKey, TValue>>,
    IIterable<IBinaryTreeNode<TKey, TValue>> {

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

    /**
     * Gets an iterator of a tree.
     */
    IIterator<IBinaryTreeNode<TKey , TValue>> getIterator();

    /**
     * Gets a reverse iterator of a tree.
     */
    IReverseIterator<IBinaryTreeNode<TKey , TValue>> getReverseIterator();

    /**
     * Gets an inorder iterator of a tree.
     */
    IIterator<IBinaryTreeNode<TKey , TValue>> getInorderIterator();

    /**
     * Gets a preorder iterator of a tree.
     */
    IIterator<IBinaryTreeNode<TKey , TValue>> getPreorderIterator();
}
