package datastructures.linkedlist.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.core.Collections;
import datastructures.linkedlist.interfaces.ILinkedList;
import datastructures.linkedlist.interfaces.ILinkedListNode;

/**
 * The LinkedList class implements a linked list.
 */
public final class LinkedList<T extends Comparable<T>> implements ILinkedList<T> {
    private ILinkedListNode<T> head;
    private ILinkedListNode<T> tail;
    private int size;
    private final IBinaryComparator<ILinkedList<T>> comparator;

    /**
     * The LinkedList constructor.
     */
    public LinkedList() {
        this(null);
    }

    /**
     * The LinkedList constructor.
     */
    private LinkedList(ILinkedListNode<T> head) {
        this(
            head,
            LinkedList.defaultComparator());
    }

    /**
     * The LinkedList constructor.
     */
    private LinkedList(
        ILinkedListNode<T> head,
        IBinaryComparator<ILinkedList<T>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a linked list.");

        if (head != null) {
            this.addToFront(head);
        }

        this.comparator = comparator;
    }

    /**
     * Gets the head node of the list.
     */
    @Override
    public ILinkedListNode<T> getHead() {
        return this.head;
    }

    /**
     * Gets the tail node of the list.
     */
    @Override
    public ILinkedListNode<T> getTail() {
        return this.tail;
    }

    /**
     * Gets the size of the list.
     */
    @Override
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
    public void addToFront(T value) {
        this.addToFront(LinkedListNode.of(value));
    }

    /**
     * Adds a new value to the back of the list.
     */
    @Override
    public void addToBack(T value) {
        this.addToBack(LinkedListNode.of(value));
    }

    /**
     * Adds a new value after a specific node of the list.
     */
    @Override
    public void addAfter(ILinkedListNode<T> currNode, T valueToAdd) {
        this.addAfter(currNode, LinkedListNode.of(valueToAdd));
    }

    /**
     * Adds a new node to the front of the list.
     */
    @Override
    public void addToFront(ILinkedListNode<T> node) {
        Conditions.validateNotNull(
            node,
            "The node to add.");

        node.unlinked();

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
    public void addToBack(ILinkedListNode<T> node) {
        Conditions.validateNotNull(
            node,
            "The node to add.");

        node.unlinked();

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
        ILinkedListNode<T> currNode,
        ILinkedListNode<T> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node to add after.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node to add.");

        nodeToAdd.unlinked();

        ILinkedListNode<T> nextNode = currNode.next();

        this.linkedNodes(currNode, nodeToAdd);
        this.linkedNodes(nodeToAdd, nextNode);

        if (this.tail == currNode) {
            this.tail = nodeToAdd;
        }

        this.nodeAdded();
    }

    /**
     * Removes the front node from the list.
     * Returns the removed node or null if the list is empty.
     */
    @Override
    public ILinkedListNode<T> removeFromFront() {
        if (this.head == null) {
            assert(this.tail == null && this.empty());
            return null;
        }

        ILinkedListNode<T> nodeToRemove = this.head;
        ILinkedListNode<T> nextNode = nodeToRemove.next();

        this.head = nextNode;

        if (this.head == null) {
            this.tail = null;
        }

        this.nodeRemoved(nodeToRemove);

        return nodeToRemove;
    }

    /**
     * Removes a node after a specific node of the list.
     */
    @Override
    public void removeAfter(ILinkedListNode<T> currNode) {
        Conditions.validateNotNull(
            currNode,
            "The exiting node to remove after.");

        ILinkedListNode<T> nodeToRemove = currNode.next();

        if (nodeToRemove == null) {
            return;
        }

        ILinkedListNode<T> nextNode = nodeToRemove.next();
        this.linkedNodes(currNode, nextNode);

        if (nextNode == null) {
            this.tail = currNode;
        }

        this.nodeRemoved(nodeToRemove);
    }

    /**
     * Clears the list.
     */
    @Override
    public void clear() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    /**
     * Gets an iterator of nodes.
     */
    @Override
    public IIterator<ILinkedListNode<T>> getIterator() {
        return new LinkedListNodeIterator<>(this.head);
    }

    /**
     * Gets an iterator of values.
     */
    @Override
    public IIterator<T> getValueIterator() {
        return new LinkedListNodeValueIterator<>(this.getIterator());
    }

    /**
     * Gets a specific node by index. [0, 1, 2, ... , size -1]
     */
    @Override
    public ILinkedListNode<T> getNode(int index) {
        Conditions.validate(
            index >= 0 && index < this.size(),
            "Invalid index.");

        ILinkedListNode<T> currNode = this.head;

        int currIndex = 0;

        while (currNode != null) {
            if (currIndex == index) {
                return currNode;
            }

            ++currIndex;
            currNode = currNode.next();
        }

        return currNode;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getValueIterator());
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.comparator.getHashCode(this);
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(ILinkedList<T> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(ILinkedList<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<ILinkedList<T>> defaultComparator() {
        IBinaryComparator<ILinkedListNode<T>> nodeComparator = LinkedListNode.defaultComparator();
        return new LinkedList.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a linked list.
     */
    public static final class Comparator<T extends Comparable<T>>
        extends AbstractBinaryComparator<ILinkedList<T>> {

        private final IBinaryComparator<ILinkedListNode<T>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<ILinkedListNode<T>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a node of a linked list.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ILinkedList<T> obj) {
            return new HashCodeBuilder(577, 587)
                .withIterator(obj.getIterator(), this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ILinkedList<T> lhs, ILinkedList<T> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.nodeComparator)
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(ILinkedList<T> lhs, ILinkedList<T> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.nodeComparator)
                .build();
        }
    }

    /**
     * Linked nodes.
     */
    private void linkedNodes(ILinkedListNode<T> left, ILinkedListNode<T> right) {
        if (left != null) {
            left.setNext(right);
        }
    }

    /**
     * Node removed.
     */
    private void nodeRemoved(ILinkedListNode<T> node) {
        node.unlinked();

        --this.size;
    }

    /**
     * Node added.
     */
    private void nodeAdded() {
        ++this.size;
    }
}
