package datastructures.node.interfaces;

import java.util.List;

/**
 * The INodes interface defines a list of generic nodes.
 */
public interface INodes<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets an iterator of a generic node.
     */
    INodeIterator<TKey, TValue> getIterator();

    /**
     * Gets a list of generic nodes.
     */
    List<INode<TKey, TValue>> getNodes();
}
