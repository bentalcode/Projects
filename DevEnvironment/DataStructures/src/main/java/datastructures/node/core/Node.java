package datastructures.node.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.node.interfaces.INode;

/**
 * The Node class implements a generic node.
 */
public final class Node<T extends Comparable<T>> implements INode<T> {
    private T value;
    private final IBinaryComparator<INode<T>> comparator;

    /**
     * Creates a new instance of a node.
     */
    public static <T extends Comparable<T>> INode<T> make(
        T value,
        IBinaryComparator<INode<T>> comparator) {

        return new Node<>(value, comparator);
    }

    /**
     * The Node constructor.
     */
    private Node(
        T value,
        IBinaryComparator<INode<T>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a node.");

        this.value = value;
        this.comparator = comparator;
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
    public boolean isEqual(INode<T> other) {
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
    public int compareTo(INode<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * The Comparator class implements a comparator of a generic node.
     */
    public static final class Comparator<T extends Comparable<T>>
        extends AbstractBinaryComparator<INode<T>> {

        private final IBinaryComparator<T> valueComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<T> valueComparator) {
            Conditions.validateNotNull(
                valueComparator,
                "The value comparator of a node.");

            this.valueComparator = valueComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(INode<T> obj) {
            return this.valueComparator.getHashCode(obj.getValue());
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(INode<T> lhs, INode<T> rhs) {
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
        public int compareTo(INode<T> lhs, INode<T> rhs) {
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

    /**
     * The Builder class implements a builder for creating a node.
     */
    public static final class Builder<T extends Comparable<T>> implements IBuilder<INode<T>> {
        private T value;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets the value of a node.
         */
        public Builder setValue(T value) {
            this.value = value;
            return this;
        }

        /**
         * Builds a node.
         */
        @Override
        public INode<T> build() {
            return new Node<>(
                this.value,
                base.core.Comparator.make());
        }
    }
}
