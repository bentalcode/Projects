package datastructures.collections.interfaces;

import base.interfaces.IIterator;

/**
 * The ISortedCollectionsIterator interface defines an iterator of sorted collections.
 * The iterator returns the next element in the input collections based on the defined sorted order.
 */
public interface ISortedCollectionsIterator<TKey extends Comparable<TKey>> extends IIterator<TKey> {
}
