package datastructures.collections.interfaces;

import base.interfaces.IIterator;

/**
 * The IKeyIterator interface defines an iterator of keys of a collection.
 */
public interface IKeyIterator<TKey extends Comparable<TKey>> extends IIterator<TKey> {
}
