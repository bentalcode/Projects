package datastructures.doublylinkedlist.core;

import testbase.core.Conditions;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;
import java.util.Iterator;

/**
 * The DoublyLinkedListNodeIterator class implements an iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeIterator<TValue> implements IDoublyLinkedListNodeIterator<TValue> {

    private final IDoublyLinkedListNode<TValue> headNode;
    private IDoublyLinkedListNode<TValue> currentNode;

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListNodeIterator(IDoublyLinkedListNode<TValue> headNode) {
        Conditions.validateNotNull(
            headNode,
            "The head node of a doubly linked list.");

        this.headNode = headNode;
        this.reset();
    }

    /**
     * Gets an iterator for iterating over nodes.
     */
    @Override
    public Iterator<IDoublyLinkedListNode<TValue>> iterator() {
        this.reset();
        return this;
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
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the end of list.");


        IDoublyLinkedListNode<TValue> currentNode = this.currentNode;
        this.currentNode = this.currentNode.next();

        return currentNode;
    }

    /**
     * Checks whether there is a previous node.
     */
    @Override
    public boolean hasPrevious() {
        return this.currentNode.previous() != null;
    }

    /**
     * Gets the previous node.
     */
    @Override
    public IDoublyLinkedListNode<TValue> previous() {
        Conditions.validate(
            this.hasPrevious(),
            "The iterator has already reached the start of list.");

        IDoublyLinkedListNode<TValue> currentNode = this.currentNode;
        this.currentNode = this.currentNode.previous();

        return currentNode;
    }

    /**
     * Resets an iterator.
     */
    private void reset() {
        this.currentNode = this.headNode;
    }
}
