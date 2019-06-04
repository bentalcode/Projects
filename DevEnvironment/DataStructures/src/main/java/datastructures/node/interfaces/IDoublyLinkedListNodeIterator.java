package datastructures.node.interfaces;

/**
 * The IDoublyLinkedListNodeIterator interface defines an iterator of a doubly linked list node.
 */
public interface IDoublyLinkedListNodeIterator<TKey extends Comparable<TKey>, TValue> extends
    INodeIterator<TKey, TValue> {

    /**
     * Checks whether there is a previous node.
     */
    boolean hasPrevious();

    /**
     * Gets the previous node.
     */
    INode<TKey, TValue> previous();
}
