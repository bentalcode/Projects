package datastructures.trie.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import datastructures.trie.TrieException;
import datastructures.trie.interfaces.ITrieNode;
import java.util.Collection;
import java.util.LinkedHashMap;

/**
 * The TrieNode class implements a node in a trie.
 */
public final class TrieNode<TKey extends Comparable<TKey>, TValue> implements ITrieNode<TKey, TValue> {
    private final TKey key;
    private TValue value;
    private final LinkedHashMap<TKey, ITrieNode<TKey, TValue>> children = new LinkedHashMap<>();
    private final IBinaryComparator<TKey> keyComparator;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * Creates a new trie node.
     */
    public static <TKey extends Comparable<TKey>, TValue> ITrieNode<TKey, TValue> create(TKey key) {
        return TrieNode.create(key, null);
    }

    /**
     * Creates a new trie node.
     */
    public static <TKey extends Comparable<TKey>, TValue> ITrieNode<TKey, TValue> create(TKey key, TValue value) {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.DefaultComparator();
        return TrieNode.create(key, value, keyComparator);
    }

    /**
     * Creates a new trie node.
     */
    public static <TKey extends Comparable<TKey>, TValue> ITrieNode<TKey, TValue> create(
        TKey key,
        TValue value,
        IBinaryComparator<TKey> keyComparator) {

        return new TrieNode<>(key, value, keyComparator);
    }

    /**
     * The TrieNode constructor.
     */
    private TrieNode(
        TKey key,
        IBinaryComparator<TKey> keyComparator) {
        this(
            key,
            null,
            keyComparator);
    }

    /**
     * The TrieNode constructor.
     */
    public TrieNode(
        TKey key,
        TValue value,
        IBinaryComparator<TKey> keyComparator) {

        Conditions.validateNotNull(
            keyComparator,
            "The comparator of a key of a node of a trie.");

        this.key = key;
        this.value = value;
        this.keyComparator = keyComparator;
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
    public Collection<ITrieNode<TKey, TValue>> getChildren() {
        return this.children.values();
    }

    /**
     * Adds a child to the node.
     */
    @Override
    public void addChild(ITrieNode<TKey, TValue> child) {
        Conditions.validateNotNull(
            child,
            "The child.");

        this.children.put(child.getKey(), child);
    }

    /**
     * Adds a child of the node.
     */
    @Override
    public ITrieNode<TKey, TValue> getChild(TKey key) {
        ITrieNode<TKey, TValue> child = this.children.get(key);

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
        return this.keyComparator.getHashCode(this.getKey());
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
    public boolean isEqual(ITrieNode<TKey, TValue> other) {
        boolean status = new EqualBuilder()
            .withObject(this.getKey(), other.getKey(), this.keyComparator)
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
    public int compareTo(ITrieNode<TKey, TValue> other) {
        int status = new CompareToBuilder()
            .withObject(this.getKey(), other.getKey(), this.keyComparator)
            .build();

        return status;
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ITrieNode<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.DefaultComparator();
        return new Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a node of a trie.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<ITrieNode<TKey, TValue>> {

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
        public int getHashCode(ITrieNode<TKey, TValue> obj) {
            return this.keyComparator.getHashCode(obj.getKey());
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ITrieNode<TKey, TValue> lhs, ITrieNode<TKey, TValue> rhs) {
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
        public int compareTo(ITrieNode<TKey, TValue> lhs, ITrieNode<TKey, TValue> rhs) {
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
}
