package datastructures.linkedlist.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import datastructures.collections.core.Collections;
import datastructures.linkedlist.interfaces.ILinkedList;
import datastructures.linkedlist.interfaces.ILinkedListNode;

/**
 * The LinkedList class implements a linked list.
 */
public final class LinkedList<TValue extends Comparable<TValue>> implements ILinkedList<TValue> {
    private ILinkedListNode<TValue> head;
    private ILinkedListNode<TValue> tail;
    private int size;
    private final IBinaryComparator<ILinkedList<TValue>> comparator;

    /**
     * The LinkedList constructor.
     */
    public LinkedList() {
        this(null);
    }

    /**
     * The LinkedList constructor.
     */
    private LinkedList(ILinkedListNode<TValue> head) {
        this(
            head,
            LinkedList.defaultComparator());
    }

    /**
     * The LinkedList constructor.
     */
    private LinkedList(
        ILinkedListNode<TValue> head,
        IBinaryComparator<ILinkedList<TValue>> comparator) {

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
    public ILinkedListNode<TValue> getHead() {
        return this.head;
    }

    /**
     * Gets the tail node of the list.
     */
    @Override
    public ILinkedListNode<TValue> getTail() {
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
        this.addToFront(LinkedListNode.of(value));
    }

    /**
     * Adds a new value to the back of the list.
     */
    @Override
    public void addToBack(TValue value) {
        this.addToBack(LinkedListNode.of(value));
    }

    /**
     * Adds a new value after a specific node of the list.
     */
    @Override
    public void addAfter(ILinkedListNode<TValue> currNode, TValue valueToAdd) {
        this.addAfter(currNode, LinkedListNode.of(valueToAdd));
    }

    /**
     * Adds a new node to the front of the list.
     */
    @Override
    public void addToFront(ILinkedListNode<TValue> node) {
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
    public void addToBack(ILinkedListNode<TValue> node) {
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
        ILinkedListNode<TValue> currNode,
        ILinkedListNode<TValue> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node to add after.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node to add.");

        nodeToAdd.unlinked();

        ILinkedListNode<TValue> nextNode = currNode.next();

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
    public ILinkedListNode<TValue> removeFromFront() {
        if (this.head == null) {
            assert(this.tail == null && this.empty());
            return null;
        }

        ILinkedListNode<TValue> nodeToRemove = this.head;
        ILinkedListNode<TValue> nextNode = nodeToRemove.next();

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
    public void removeAfter(ILinkedListNode<TValue> currNode) {
        Conditions.validateNotNull(
            currNode,
            "The exiting node to remove after.");

        ILinkedListNode<TValue> nodeToRemove = currNode.next();

        if (nodeToRemove == null) {
            return;
        }

        ILinkedListNode<TValue> nextNode = nodeToRemove.next();
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
    public IIterator<ILinkedListNode<TValue>> getIterator() {
        return new LinkedListNodeIterator<>(this.head);
    }

    /**
     * Gets an iterator of values.
     */
    @Override
    public IIterator<TValue> getValueIterator() {
        return new LinkedListNodeValueIterator<>(this.getIterator());
    }

    /**
     * Gets a specific node by index. [0, 1, 2, ... , size -1]
     */
    @Override
    public ILinkedListNode<TValue> getNode(int index) {
        Conditions.validate(
            index >= 0 && index < this.size(),
            "Invalid index.");

        ILinkedListNode<TValue> currNode = this.head;

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
    public boolean isEqual(ILinkedList<TValue> other) {
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
    public int compareTo(ILinkedList<TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TValue extends Comparable<TValue>> IBinaryComparator<ILinkedList<TValue>> defaultComparator() {
        IBinaryComparator<ILinkedListNode<TValue>> nodeComparator = LinkedListNode.defaultComparator();
        return new LinkedList.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a linked list.
     */
    public static final class Comparator<TValue extends Comparable<TValue>>
        extends AbstractBinaryComparator<ILinkedList<TValue>> {

        private final IBinaryComparator<ILinkedListNode<TValue>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<ILinkedListNode<TValue>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a node of a linked list.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ILinkedList<TValue> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ILinkedList<TValue> lhs, ILinkedList<TValue> rhs) {
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
        public int compareTo(ILinkedList<TValue> lhs, ILinkedList<TValue> rhs) {
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
    private void linkedNodes(ILinkedListNode<TValue> left, ILinkedListNode<TValue> right) {
        if (left != null) {
            left.setNext(right);
        }
    }

    /**
     * Node removed.
     */
    private void nodeRemoved(ILinkedListNode<TValue> node) {
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
