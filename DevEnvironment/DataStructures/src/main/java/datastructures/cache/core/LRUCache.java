package datastructures.cache.core;

import base.core.Conditions;
import datastructures.cache.CacheException;
import datastructures.cache.interfaces.ICacheProperties;
import datastructures.cache.interfaces.ILRUCache;
import datastructures.node.core.DoublyLinkedListNode;
import datastructures.node.core.DoublyLinkedListNodeIterator;
import datastructures.node.interfaces.IDoublyLinkedListNode;
import datastructures.node.interfaces.INodeIterator;
import datastructures.tree.core.KeyIterator;
import datastructures.tree.core.ValueIterator;
import datastructures.tree.interfaces.IKeyIterator;
import datastructures.tree.interfaces.IValueIterator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.security.Key;
import java.util.HashMap;
import java.util.Map;

/**
 * The LRUCache class implements a least recently used cache.
 * Discards the least recently used items first.
 */
public final class LRUCache<TKey extends Comparable<TKey>, TValue> implements ILRUCache<TKey, TValue> {
    private final ICacheProperties properties;

    private IDoublyLinkedListNode<TKey, TValue> usedListHead;
    private IDoublyLinkedListNode<TKey, TValue> usedListTail;
    private Map<Key, IDoublyLinkedListNode<TKey, TValue>> data = new HashMap<>();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The LRUCache constructor.
     */
    public LRUCache(ICacheProperties properties) {
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

        IDoublyLinkedListNode<TKey, TValue> currentNode;

        if (this.data.containsKey(key)) {
            //
            // If the key is set in the cache, update it's value...
            //
            currentNode = this.data.get(key);
            currentNode.setValue(value);
        }
        else {
            //
            // If the cache is over it's capacity, discard the least recently used item
            // from the back of the used list, and create a new node...
            //
            if (this.overCapacity()) {
                this.removeNodeToBackUsedList();

                Conditions.validate(
                    !this.overCapacity(),
                    "The cache should have an available space.");
            }

            currentNode = new DoublyLinkedListNode<>(key, value);
        }

        //
        // Move the node to the from of the used list...
        //
        this.moveNodeToFrontUsedList(currentNode);
    }

    /**
     * Gets a value of a specific key in the cache.
     * Complexity: O(1)
     */
    @Override
    public TValue get(TKey key) {
        this.validateKey(key);
        this.validateKeyExists(key);

        //
        // Get the current value of the node...
        //
        IDoublyLinkedListNode<TKey, TValue> currentNode = this.data.get(key);
        TValue currentValue = currentNode.getValue();

        //
        // Move the node to the from of the used list...
        //
        this.moveNodeToFrontUsedList(currentNode);

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

        if (!this.data.containsKey(key)) {
            return false;
        }

        this.data.remove(key);
        return true;
    }

    /**
     * Checks whether a key is set in the cache.
     * Complexity: O(1)
     */
    @Override
    public boolean has(TKey key) {
        return this.data.containsKey(key);
    }

    /**
     * Gets an iterator of keys of a cache.
     * Complexity: O(1)
     */
    public IKeyIterator<TKey> getKeyIterator() {
        return new KeyIterator<>(this.getDataIterator());
    }

    /**
     * Gets an iterator of values of a cache.
     * Complexity: O(1)
     */
    @Override
    public IValueIterator<TValue> getValueIterator() {
        return new ValueIterator<>(this.getDataIterator());
    }

    /**
     * Gets an iterator of data of a cache.
     * Complexity: O(1)
     */
    @Override
    public INodeIterator<TKey, TValue> getDataIterator() {
        return new DoublyLinkedListNodeIterator<>(this.usedListHead);
    }

    /**
     * Gets the size of a cache.
     */
    @Override
    public int getSize() {
        return this.data.size();
    }

    /**
     * Determines whether the used-list has reached it's maximum capacity.
     */
    private boolean overCapacity() {
        return this.getSize() >= this.properties.getCapacity();
    }

    /**
     * Moves a node to front of used-list.
     */
    private void moveNodeToFrontUsedList(IDoublyLinkedListNode<TKey, TValue> node) {
        throw new UnsupportedOperationException();
    }

    /**
     * Removes a node from back of used-list.
     */
    private void removeNodeToBackUsedList() {
        throw new UnsupportedOperationException();
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
    private void validateKeyExists(TKey key) {
        if (!this.has(key)) {
            String errorMessage = "The key: " + key + " is not set in the cache.";

            this.log.error(errorMessage);
            throw new CacheException(errorMessage);
        }
    }

    /**
     * Validates a key does not exist.
     */
    private void validateKeyDoesNotExist(TKey key) {
        if (this.has(key)) {
            String errorMessage = "The key: " + key + " is already set in the cache.";

            this.log.error(errorMessage);
            throw new CacheException(errorMessage);
        }
    }
}
