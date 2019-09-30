package datastructures.trie.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.hashmap.core.HashMap;
import datastructures.map.interfaces.IMap;
import java.util.List;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import datastructures.trie.TrieException;
import datastructures.trie.interfaces.ITrieNode;

/**
 * The TrieNode class implements a node in a trie.
 */
public final class TrieNode<TKey extends Comparable<TKey>> implements ITrieNode<TKey> {
    private TKey key;
    private boolean isEndNode;
    private final IMap<TKey, ITrieNode<TKey>> children = new HashMap<>();
    private final IBinaryComparator<ITrieNode<TKey>> comparator;
    private final int hashCode;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The TrieNode constructor.
     */
    public TrieNode() {
        this(
            null,
            false,
            TrieNode.defaultComparator());
    }

    /**
     * The TrieNode constructor.
     */
    public TrieNode(
        TKey key,
        boolean isEndNode) {

        this(
            key,
            isEndNode,
            TrieNode.defaultComparator());
    }

    /**
     * The TrieNode constructor.
     */
    public TrieNode(
        TKey key,
        boolean isEndNode,
        IBinaryComparator<ITrieNode<TKey>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a trie node.");

        this.key = key;
        this.isEndNode = isEndNode;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets a key of the node.
     */
    @Override
    public TKey getKey() {
        return this.key;
    }

    /**
     * Returns whether this is an end node.
     */
    @Override
    public boolean isEndNode() {
        return this.isEndNode;
    }

    /**
     * Gets children of the node.
     */
    @Override
    public List<ITrieNode<TKey>> getChildren() {
        return this.children.getValues();
    }

    /**
     * Gets an iterator of children of the node.
     */
    @Override
    public IIterator<ITrieNode<TKey>> getChildrenIterator() {
        return this.children.getValueIterator();
    }

    /**
     * Gets a reverse iterator of children of the node.
     */
    @Override
    public IReverseIterator<ITrieNode<TKey>> getChildrenReverseIterator() {
        return this.children.getValueReverseIterator();
    }

    /**
     * Adds a child to the node.
     */
    @Override
    public void addChild(ITrieNode<TKey> child) {
        Conditions.validateNotNull(
            child,
            "The child for adding.");

        this.children.set(child.getKey(), child);
    }

    /**
     * Adds a specific child of the node.
     */
    @Override
    public ITrieNode<TKey> getChild(TKey key) {
        ITrieNode<TKey> child = this.children.get(key);

        if (child == null) {
            String errorMessage = "The child with key: " + key + " does not exist in the trie.";

            this.log.error(errorMessage);
            throw new TrieException(errorMessage);
        }

        return child;
    }

    /**
     * Checks whether a child exists.
     */
    @Override
    public boolean hasChild(TKey key) {
        return this.children.containsKey(key);
    }

    /**
     * Gets a hash code of this instance.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Gets the hash code of this instance.
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
    public boolean isEqual(ITrieNode<TKey> other) {
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
    public int compareTo(ITrieNode<TKey> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>> IBinaryComparator<ITrieNode<TKey>> defaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a node of a trie.
     */
    public static final class Comparator<TKey extends Comparable<TKey>>
        extends AbstractBinaryComparator<ITrieNode<TKey>> {

        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TKey> keyComparator) {
            Conditions.validateNotNull(
                keyComparator,
                "The comparator of a key of a node of a trie.");

            this.keyComparator = keyComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITrieNode<TKey> obj) {
            return new HashCodeBuilder(3, 5)
                .withObject(obj.getKey(), this.keyComparator)
                .withBoolean(obj.isEndNode())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ITrieNode<TKey> lhs, ITrieNode<TKey> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getKey(), rhs.getKey(), this.keyComparator)
                .withBoolean(lhs.isEndNode(), rhs.isEndNode())
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
        public int compareTo(ITrieNode<TKey> lhs, ITrieNode<TKey> rhs) {
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
                .withBoolean(lhs.isEndNode(), rhs.isEndNode())
                .build();
        }
    }
}
