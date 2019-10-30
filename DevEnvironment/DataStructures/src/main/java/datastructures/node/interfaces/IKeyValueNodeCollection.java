package datastructures.node.interfaces;

import base.interfaces.IIterable;
import base.interfaces.ISizableCollection;

/**
 * The IKeyValueNodeCollection interface defines a collection.
 */
public interface IKeyValueNodeCollection<TKey extends Comparable<TKey>, TValue> extends
    ISizableCollection,
    IIterable<IKeyValueNode<TKey, TValue>> {
}
