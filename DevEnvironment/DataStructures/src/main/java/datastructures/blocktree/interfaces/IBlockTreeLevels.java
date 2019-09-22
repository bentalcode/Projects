package datastructures.blocktree.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The IBlockTreeLevels interface defines levels of a block tree.
 */
public interface IBlockTreeLevels<TKey extends Comparable<TKey>, TValue>
    extends IUnaryComparator<IBlockTreeLevels<TKey, TValue>> {

    /**
     * Gets the levels of a block tree.
     */
    List<IBlockTreeLevel<TKey, TValue>> getLevels();
}
