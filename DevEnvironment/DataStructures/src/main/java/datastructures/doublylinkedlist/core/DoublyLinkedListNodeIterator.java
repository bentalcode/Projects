package datastructures.doublylinkedlist.core;

import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeIterator class implements an iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeIterator<T extends Comparable<T>>
    implements IIterator<IDoublyLinkedListNode<T>> {

    private final IDoublyLinkedListNode<T> headNode;
    private IDoublyLinkedListNode<T> currentNode;

    /**
     * Creates a new iterator of a doubly linked list.
     */
    public static <T extends Comparable<T>> IIterator<IDoublyLinkedListNode<T>> of(IDoublyLinkedListNode<T> headNode) {
        return new DoublyLinkedListNodeIterator<>(headNode);
    }

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListNodeIterator(IDoublyLinkedListNode<T> headNode) {
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
    public IDoublyLinkedListNode<T> next() {
        assert(this.hasNext());


        IDoublyLinkedListNode<T> currentNode = this.currentNode;
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
