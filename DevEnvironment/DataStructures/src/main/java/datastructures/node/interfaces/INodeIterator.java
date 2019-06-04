package datastructures.node.interfaces;

import java.util.Iterator;

/**
 * The INodeIterator interface defines an iterator of a generic node.
 */
public interface INodeIterator<TKey extends Comparable<TKey>, TValue> extends
    Iterable<INode<TKey, TValue>>, Iterator<INode<TKey, TValue>> {
}
