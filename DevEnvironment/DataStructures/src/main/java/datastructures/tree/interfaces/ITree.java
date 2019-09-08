package datastructures.tree.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IUnaryComparator;

/**
 * The ITreeNode interface defines a generic tree.
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
    ITreeTraversal<TKey, TValue> getTreeTraversal();

    /**
     * Gets an interface of a tree traversal.
     */
    ITreeTraversal<TKey , TValue> getTreeTraversal(IBinaryComparator<ITreeNode<TKey, TValue>> nodeComparator);
}
