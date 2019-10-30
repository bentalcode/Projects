package datastructures.tree.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;
import java.util.List;

/**
 * The ITreeLevels interface defines levels of a tree.
 */
public interface ITreeLevels<TKey extends Comparable<TKey>, TValue> extends
    ISizableCollection,
    IIterable<ITreeLevel<TKey, TValue>>,
    IReverseIterable<ITreeLevel<TKey, TValue>>,
    IUnaryComparator<ITreeLevels<TKey, TValue>> {

    /**
     * Gets the levels of a tree.
     */
    List<ITreeLevel<TKey, TValue>> getLevels();
}
