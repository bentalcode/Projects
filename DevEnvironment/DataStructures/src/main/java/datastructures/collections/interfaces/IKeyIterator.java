package datastructures.collections.interfaces;

import java.util.Iterator;

/**
 * The IKeyIterator interface defines an iterator of keys of a collection.
 */
public interface IKeyIterator<TKey extends Comparable<TKey>> extends Iterable<TKey>, Iterator<TKey> {
}
