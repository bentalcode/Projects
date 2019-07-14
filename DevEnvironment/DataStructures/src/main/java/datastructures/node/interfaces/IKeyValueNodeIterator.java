package datastructures.node.interfaces;

import java.util.Iterator;

/**
 * The IKeyValueNodeIterator interface defines an iterator of a generic key-value node.
 */
public interface IKeyValueNodeIterator<TKey extends Comparable<TKey>, TValue> extends
    Iterable<IKeyValueNode<TKey, TValue>>, Iterator<IKeyValueNode<TKey, TValue>> {
}
