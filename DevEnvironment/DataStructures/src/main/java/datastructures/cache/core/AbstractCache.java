package datastructures.cache.core;

import base.core.Conditions;
import datastructures.cache.CacheException;
import datastructures.cache.interfaces.ICache;
import datastructures.cache.interfaces.ICacheProperties;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.doublylinkedlist.core.DoublyLinkedList;
import datastructures.doublylinkedlist.core.DoublyLinkedListKeyValueNodeIterator;
import datastructures.doublylinkedlist.core.DoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;
import datastructures.node.core.KeyValueNode;
import datastructures.node.core.NodeKeyIterator;
import datastructures.node.core.NodeValueIterator;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeIterator;
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

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The AbstractCache constructor.
     */
    protected AbstractCache(ICacheProperties properties) {
        Conditions.validateNotNull(
            properties,
            "The properties of a cache.");

        this.properties = properties;
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

            currentNode = new DoublyLinkedListNode<>(new KeyValueNode<>(key, value));

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
     * Complexity: O(1)
     */
    @Override
    public IKeyValueNodeIterator<TKey, TValue> getIterator() {
        IDoublyLinkedListNodeIterator<IKeyValueNode<TKey, TValue>> iterator = this.data.usedList().getIterator();
        return new DoublyLinkedListKeyValueNodeIterator<>(iterator);
    }

    /**
     * Gets an iterator of keys of a cache.
     * Complexity: O(1)
     */
    public IKeyIterator<TKey> getKeyIterator() {
        return new NodeKeyIterator<>(this.getIterator());
    }

    /**
     * Gets an iterator of values of a cache.
     * Complexity: O(1)
     */
    @Override
    public IValueIterator<TValue> getValueIterator() {
        return new NodeValueIterator<>(this.getIterator());
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
        private Map<TKey, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> dataLookup = new HashMap<>();
        private DoublyLinkedList<IKeyValueNode<TKey, TValue>> usedList = new DoublyLinkedList<>();

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
