package datastructures.tree.interfaces;

import base.interfaces.IVisitor;

/**
 * The ITreeTraversal interface defines various traversal in a tree.
 */
public interface ITreeTraversal<TKey extends Comparable<TKey>, TValue> {
    /**
     * Performs a Breadth-First search.
     */
    void breadthFirstSearch(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor);

    /**
     * Performs a Depth-First search.
     */
    void depthFirstSearch(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor);

    /**
     * Performs a Pre-Order search.
     */
    void preOrder(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor);

    /**
     * Performs an In-Order search.
     */
    void inOrder(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor);

    /**
     * Performs an Post-Order search.
     */
    void postOrder(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor);
}
