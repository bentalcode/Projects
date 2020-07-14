package datastructures.multileveldoublylinkedlist.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Matrix;
import base.core.Position;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IMatrix;
import base.interfaces.IPosition;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedList;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListLogic;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;

/**
 * The MultiLevelDoublyLinkedList class implements a multi-level doubly linked list.
 */
public final class MultiLevelDoublyLinkedList<T extends Comparable<T>> implements IMultiLevelDoublyLinkedList<T> {
    private IMultiLevelDoublyLinkedListNode<T> head;
    private int size;
    private final IBinaryComparator<IMultiLevelDoublyLinkedList<T>> comparator;

    /**
     * The MultiLevelDoublyLinkedList constructor.
     */
    public MultiLevelDoublyLinkedList() {
        this(null);
    }

    /**
     * The MultiLevelDoublyLinkedList constructor.
     */
    public MultiLevelDoublyLinkedList(IMultiLevelDoublyLinkedListNode<T> head) {
        this(
            head,
            MultiLevelDoublyLinkedList.defaultComparator());
    }

    /**
     * The MultiLevelDoublyLinkedList constructor.
     */
    private MultiLevelDoublyLinkedList(
        IMultiLevelDoublyLinkedListNode<T> head,
        IBinaryComparator<IMultiLevelDoublyLinkedList<T>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a multi-level doubly linked list.");

        if (head != null) {
            this.addToFront(head);
        }

        this.comparator = comparator;
    }

    /**
     * Gets the head node of the list.
     */
    @Override
    public IMultiLevelDoublyLinkedListNode<T> getHead() {
        return this.head;
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
        this.addToFront(MultiLevelDoublyLinkedListNode.of(value));
    }

    /**
     * Adds a new value after a specific node of the list.
     */
    @Override
    public void addAfter(IMultiLevelDoublyLinkedListNode<T> currNode, T valueToAdd) {
        this.addAfter(currNode, MultiLevelDoublyLinkedListNode.of(valueToAdd));
    }

    /**
     * Adds a new value before a specific node of the list.
     */
    @Override
    public void addBefore(IMultiLevelDoublyLinkedListNode<T> currNode, T valueToAdd) {
        this.addBefore(currNode, MultiLevelDoublyLinkedListNode.of(valueToAdd));
    }

    /**
     * Adds a new value bellow a specific node of the list.
     */
    @Override
    public void addBellow(IMultiLevelDoublyLinkedListNode<T> currNode, T valueToAdd) {
        this.addBellow(currNode, MultiLevelDoublyLinkedListNode.of(valueToAdd));
    }

    /**
     * Adds a new value above a specific node of the list.
     */
    @Override
    public void addAbove(IMultiLevelDoublyLinkedListNode<T> currNode, T valueToAdd) {
        this.addAbove(currNode, MultiLevelDoublyLinkedListNode.of(valueToAdd));
    }

    /**
     * Adds a new node to the front of the list.
     */
    @Override
    public void addToFront(IMultiLevelDoublyLinkedListNode<T> node) {
        Conditions.validateNotNull(
            node,
            "The node for adding.");

        node.unlinked();

        if (this.head == null) {
            assert(this.empty());

            this.head = node;
        }
        else {
            this.linkedNodes(node, this.head);
            this.head = node;
        }

        this.nodeAdded();
    }

    /**
     * Adds a new node after a specific node of the list.
     */
    @Override
    public void addAfter(
        IMultiLevelDoublyLinkedListNode<T> currNode,
        IMultiLevelDoublyLinkedListNode<T> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node for adding after.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node for adding.");

        nodeToAdd.unlinked();

        IMultiLevelDoublyLinkedListNode<T> nextNode = currNode.next();

        this.linkedNodes(currNode, nodeToAdd);
        this.linkedNodes(nodeToAdd, nextNode);

        this.nodeAdded();
    }

    /**
     * Adds a new node before a specific node of the list.
     */
    @Override
    public void addBefore(
        IMultiLevelDoublyLinkedListNode<T> currNode,
        IMultiLevelDoublyLinkedListNode<T> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node for adding before.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node for adding.");

        nodeToAdd.unlinked();

        IMultiLevelDoublyLinkedListNode<T> previousNode = currNode.previous();

        this.linkedNodes(previousNode, nodeToAdd);
        this.linkedNodes(nodeToAdd, currNode);

        if (this.head == currNode) {
            this.head = nodeToAdd;
        }

        this.nodeAdded();
    }

    /**
     * Adds a new node bellow a specific node of the list.
     */
    @Override
    public void addBellow(
        IMultiLevelDoublyLinkedListNode<T> currNode,
        IMultiLevelDoublyLinkedListNode<T> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node for adding bellow.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node for adding.");

        nodeToAdd.unlinked();

        IMultiLevelDoublyLinkedListNode<T> childNode = currNode.child();

        this.linkedNodesVertically(currNode, nodeToAdd);
        this.linkedNodes(nodeToAdd, childNode);

        this.nodeAdded();
    }

    /**
     * Adds a new node above a specific node of the list.
     */
    @Override
    public void addAbove(
        IMultiLevelDoublyLinkedListNode<T> currNode,
        IMultiLevelDoublyLinkedListNode<T> nodeToAdd) {

        Conditions.validateNotNull(
            currNode,
            "The exiting node for adding above.");

        Conditions.validateNotNull(
            nodeToAdd,
            "The node for adding.");

        nodeToAdd.unlinked();

        this.linkedNodesVertically(nodeToAdd, currNode);

        this.nodeAdded();
    }

    /**
     * Clears the list.
     */
    @Override
    public void clear() {
        this.head = null;
        this.size = 0;
    }

    /**
     * Gets the logic.
     */
    @Override
    public IMultiLevelDoublyLinkedListLogic<T> getLogic() {
        return new MultiLevelDoublyLinkedListLogic<>(this);
    }

    /**
     * Gets an iterator of nodes.
     */
    @Override
    public IIterator<IMultiLevelDoublyLinkedListNode<T>> getIterator() {
        return new MultiLevelDoublyLinkedListNodeIterator<>(this.head);
    }

    /**
     * Gets an iterator of values.
     */
    @Override
    public IIterator<T> getValueIterator() {
        return new MultiLevelDoublyLinkedListNodeValueIterator<>(this.getIterator());
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        IMatrix<T> matrix = this.createMatrix();
        return matrix.toString();
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
    public boolean isEqual(IMultiLevelDoublyLinkedList<T> other) {
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
    public int compareTo(IMultiLevelDoublyLinkedList<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IMultiLevelDoublyLinkedList<T>> defaultComparator() {
        IBinaryComparator<IMultiLevelDoublyLinkedListNode<T>> nodeComparator = MultiLevelDoublyLinkedListNode.defaultComparator();
        return new MultiLevelDoublyLinkedList.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a multi-level doubly linked list.
     */
    public static final class Comparator<T extends Comparable<T>>
        extends AbstractBinaryComparator<IMultiLevelDoublyLinkedList<T>> {

        private final IBinaryComparator<IMultiLevelDoublyLinkedListNode<T>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IMultiLevelDoublyLinkedListNode<T>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a node of a multi-level doubly linked list.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IMultiLevelDoublyLinkedList<T> obj) {
            return new HashCodeBuilder(641, 643)
                .withIterator(obj.getIterator(), this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IMultiLevelDoublyLinkedList<T> lhs, IMultiLevelDoublyLinkedList<T> rhs) {
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
        public int compareTo(IMultiLevelDoublyLinkedList<T> lhs, IMultiLevelDoublyLinkedList<T> rhs) {
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
    private void linkedNodes(IMultiLevelDoublyLinkedListNode<T> left, IMultiLevelDoublyLinkedListNode<T> right) {
        if (left != null) {
            left.setNext(right);
        }

        if (right != null) {
            right.setPrevious(left);
        }
    }

    /**
     * Linked nodes vertically.
     */
    private void linkedNodesVertically(IMultiLevelDoublyLinkedListNode<T> upper, IMultiLevelDoublyLinkedListNode<T> bellow) {
        if (upper != null) {
            upper.setChild(bellow);
        }
    }

    /**
     * Node added.
     */
    private void nodeAdded() {
        ++this.size;
    }

    /**
     * Returns the data of a multi-level doubly linked list as a matrix.
     */
    private IMatrix<T> createMatrix() {
        IPosition rightBottomPosition = this.calculateMatrixFrame();

        int rowsSize = rightBottomPosition.getRow() + 1;
        int colsSize = rightBottomPosition.getColumn() + 1;
        IMatrix<T> matrix = new Matrix<>(rowsSize, colsSize);

        IPosition headPosition = Position.origin();
        this.setMatrixData(this.head, headPosition, matrix);

        return matrix;
    }

    /**
     * Calculates a matrix frame of a multi-level doubly linked list.
     * The head of the multi-level doubly linked list is defined as the left upper position (0,0).
     */
    private IPosition calculateMatrixFrame() {
        IPosition rightBottomPosition = new Position();

        IPosition headPosition = Position.origin();
        this.calculateMatrixFrame(this.head, headPosition, rightBottomPosition);

        return rightBottomPosition;
    }

    /**
     * Calculates a matrix frame of a multi-level doubly linked list.
     * The head of the multi-level doubly linked list is defined as the left upper position (0,0).
     */
    private void calculateMatrixFrame(
        IMultiLevelDoublyLinkedListNode<T> node,
        IPosition currPosition,
        IPosition rightBottomPosition) {

        if (node == null) {
            return;
        }

        if (currPosition.getRow() > rightBottomPosition.getRow()) {
            rightBottomPosition.setRow(currPosition.getRow());
        }

        if (currPosition.getColumn() > rightBottomPosition.getColumn()) {
            rightBottomPosition.setColumn(currPosition.getColumn());
        }

        if (node.next() != null) {
            IPosition rightPosition = Position.add(currPosition, 0, 1);
            this.calculateMatrixFrame(node.next(), rightPosition, rightBottomPosition);
        }

        if (node.child() != null) {
            IPosition bottomPosition = Position.add(currPosition, 1, 0);
            this.calculateMatrixFrame(node.child(), bottomPosition, rightBottomPosition);
        }
    }

    /**
     * Sets the data of the matrix.
     */
    private void setMatrixData(
        IMultiLevelDoublyLinkedListNode<T> node,
        IPosition currPosition,
        IMatrix<T> matrix) {

        if (node == null) {
            return;
        }

        matrix.set(currPosition.getRow(), currPosition.getColumn(), node.getValue());

        if (node.next() != null) {
            IPosition rightPosition = Position.add(currPosition, 0, 1);
            this.setMatrixData(node.next(), rightPosition, matrix);
        }

        if (node.child() != null) {
            IPosition bottomPosition = Position.add(currPosition, 1, 0);
            this.setMatrixData(node.child(), bottomPosition, matrix);
        }
    }
}
