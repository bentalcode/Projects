package datastructures.blocktree.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The IBlockTreeNodeData interface defines data of a block-node in a tree.
 */
public interface IBlockTreeNodeData<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<IBlockTreeNodeData<TKey, TValue>> {
    /**
     * Gets the keys of the node.
     */
    List<TKey> getKeys();

    /**
     * Gets the values of the node.
     */
    List<TValue> getValues();
}
