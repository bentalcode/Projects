package trie.core;

import base.core.Casting;
import base.core.CollectionIterator;
import base.core.Conditions;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import base.interfaces.IHashCodeBuilder;
import base.interfaces.IIterator;
import base.interfaces.IVisitor;
import trie.interfaces.ITrie;
import trie.interfaces.ITrieNode;
import trie.interfaces.ITrieTraversal;
import java.util.Collection;

/**
 * The Trie class implements a trie.
 */
public final class Trie<TKey extends Comparable<TKey>, TValue> implements ITrie<TKey, TValue> {
    private ITrieNode<TKey, TValue> root;
    private final IBinaryComparator<ITrie<TKey, TValue>> comparator;

    /**
     * The Trie constructor.
     */
    public Trie() {
        this(null, Trie.DefaultComparator());
    }

    /**
     * The Trie constructor.
     */
    public Trie(IBinaryComparator<ITrie<TKey, TValue>> comparator) {
        this(null, comparator);
    }

    /**
     * The Trie constructor.
     */
    public Trie(
        ITrieNode<TKey, TValue> root,
        IBinaryComparator<ITrie<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The trie comparator.");

        this.root = root;
        this.comparator = comparator;
    }

    /**
     * Gets a root of a trie.
     */
    @Override
    public ITrieNode<TKey, TValue> getRoot() {
        return this.root;
    }

    /**
     * Sets a root of a trie.
     */
    @Override
    public void setRoot(ITrieNode<TKey, TValue> root) {
        this.root = root;
    }

    /**
     * Gets an interface of a trie traversal.
     */
    @Override
    public ITrieTraversal<TKey , TValue> getTrieTraversal() {
        return this.getTrieTraversal(TrieNode.DefaultComparator());
    }

    /**
     * Gets an interface of a trie traversal.
     */
    @Override
    public ITrieTraversal<TKey , TValue> getTrieTraversal(IBinaryComparator<ITrieNode<TKey, TValue>> nodeComparator) {
        return new TrieTraversal<>(nodeComparator);
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
    public boolean isEqual(ITrie<TKey, TValue> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    public int compareTo(ITrie<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ITrie<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<ITrieNode<TKey, TValue>> nodeComparator = TrieNode.DefaultComparator();
        return new Trie.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a trie.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> implements IBinaryComparator<ITrie<TKey, TValue>> {
        private final IBinaryComparator<ITrieNode<TKey, TValue>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<ITrieNode<TKey, TValue>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a node of a trie.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITrie<TKey, TValue> obj) {
            if (obj == null) {
                return 0;
            }

            IHashCodeBuilder hashCodeBuilder = new HashCodeBuilder(3, 5);
            IVisitor<ITrieNode<TKey, TValue>> visitor = new HashCodeVisitor<>(
                hashCodeBuilder,
                this.nodeComparator);

            ITrieTraversal<TKey, TValue> traversal = obj.getTrieTraversal();
            traversal.breadthFirstSearch(obj.getRoot(), visitor);

            return hashCodeBuilder.build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ITrie<TKey, TValue> lhsTrie, ITrie<TKey, TValue> rhsTrie) {
            if (lhsTrie == null && rhsTrie == null) {
                return true;
            }

            if (lhsTrie == null || rhsTrie == null) {
                return false;
            }

            return this.isEqual(lhsTrie.getRoot(), rhsTrie.getRoot());
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ITrieNode<TKey, TValue> lhsRoot, ITrieNode<TKey, TValue> rhsRoot) {
            if (lhsRoot == null && rhsRoot == null) {
                return true;
            }

            if (lhsRoot == null || rhsRoot == null) {
                return false;
            }

            if (!this.nodeComparator.isEqual(lhsRoot, rhsRoot)) {
                return false;
            }

            Collection<ITrieNode<TKey, TValue>> lhsChildren = lhsRoot.getChildren();
            Collection<ITrieNode<TKey, TValue>> rhsChildren = rhsRoot.getChildren();

            if (lhsChildren.size() != rhsChildren.size()) {
                return false;
            }

            IIterator<ITrieNode<TKey, TValue>> lhsChildrenIterator = CollectionIterator.of(lhsChildren);
            IIterator<ITrieNode<TKey, TValue>> rhsChildrenIterator = CollectionIterator.of(rhsChildren);

            while (lhsChildrenIterator.hasNext() && rhsChildrenIterator.hasNext()) {
                ITrieNode<TKey, TValue> lhsChild = lhsChildrenIterator.next();
                ITrieNode<TKey, TValue> rhsChild = rhsChildrenIterator.next();

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
        public int compareTo(ITrie<TKey, TValue> lhsTrie, ITrie<TKey, TValue> rhsTrie) {
            if (lhsTrie == null && rhsTrie == null) {
                return 0;
            }

            if (lhsTrie == null) {
                return -1;
            }

            if (rhsTrie == null) {
                return 1;
            }

            return this.compareTo(lhsTrie.getRoot(), rhsTrie.getRoot());
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        public int compareTo(ITrieNode<TKey, TValue> lhsRoot, ITrieNode<TKey, TValue> rhsRoot) {
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

            Collection<ITrieNode<TKey, TValue>> lhsChildren = lhsRoot.getChildren();
            Collection<ITrieNode<TKey, TValue>> rhsChildren = rhsRoot.getChildren();

            if (lhsChildren.size() < rhsChildren.size()) {
                return -1;
            }

            if (lhsChildren.size() > rhsChildren.size()) {
                return 1;
            }

            IIterator<ITrieNode<TKey, TValue>> lhsChildrenIterator = CollectionIterator.of(lhsChildren);
            IIterator<ITrieNode<TKey, TValue>> rhsChildrenIterator = CollectionIterator.of(rhsChildren);

            while (lhsChildrenIterator.hasNext() && rhsChildrenIterator.hasNext()) {
                ITrieNode<TKey, TValue> lhsChild = lhsChildrenIterator.next();
                ITrieNode<TKey, TValue> rhsChild = rhsChildrenIterator.next();

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
     * The Builder class implements a builder for creating levels of a trie.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<ITrie<TKey, TValue>> {
        private ITrieNode<TKey, TValue> root;
        private IBinaryComparator<ITrie<TKey, TValue>> comparator;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets the root of a trie.
         */
        public Trie.Builder<TKey, TValue> setRoot(ITrieNode<TKey, TValue> root) {
            Conditions.validateNotNull(
                root,
                "The root of a trie.");

            this.root = root;

            return this;
        }

        /**
         * Adds a node.
         */
        public Trie.Builder<TKey, TValue> addNode(
            ITrieNode<TKey, TValue> parentNode,
            ITrieNode<TKey, TValue> childNode) {

            Conditions.validateNotNull(
                parentNode,
                "The parent node of a new child node.");

            Conditions.validateNotNull(
                childNode,
                "The child node to add to a parent node.");

            parentNode.addChild(childNode);

            return this;
        }

        /**
         * Sets the comparator of a trie.
         */
        public Trie.Builder<TKey, TValue> setComparator(IBinaryComparator<ITrie<TKey, TValue>> comparator) {
            Conditions.validateNotNull(
                comparator,
                "The comparator of a trie.");

            this.comparator = comparator;

            return this;
        }

        /**
         * Builds the trie.
         */
        @Override
        public ITrie<TKey, TValue> build() {
            if (this.comparator == null) {
                this.comparator = Trie.DefaultComparator();
            }

            return new Trie<>(this.root, this.comparator);
        }
    }

    /**
     * The HashCodeVisitor class implements a visitor for calculating the hash code of the trie.
     */
    private static class HashCodeVisitor<TKey extends Comparable<TKey>, TValue> implements IVisitor<ITrieNode<TKey, TValue>> {
        public final IHashCodeBuilder hashCodeBuilder;
        private final IBinaryComparator<ITrieNode<TKey, TValue>> comparator;

        /**
         * The HashCodeVisitor constructor.
         */
        public HashCodeVisitor(
            IHashCodeBuilder hashCodeBuilder,
            IBinaryComparator<ITrieNode<TKey, TValue>> comparator) {
            this.hashCodeBuilder = hashCodeBuilder;
            this.comparator = comparator;
        }

        /**
         * Visits a node in the trie.
         */
        @Override
        public void visit(ITrieNode<TKey, TValue> root) {
            if (root == null) {
                return;
            }

            this.hashCodeBuilder.withObject(root, this.comparator);
        }
    }
}
