package datastructures.tree.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The ITreeLevel interface defines a level of a tree.
 */
public interface ITreeLevel<TKey extends Comparable<TKey>, TValue> extends
    ISizableCollection,
    IIterable<IKeyValueNode<TKey, TValue>>,
    IReverseIterable<IKeyValueNode<TKey, TValue>>,
    IUnaryComparator<ITreeLevel<TKey, TValue>> {

    /**
     * Gets the data of nodes.
     */
    List<IKeyValueNode<TKey, TValue>> getNodesData();
}
