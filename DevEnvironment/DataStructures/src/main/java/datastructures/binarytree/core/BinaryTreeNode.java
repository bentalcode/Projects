package datastructures.binarytree.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.binarytree.interfaces.IBinaryTreeNode;

/**
 * The BinaryTreeNode class implements a binary node in a binary tree.
 */
public final class BinaryTreeNode<TKey extends Comparable<TKey>, TValue> implements IBinaryTreeNode<TKey, TValue> {
    private final TKey key;
    private TValue value;
    private IBinaryTreeNode<TKey, TValue> leftChild;
    private IBinaryTreeNode<TKey, TValue> rightChild;
    private final IBinaryComparator<TKey> comparator;

    /**
     * The BinaryTreeNode constructor.
     */
    public BinaryTreeNode(
        TKey key,
        IBinaryComparator<TKey> comparator) {
        this(
            key,
            null,
            null,
            null,
            comparator);
    }

    /**
     * The BinaryTreeNode constructor.
     */
    public BinaryTreeNode(
        TKey key,
        TValue value,
        IBinaryTreeNode<TKey, TValue> leftChild,
        IBinaryTreeNode<TKey, TValue> rightChild,
        IBinaryComparator<TKey> comparator) {

        Conditions.validateNotNull(
            key,
            "The key of a node of a binary tree.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a key of a node of a binary tree.");

        this.key = key;
        this.value = value;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
        this.comparator = comparator;
    }

    /**
     * Gets the key of the node.
     */
    @Override
    public TKey getKey() {
        return this.key;
    }

    /**
     * Gets the value of the node.
     */
    @Override
    public TValue getValue() {
        return this.value;
    }

    /**
     * Sets the value of the node.
     */
    @Override
    public void setValue(TValue value) {
        this.value = value;
    }

    /**
     * Gets the left child node.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getLeftChild() {
        return this.leftChild;
    }

    /**
     * Gets the right child node.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getRightChild() {
        return this.rightChild;
    }

    /**
     * Sets the left child node.
     */
    @Override
    public void setLeftChild(IBinaryTreeNode<TKey, TValue> node) {
        this.leftChild = node;
    }

    /**
     * Sets the right child node.
     */
    @Deprecated
    public void setRightChild(IBinaryTreeNode<TKey, TValue> node) {
        this.rightChild = node;
    }

    /**
     * Gets a hash code of this instance.
     */
    @Override
    public int hashCode() {
        return this.comparator.getHashCode(this.getKey());
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
    public boolean isEqual(IBinaryTreeNode<TKey, TValue> other) {
        boolean status = new EqualBuilder()
            .withObject(this.getKey(), other.getKey(), this.comparator)
            .build();

        return status;
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IBinaryTreeNode<TKey, TValue> other) {
        int status = new CompareToBuilder()
            .withObject(this.getKey(), other.getKey(), this.comparator)
            .build();

        return status;
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IBinaryTreeNode<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.DefaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a binary node of a binary tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> implements IBinaryComparator<IBinaryTreeNode<TKey, TValue>> {
        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TKey> keyComparator) {
            Conditions.validateNotNull(
                keyComparator,
                "The key comparator of a binary tree.");

            this.keyComparator = keyComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IBinaryTreeNode<TKey, TValue> obj) {
            return this.keyComparator.getHashCode(obj.getKey());
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IBinaryTreeNode<TKey, TValue> lhs, IBinaryTreeNode<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getKey(), rhs.getKey(), this.keyComparator)
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
        public int compareTo(IBinaryTreeNode<TKey, TValue> lhs, IBinaryTreeNode<TKey, TValue> rhs) {
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
                .withObject(lhs.getKey(), rhs.getKey(), this.keyComparator)
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating a binary node of a binary tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IBinaryTreeNode<TKey, TValue>> {
        private TKey key;
        private TValue value;
        private IBinaryTreeNode<TKey, TValue> leftChild;
        private IBinaryTreeNode<TKey, TValue> rightChild;
        private IBinaryComparator<TKey> comparator;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets a key a tree node.
         */
        public Builder<TKey, TValue> setKey(TKey key) {
            Conditions.validateNotNull(
                key,
                "The key of a binary node of a binary tree.");

            this.key = key;

            return this;
        }

        /**
         * Sets a value of a tree node.
         */
        public Builder<TKey, TValue> setValue(TValue value) {
            this.value = value;
            return this;
        }

        /**
         * Adds a left child to a binary tree node.
         */
        public Builder<TKey, TValue> setLeftChild(IBinaryTreeNode<TKey, TValue> node) {
            Conditions.validateNotNull(
                node,
                "The left child of a binary tree.");

            this.leftChild = node;

            return this;
        }

        /**
         * Adds a right child to a binary tree node.
         */
        public Builder<TKey, TValue> setRightChild(IBinaryTreeNode<TKey, TValue> node) {
            Conditions.validateNotNull(
                node,
                "The right child of a binary tree.");

            this.rightChild = node;

            return this;
        }

        /**
         * Sets a comparator of a key of node of a tree.
         */
        public Builder<TKey, TValue> setComparator(IBinaryComparator<TKey> comparator) {
            Conditions.validateNotNull(
                comparator,
                "The comparator of a binary node of a binary tree.");

            this.comparator = comparator;

            return this;
        }

        /**
         * Builds a node of a tree.
         */
        @Override
        public IBinaryTreeNode<TKey, TValue> build() {
            IBinaryTreeNode<TKey, TValue> node = new BinaryTreeNode<>(
                this.key,
                this.value,
                this.leftChild,
                this.rightChild,
                this.comparator);

            return node;
        }
    }
}
