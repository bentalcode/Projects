package datastructures.linkedlist.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.linkedlist.interfaces.ILinkedListNode;

/**
 * The LinkedListNode class implements a node of a linked list.
 */
public final class LinkedListNode<T extends Comparable<T>> implements ILinkedListNode<T> {
    private T value;
    private ILinkedListNode<T> next;
    private final IBinaryComparator<ILinkedListNode<T>> comparator;
    private final int hashCode;

    /**
     * Creates a new linked list node with a value.
     */
    public static <T extends Comparable<T>> ILinkedListNode<T> make(T value) {
        return new LinkedListNode<>(value);
    }

    /**
     * Creates a new linked list node with a value and a next node.
     */
    public static <T extends Comparable<T>> ILinkedListNode<T> make(
        T value,
        ILinkedListNode<T> next) {

        return new LinkedListNode<>(value, next, LinkedListNode.defaultComparator());
    }

    /**
     * Creates a new linked list node with a value, a next node, and a comparator.
     */
    public static <T extends Comparable<T>> ILinkedListNode<T> make(
        T value,
        ILinkedListNode<T> next,
        IBinaryComparator<ILinkedListNode<T>> comparator) {

        return new LinkedListNode<>(value, next, comparator);
    }

    /**
     * The LinkedListNode constructor.
     */
    private LinkedListNode(T value) {
        this(
            value,
            null,
            LinkedListNode.defaultComparator());
    }

    /**
     * The LinkedListNode constructor.
     */
    private LinkedListNode(
        T value,
        ILinkedListNode<T> next,
        IBinaryComparator<ILinkedListNode<T>> comparator) {

        this.value = value;
        this.next = next;
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
    public ILinkedListNode<T> next() {
        return this.next;
    }

    /**
     * Sets a next node.
     */
    @Override
    public void setNext(ILinkedListNode<T> node) {
        this.next = node;
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.next != null;
    }

    /**
     * Unlinked the node.
     */
    @Override
    public void unlinked() {
        this.next = null;
    }

    /**
     * Gets a hash code of this instance.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Gets the hash code of a node of a linked list.
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
    public boolean isEqual(ILinkedListNode<T> other) {
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
    public int compareTo(ILinkedListNode<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>> IBinaryComparator<ILinkedListNode<TKey>> defaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.make();
        return new LinkedListNode.Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a linked list.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<ILinkedListNode<T>> {
        private final IBinaryComparator<T> valueComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<T> valueComparator) {
            Conditions.validateNotNull(
                valueComparator,
                "The comparator of a value of a linked list node.");

            this.valueComparator = valueComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ILinkedListNode<T> obj) {
            return this.valueComparator.getHashCode(obj.getValue());
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ILinkedListNode<T> lhs, ILinkedListNode<T> rhs) {
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
        public int compareTo(ILinkedListNode<T> lhs, ILinkedListNode<T> rhs) {
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
