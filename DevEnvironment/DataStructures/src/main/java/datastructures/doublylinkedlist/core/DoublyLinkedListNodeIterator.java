package datastructures.doublylinkedlist.core;

import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeIterator class implements an iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeIterator<TValue extends Comparable<TValue>>
    implements IIterator<IDoublyLinkedListNode<TValue>> {

    private final IDoublyLinkedListNode<TValue> headNode;
    private IDoublyLinkedListNode<TValue> currentNode;

    /**
     * Creates a new iterator of a doubly linked list.
     */
    public static <TValue extends Comparable<TValue>> IIterator<IDoublyLinkedListNode<TValue>> of(IDoublyLinkedListNode<TValue> headNode) {
        return new DoublyLinkedListNodeIterator<>(headNode);
    }

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListNodeIterator(IDoublyLinkedListNode<TValue> headNode) {
        this.headNode = headNode;

        this.reset();
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.currentNode != null;
    }

    /**
     * Gets the next node.
     */
    @Override
    public IDoublyLinkedListNode<TValue> next() {
        assert(this.hasNext());


        IDoublyLinkedListNode<TValue> currentNode = this.currentNode;
        this.currentNode = this.currentNode.next();

        return currentNode;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currentNode = this.headNode;
    }
}
