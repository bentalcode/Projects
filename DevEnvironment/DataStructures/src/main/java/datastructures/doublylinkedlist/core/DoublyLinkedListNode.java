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
public final class DoublyLinkedListNode<TValue extends Comparable<TValue>> implements IDoublyLinkedListNode<TValue> {
    private TValue value;
    private IDoublyLinkedListNode<TValue> previous;
    private IDoublyLinkedListNode<TValue> next;
    private IBinaryComparator<IDoublyLinkedListNode<TValue>> comparator;
    private int hashCode;

    /**
     * The DoublyLinkedListNode constructor.
     */
    public DoublyLinkedListNode(TValue value) {
        this(
            value,
            null,
            null,
            DoublyLinkedListNode.DefaultComparator());
    }

    /**
     * The DoublyLinkedListNode constructor.
     */
    public DoublyLinkedListNode(
        TValue value,
        IDoublyLinkedListNode<TValue> previous,
        IDoublyLinkedListNode<TValue> next,
        IBinaryComparator<IDoublyLinkedListNode<TValue>> comparator) {

        this.value = value;
        this.previous = previous;
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
     * Gets a previous node.
     */
    @Override
    public IDoublyLinkedListNode<TValue> previous() {
        return this.previous;
    }

    /**
     * Sets a previous node.
     */
    @Override
    public void setPrevious(IDoublyLinkedListNode<TValue> node) {
        this.previous = node;
    }

    /**
     * Gets a next node.
     */
    @Override
    public IDoublyLinkedListNode<TValue> next() {
        return this.next;
    }

    /**
     * Sets a previous node.
     */
    @Override
    public void setNext(IDoublyLinkedListNode<TValue> node) {
        this.next = node;
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
     * Gets the hash code of a node of a B+ tree.
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
    public boolean isEqual(IDoublyLinkedListNode<TValue> other) {
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
    public int compareTo(IDoublyLinkedListNode<TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>> IBinaryComparator<IDoublyLinkedListNode<TKey>> DefaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.DefaultComparator();
        return new DoublyLinkedListNode.Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a doubly linked list.
     */
    public static final class Comparator<TValue extends Comparable<TValue>>
        extends AbstractBinaryComparator<IDoublyLinkedListNode<TValue>> {

        private final IBinaryComparator<TValue> valueComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TValue> valueComparator) {
            Conditions.validateNotNull(
                valueComparator,
                "The comparator of a value of a doubly linked list node.");

            this.valueComparator = valueComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IDoublyLinkedListNode<TValue> obj) {
            return this.valueComparator.getHashCode(obj.getValue());
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IDoublyLinkedListNode<TValue> lhs, IDoublyLinkedListNode<TValue> rhs) {
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
         * <p>
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IDoublyLinkedListNode<TValue> lhs, IDoublyLinkedListNode<TValue> rhs) {
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
