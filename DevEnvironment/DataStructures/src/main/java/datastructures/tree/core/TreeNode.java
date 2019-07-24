package datastructures.tree.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.tree.interfaces.ITreeNode;
import java.util.ArrayList;
import java.util.List;

/**
 * The TreeNode class implements a node in a tree.
 */
public final class TreeNode<TKey extends Comparable<TKey>, TValue> implements ITreeNode<TKey, TValue> {
    private final TKey key;
    private TValue value;
    private List<ITreeNode<TKey, TValue>> children;
    private final IBinaryComparator<TKey> comparator;

    /**
     * The TreeNode constructor.
     */
    public TreeNode(
        TKey key,
        IBinaryComparator<TKey> comparator) {
        this(
            key,
            null,
            new ArrayList<>(),
            comparator);
    }

    /**
     * The TreeNode constructor.
     */
    public TreeNode(
        TKey key,
        TValue value,
        List<ITreeNode<TKey, TValue>> children,
        IBinaryComparator<TKey> comparator) {

        Conditions.validateNotNull(
            key,
            "The key of a node of a tree.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a key of a node of a tree.");

        this.key = key;
        this.value = value;
        this.children = children;
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
     * Gets the children the node.
     */
    @Override
    public List<ITreeNode<TKey, TValue>> getChildren() {
        return this.children;
    }

    /**
     * Sets the children of the node.
     */
    @Override
    public void setChildren(List<ITreeNode<TKey, TValue>> children) {
        this.children = children;
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
    public boolean isEqual(ITreeNode<TKey, TValue> other) {
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
    public int compareTo(ITreeNode<TKey, TValue> other) {
        int status = new CompareToBuilder()
            .withObject(this.getKey(), other.getKey(), this.comparator)
            .build();

        return status;
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ITreeNode<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.DefaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a node of a tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> implements IBinaryComparator<ITreeNode<TKey, TValue>> {
        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TKey> keyComparator) {
            Conditions.validateNotNull(
                    keyComparator,
                    "The key comparator of a tree.");

            this.keyComparator = keyComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITreeNode<TKey, TValue> obj) {
            return this.keyComparator.getHashCode(obj.getKey());
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ITreeNode<TKey, TValue> lhs, ITreeNode<TKey, TValue> rhs) {
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
        public int compareTo(ITreeNode<TKey, TValue> lhs, ITreeNode<TKey, TValue> rhs) {
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
     * The Builder class implements a builder for creating a node of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<ITreeNode<TKey, TValue>> {
        private TKey key;
        private TValue value;
        private List<ITreeNode<TKey, TValue>> children;
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
                "The key of a node of a tree.");

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
         * Adds a new child to a tree node.
         */
        public Builder<TKey, TValue> addChild(ITreeNode<TKey, TValue> child) {
            Conditions.validateNotNull(
                child,
                "The child of a tree.");

            this.children.add(child);

            return this;
        }

        /**
         * Sets a comparator of a key of node of a tree.
         */
        public Builder<TKey, TValue> setComparator(IBinaryComparator<TKey> comparator) {
            Conditions.validateNotNull(
                comparator,
                "The comparator of a node of a tree.");

            this.comparator = comparator;

            return this;
        }

        /**
         * Builds a node of a tree.
         */
        @Override
        public ITreeNode<TKey, TValue> build() {
            ITreeNode<TKey, TValue> node = new TreeNode<>(
                this.key,
                this.value,
                this.children,
                this.comparator);

            return node;
        }
    }
}
