package datastructures.tree.interfaces;

import java.util.Iterator;

/**
 * The ITreeDataIterator interface defines an iterator of data of a tree.
 */
public interface ITreeDataIterator<TKey extends Comparable<TKey>, TValue> extends
    Iterator<ITreeNodeData<TKey, TValue>>, Iterable<ITreeNodeData<TKey, TValue>> {
}
