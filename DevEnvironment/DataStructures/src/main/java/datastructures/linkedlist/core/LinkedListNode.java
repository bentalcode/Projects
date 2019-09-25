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
public final class LinkedListNode<TValue extends Comparable<TValue>> implements ILinkedListNode<TValue> {
    private TValue value;
    private ILinkedListNode<TValue> next;
    private IBinaryComparator<ILinkedListNode<TValue>> comparator;
    private int hashCode;

    /**
     * Creates a new linked list node.
     */
    public static <TValue extends Comparable<TValue>> ILinkedListNode<TValue> of(TValue value) {
        return new LinkedListNode<>(value);
    }

    /**
     * Creates a new linked list node.
     */
    public static <TValue extends Comparable<TValue>> ILinkedListNode<TValue> of(
        TValue value,
        ILinkedListNode<TValue> next,
        IBinaryComparator<ILinkedListNode<TValue>> comparator) {

        return new LinkedListNode<>(value, next, comparator);
    }

    /**
     * The LinkedListNode constructor.
     */
    private LinkedListNode(TValue value) {
        this(
            value,
            null,
            LinkedListNode.defaultComparator());
    }

    /**
     * The LinkedListNode constructor.
     */
    private LinkedListNode(
        TValue value,
        ILinkedListNode<TValue> next,
        IBinaryComparator<ILinkedListNode<TValue>> comparator) {

        this.value = value;
        this.next = next;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets a value of a node.
     */
    @Override
    public TValue getValue() {
        return this.value;
    }

    /**
     * Sets a value of a node.
     */
    @Override
    public void setValue(TValue value) {
        this.value = value;
    }

    /**
     * Gets a next node.
     */
    @Override
    public ILinkedListNode<TValue> next() {
        return this.next;
    }

    /**
     * Sets a next node.
     */
    @Override
    public void setNext(ILinkedListNode<TValue> node) {
        this.next = node;
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
    public boolean isEqual(ILinkedListNode<TValue> other) {
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
    public int compareTo(ILinkedListNode<TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>> IBinaryComparator<ILinkedListNode<TKey>> defaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.defaultComparator();
        return new LinkedListNode.Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a linked list.
     */
    public static final class Comparator<TValue extends Comparable<TValue>>
        extends AbstractBinaryComparator<ILinkedListNode<TValue>> {

        private final IBinaryComparator<TValue> valueComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TValue> valueComparator) {
            Conditions.validateNotNull(
                valueComparator,
                "The comparator of a value of a linked list node.");

            this.valueComparator = valueComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ILinkedListNode<TValue> obj) {
            return this.valueComparator.getHashCode(obj.getValue());
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ILinkedListNode<TValue> lhs, ILinkedListNode<TValue> rhs) {
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
        public int compareTo(ILinkedListNode<TValue> lhs, ILinkedListNode<TValue> rhs) {
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
