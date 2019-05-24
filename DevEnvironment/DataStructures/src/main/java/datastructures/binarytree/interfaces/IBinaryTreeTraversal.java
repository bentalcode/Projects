package datastructures.binarytree.interfaces;

import base.interfaces.IVisitor;

/**
 * The IBinaryTreeTraversal interface defines various traversal in a binary tree.
 */
public interface IBinaryTreeTraversal<TKey extends Comparable<TKey>, TValue> {
    /**
     * Performs a Breadth-First search.
     */
    void breadthFirstSearch(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor);

    /**
     * Performs a Depth-First search.
     */
    void depthFirstSearch(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor);

    /**
     * Performs a Pre-Order search.
     */
    void preOrder(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor);

    /**
     * Performs an In-Order search.
     */
    void inOrder(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor);

    /**
     * Performs an Post-Order search.
     */
    void postOrder(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor);
}
