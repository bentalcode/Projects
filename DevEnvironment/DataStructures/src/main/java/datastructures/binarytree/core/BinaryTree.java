package datastructures.binarytree.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeTraversal;

/**
 * The BinaryTree class implements a binary tree.
 */
public final class BinaryTree<TKey extends Comparable<TKey>, TValue> implements IBinaryTree<TKey, TValue> {
    private IBinaryTreeNode<TKey, TValue> root;
    private final IBinaryComparator<IBinaryTree<TKey, TValue>> comparator;

    /**
     * The BinaryTree constructor.
     */
    public BinaryTree() {
        this(null);
    }

    /**
     * The BinaryTree constructor.
     */
    public BinaryTree(IBinaryTreeNode<TKey, TValue> root) {
        this(root, BinaryTree.defaultComparator());
    }

    /**
     * The BinaryTree constructor.
     */
    public BinaryTree(
        IBinaryTreeNode<TKey, TValue> root,
        IBinaryComparator<IBinaryTree<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a binary tree.");

        this.root = root;
        this.comparator = comparator;
    }

    /**
     * Gets a root of a tree.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getRoot() {
        return this.root;
    }

    /**
     * Sets a root of a tree.
     */
    @Override
    public void setRoot(IBinaryTreeNode<TKey, TValue> root) {
        this.root = root;
    }

    /**
     * Gets an interface of a tree traversal.
     */
    @Override
    public IBinaryTreeTraversal<TKey , TValue> getTreeTraversal() {
        return new BinaryTreeTraversal<>();
    }

    /**
     * Gets an iterator of a tree.
     */
    @Override
    public IIterator<IBinaryTreeNode<TKey , TValue>> getIterator() {
        return this.getInorderIterator();
    }

    /**
     * Gets a reverse iterator of a tree.
     */
    @Override
    public IReverseIterator<IBinaryTreeNode<TKey , TValue>> getReverseIterator() {
        return BinaryTreeReverseInorderIterator.of(this.root);
    }

    /**
     * Gets a level order iterator of a tree.
     */
    @Override
    public IIterator<IBinaryTreeNode<TKey , TValue>> getLevelOrderIterator() {
        return BinaryTreeLevelOrderIterator.of(this.root);
    }

    /**
     * Gets an inorder iterator of a tree.
     */
    @Override
    public IIterator<IBinaryTreeNode<TKey , TValue>> getInorderIterator() {
        return BinaryTreeInorderIterator.of(this.root);
    }

    /**
     * Gets a preorder iterator of a tree.
     */
    @Override
    public IIterator<IBinaryTreeNode<TKey , TValue>> getPreorderIterator() {
        return BinaryTreePreorderIterator.of(this.root);
    }

    /**
     * Gets a postorder iterator of a tree.
     */
    @Override
    public IIterator<IBinaryTreeNode<TKey , TValue>> getPostorderIterator() {
        return BinaryTreePostorderIterator.of(this.root);
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return this.root != null ? this.root.toString() : "null";
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
    public boolean isEqual(IBinaryTree<TKey, TValue> other) {
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
    public int compareTo(IBinaryTree<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IBinaryTree<TKey, TValue>> defaultComparator() {
        IBinaryComparator<IBinaryTreeNode<TKey, TValue>> nodeComparator = BinaryTreeNode.defaultComparator();
        return new BinaryTree.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> extends AbstractBinaryComparator<IBinaryTree<TKey, TValue>> {
        private final IBinaryComparator<IBinaryTreeNode<TKey, TValue>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IBinaryTreeNode<TKey, TValue>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a binary node.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IBinaryTree<TKey, TValue> obj) {
            return new HashCodeBuilder(271, 277)
                .withIterator(obj.getIterator(), this.nodeComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IBinaryTree<TKey, TValue> lhs, IBinaryTree<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            IIterator<IBinaryTreeNode<TKey, TValue>> lhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator.of(lhs.getRoot());

            IIterator<IBinaryTreeNode<TKey, TValue>> rhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator.of(rhs.getRoot());

            return new EqualBuilder()
                .withIterator(lhsIterator, rhsIterator, this.nodeComparator)
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
        public int compareTo(IBinaryTree<TKey, TValue> lhs, IBinaryTree<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            IIterator<IBinaryTreeNode<TKey, TValue>> lhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator.of(lhs.getRoot());

            IIterator<IBinaryTreeNode<TKey, TValue>> rhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator.of(rhs.getRoot());

            return new CompareToBuilder()
                .withIterator(lhsIterator, rhsIterator, this.nodeComparator)
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating levels of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IBinaryTree<TKey, TValue>> {
        private IBinaryTreeNode<TKey, TValue> root;
        private IBinaryComparator<IBinaryTree<TKey, TValue>> comparator;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets the root of a tree.
         */
        public BinaryTree.Builder<TKey, TValue> setRoot(IBinaryTreeNode<TKey, TValue> root) {
            Conditions.validateNotNull(
                root,
                "The root of a binary tree.");

            this.root = root;

            return this;
        }

        /**
         * Sets a left node.
         */
        public BinaryTree.Builder<TKey, TValue> setLeftNode(
            IBinaryTreeNode<TKey, TValue> parentNode,
            IBinaryTreeNode<TKey, TValue> childNode) {

            Conditions.validateNotNull(
                parentNode,
                "The parent node for adding to.");

            Conditions.validateNotNull(
                childNode,
                "The child node for adding.");

            parentNode.setLeftChild(childNode);

            return this;
        }

        /**
         * Sets a right node.
         */
        public BinaryTree.Builder<TKey, TValue> setRightNode(
            IBinaryTreeNode<TKey, TValue> parentNode,
            IBinaryTreeNode<TKey, TValue> childNode) {

            Conditions.validateNotNull(
                parentNode,
                "The parent node for adding to.");

            Conditions.validateNotNull(
                childNode,
                "The child node for adding.");

            parentNode.setRightChild(childNode);

            return this;
        }

        /**
         * Sets the comparator of a tree.
         */
        public BinaryTree.Builder<TKey, TValue> setComparator(IBinaryComparator<IBinaryTree<TKey, TValue>> comparator) {
            Conditions.validateNotNull(
                comparator,
                "The comparator of a binary tree.");

            this.comparator = comparator;

            return this;
        }

        /**
         * Builds the binary tree.
         */
        @Override
        public IBinaryTree<TKey, TValue> build() {
            if (this.comparator == null) {
                this.comparator = BinaryTree.defaultComparator();
            }

            return new BinaryTree<>(this.root, this.comparator);
        }
    }
}
