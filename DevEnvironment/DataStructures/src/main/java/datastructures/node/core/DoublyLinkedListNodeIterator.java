package datastructures.node.core;

import base.core.Conditions;
import datastructures.node.interfaces.IDoublyLinkedListNode;
import datastructures.node.interfaces.IDoublyLinkedListNodeIterator;
import datastructures.node.interfaces.INode;
import java.util.Iterator;

/**
 * The DoublyLinkedListNodeIterator class implements an iterator of a node of a doubly linked list.
 */
public final class DoublyLinkedListNodeIterator<TKey extends Comparable<TKey>, TValue>
    implements IDoublyLinkedListNodeIterator<TKey, TValue> {

    private final IDoublyLinkedListNode<TKey, TValue> headNode;
    private IDoublyLinkedListNode<TKey, TValue> currentNode;

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListNodeIterator(IDoublyLinkedListNode<TKey, TValue> headNode) {
        Conditions.validateNotNull(
            headNode,
            "The head node of a doubly linked list.");

        this.headNode = headNode;
    }

    /**
     * Gets an iterator for iterating over nodes.
     */
    @Override
    public Iterator<INode<TKey, TValue>> iterator() {
        this.currentNode = headNode;
        return this;
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.currentNode.getNext() != null;
    }

    /**
     * Gets the next node.
     */
    @Override
    public INode<TKey, TValue> next() {
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the end of list.");

        this.currentNode = this.currentNode.getNext();

        INode<TKey, TValue> currentNode = new Node<>(
            this.currentNode.getKey(),
            this.currentNode.getValue());

        return currentNode;
    }

    /**
     * Checks whether there is a previous node.
     */
    @Override
    public boolean hasPrevious() {
        return this.currentNode.getPrevious() != null;
    }

    /**
     * Gets the previous node.
     */
    @Override
    public INode<TKey, TValue> previous() {
        Conditions.validate(
            this.hasPrevious(),
            "The iterator has already reached the start of list.");

        this.currentNode = this.currentNode.getPrevious();

        INode<TKey, TValue> currentNode = new Node<>(
            this.currentNode.getKey(),
            this.currentNode.getValue());

        return currentNode;
    }

    /**
     * Removes the current node.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException("Removing node from a list is not supported.");
    }
}
