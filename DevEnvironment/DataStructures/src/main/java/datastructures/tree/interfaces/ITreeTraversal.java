package datastructures.tree.interfaces;

import base.interfaces.IVisitor;

/**
 * The ITreeTraversal interface defines various traversals of a tree.
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
}
