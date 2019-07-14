package datastructures.node.interfaces;

/**
 * The IDoublyLinkedListKeyValueNodeIterator interface defines an iterator of key-value nodes
 * of a doubly linked list.
 */
public interface IDoublyLinkedListKeyValueNodeIterator<TKey extends Comparable<TKey>, TValue> extends
        IKeyValueNodeIterator<TKey, TValue> {

    /**
     * Checks whether there is a previous node.
     */
    boolean hasPrevious();

    /**
     * Gets the previous node.
     */
    IKeyValueNode<TKey, TValue> previous();
}
