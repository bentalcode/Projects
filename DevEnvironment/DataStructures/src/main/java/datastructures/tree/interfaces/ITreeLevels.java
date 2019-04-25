package datastructures.tree.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The ITreeLevels interface defines levels of a tree.
 */
public interface ITreeLevels<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<ITreeLevels<TKey, TValue>> {
    /**
     * Gets the levels of a tree.
     */
    List<ITreeLevel<TKey, TValue>> getLevels();
}
