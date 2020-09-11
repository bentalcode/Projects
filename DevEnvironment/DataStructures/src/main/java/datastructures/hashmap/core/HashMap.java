package datastructures.hashmap.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IPair;
import base.interfaces.IReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.hashmap.interfaces.IHashMap;
import datastructures.hashmap.interfaces.IHashMapConstants;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The HashMap class implements a hash map.
 *
 * Note:
 *  HashMap is implemented as a hash table, and there is no ordering on keys or values.
 *  TreeMap is implemented based on red-black tree structure, and it is ordered by the key.
 *  LinkedHashMap preserves the insertion order.
 */
public final class HashMap<TKey extends Comparable<TKey>, TValue>
    extends AbstractHashMap<TKey, TValue> implements IHashMap<TKey, TValue> {

    private final IBinaryComparator<IHashMap<TKey, TValue>> comparator;

    /**
     * The HashMap constructor.
     */
    public HashMap() {
        this(
            IHashMapConstants.DefaultCapacity,
            IHashMapConstants.DefaultLoadFactor,
            HashMap.defaultComparator(),
            base.core.Comparator.make());
    }

    /**
     * The HashMap constructor.
     */
    public HashMap(
        int capacity,
        double loadFactor,
        IBinaryComparator<TKey> keyComparator) {
        this(
            capacity,
            loadFactor,
            HashMap.defaultComparator(),
            keyComparator);
    }

    /**
     * The HashMap constructor.
     */
    public HashMap(
        int capacity,
        double loadFactor,
        IBinaryComparator<IHashMap<TKey, TValue>> comparator,
        IBinaryComparator<TKey> keyComparator) {

        super(
            capacity,
            loadFactor,
            keyComparator);

        Conditions.validateNotNull(
            comparator,
            "The comparator of a hash map.");

        this.comparator = comparator;
    }

    /**
     * Sets a value for a specific key.
     *
     * Returns true for a creation of a key-value pair.
     * Returns false for an update of a key-value pair.
     */
    @Override
    public boolean set(TKey key, TValue value) {
        //
        // Update or create a key-value node...
        //
        IPair<Boolean, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> result = this.setKeyValueNode(key, value);
        return result.first();
    }

    /**
     * Removes a key from the map.
     * Returns the corresponding removed value, or null if the key was not found.
     */
    @Override
    public IKeyValueNode<TKey, TValue> remove(TKey key) {
        //
        // Remove the corresponding node of the specified key...
        //
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> removedNode = this.removeNode(key);

        //
        // If the corresponding node is not found, then simply return null...
        //
        if (removedNode == null) {
            return null;
        }

        return removedNode.getValue();
    }

    /**
     * Gets the internal iterator of a hash map.
     */
    @Override
    protected IIterator<IKeyValueNode<TKey, TValue>> getInternalIterator(
        List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header) {

        return HashMapInternalIterator.make(header);
    }

    /**
     * Gets the internal reverse iterator of a hash map.
     */
    @Override
    protected IReverseIterator<IKeyValueNode<TKey, TValue>> getInternalReverseIterator(
        List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header) {

        return HashMapInternalReverseIterator.make(header);
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
    public boolean isEqual(IHashMap<TKey, TValue> other) {
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
    public int compareTo(IHashMap<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IHashMap<TKey, TValue>> defaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.make();
        IBinaryComparator<IKeyValueNode<TKey, TValue>> comparator = new KeyValueNode.Comparator<>(keyComparator);

        return new Comparator<>(
            comparator,
            keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a hash map.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IHashMap<TKey, TValue>> {

        private final IBinaryComparator<IKeyValueNode<TKey, TValue>> comparator;
        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(
            IBinaryComparator<IKeyValueNode<TKey, TValue>> comparator,
            IBinaryComparator<TKey> keyComparator) {

            Conditions.validateNotNull(
                comparator,
                "The comparator of a key-value node.");

            Conditions.validateNotNull(
                keyComparator,
                "The comparator of a key.");

            this.comparator = comparator;
            this.keyComparator = keyComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IHashMap<TKey, TValue> obj) {
            return new HashCodeBuilder(541, 547)
                .withIterator(obj.getKeyIterator(), this.keyComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IHashMap<TKey, TValue> lhs, IHashMap<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.comparator)
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
        public int compareTo(IHashMap<TKey, TValue> lhs, IHashMap<TKey, TValue> rhs) {
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
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.comparator)
                .build();
        }
    }
}
