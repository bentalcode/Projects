package datastructures.node.interfaces;

/**
 * The IDoublyLinkedListKeyValueNodeIterator interface defines an iterator of key-value nodes
 * of a doubly linked list.
 */
public interface IDoublyLinkedListKeyValueNodeIterator<TKey extends Comparable<TKey>, TValue> extends
    IKeyValueNodeIterator<TKey, TValue>, IKeyValueNodeReverseIterator<TKey, TValue> {
}
