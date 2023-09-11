package datastructures.trie.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.ListIterator;
import base.interfaces.IBuilder;
import datastructures.collections.core.CollectionIterator;
import base.core.Conditions;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IHashCodeBuilder;
import base.interfaces.IIterator;
import base.interfaces.IVisitor;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.trie.interfaces.ITrie;
import datastructures.trie.interfaces.ITrieNode;
import datastructures.trie.interfaces.ITrieTraversal;
import java.util.List;

/**
 * The Trie class implements a trie.
 */
public final class Trie<TKey extends Comparable<TKey>> implements ITrie<TKey> {
    private final ITrieNode<TKey> root;
    private final IBinaryComparator<ITrie<TKey>> comparator;
    private final int hashCode;

    /**
     * The Trie constructor.
     */
    public Trie() {
        this(
            new TrieNode<>(),
            Trie.defaultComparator());
    }

    /**
     * The Trie constructor.
     */
    public Trie(
        ITrieNode<TKey> root,
        IBinaryComparator<ITrie<TKey>> comparator) {

        Conditions.validateNotNull(
            root,
            "The root of a trie.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a trie.");

        this.root = root;
        this.comparator = comparator;
        this.hashCode = this.comparator.getHashCode(this);
    }

    /**
     * Gets a root of a trie.
     */
    @Override
    public ITrieNode<TKey> getRoot() {
        return this.root;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        serialize(this.root, stringBuilder);
        return stringBuilder.toString();
    }

    private static <TKey extends Comparable<TKey>> void serialize(
        ITrieNode<TKey> root,
        StringBuilder stringBuilder) {

        if (root == null) {
            return;
        }

        stringBuilder.append(root);

        for (ITrieNode<TKey> childNode : root.getChildren()) {
            serialize(childNode, stringBuilder);
        }

        stringBuilder.append(")");
    }

    /**
     * Gets an iterator of the trie.
     */
    @Override
    public IIterator<IKeyValueNode<TKey, Boolean>> getIterator() {
        return TrieIterator.make(this.root);
    }

    /**
     * Gets an interface of a trie traversal.
     */
    @Override
    public ITrieTraversal<TKey> getTrieTraversal() {
        return new TrieTraversal<>();
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
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
    public boolean isEqual(ITrie<TKey> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    public int compareTo(ITrie<TKey> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>> IBinaryComparator<ITrie<TKey>> defaultComparator() {
        IBinaryComparator<ITrieNode<TKey>> nodeComparator = TrieNode.defaultComparator();
        return new Trie.Comparator<>(nodeComparator);
    }

    /**
     * The Comparator class implements a comparator of a trie.
     */
    public static final class Comparator<TKey extends Comparable<TKey>> extends AbstractBinaryComparator<ITrie<TKey>> {
        private final IBinaryComparator<ITrieNode<TKey>> nodeComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<ITrieNode<TKey>> nodeComparator) {
            Conditions.validateNotNull(
                nodeComparator,
                "The comparator of a node of a trie.");

            this.nodeComparator = nodeComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITrie<TKey> obj) {
            if (obj == null) {
                return 0;
            }

            IHashCodeBuilder hashCodeBuilder = new HashCodeBuilder(719, 727);
            IVisitor<ITrieNode<TKey>> visitor = new HashCodeVisitor<>(
                hashCodeBuilder,
                this.nodeComparator);

            ITrieTraversal<TKey> traversal = obj.getTrieTraversal();
            traversal.breadthFirstSearch(obj.getRoot(), visitor);

            return hashCodeBuilder.build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ITrie<TKey> lhsTrie, ITrie<TKey> rhsTrie) {
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
        private boolean isEqual(ITrieNode<TKey> lhsRoot, ITrieNode<TKey> rhsRoot) {
            if (lhsRoot == null && rhsRoot == null) {
                return true;
            }

            if (lhsRoot == null || rhsRoot == null) {
                return false;
            }

            if (!this.nodeComparator.isEqual(lhsRoot, rhsRoot)) {
                return false;
            }

            List<ITrieNode<TKey>> lhsChildren = lhsRoot.getChildren();
            List<ITrieNode<TKey>> rhsChildren = rhsRoot.getChildren();

            if (lhsChildren.size() != rhsChildren.size()) {
                return false;
            }

            IIterator<ITrieNode<TKey>> lhsChildrenIterator = CollectionIterator.make(lhsChildren);
            IIterator<ITrieNode<TKey>> rhsChildrenIterator = CollectionIterator.make(rhsChildren);

            while (lhsChildrenIterator.hasNext() && rhsChildrenIterator.hasNext()) {
                ITrieNode<TKey> lhsChild = lhsChildrenIterator.next();
                ITrieNode<TKey> rhsChild = rhsChildrenIterator.next();

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
        public int compareTo(ITrie<TKey> lhsTrie, ITrie<TKey> rhsTrie) {
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
        private int compareTo(ITrieNode<TKey> lhsRoot, ITrieNode<TKey> rhsRoot) {
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

            List<ITrieNode<TKey>> lhsChildren = lhsRoot.getChildren();
            List<ITrieNode<TKey>> rhsChildren = rhsRoot.getChildren();

            if (lhsChildren.size() < rhsChildren.size()) {
                return -1;
            }

            if (lhsChildren.size() > rhsChildren.size()) {
                return 1;
            }

            IIterator<ITrieNode<TKey>> lhsChildrenIterator = CollectionIterator.make(lhsChildren);
            IIterator<ITrieNode<TKey>> rhsChildrenIterator = CollectionIterator.make(rhsChildren);

            while (lhsChildrenIterator.hasNext() && rhsChildrenIterator.hasNext()) {
                ITrieNode<TKey> lhsChild = lhsChildrenIterator.next();
                ITrieNode<TKey> rhsChild = rhsChildrenIterator.next();

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
    public static final class Builder<TKey extends Comparable<TKey>> implements IBuilder<ITrie<TKey>> {
        private final ITrieNode<TKey> root = new TrieNode<>();
        private IBinaryComparator<ITrie<TKey>> comparator;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a sequence to a trie.
         */
        public Trie.Builder<TKey> addSequence(List<TKey> sequence) {
            Conditions.validateNotNull(
                sequence,
                "The sequence to add to a trie.");

            return this.addSequence(ListIterator.make(sequence));
        }

        /**
         * Adds a sequence to a trie.
         */
        public Trie.Builder<TKey> addSequence(IIterator<TKey> iterator) {
            Conditions.validateNotNull(
                iterator,
                "The iterator of a sequence to add to a trie.");

            ITrieNode<TKey> currNode = root;

            while (iterator.hasNext()) {
                TKey key = iterator.next();

                if (currNode.hasChild(key)) {
                    currNode = currNode.getChild(key);
                }
                else {
                    boolean isEndNode = !iterator.hasNext();
                    ITrieNode<TKey> newChild = new TrieNode<>(key, isEndNode);
                    currNode.addChild(newChild);

                    currNode = newChild;
                }
            }

            return this;
        }

        /**
         * Sets the comparator of a trie.
         */
        public Trie.Builder<TKey> setComparator(IBinaryComparator<ITrie<TKey>> comparator) {
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
        public ITrie<TKey> build() {
            if (this.comparator == null) {
                this.comparator = Trie.defaultComparator();
            }

            return new Trie<>(this.root, this.comparator);
        }
    }

    /**
     * The HashCodeVisitor class implements a visitor for calculating the hash code of the trie.
     */
    private static class HashCodeVisitor<TKey extends Comparable<TKey>> implements IVisitor<ITrieNode<TKey>> {
        public final IHashCodeBuilder hashCodeBuilder;
        private final IBinaryComparator<ITrieNode<TKey>> comparator;

        /**
         * The HashCodeVisitor constructor.
         */
        public HashCodeVisitor(
            IHashCodeBuilder hashCodeBuilder,
            IBinaryComparator<ITrieNode<TKey>> comparator) {
            this.hashCodeBuilder = hashCodeBuilder;
            this.comparator = comparator;
        }

        /**
         * Visits a node in the trie.
         */
        @Override
        public void visit(ITrieNode<TKey> root) {
            if (root == null) {
                return;
            }

            this.hashCodeBuilder.withObject(root, this.comparator);
        }
    }
}
