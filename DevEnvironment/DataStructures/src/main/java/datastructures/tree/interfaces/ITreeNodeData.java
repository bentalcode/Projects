package datastructures.tree.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The ITreeNodeData interface defines data of a node in a tree.
 */
public interface ITreeNodeData<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<ITreeNodeData<TKey, TValue>> {
    /**
     * Gets the key of the node.
     */
    TKey getKey();

    /**
     * Gets the value of the node.
     */
    TValue getValue();
}
