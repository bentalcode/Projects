package datastructures.node.core;

import base.core.Conditions;
import datastructures.node.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNode class implements a node of a doubly linked list.
 */
public final class DoublyLinkedListNode<TKey extends Comparable<TKey>, TValue> implements IDoublyLinkedListNode<TKey, TValue> {
    private final TKey key;
    private TValue value;
    private IDoublyLinkedListNode<TKey, TValue> previous;
    private IDoublyLinkedListNode<TKey, TValue> next;

    /**
     * The DoublyLinkedListNode constructor.
     */
    public DoublyLinkedListNode(TKey key, TValue value) {
        this(key, value, null, null);
    }

    /**
     * The DoublyLinkedListNode constructor.
     */
    public DoublyLinkedListNode(
        TKey key,
        TValue value,
        IDoublyLinkedListNode<TKey, TValue> previous,
        IDoublyLinkedListNode<TKey, TValue> next) {

        Conditions.validateNotNull(
            key,
            "The key of a node of a doubly linked list.");

        this.key = key;
        this.value = value;
        this.previous = previous;
        this.next = next;
    }

    /**
     * Gets a key of a node.
     */
    @Override
    public TKey getKey() {
        return this.key;
    }

    /**
     * Gets a value of a node.
     */
    @Override
    public TValue getValue() {
        return this.value;
    }

    /**
     * Sets a value of a node.
     */
    @Override
    public void setValue(TValue value) {
        this.value = value;
    }

    /**
     * Gets a previous node.
     */
    @Override
    public IDoublyLinkedListNode<TKey, TValue> getPrevious() {
        return this.previous;
    }

    /**
     * Gets a next node.
     */
    @Override
    public IDoublyLinkedListNode<TKey, TValue> getNext() {
        return this.next;
    }
}
