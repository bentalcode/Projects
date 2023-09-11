package datastructures.cache.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.cache.CacheException;
import datastructures.cache.interfaces.ICache;
import datastructures.cache.interfaces.ICacheProperties;
import base.core.Collections;
import datastructures.doublylinkedlist.core.DoublyLinkedList;
import datastructures.doublylinkedlist.core.DoublyLinkedListKeyValueNodeIterator;
import datastructures.doublylinkedlist.core.DoublyLinkedListKeyValueNodeReverseIterator;
import datastructures.doublylinkedlist.core.DoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.node.core.KeyValueNode;
import datastructures.node.core.KeyIterator;
import datastructures.node.core.KeyReverseIterator;
import datastructures.node.core.ValueIterator;
import datastructures.node.core.ValueReverseIterator;
import datastructures.node.interfaces.IKeyValueNode;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.HashMap;
import java.util.Map;

/**
 * The AbstractCache class implements an abstract cache.
 */
public abstract class AbstractCache<TKey extends Comparable<TKey>, TValue> implements ICache<TKey, TValue> {
    private final ICacheProperties properties;
    private final CacheData<TKey, TValue> data = new CacheData<>();
    private final IBinaryComparator<ICache<TKey, TValue>> comparator;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The AbstractCache constructor.
     */
    protected AbstractCache(
        ICacheProperties properties,
        IBinaryComparator<ICache<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            properties,
            "The properties of a cache.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a cache.");

        this.properties = properties;
        this.comparator = comparator;
    }

    /**
     * Gets properties of a cache.
     */
    @Override
    public ICacheProperties getProperties() {
        return this.properties;
    }

    /**
     * Set a new key in the cache.
     * Complexity: O(1)
     */
    @Override
    public void set(TKey key, TValue value) {
        this.validateKey(key);

        if (this.has(key)) {
            //
            // If the key is set in the cache, update its value...
            //
            IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currNode = this.data.getKeyValueNode(key);
            currNode.getValue().setValue(value);

            this.currentItemAccessed(currNode);
        }
        else {
            //
            // If the cache is over its capacity, then make available space for the new item...
            //
            if (this.overCapacity()) {
                assert(this.properties.getNumberOfItemsForMakingAvailableSpace() <= this.size());

                this.makeAvailableSpace(
                    this.data,
                    this.properties.getNumberOfItemsForMakingAvailableSpace());

                Conditions.validate(
                    !this.overCapacity(),
                    "The cache should have an available space.");
            }

            IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currNode =
                DoublyLinkedListNode.make(KeyValueNode.make(key, value));

            this.newItemAccessed(currNode);
        }
    }

    /**
     * Gets a value of a specific key in the cache.
     * Complexity: O(1)
     */
    @Override
    public TValue get(TKey key) {
        //
        // Validate that the key exists...
        //
        this.validateKeyExists(key);

        //
        // Get the current value of the node...
        //
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currNode = this.data.getKeyValueNode(key);
        TValue currValue = currNode.getValue().getValue();

        //
        // Mark that the item is accessed...
        //
        this.currentItemAccessed(currNode);

        return currValue;
    }

    /**
     * Deletes a key, and it's associated value from the cache.
     *
     * Returns true if the key has been removed successfully from the cache.
     * Returns false if the key is not in the cache.
     *
     * Complexity: O(1)
     */
    @Override
    public boolean delete(TKey key) {
        this.validateKey(key);

        if (!this.has(key)) {
            return false;
        }

        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node = this.data.dataLookup().get(key);
        this.data.removeKeyValueNode(node);

        return true;
    }

    /**
     * Checks whether a key is set in the cache.
     * Complexity: O(1)
     */
    @Override
    public boolean has(TKey key) {
        return this.data.hasKey(key);
    }

    /**
     * Gets the size of a cache.
     */
    @Override
    public int size() {
        return this.data.dataLookup().size();
    }

    /**
     * Checks whether the cache is empty.
     */
    @Override
    public boolean empty() {
        return this.data.dataLookup().isEmpty();
    }

    /**
     * Gets an iterator of data of a cache.
     */
    @Override
    public IIterator<IKeyValueNode<TKey, TValue>> getIterator() {
        IIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> iterator = this.data.usedList().getIterator();
        return DoublyLinkedListKeyValueNodeIterator.make(iterator);
    }

    /**
     * Gets a reverse iterator of data of a cache.
     */
    @Override
    public IReverseIterator<IKeyValueNode<TKey, TValue>> getReverseIterator() {
        IReverseIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> reverseIterator = this.data.usedList().getReverseIterator();
        return DoublyLinkedListKeyValueNodeReverseIterator.make(reverseIterator);
    }

    /**
     * Gets an iterator of keys of a cache.
     */
    @Override
    public IIterator<TKey> getKeyIterator() {
        IIterator<IKeyValueNode<TKey, TValue>> iterator = this.getIterator();
        return KeyIterator.make(iterator);
    }

    /**
     * Gets a reverse iterator of keys of a cache.
     */
    @Override
    public IReverseIterator<TKey> getKeyReverseIterator() {
        IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator = this.getReverseIterator();
        return KeyReverseIterator.make(reverseIterator);
    }

    /**
     * Gets an iterator of values of a cache.
     */
    @Override
    public IIterator<TValue> getValueIterator() {
        IIterator<IKeyValueNode<TKey, TValue>> iterator = this.getIterator();
        return ValueIterator.make(iterator);
    }

    /**
     * Gets a reverse iterator of values of a cache.
     */
    @Override
    public IReverseIterator<TValue> getValueReverseIterator() {
        IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator = this.getReverseIterator();
        return ValueReverseIterator.make(reverseIterator);
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getIterator());
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
    public boolean isEqual(ICache<TKey, TValue> other) {
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
    public int compareTo(ICache<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ICache<TKey, TValue>> defaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.make();
        IBinaryComparator<IKeyValueNode<TKey, TValue>> comparator = new KeyValueNode.Comparator<>(keyComparator);

        return new Comparator<>(
            comparator,
            keyComparator);
    }

    /**
     * The Comparator class implements a comparator of a cache.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<ICache<TKey, TValue>> {

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
        public int getHashCode(ICache<TKey, TValue> obj) {
            return new HashCodeBuilder(373, 379)
                .withIterator(obj.getKeyIterator(), this.keyComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICache<TKey, TValue> lhs, ICache<TKey, TValue> rhs) {
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
        public int compareTo(ICache<TKey, TValue> lhs, ICache<TKey, TValue> rhs) {
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

    /**
     * Makes available space for the specified number of items.
     */
    protected abstract void makeAvailableSpace(
        CacheData<TKey, TValue> cacheData,
        int numberOfItems);

    /**
     * Processes accessing a current item.
     */
    private void currentItemAccessed(IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node) {
        this.data.usedList().remove(node);
        this.data.usedList().addToBack(node);
    }

    /**
     * Processes accessing a new item.
     */
    private void newItemAccessed(IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node) {
        this.data.dataLookup().put(node.getValue().getKey(), node);
        this.data.usedList().addToBack(node);
    }

    /**
     * Determines whether the used-list has reached its maximum capacity.
     */
    private boolean overCapacity() {
        return this.size() >= this.properties.getCapacity();
    }

    /**
     * Validates a key.
     */
    private void validateKey(TKey key) {
        Conditions.validateNotNull(
            key,
            "The key of a cache.");
    }

    /**
     * Validates that the key exists.
     */
    private void validateKeyExists(TKey key) {
        if (!this.has(key)) {
            String errorMessage = "The key: " + key + " is not defined in the cache.";

            this.log.error(errorMessage);
            throw new CacheException(errorMessage);
        }
    }

    /**
     * The CacheData class captures the internal data of a cache.
     */
    protected static final class CacheData<TKey extends Comparable<TKey>, TValue> {
        private final Map<TKey, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> dataLookup = new HashMap<>();
        private final DoublyLinkedList<IKeyValueNode<TKey, TValue>> usedList = new DoublyLinkedList<>();

        /**
         * The CacheData constructor.
         */
        public CacheData() {
        }

        /**
         * Gets the data lookup.
         */
        public Map<TKey, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> dataLookup() {
            return this.dataLookup;
        }

        /**
         * Gets the data lookup.
         */
        public DoublyLinkedList<IKeyValueNode<TKey, TValue>> usedList() {
            return this.usedList;
        }

        /**
         * Gets the key-value node.
         */
        public IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> getKeyValueNode(TKey key) {
            return this.dataLookup.get(key);
        }

        /**
         * Removes the key-value node.
         */
        public void removeKeyValueNode(IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node) {
            this.dataLookup.remove(node.getValue().getKey());
            this.usedList.remove(node);
        }

        /**
         * Checks whether the key exists.
         */
        public boolean hasKey(TKey key) {
            return this.dataLookup.containsKey(key);
        }
    }
}
