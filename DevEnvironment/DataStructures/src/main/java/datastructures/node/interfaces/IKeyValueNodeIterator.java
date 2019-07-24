package datastructures.node.interfaces;

import base.interfaces.IIterator;

/**
 * The IKeyValueNodeIterator interface defines an iterator of a generic key-value node.
 */
public interface IKeyValueNodeIterator<TKey extends Comparable<TKey>, TValue>
    extends IIterator<IKeyValueNode<TKey, TValue>> {
}
