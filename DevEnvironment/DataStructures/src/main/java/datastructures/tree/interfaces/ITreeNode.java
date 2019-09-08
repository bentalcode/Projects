package datastructures.tree.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.Collection;

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
    Collection<ITreeNode<TKey, TValue>> getChildren();

    /**
     * Adds a child to the node.
     */
    void addChild(ITreeNode<TKey, TValue> child);
}
