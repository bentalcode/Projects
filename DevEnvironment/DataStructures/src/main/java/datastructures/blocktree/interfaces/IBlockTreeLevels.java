package datastructures.blocktree.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import datastructures.collections.interfaces.ISizableCollection;
import java.util.List;

/**
 * The IBlockTreeLevels interface defines levels of a block tree.
 */
public interface IBlockTreeLevels<TKey extends Comparable<TKey>, TValue> extends
    ISizableCollection,
    IIterable<IBlockTreeLevel<TKey, TValue>>,
    IReverseIterable<IBlockTreeLevel<TKey, TValue>>,
    IUnaryComparator<IBlockTreeLevels<TKey, TValue>> {

    /**
     * Gets the levels of a block tree.
     */
    List<IBlockTreeLevel<TKey, TValue>> getLevels();
}
