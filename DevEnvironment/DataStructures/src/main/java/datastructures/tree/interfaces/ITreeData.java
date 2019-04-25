package datastructures.tree.interfaces;

import java.util.List;

/**
 * The ITreeData interface defines a data of a tree.
 */
public interface ITreeData<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets an iterator of a tree.
     */
    ITreeDataIterator<TKey, TValue> getIterator();

    /**
     * Gets the data of nodes of a tree.
     */
    List<ITreeNodeData<TKey, TValue>> getNodesData();
}
