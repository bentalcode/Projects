package datastructures.tree.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The ITreeNode interface defines a node in a tree.
 */
public interface ITreeNode<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<ITreeNode<TKey, TValue>> {
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
     * Gets the children of the node.
     */
    List<ITreeNode<TKey, TValue>> getChildren();

    /**
     * Sets the children of the node.
     */
    void setChildren(List<ITreeNode<TKey, TValue>> children);
}
