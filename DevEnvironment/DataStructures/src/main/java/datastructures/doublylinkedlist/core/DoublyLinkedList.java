package datastructures.doublylinkedlist.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import base.core.Collections;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedList class implements a doubly linked list.
 */
public final class DoublyLinkedList<T extends Comparable<T>> implements IDoublyLinkedList<T> {
    private IDoublyLinkedListNode<T> head;
    private IDoublyLinkedListNode<T> tail;
    private int size;
    private final IBinaryComparator<IDoublyLinkedList<T>> comparator;

    /**
     * The DoublyLinkedList constructor.
     */
    public DoublyLinkedList() {
        this(null);
    }

    /**
     * The DoublyLinkedList constructor.
     */
    private DoublyLinkedList(IDoublyLinkedListNode<T> head) {
        this(
            head,
            DoublyLinkedList.defaultComparator());
    }

    /**
     * The DoublyLinkedList constructor.
     */
    private DoublyLinkedList(
        IDoublyLinkedListNode<T> head,
        IBinaryComparator<IDoublyLinkedList<T>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a doubly linked list.");

        this.comparator = comparator;

        IDoublyLinkedListNode<T> currNode = head;

        while (currNode != null) {
            IDoublyLinkedListNode<T> nextNode = currNode.next();
            this.addToBack(currNode);

            currNode = nextNode;
        }
    }

    /**
     * Gets the head node of the list.
     */
    @Override
    public IDoublyLinkedListNode<T> getHead() {
        return this.head;
    }

    /**
     * Gets the tail node of the list.
     */
    @Override
    public IDoublyLinkedListNode<T> getTail() {
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
        this.addToFront(DoublyLinkedListNode.make(value));
    }

    /**
     * Adds a new value to the back of the list.
     */
    @Override
    public void addToBack(T value) {
        this.addToBack(DoublyLinkedListNode.make(value));
    }

    /**
     * Adds a new value after a specific node of the list.
     */
    @Override
    public void addAfter(IDoublyLinkedListNode<T> currNode, T valueToAdd) {
        this.addAfter(currNode, DoublyLinkedListNode.make(valueToAdd));
    }

    /**
     * Adds a new value before a specific node of the list.
     */
    @Override
    public void addBefore(IDoublyLinkedListNode<T> currNode, T nodeToAdd) {
        this.addBefore(currNode, DoublyLinkedListNode.make(nodeToAdd));
    }

    /**
     * Adds a new node to the front of the list.
     */
    @Override
    public void addToFront(IDoublyLinkedListNode<T> node) {
        Conditions.validateNotNull(
            node,
            "The node for adding.");

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
    public void addToBack(IDoublyLinkedListNode<T> node) {
        Conditions.validateNotNull(
            node,
            "The node for adding.");

        node.unlinked();

        if (this.tail == null) {
            assert(this.head == null && this.empty());
            this.head = node;
        }
        else {
            this.linkedNodes(this.tail, node);
        }

        this.tail = node;

        this.nodeAdded();
    }

    /**
     * Adds a new node after a specific node of the list.
     */
    @Override
    public void addAfter(
        IDoublyLinkedListNode<T> currNode,
        IDoublyLinkedListNode<T> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node for adding after.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node for adding.");

        nodeToAdd.unlinked();

        IDoublyLinkedListNode<T> nextNode = currNode.next();

        this.linkedNodes(currNode, nodeToAdd);

        if (nextNode != null)
        {
            this.linkedNodes(nodeToAdd, nextNode);
        }
        else
        {
            this.tail = nodeToAdd;
        }

        this.nodeAdded();
    }

    /**
     * Adds a new node before a specific node of the list.
     */
    @Override
    public void addBefore(
        IDoublyLinkedListNode<T> currNode,
        IDoublyLinkedListNode<T> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node for adding before.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node for adding.");

        nodeToAdd.unlinked();

        IDoublyLinkedListNode<T> previousNode = currNode.previous();

        if (previousNode != null) {
            this.linkedNodes(previousNode, nodeToAdd);
        }
        else {
            this.head = nodeToAdd;
        }

        this.linkedNodes(nodeToAdd, currNode);

        this.nodeAdded();
    }

    /**
     * Removes the front node from the list.
     * Returns the removed node or null if the list is empty.
     */
    @Override
    public IDoublyLinkedListNode<T> removeFromFront() {
        if (this.head == null) {
            assert(this.tail == null && this.empty());
            return null;
        }

        IDoublyLinkedListNode<T> nodeToRemove = this.head;
        this.remove(nodeToRemove);

        return nodeToRemove;
    }

    /**
     * Removes the back node from the list.
     * Returns the removed node or null if the list is empty.
     */
    @Override
    public IDoublyLinkedListNode<T> removeFromBack() {
        if (this.tail == null) {
            assert(this.head == null && this.empty());
            return null;
        }

        IDoublyLinkedListNode<T> nodeToRemove = this.tail;
        this.remove(nodeToRemove);

        return nodeToRemove;
    }

    /**
     * Removes the node from the list.
     */
    @Override
    public void remove(IDoublyLinkedListNode<T> nodeToRemove) {
        Conditions.validateNotNull(
            nodeToRemove,
            "The node for removing.");

        IDoublyLinkedListNode<T> previousNode = nodeToRemove.previous();
        IDoublyLinkedListNode<T> nextNode = nodeToRemove.next();

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
    public IIterator<IDoublyLinkedListNode<T>> getIterator() {
        return DoublyLinkedListNodeIterator.make(this.head);
    }

    /**
     * Gets a reverse iterator of nodes.
     */
    @Override
    public IReverseIterator<IDoublyLinkedListNode<T>> getReverseIterator() {
        return DoublyLinkedListNodeReverseIterator.make(this.tail);
    }

    /**
     * Gets an iterator of values.
     */
    @Override
    public IIterator<T> getValueIterator() {
        return DoublyLinkedListNodeValueIterator.make(this.getIterator());
    }

    /**
     * Gets a reverse iterator of values.
     */
    @Override
    public IReverseIterator<T> getValueReverseIterator() {
        return DoublyLinkedListNodeValueReverseIterator.make(this.getReverseIterator());
    }

    /**
     * Gets a specific node by index. [0, 1, 2, ... , size -1]
     */
    @Override
    public IDoublyLinkedListNode<T> getNode(int index) {
        Conditions.validate(
            index >= 0 && index < this.size(),
            "Invalid index.");

        IDoublyLinkedListNode<T> currNode = this.head;

        int currIndex = 0;

        while (currNode != null) {
            assert(currIndex < this.size());

            if (currIndex == index) {
                return currNode;
            }

            ++currIndex;
            currNode = currNode.next();
        }

        return null;
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
    public boolean isEqual(IDoublyLinkedList<T> other) {
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
    public int compareTo(IDoublyLinkedList<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IDoublyLinkedList<T>> defaultComparator() {
        IBinaryComparator<IDoublyLinkedListNode<T>> nodeComparator = DoublyLinkedListNode.defaultComparator();
        return new DoublyLinkedList.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a doubly linked list.
     */
    public static final class Comparator<T extends Comparable<T>>
        extends AbstractBinaryComparator<IDoublyLinkedList<T>> {

        private final IBinaryComparator<IDoublyLinkedListNode<T>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IDoublyLinkedListNode<T>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a node of a doubly linked list.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IDoublyLinkedList<T> obj) {
            return new HashCodeBuilder(443, 449)
                .withIterator(obj.getIterator(), this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IDoublyLinkedList<T> lhs, IDoublyLinkedList<T> rhs) {
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
        public int compareTo(IDoublyLinkedList<T> lhs, IDoublyLinkedList<T> rhs) {
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
    private void linkedNodes(IDoublyLinkedListNode<T> left, IDoublyLinkedListNode<T> right) {
        if (left != null) {
            left.setNext(right);
        }

        if (right != null) {
            right.setPrevious(left);
        }
    }

    /**
     * Node added.
     */
    private void nodeAdded() {
        ++this.size;
    }

    /**
     * Node removed.
     */
    private void nodeRemoved(IDoublyLinkedListNode<T> node) {
        node.unlinked();

        --this.size;
    }
}
