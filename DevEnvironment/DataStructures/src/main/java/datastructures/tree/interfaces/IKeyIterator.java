package datastructures.tree.interfaces;

import java.util.Iterator;

/**
 * The IKeyIterator interface defines an iterator of keys of a tree.
 */
public interface IKeyIterator<TKey extends Comparable<TKey>> extends Iterator<TKey>, Iterable<TKey> {
}
