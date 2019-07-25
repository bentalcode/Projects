package datastructures.node.interfaces;

import base.interfaces.IReverseIterator;

/**
 * The IKeyValueNodeReverseIterator interface defines a reverse iterator of a generic key-value node.
 */
public interface IKeyValueNodeReverseIterator<TKey extends Comparable<TKey>, TValue> extends
    IReverseIterator<IKeyValueNode<TKey, TValue>> {
}
