package datastructures.blocktree.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import datastructures.collections.interfaces.ISizableCollection;
import java.util.List;

/**
 * The IBlockTreeLevel interface defines a level of a block tree.
 */
public interface IBlockTreeLevel<TKey extends Comparable<TKey>, TValue> extends
    ISizableCollection,
    IIterable<IBlockTreeNodeData<TKey, TValue>>,
    IReverseIterable<IBlockTreeNodeData<TKey, TValue>>,
    IUnaryComparator<IBlockTreeLevel<TKey, TValue>> {

    /**
     * Gets the data of nodes.
     */
    List<IBlockTreeNodeData<TKey, TValue>> getNodesData();
}
