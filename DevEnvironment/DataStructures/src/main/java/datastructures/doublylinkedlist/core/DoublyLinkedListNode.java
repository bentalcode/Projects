package datastructures.doublylinkedlist.core;

import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNode class implements a node of a doubly linked list.
 */
public final class DoublyLinkedListNode<TValue> implements IDoublyLinkedListNode<TValue> {
    private TValue value;
    private IDoublyLinkedListNode<TValue> previous;
    private IDoublyLinkedListNode<TValue> next;

    /**
     * The DoublyLinkedListNode constructor.
     */
    public DoublyLinkedListNode(TValue value) {
        this(value, null, null);
    }

    /**
     * The DoublyLinkedListNode constructor.
     */
    public DoublyLinkedListNode(
        TValue value,
        IDoublyLinkedListNode<TValue> previous,
        IDoublyLinkedListNode<TValue> next) {

        this.value = value;
        this.previous = previous;
        this.next = next;
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
    public IDoublyLinkedListNode<TValue> previous() {
        return this.previous;
    }

    /**
     * Sets a previous node.
     */
    @Override
    public void setPrevious(IDoublyLinkedListNode<TValue> node) {
        this.previous = node;
    }

    /**
     * Gets a next node.
     */
    @Override
    public IDoublyLinkedListNode<TValue> next() {
        return this.next;
    }

    /**
     * Sets a previous node.
     */
    @Override
    public void setNext(IDoublyLinkedListNode<TValue> node) {
        this.next = node;
    }
}
