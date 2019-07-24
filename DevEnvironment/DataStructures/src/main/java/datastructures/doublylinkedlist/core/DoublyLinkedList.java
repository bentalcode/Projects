package datastructures.doublylinkedlist.core;

import datastructures.collections.core.Collections;
import testbase.core.Conditions;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;

/**
 * The DoublyLinkedList class implements a doubly linked list.
 */
public final class DoublyLinkedList<TValue> implements IDoublyLinkedList<TValue> {
    private IDoublyLinkedListNode<TValue> head;
    private IDoublyLinkedListNode<TValue> tail;
    private int size;

    /**
     * The DoublyLinkedList constructor.
     */
    public DoublyLinkedList() {
    }

    /**
     * Gets the head node of the list.
     */
    @Override
    public IDoublyLinkedListNode<TValue> getHead() {
        return this.head;
    }

    /**
     * Gets the tail node of the list.
     */
    @Override
    public IDoublyLinkedListNode<TValue> getTail() {
        return this.tail;
    }

    /**
     * Gets the size of the list.
     */
    public int size() {
        return this.size;
    }

    /**
     * Checks whether the list is empty.
     */
    @Override
    public boolean empty() {
        return this.size == 0;
    }

    /**
     * Adds a new value to the front of the list.
     */
    @Override
    public void addToFront(TValue value) {
        this.addToFront(new DoublyLinkedListNode<>(value));
    }

    /**
     * Adds a new value to the back of the list.
     */
    @Override
    public void addToBack(TValue value) {
        this.addToBack(new DoublyLinkedListNode<>(value));
    }

    /**
     * Adds a new value after a specific node of the list.
     */
    @Override
    public void addAfter(IDoublyLinkedListNode<TValue> currNode, TValue valueToAdd) {
        this.addAfter(currNode, new DoublyLinkedListNode<>(valueToAdd));
    }

    /**
     * Adds a new value before a specific node of the list.
     */
    @Override
    public void addBefore(IDoublyLinkedListNode<TValue> currNode, TValue nodeToAdd) {
        this.addBefore(currNode, new DoublyLinkedListNode<>(nodeToAdd));
    }

    /**
     * Adds a new node to the front of the list.
     */
    @Override
    public void addToFront(IDoublyLinkedListNode<TValue> node) {
        Conditions.validateNotNull(
            node,
            "The node to add.");

        this.unlinkedNode(node);

        if (this.head == null) {
            assert(this.tail == null && this.empty());

            this.head = node;
            this.tail = node;
        }
        else {
            this.linkedNodes(node, this.head);

            this.head = node;
        }

        this.nodeAdded();
    }

    /**
     * Adds a new node to the back of the list.
     */
    @Override
    public void addToBack(IDoublyLinkedListNode<TValue> node) {
        Conditions.validateNotNull(
            node,
            "The node to add.");

        this.unlinkedNode(node);

        if (this.tail == null) {
            assert(this.head == null && this.empty());

            this.head = node;
            this.tail = node;
        }
        else {
            this.linkedNodes(this.tail, node);

            this.tail = node;
        }

        this.nodeAdded();
    }

    /**
     * Adds a new node after a specific node of the list.
     */
    @Override
    public void addAfter(
        IDoublyLinkedListNode<TValue> currNode,
        IDoublyLinkedListNode<TValue> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node to add after.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node to add.");

        this.unlinkedNode(nodeToAdd);

        IDoublyLinkedListNode<TValue> nextNode = currNode.next();

        this.linkedNodes(currNode, nodeToAdd);
        this.linkedNodes(nodeToAdd, nextNode);

        if (this.tail == currNode) {
            this.tail = nodeToAdd;
        }

        this.nodeAdded();
    }

    /**
     * Adds a new node before a specific node of the list.
     */
    @Override
    public void addBefore(
        IDoublyLinkedListNode<TValue> currNode,
        IDoublyLinkedListNode<TValue> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node to add before.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node to add.");

        this.unlinkedNode(nodeToAdd);

        IDoublyLinkedListNode<TValue> previousNode = currNode.previous();

        this.linkedNodes(previousNode, nodeToAdd);
        this.linkedNodes(nodeToAdd, currNode);

        if (this.head == currNode) {
            this.head = nodeToAdd;
        }

        this.nodeAdded();
    }

    /**
     * Removes the front node from the list.
     */
    @Override
    public void removeFromFront() {
        if (this.head == null) {
            assert(this.tail == null && this.empty());
            return;
        }

        IDoublyLinkedListNode<TValue> nodeToRemove = this.head;
        this.remove(nodeToRemove);
    }

    /**
     * Removes the back node from the list.
     */
    @Override
    public void removeFromBack() {
        if (this.tail == null) {
            assert(this.head == null && this.empty());
            return;
        }

        IDoublyLinkedListNode<TValue> nodeToRemove = this.tail;

        this.remove(nodeToRemove);
    }

    /**
     * Removes the a node from the list.
     */
    @Override
    public void remove(IDoublyLinkedListNode<TValue> nodeToRemove) {
        Conditions.validateNotNull(
            nodeToRemove,
            "The node to remove.");

        IDoublyLinkedListNode<TValue> previousNode = nodeToRemove.previous();
        IDoublyLinkedListNode<TValue> nextNode = nodeToRemove.next();

        this.linkedNodes(previousNode, nextNode);

        if (previousNode == null) {
            this.head = nextNode;
        }

        if (nextNode == null) {
            this.tail = previousNode;
        }

        this.nodeRemoved(nodeToRemove);
    }

    /**
     * Gets an iterator of nodes of a list.
     */
    @Override
    public IDoublyLinkedListNodeIterator<TValue> getIterator() {
        return new DoublyLinkedListNodeIterator<>(this.head);
    }

    /**
     * Gets a reverse iterator of nodes of a list.
     */
    @Override
    public IDoublyLinkedListNodeIterator<TValue> getReverseIterator() {
        return new DoublyLinkedListNodeReverseIterator<>(this.tail);
    }

    /**
     * Gets an iterator of values of a list.
     */
    @Override
    public IValueIterator<TValue> getValueIterator() {
        return new DoublyLinkedListNodeValueIterator<>(this.getIterator());
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getValueIterator());
    }

    /**
     * Linked nodes.
     */
    private void linkedNodes(IDoublyLinkedListNode<TValue> left, IDoublyLinkedListNode<TValue> right) {
        if (left != null) {
            left.setNext(right);
        }

        if (right != null) {
            right.setPrevious(left);
        }
    }

    /**
     * Unlinked node.
     */
    private void unlinkedNode(IDoublyLinkedListNode<TValue> node) {
        node.setNext(null);
        node.setPrevious(null);
    }

    /**
     * Node removed.
     */
    private void nodeRemoved(IDoublyLinkedListNode<TValue> node) {
        this.unlinkedNode(node);

        --this.size;
    }

    /**
     * Node added.
     */
    private void nodeAdded() {
        ++this.size;
    }
}
