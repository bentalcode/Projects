package datastructures.multileveldoublylinkedlist.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;

/**
 * The MultiLevelDoublyLinkedListNode class implements a node of a multi-level doubly linked list.
 */
public final class MultiLevelDoublyLinkedListNode<T extends Comparable<T>> implements IMultiLevelDoublyLinkedListNode<T> {
    private T value;
    private IMultiLevelDoublyLinkedListNode<T> previous;
    private IMultiLevelDoublyLinkedListNode<T> next;
    private IMultiLevelDoublyLinkedListNode<T> child;
    private final IBinaryComparator<IMultiLevelDoublyLinkedListNode<T>> comparator;
    private final int hashCode;

    /**
     * Creates a new multi-level doubly linked list node.
     */
    public static <T extends Comparable<T>> IMultiLevelDoublyLinkedListNode<T> make(T value) {
        return new MultiLevelDoublyLinkedListNode<>(value);
    }

    /**
     * Creates a new multi-level doubly linked list node.
     */
    public static <T extends Comparable<T>> IMultiLevelDoublyLinkedListNode<T> make(
        T value,
        IMultiLevelDoublyLinkedListNode<T> previous,
        IMultiLevelDoublyLinkedListNode<T> next,
        IMultiLevelDoublyLinkedListNode<T> child,
        IBinaryComparator<IMultiLevelDoublyLinkedListNode<T>> comparator) {

        return new MultiLevelDoublyLinkedListNode<>(
            value,
            previous,
            next,
            child,
            comparator);
    }

    /**
     * The MultiLevelDoublyLinkedListNode constructor.
     */
    private MultiLevelDoublyLinkedListNode(T value) {
        this(
            value,
            null,
            null,
            null,
            MultiLevelDoublyLinkedListNode.defaultComparator());
    }

    /**
     * The MultiLevelDoublyLinkedListNode constructor.
     */
    private MultiLevelDoublyLinkedListNode(
        T value,
        IMultiLevelDoublyLinkedListNode<T> previous,
        IMultiLevelDoublyLinkedListNode<T> next,
        IMultiLevelDoublyLinkedListNode<T> child,
        IBinaryComparator<IMultiLevelDoublyLinkedListNode<T>> comparator) {

        this.value = value;
        this.previous = previous;
        this.next = next;
        this.child = child;

        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets a value of a node.
     */
    @Override
    public T getValue() {
        return this.value;
    }

    /**
     * Sets a value of a node.
     */
    @Override
    public void setValue(T value) {
        this.value = value;
    }

    /**
     * Gets a previous node.
     */
    @Override
    public IMultiLevelDoublyLinkedListNode<T> previous() {
        return this.previous;
    }

    /**
     * Sets a previous node.
     */
    @Override
    public void setPrevious(IMultiLevelDoublyLinkedListNode<T> node) {
        this.previous = node;
    }

    /**
     * Gets a next node.
     */
    @Override
    public IMultiLevelDoublyLinkedListNode<T> next() {
        return this.next;
    }

    /**
     * Sets a next node.
     */
    @Override
    public void setNext(IMultiLevelDoublyLinkedListNode<T> node) {
        this.next = node;
    }

    /**
     * Gets a child node.
     */
    @Override
    public IMultiLevelDoublyLinkedListNode<T> child() {
        return this.child;
    }

    /**
     * Sets a child node.
     */
    @Override
    public void setChild(IMultiLevelDoublyLinkedListNode<T> node) {
        this.child = node;
    }

    /**
     * Unlinked the node.
     */
    @Override
    public void unlinked() {
        this.next = null;
        this.previous = null;
        this.child = null;
    }

    /**
     * Gets a hash code of this instance.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Gets the hash code of a node of a multi-level doubly linked list.
     */
    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }

        if (!this.getClass().isInstance(obj)) {
            return false;
        }

        return this.isEqual(Casting.cast(obj));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IMultiLevelDoublyLinkedListNode<T> other) {
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
    public int compareTo(IMultiLevelDoublyLinkedListNode<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IMultiLevelDoublyLinkedListNode<T>> defaultComparator() {
        IBinaryComparator<T> keyComparator = base.core.Comparator.defaultComparator();
        return new MultiLevelDoublyLinkedListNode.Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a multi-level doubly linked list.
     */
    public static final class Comparator<T extends Comparable<T>>
        extends AbstractBinaryComparator<IMultiLevelDoublyLinkedListNode<T>> {

        private final IBinaryComparator<T> valueComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<T> valueComparator) {
            Conditions.validateNotNull(
                valueComparator,
                "The comparator of a value of a multi-level doubly linked list node.");

            this.valueComparator = valueComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IMultiLevelDoublyLinkedListNode<T> obj) {
            return this.valueComparator.getHashCode(obj.getValue());
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IMultiLevelDoublyLinkedListNode<T> lhs, IMultiLevelDoublyLinkedListNode<T> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getValue(), rhs.getValue(), this.valueComparator)
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
        public int compareTo(IMultiLevelDoublyLinkedListNode<T> lhs, IMultiLevelDoublyLinkedListNode<T> rhs) {
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
                .withObject(lhs.getValue(), rhs.getValue(), this.valueComparator)
                .build();
        }
    }
}
