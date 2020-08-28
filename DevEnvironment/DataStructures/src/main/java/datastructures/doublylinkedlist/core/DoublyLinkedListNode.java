package datastructures.doublylinkedlist.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNode class implements a node of a doubly linked list.
 */
public final class DoublyLinkedListNode<T extends Comparable<T>> implements IDoublyLinkedListNode<T> {
    private T value;
    private IDoublyLinkedListNode<T> next;
    private IDoublyLinkedListNode<T> previous;
    private final IBinaryComparator<IDoublyLinkedListNode<T>> comparator;
    private final int hashCode;

    /**
     * Creates a new doubly linked list node.
     */
    public static <T extends Comparable<T>> IDoublyLinkedListNode<T> make(T value) {
        return new DoublyLinkedListNode<>(value);
    }

    /**
     * Creates a new doubly linked list node.
     */
    public static <T extends Comparable<T>> IDoublyLinkedListNode<T> make(
        T value,
        IDoublyLinkedListNode<T> next,
        IDoublyLinkedListNode<T> previous,
        IBinaryComparator<IDoublyLinkedListNode<T>> comparator) {

        return new DoublyLinkedListNode<>(value, next, previous, comparator);
    }

    /**
     * The DoublyLinkedListNode constructor.
     */
    private DoublyLinkedListNode(T value) {
        this(
            value,
            null,
            null,
            DoublyLinkedListNode.defaultComparator());
    }

    /**
     * The DoublyLinkedListNode constructor.
     */
    private DoublyLinkedListNode(
        T value,
        IDoublyLinkedListNode<T> next,
        IDoublyLinkedListNode<T> previous,
        IBinaryComparator<IDoublyLinkedListNode<T>> comparator) {

        this.value = value;
        this.next = next;
        this.previous = previous;
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
     * Gets a next node.
     */
    @Override
    public IDoublyLinkedListNode<T> next() {
        return this.next;
    }

    /**
     * Sets a next node.
     */
    @Override
    public void setNext(IDoublyLinkedListNode<T> node) {
        this.next = node;
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext()
    {
        return this.next != null;
    }

    /**
     * Gets a previous node.
     */
    @Override
    public IDoublyLinkedListNode<T> previous() {
        return this.previous;
    }

    /**
     * Sets a previous node.
     */
    @Override
    public void setPrevious(IDoublyLinkedListNode<T> node) {
        this.previous = node;
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasPrevious()
    {
        return this.previous != null;
    }

    /**
     * Unlinked the node.
     */
    @Override
    public void unlinked() {
        this.next = null;
        this.previous = null;
    }

    /**
     * Gets a hash code of this instance.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Gets the hash code of a node of a doubly linked list.
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
    public boolean isEqual(IDoublyLinkedListNode<T> other) {
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
    public int compareTo(IDoublyLinkedListNode<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IDoublyLinkedListNode<T>> defaultComparator() {
        IBinaryComparator<T> valueComparator = base.core.Comparator.defaultComparator();
        return new DoublyLinkedListNode.Comparator<>(valueComparator);
    }

    /**
     * The Comparator class implements a comparator of a doubly linked list.
     */
    public static final class Comparator<T extends Comparable<T>>
        extends AbstractBinaryComparator<IDoublyLinkedListNode<T>> {

        private final IBinaryComparator<T> valueComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<T> valueComparator) {
            Conditions.validateNotNull(
                valueComparator,
                "The comparator of a value of a doubly linked list node.");

            this.valueComparator = valueComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IDoublyLinkedListNode<T> obj) {
            return this.valueComparator.getHashCode(obj.getValue());
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IDoublyLinkedListNode<T> lhs, IDoublyLinkedListNode<T> rhs) {
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
        public int compareTo(IDoublyLinkedListNode<T> lhs, IDoublyLinkedListNode<T> rhs) {
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
