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
import datastructures.node.core.KeyValueNodeKeyIterator;
import datastructures.node.core.KeyValueNodeKeyReverseIterator;
import datastructures.node.core.KeyValueNodeValueIterator;
import datastructures.node.core.KeyValueNodeValueReverseIterator;
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

        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currentNode;

        if (this.data.dataLookup().containsKey(key)) {
            //
            // If the key is set in the cache, update it's value...
            //
            currentNode = this.data.dataLookup().get(key);
            currentNode.getValue().setValue(value);

            this.currentItemAccessed(currentNode);
        }
        else {
            //
            // If the cache is over it's capacity, then make available space for the new item...
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

            currentNode = DoublyLinkedListNode.of(KeyValueNode.of(key, value));

            this.newItemAccessed(currentNode);
        }
    }

    /**
     * Gets a value of a specific key in the cache.
     * Complexity: O(1)
     */
    @Override
    public TValue get(TKey key) {
        this.validateKey(key);

        //
        // Get the current value of the node...
        //
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currentNode = this.data.dataLookup().get(key);
        this.validateKeyExists(key, currentNode);

        TValue currentValue = currentNode.getValue().getValue();

        //
        // Mark that the item is accessed...
        //
        this.currentItemAccessed(currentNode);

        return currentValue;
    }

    /**
     * Deletes a key and it's associated value from the cache.
     *
     * Returns true if the key has been removed successfully from the cache.
     * Returns false if the key is not in the cache.
     *
     * Complexity: O(1)
     */
    @Override
    public boolean delete(TKey key) {
        this.validateKey(key);

        if (!this.data.dataLookup().containsKey(key)) {
            return false;
        }

        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node = this.data.dataLookup().get(key);

        this.data.usedList().remove(node);
        this.data.dataLookup().remove(key);

        return true;
    }

    /**
     * Checks whether a key is set in the cache.
     * Complexity: O(1)
     */
    @Override
    public boolean has(TKey key) {
        return this.data.dataLookup().containsKey(key);
    }

    /**
     * Gets an iterator of data of a cache.
     */
    @Override
    public IIterator<IKeyValueNode<TKey, TValue>> getIterator() {
        IIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> iterator = this.data.usedList().getIterator();
        return DoublyLinkedListKeyValueNodeIterator.of(iterator);
    }

    /**
     * Gets a reverse iterator of data of a cache.
     */
    @Override
    public IReverseIterator<IKeyValueNode<TKey, TValue>> getReverseIterator() {
        IReverseIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> reverseIterator = this.data.usedList().getReverseIterator();
        return DoublyLinkedListKeyValueNodeReverseIterator.of(reverseIterator);
    }

    /**
     * Gets an iterator of keys of a cache.
     */
    @Override
    public IIterator<TKey> getKeyIterator() {
        IIterator<IKeyValueNode<TKey, TValue>> iterator = this.getIterator();
        return KeyValueNodeKeyIterator.of(iterator);
    }

    /**
     * Gets a reverse iterator of keys of a cache.
     */
    @Override
    public IReverseIterator<TKey> getKeyReverseIterator() {
        IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator = this.getReverseIterator();
        return KeyValueNodeKeyReverseIterator.of(reverseIterator);
    }

    /**
     * Gets an iterator of values of a cache.
     */
    @Override
    public IIterator<TValue> getValueIterator() {
        IIterator<IKeyValueNode<TKey, TValue>> iterator = this.getIterator();
        return KeyValueNodeValueIterator.of(iterator);
    }

    /**
     * Gets a reverse iterator of values of a cache.
     */
    @Override
    public IReverseIterator<TValue> getValueReverseIterator() {
        IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator = this.getReverseIterator();
        return KeyValueNodeValueReverseIterator.of(reverseIterator);
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
        return this.size() == 0;
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
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.defaultComparator();
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
            return new HashCodeBuilder(3, 5)
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
     * Determines whether the used-list has reached it's maximum capacity.
     */
    private boolean overCapacity() {
        return this.size() >= this.properties.getCapacity();
    }

    /**
     * Processes accessing a current item.
     */
    private void currentItemAccessed(IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node) {
        this.data.usedList().remove(node);
        this.data.usedList().addToFront(node);
    }

    /**
     * Processes accessing a new item.
     */
    private void newItemAccessed(IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node) {
        this.data.dataLookup.put(node.getValue().getKey(), node);
        this.data.usedList().addToFront(node);
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
     * Validates a key exists.
     */
    private void validateKeyExists(TKey key, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currentNode) {
        if (currentNode == null || !key.equals(currentNode.getValue().getKey())) {
            String errorMessage = "The key: " + key + " is not set in the cache.";

            this.log.error(errorMessage);
            throw new CacheException(errorMessage);
        }
    }

    /**
     * The CacheData class captures the internal data of a cache.
     */
    protected final class CacheData<TKey extends Comparable<TKey>, TValue> {
        private final Map<TKey, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> dataLookup = new HashMap<>();
        private final DoublyLinkedList<IKeyValueNode<TKey, TValue>> usedList = new DoublyLinkedList<>();

        /**
         * The CacheData constructor.
         */
        protected CacheData() {
        }

        /**
         * Gets the data lookup.
         */
        protected Map<TKey, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> dataLookup() {
            return this.dataLookup;
        }

        /**
         * Gets the data lookup.
         */
        protected DoublyLinkedList<IKeyValueNode<TKey, TValue>> usedList() {
            return this.usedList;
        }
    }
}
