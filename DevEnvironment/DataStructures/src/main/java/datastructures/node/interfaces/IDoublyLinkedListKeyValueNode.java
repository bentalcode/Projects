package datastructures.node.interfaces;

/**
 * The IDoublyLinkedListKeyValueNode interface defines a key-value node of a doubly linked list.
 */
public interface IDoublyLinkedListKeyValueNode<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets a key of a node.
     */
    TKey getKey();

    /**
     * Gets a value of a node.
     */
    TValue getValue();

    /**
     * Sets a value of a node.
     */
    void setValue(TValue value);

    /**
     * Gets a next node.
     */
    IDoublyLinkedListKeyValueNode<TKey, TValue> next();

    /**
     * Gets a previous node.
     */
    IDoublyLinkedListKeyValueNode<TKey, TValue> previous();
}