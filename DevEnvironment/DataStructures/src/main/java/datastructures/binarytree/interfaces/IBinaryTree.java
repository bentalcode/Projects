package datastructures.binarytree.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import datastructures.collections.interfaces.ICollection;

/**
 * The IBinaryTree interface defines a binary tree.
 */
public interface IBinaryTree<TKey extends Comparable<TKey>, TValue> extends
    ICollection,
    IIterable<IBinaryTreeNode<TKey, TValue>>,
    IReverseIterable<IBinaryTreeNode<TKey, TValue>>,
    IUnaryComparator<IBinaryTree<TKey, TValue>> {

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
     * Gets an inorder iterator of a tree.
     */
    IIterator<IBinaryTreeNode<TKey , TValue>> getInorderIterator();

    /**
     * Gets a preorder iterator of a tree.
     */
    IIterator<IBinaryTreeNode<TKey , TValue>> getPreorderIterator();

    /**
     * Gets a postorder iterator of a tree.
     */
    IIterator<IBinaryTreeNode<TKey , TValue>> getPostorderIterator();
}
