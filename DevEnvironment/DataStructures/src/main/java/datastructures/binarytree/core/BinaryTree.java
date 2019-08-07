package datastructures.binarytree.core;

import base.core.Casting;
import base.core.Conditions;
import base.core.ReverseIterator;
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
        this(root, BinaryTree.DefaultComparator());
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
    public IIterator<IBinaryTreeNode<TKey , TValue>> getIterator() {
        return BinaryTreeIterator.of(this.root);
    }

    /**
     * Gets a reverse iterator of a tree.
     */
    public IReverseIterator<IBinaryTreeNode<TKey , TValue>> getReverseIterator() {
        return BinaryTreeReverseIterator.of(this.root);
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
    public int compareTo(IBinaryTree<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IBinaryTree<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<IBinaryTreeNode<TKey, TValue>> nodeComparator = BinaryTreeNode.DefaultComparator();
        return new BinaryTree.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> implements IBinaryComparator<IBinaryTree<TKey, TValue>> {
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
            return this.nodeComparator.getHashCode(obj.getRoot());
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IBinaryTree<TKey, TValue> lhsTree, IBinaryTree<TKey, TValue> rhsTree) {
            if (lhsTree == null && rhsTree == null) {
                return true;
            }

            if (lhsTree == null || rhsTree == null) {
                return false;
            }

            return this.isEqual(lhsTree.getRoot(), rhsTree.getRoot());
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IBinaryTree<TKey, TValue> lhsTree, IBinaryTree<TKey, TValue> rhsTree) {
            if (lhsTree == null && rhsTree == null) {
                return 0;
            }

            if (lhsTree == null) {
                return -1;
            }

            if (rhsTree == null) {
                return 1;
            }

            return this.compareTo(lhsTree.getRoot(), rhsTree.getRoot());
        }

        /**
         * Checks whether two instances are equals.
         */
        private boolean isEqual(IBinaryTreeNode<TKey, TValue> lhsRoot, IBinaryTreeNode<TKey, TValue> rhsRoot) {
            if (lhsRoot == null && rhsRoot == null) {
                return true;
            }

            if (lhsRoot == null || rhsRoot == null) {
                return false;
            }

            return
                this.nodeComparator.isEqual(lhsRoot, rhsRoot) &&
                    this.isEqual(lhsRoot.getLeftChild(), rhsRoot.getLeftChild()) &&
                    this.isEqual(lhsRoot.getRightChild(), rhsRoot.getRightChild());
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        private int compareTo(IBinaryTreeNode<TKey, TValue> lhsRoot, IBinaryTreeNode<TKey, TValue> rhsRoot) {
            if (lhsRoot == null && rhsRoot == null) {
                return 0;
            }

            if (lhsRoot == null) {
                return -1;
            }

            if (rhsRoot == null) {
                return 1;
            }

            int result = this.nodeComparator.compareTo(lhsRoot, rhsRoot);

            if (result != 0) {
                return result;
            }

            result = this.compareTo(lhsRoot.getLeftChild(), rhsRoot.getLeftChild());

            if (result != 0) {
                return result;
            }

            return this.compareTo(lhsRoot.getRightChild(), rhsRoot.getRightChild());
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
                this.comparator = BinaryTree.DefaultComparator();
            }

            return new BinaryTree<>(this.root, this.comparator);
        }
    }
}
