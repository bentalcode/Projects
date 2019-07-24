package datastructures.node.interfaces;

/**
 * The IKeyValueNodeReverseIterator interface defines a reverse iterator of a generic key-value node.
 */
public interface IKeyValueNodeReverseIterator<TKey extends Comparable<TKey>, TValue> {
    /**
     * Checks whether there is a previous node.
     */
    boolean hasPrevious();

    /**
     * Gets the previous node.
     */
    IKeyValueNode<TKey, TValue> previous();
}
