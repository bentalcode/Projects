package datastructures.blocktree.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The IBlockTreeLevel interface defines a level of a block tree.
 */
public interface IBlockTreeLevel<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<IBlockTreeLevel<TKey, TValue>> {
    /**
     * Gets the data of nodes.
     */
    List<IBlockTreeNodeData<TKey, TValue>> getNodesData();
}
