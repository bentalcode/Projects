package datastructures.node.interfaces;

/**
 * The IDoublyLinkedListNode interface defines a node of a doubly linked list.
 */
public interface IDoublyLinkedListNode<TKey extends Comparable<TKey>, TValue> {
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
    IDoublyLinkedListNode<TKey, TValue> getNext();

    /**
     * Gets a previous node.
     */
    IDoublyLinkedListNode<TKey, TValue> getPrevious();
}