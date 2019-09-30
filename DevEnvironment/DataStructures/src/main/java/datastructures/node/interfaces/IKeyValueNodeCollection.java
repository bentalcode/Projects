package datastructures.node.interfaces;

import base.interfaces.IIterable;
import datastructures.collections.interfaces.IAbstractCollection;

/**
 * The IKeyValueNodeCollection interface defines a collection.
 */
public interface IKeyValueNodeCollection<TKey extends Comparable<TKey>, TValue> extends
    IAbstractCollection,
    IIterable<IKeyValueNode<TKey, TValue>> {
}
