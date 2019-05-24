package datastructures.binarytree.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IUnaryComparator;
import datastructures.tree.interfaces.ITreeNode;
import datastructures.tree.interfaces.ITreeTraversal;

/**
 * The IBinaryTree interface defines a binary tree.
 */
public interface IBinaryTree<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<IBinaryTree<TKey, TValue>> {
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

    /**
     * Gets an interface of a tree traversal.
     */
    ITreeTraversal<TKey , TValue> getTreeTraversal(IBinaryComparator<ITreeNode<TKey, TValue>> nodeComparator);
}
