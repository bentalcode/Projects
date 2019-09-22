package datastructures.tree.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import datastructures.collections.core.CollectionIterator;
import base.core.Conditions;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import base.interfaces.IHashCodeBuilder;
import base.interfaces.IIterator;
import base.interfaces.IVisitor;
import datastructures.tree.interfaces.ITree;
import datastructures.tree.interfaces.ITreeNode;
import datastructures.tree.interfaces.ITreeTraversal;

import java.util.Collection;

/**
 * The Tree class implements a generic tree.
 */
public final class Tree<TKey extends Comparable<TKey>, TValue> implements ITree<TKey, TValue> {
    private ITreeNode<TKey, TValue> root;
    private final IBinaryComparator<ITree<TKey, TValue>> comparator;

    /**
     * The Tree constructor.
     */
    public Tree() {
        this(null, Tree.defaultComparator());
    }

    /**
     * The Tree constructor.
     */
    public Tree(IBinaryComparator<ITree<TKey, TValue>> comparator) {
        this(null, comparator);
    }

    /**
     * The Tree constructor.
     */
    public Tree(
        ITreeNode<TKey, TValue> root,
        IBinaryComparator<ITree<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The tree comparator.");

        this.root = root;
        this.comparator = comparator;
    }

    /**
     * Gets a root of a tree.
     */
    @Override
    public ITreeNode<TKey, TValue> getRoot() {
        return this.root;
    }

    /**
     * Sets a root of a tree.
     */
    @Override
    public void setRoot(ITreeNode<TKey, TValue> root) {
        this.root = root;
    }

    /**
     * Gets an interface of a tree traversal.
     */
    @Override
    public ITreeTraversal<TKey , TValue> getTreeTraversal() {
        return this.getTreeTraversal(TreeNode.defaultComparator());
    }

    /**
     * Gets an interface of a tree traversal.
     */
    @Override
    public ITreeTraversal<TKey , TValue> getTreeTraversal(IBinaryComparator<ITreeNode<TKey, TValue>> nodeComparator) {
        return new TreeTraversal<>(nodeComparator);
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
    public boolean isEqual(ITree<TKey, TValue> other) {
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
    public int compareTo(ITree<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ITree<TKey, TValue>> defaultComparator() {
        IBinaryComparator<ITreeNode<TKey, TValue>> nodeComparator = TreeNode.defaultComparator();
        return new Tree.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<ITree<TKey, TValue>> {

        private final IBinaryComparator<ITreeNode<TKey, TValue>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<ITreeNode<TKey, TValue>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a node of a tree.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITree<TKey, TValue> obj) {
            if (obj == null) {
                return 0;
            }

            IHashCodeBuilder hashCodeBuilder = new HashCodeBuilder(3, 5);
            IVisitor<ITreeNode<TKey, TValue>> visitor = new HashCodeVisitor<>(
                hashCodeBuilder,
                this.nodeComparator);

            ITreeTraversal<TKey, TValue> traversal = obj.getTreeTraversal();
            traversal.breadthFirstSearch(obj.getRoot(), visitor);

            return hashCodeBuilder.build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ITree<TKey, TValue> lhsTree, ITree<TKey, TValue> rhsTree) {
            if (lhsTree == null && rhsTree == null) {
                return true;
            }

            if (lhsTree == null || rhsTree == null) {
                return false;
            }

            return this.isEqual(lhsTree.getRoot(), rhsTree.getRoot());
        }

        /**
         * Checks whether two instances are equals.
         */
        private boolean isEqual(ITreeNode<TKey, TValue> lhsRoot, ITreeNode<TKey, TValue> rhsRoot) {
            if (lhsRoot == null && rhsRoot == null) {
                return true;
            }

            if (lhsRoot == null || rhsRoot == null) {
                return false;
            }

            if (!this.nodeComparator.isEqual(lhsRoot, rhsRoot)) {
                return false;
            }

            Collection<ITreeNode<TKey, TValue>> lhsChildren = lhsRoot.getChildren();
            Collection<ITreeNode<TKey, TValue>> rhsChildren = rhsRoot.getChildren();

            if (lhsChildren.size() != rhsChildren.size()) {
                return false;
            }

            IIterator<ITreeNode<TKey, TValue>> lhsChildrenIterator = CollectionIterator.of(lhsChildren);
            IIterator<ITreeNode<TKey, TValue>> rhsChildrenIterator = CollectionIterator.of(rhsChildren);

            while (lhsChildrenIterator.hasNext() && rhsChildrenIterator.hasNext()) {
                ITreeNode<TKey, TValue> lhsChild = lhsChildrenIterator.next();
                ITreeNode<TKey, TValue> rhsChild = rhsChildrenIterator.next();

                if (!this.isEqual(lhsChild, rhsChild)) {
                    return false;
                }
            }

            assert(!lhsChildrenIterator.hasNext() && !rhsChildrenIterator.hasNext());

            return true;
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(ITree<TKey, TValue> lhsTree, ITree<TKey, TValue> rhsTree) {
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
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        private int compareTo(ITreeNode<TKey, TValue> lhsRoot, ITreeNode<TKey, TValue> rhsRoot) {
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

            Collection<ITreeNode<TKey, TValue>> lhsChildren = lhsRoot.getChildren();
            Collection<ITreeNode<TKey, TValue>> rhsChildren = rhsRoot.getChildren();

            if (lhsChildren.size() < rhsChildren.size()) {
                return -1;
            }

            if (lhsChildren.size() > rhsChildren.size()) {
                return 1;
            }

            IIterator<ITreeNode<TKey, TValue>> lhsChildrenIterator = CollectionIterator.of(lhsChildren);
            IIterator<ITreeNode<TKey, TValue>> rhsChildrenIterator = CollectionIterator.of(rhsChildren);

            while (lhsChildrenIterator.hasNext() && rhsChildrenIterator.hasNext()) {
                ITreeNode<TKey, TValue> lhsChild = lhsChildrenIterator.next();
                ITreeNode<TKey, TValue> rhsChild = rhsChildrenIterator.next();

                result = this.compareTo(lhsChild, rhsChild);

                if (result != 0) {
                    return result;
                }
            }

            assert(!lhsChildrenIterator.hasNext() && !rhsChildrenIterator.hasNext());

            return result;
        }
    }

    /**
     * The Builder class implements a builder for creating levels of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<ITree<TKey, TValue>> {
        private ITreeNode<TKey, TValue> root;
        private IBinaryComparator<ITree<TKey, TValue>> comparator;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets the root of a tree.
         */
        public Tree.Builder<TKey, TValue> setRoot(ITreeNode<TKey, TValue> root) {
            Conditions.validateNotNull(
                root,
                "The root of a tree.");

            this.root = root;

            return this;
        }

        /**
         * Adds a node.
         */
        public Tree.Builder<TKey, TValue> addNode(
            ITreeNode<TKey, TValue> parentNode,
            ITreeNode<TKey, TValue> childNode) {

            Conditions.validateNotNull(
                parentNode,
                "The parent node of a new child node.");

            Conditions.validateNotNull(
                childNode,
                "The child node to add to a parent node.");

            parentNode.getChildren().add(childNode);

            return this;
        }

        /**
         * Sets the comparator of a tree.
         */
        public Tree.Builder<TKey, TValue> setComparator(IBinaryComparator<ITree<TKey, TValue>> comparator) {
            Conditions.validateNotNull(
                comparator,
                "The comparator of a tree.");

            this.comparator = comparator;

            return this;
        }

        /**
         * Builds the tree.
         */
        @Override
        public ITree<TKey, TValue> build() {
            if (this.comparator == null) {
                this.comparator = Tree.defaultComparator();
            }

            return new Tree<>(this.root, this.comparator);
        }
    }

    /**
     * The HashCodeVisitor class implements a visitor for calculating the hash code of the tree.
     */
    private static class HashCodeVisitor<TKey extends Comparable<TKey>, TValue> implements IVisitor<ITreeNode<TKey, TValue>> {
        public final IHashCodeBuilder hashCodeBuilder;
        private final IBinaryComparator<ITreeNode<TKey, TValue>> comparator;

        /**
         * The HashCodeVisitor constructor.
         */
        public HashCodeVisitor(
            IHashCodeBuilder hashCodeBuilder,
            IBinaryComparator<ITreeNode<TKey, TValue>> comparator) {
            this.hashCodeBuilder = hashCodeBuilder;
            this.comparator = comparator;
        }

        /**
         * Visits a node in the tree.
         */
        @Override
        public void visit(ITreeNode<TKey, TValue> root) {
            if (root == null) {
                return;
            }

            this.hashCodeBuilder.withObject(root, this.comparator);
        }
    }
}
