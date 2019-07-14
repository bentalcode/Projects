package datastructures.node.interfaces;

import java.util.List;

/**
 * The IKeyValueNodes interface defines a list of generic key-value nodes.
 */
public interface IKeyValueNodes<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets an iterator of a generic node.
     */
    IKeyValueNodeIterator<TKey, TValue> getIterator();

    /**
     * Gets a list of generic nodes.
     */
    List<IKeyValueNode<TKey, TValue>> getNodes();
}
