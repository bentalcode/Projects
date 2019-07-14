package datastructures.cache.core;

import base.core.Conditions;
import datastructures.cache.CacheException;
import datastructures.cache.interfaces.ICacheProperties;
import datastructures.cache.interfaces.ILRUCache;
import datastructures.doublylinkedlist.core.DoublyLinkedList;
import datastructures.doublylinkedlist.core.DoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;
import datastructures.node.core.KeyValueNode;
import datastructures.node.core.KeyValueNodeIterator;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import datastructures.node.core.NodeKeyIterator;
import datastructures.node.core.NodeValueIterator;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.collections.interfaces.IValueIterator;
import java.security.Key;
import java.util.HashMap;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The LRUCache class implements a least recently used cache.
 * Discards the least recently used items first.
 */
public final class LRUCache<TKey extends Comparable<TKey>, TValue> implements ILRUCache<TKey, TValue> {
    private final ICacheProperties properties;

    private IDoublyLinkedList<IKeyValueNode<TKey, TValue>> usedList = new DoublyLinkedList<>();
    private Map<Key, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> dataLookup = new HashMap<>();

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

        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currentNode;
        boolean existingItem;

        if (this.dataLookup.containsKey(key)) {
            //
            // If the key is set in the cache, update it's value...
            //
            currentNode = this.dataLookup.get(key);
            currentNode.getValue().setValue(value);

            existingItem = true;
        }
        else {
            //
            // If the cache is over it's capacity, discard the least recently used item
            // from the back of the used list, and create a new node...
            //
            if (this.overCapacity()) {
                this.removeLruItem();

                Conditions.validate(
                    !this.overCapacity(),
                    "The cache should have an available space.");
            }

            currentNode = new DoublyLinkedListNode<>(new KeyValueNode<>(key, value));

            existingItem = false;
        }

        //
        // Mark the item as most recently used...
        //
        this.setMruItem(currentNode, existingItem);
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
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currentNode = this.dataLookup.get(key);

        TValue currentValue = currentNode.getValue().getValue();

        //
        // Mark the item as most recently used...
        //
        boolean existingItem = true;
        this.setMruItem(currentNode, existingItem);

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

        if (!this.dataLookup.containsKey(key)) {
            return false;
        }

        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node = this.dataLookup.get(key);

        this.usedList.remove(node);
        this.dataLookup.remove(key);

        return true;
    }

    /**
     * Checks whether a key is set in the cache.
     * Complexity: O(1)
     */
    @Override
    public boolean has(TKey key) {
        return this.dataLookup.containsKey(key);
    }

    /**
     * Gets an iterator of keys of a cache.
     * Complexity: O(1)
     */
    public IKeyIterator<TKey> getKeyIterator() {
        return new NodeKeyIterator<>(this.getDataIterator());
    }

    /**
     * Gets an iterator of values of a cache.
     * Complexity: O(1)
     */
    @Override
    public IValueIterator<TValue> getValueIterator() {
        return new NodeValueIterator<>(this.getDataIterator());
    }

    /**
     * Gets an iterator of data of a cache.
     * Complexity: O(1)
     */
    @Override
    public IKeyValueNodeIterator<TKey, TValue> getDataIterator() {
        throw new UnsupportedOperationException();
    }

    /**
     * Gets the size of a cache.
     */
    @Override
    public int size() {
        return this.dataLookup.size();
    }

    /**
     * Checks whether the cache is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Determines whether the used-list has reached it's maximum capacity.
     */
    private boolean overCapacity() {
        return this.size() >= this.properties.getCapacity();
    }

    /**
     * Removes the least recently used item.
     */
    private void removeLruItem() {
        assert(!this.empty());

        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> itemToRemove = this.usedList.getTail();

        this.usedList.removeFromBack();
        this.dataLookup.remove(itemToRemove.getValue().getKey());
    }

    //
    // Marks the item as most recently used.
    //
    private void setMruItem(
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> item,
        boolean existingItem) {

        if (existingItem) {
            this.usedList.remove(item);
        }

        this.usedList.addToFront(item);
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
