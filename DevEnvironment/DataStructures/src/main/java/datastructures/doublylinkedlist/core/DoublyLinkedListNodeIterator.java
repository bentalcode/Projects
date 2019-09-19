package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;

/**
 * The DoublyLinkedListNodeIterator class implements an iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeIterator<TValue extends Comparable<TValue>>
    implements IDoublyLinkedListNodeIterator<TValue> {

    private final IDoublyLinkedListNode<TValue> headNode;
    private IDoublyLinkedListNode<TValue> currentNode;

    /**
     * Creates a new iterator of a list.
     */
    public static <TValue extends Comparable<TValue>> IDoublyLinkedListNodeIterator<TValue> of(
        IDoublyLinkedListNode<TValue> headNode) {

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
