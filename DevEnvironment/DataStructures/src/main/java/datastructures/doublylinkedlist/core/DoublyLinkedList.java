package datastructures.doublylinkedlist.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.collections.core.Collections;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.collections.interfaces.IValueReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeReverseIterator;

/**
 * The DoublyLinkedList class implements a doubly linked list.
 */
public final class DoublyLinkedList<TValue extends Comparable<TValue>> implements IDoublyLinkedList<TValue> {
    private IDoublyLinkedListNode<TValue> head;
    private IDoublyLinkedListNode<TValue> tail;
    private int size;
    private final IBinaryComparator<IDoublyLinkedList<TValue>> comparator;

    /**
     * The DoublyLinkedList constructor.
     */
    public DoublyLinkedList() {
        this(null);
    }

    /**
     * The DoublyLinkedList constructor.
     */
    public DoublyLinkedList(IDoublyLinkedListNode<TValue> head) {
        this(
            head,
            DoublyLinkedList.DefaultComparator());
    }

    /**
     * The DoublyLinkedList constructor.
     */
    public DoublyLinkedList(
        IDoublyLinkedListNode<TValue> head,
        IBinaryComparator<IDoublyLinkedList<TValue>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a doubly linked list.");

        if (head != null) {
            this.addToFront(head);
        }

        this.comparator = comparator;
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
        this.addToFront(DoublyLinkedListNode.of(value));
    }

    /**
     * Adds a new value to the back of the list.
     */
    @Override
    public void addToBack(TValue value) {
        this.addToBack(DoublyLinkedListNode.of(value));
    }

    /**
     * Adds a new value after a specific node of the list.
     */
    @Override
    public void addAfter(IDoublyLinkedListNode<TValue> currNode, TValue valueToAdd) {
        this.addAfter(currNode, DoublyLinkedListNode.of(valueToAdd));
    }

    /**
     * Adds a new value before a specific node of the list.
     */
    @Override
    public void addBefore(IDoublyLinkedListNode<TValue> currNode, TValue nodeToAdd) {
        this.addBefore(currNode, DoublyLinkedListNode.of(nodeToAdd));
    }

    /**
     * Adds a new node to the front of the list.
     */
    @Override
    public void addToFront(IDoublyLinkedListNode<TValue> node) {
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
    public void addToBack(IDoublyLinkedListNode<TValue> node) {
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
        IDoublyLinkedListNode<TValue> currNode,
        IDoublyLinkedListNode<TValue> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node to add after.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node to add.");

        nodeToAdd.unlinked();

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

        nodeToAdd.unlinked();

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
     * Returns the removed node or null if the list is empty.
     */
    @Override
    public IDoublyLinkedListNode<TValue> removeFromFront() {
        if (this.head == null) {
            assert(this.tail == null && this.empty());
            return null;
        }

        IDoublyLinkedListNode<TValue> nodeToRemove = this.head;
        this.remove(nodeToRemove);

        return nodeToRemove;
    }

    /**
     * Removes the back node from the list.
     * Returns the removed node or null if the list is empty.
     */
    @Override
    public IDoublyLinkedListNode<TValue> removeFromBack() {
        if (this.tail == null) {
            assert(this.head == null && this.empty());
            return null;
        }

        IDoublyLinkedListNode<TValue> nodeToRemove = this.tail;

        this.remove(nodeToRemove);

        return nodeToRemove;
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
     * Clears the list
     */
    @Override
    public void clear() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    /**
     * Gets an iterator of nodes of a list.
     */
    @Override
    public IDoublyLinkedListNodeIterator<TValue> getIterator() {
        return new DoublyLinkedListNodeIterator<>(this.head);
    }

    /**
     * Gets an iterator of values of a list.
     */
    @Override
    public IValueIterator<TValue> getValueIterator() {
        return new DoublyLinkedListNodeValueIterator<>(this.getIterator());
    }

    /**
     * Gets a reverse iterator of nodes of a list.
     */
    @Override
    public IDoublyLinkedListNodeReverseIterator<TValue> getReverseIterator() {
        return new DoublyLinkedListNodeReverseIterator<>(this.tail);
    }

    /**
     * Gets a reverse iterator of values of a list.
     */
    @Override
    public IValueReverseIterator<TValue> getValueReverseIterator() {
        return new DoublyLinkedListNodeValueReverseIterator<>(this.getReverseIterator());
    }

    /**
     * Gets a specific node by index. [0, 1, 2, ... , size -1]
     */
    @Override
    public IDoublyLinkedListNode<TValue> getNode(int index) {
        Conditions.validate(
            index >= 0 && index < this.size(),
            "Invalid index.");

        IDoublyLinkedListNode<TValue> currNode = this.head;

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
    public boolean isEqual(IDoublyLinkedList<TValue> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    public int compareTo(IDoublyLinkedList<TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TValue extends Comparable<TValue>> IBinaryComparator<IDoublyLinkedList<TValue>> DefaultComparator() {
        IBinaryComparator<IDoublyLinkedListNode<TValue>> nodeComparator = DoublyLinkedListNode.DefaultComparator();
        return new DoublyLinkedList.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a doubly linked list.
     */
    public static final class Comparator<TValue extends Comparable<TValue>>
        extends AbstractBinaryComparator<IDoublyLinkedList<TValue>> {

        private final IBinaryComparator<IDoublyLinkedListNode<TValue>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IDoublyLinkedListNode<TValue>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a node of a doubly linked list.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IDoublyLinkedList<TValue> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IDoublyLinkedList<TValue> lhs, IDoublyLinkedList<TValue> rhs) {
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
        public int compareTo(IDoublyLinkedList<TValue> lhs, IDoublyLinkedList<TValue> rhs) {
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
     * Node removed.
     */
    private void nodeRemoved(IDoublyLinkedListNode<TValue> node) {
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
