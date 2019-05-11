package datastructures.tree.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The ITreeNode interface defines a node in a tree.
 */
public interface ITree<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<ITree<TKey, TValue>> {
    /**
     * Gets a root of a tree.
     */
    ITreeNode<TKey, TValue> getRoot();

    /**
     * Sets a root of a tree.
     */
    void setRoot(ITreeNode<TKey, TValue> root);

    /**
     * Gets an interface of a tree traversal.
     */
    ITreeTraversal getTreeTraversal();
}