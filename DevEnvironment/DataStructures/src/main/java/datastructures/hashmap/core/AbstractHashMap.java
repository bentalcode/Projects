package datastructures.hashmap.core;

import base.core.Conditions;
import base.core.Pair;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IPair;
import datastructures.doublylinkedlist.core.DoublyLinkedList;
import datastructures.doublylinkedlist.core.DoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.hashmap.HashMapException;
import datastructures.map.interfaces.IMap;
import datastructures.node.core.KeyValueNode;
import datastructures.node.core.KeyValueNodeKeyIterator;
import datastructures.node.core.KeyValueNodeValueIterator;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.ArrayList;
import java.util.List;

/**
 * The AbstractHashMap base class implements an abstract hash map.
 */
public abstract class AbstractHashMap<TKey extends Comparable<TKey>, TValue> implements IMap<TKey, TValue> {
    private final double loadFactor;
    private final int capacity;
    private final IBinaryComparator<TKey> keyComparator;
    private List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header;
    private int size;

    /**
     * The AbstractHashMap constructor.
     */
    protected AbstractHashMap(
        int capacity,
        double loadFactor,
        IBinaryComparator<TKey> keyComparator) {

        Conditions.validate(
            capacity > 0,
            "The capacity of a hash map has to be positive.");

        Conditions.validate(
            loadFactor > 0 && loadFactor < 1,
            "The load factor has to be between zero to one.");

        Conditions.validateNotNull(
            keyComparator,
            "The key comparator of a hash map.");

        this.loadFactor = loadFactor;
        this.capacity = capacity;
        this.keyComparator = keyComparator;

        this.header = this.createHeader(capacity);
    }

    /**
     * Gets the corresponding value of the specified key.
     */
    @Override
    public TValue get(TKey key) {
        IKeyValueNode<TKey, TValue> currNode = this.find(key);

        if (currNode == null) {
            String errorMessage = "The key: " + key + " was not found in the hash map.";
            throw new HashMapException(errorMessage);
        }

        return currNode.getValue();
    }

    /**
     * Tries getting the corresponding value of the specified key.
     * Returns null if the key was not found.
     */
    @Override
    public TValue tryGet(TKey key) {
        IKeyValueNode<TKey, TValue> currNode = this.find(key);
        return (currNode == null) ? null : currNode.getValue();
    }

    /**
     * Checks whether a key exists in the map.
     */
    @Override
    public boolean containsKey(TKey key) {
        return this.find(key) != null;
    }

    /**
     * Checks whether a value exists in the map.
     */
    @Override
    public boolean containsValue(TValue value) {
        IIterator<IKeyValueNode<TKey, TValue>> iterator = this.getIterator();

        while (iterator.hasNext()) {
            IKeyValueNode<TKey, TValue> currNode = iterator.next();

            if (currNode.getValue().equals(value)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Clears the map.
     */
    @Override
    public void clear() {
        this.header = this.createHeader(this.capacity);
        this.size = 0;
    }

    /**
     * Returns a size of the map.
     */
    @Override
    public int size() {
        return this.size;
    }

    /**
     * Checks whether the map is empty.
     */
    @Override
    public boolean isEmpty() {
        return this.size() == 0;
    }

    /**
     * Gets a key iterator of the hash map.
     */
    @Override
    public IIterator<TKey> getKeyIterator() {
        return KeyValueNodeKeyIterator.of(this.getIterator());
    }

    /**
     * Gets a value iterator of the hash map.
     */
    @Override
    public IIterator<TValue> getValueIterator() {
        return KeyValueNodeValueIterator.of(this.getIterator());
    }

    /**
     * Gets the internal iterator of a hash map.
     */
    protected IIterator<IKeyValueNode<TKey, TValue>> getInternalIterator() {
        return HashMapInternalIterator.of(this.header);
    }

    /**
     * Sets a key value node.
     *
     * Returns true for a creation of a key-value pair.
     * Returns false for an update of a key-value pair.
     */
    protected IPair<Boolean, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> setKeyValueNode(
        TKey key,
        TValue value) {

        //
        // Find the corresponding node of the specified key...
        //
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currNode = this.findNode(key);

        //
        // If the corresponding node is found, then simply update it's value and return...
        //
        if (currNode != null) {
            currNode.getValue().setValue(value);
            return Pair.of(false, currNode);
        }

        //
        // If the hash-map has exceeded it's capacity, then rehashes the existing key-value nodes...
        //
        if (this.overCapacity()) {
            this.rehash();
        }

        //
        // Add a new node...
        //
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> nodeAdded = this.addNode(key, value);

        return Pair.of(true, nodeAdded);
    }

    /**
     * Removes a key from the map.
     * Returns the corresponding removed node, or null if the key was not found.
     */
    protected IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> removeNode(TKey key) {
        //
        // Find the corresponding node of the specified key...
        //
        IPair<Integer, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> currNodeData = this.findIndexAndNode(key);

        //
        // If the corresponding node is not found, then simply return null...
        //
        if (currNodeData == null) {
            return null;
        }

        int index = currNodeData.first();
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currNode = currNodeData.second();

        //
        // Remove the existing node...
        //
        this.removeNode(index, currNode);

        //
        // Return the removed node...
        //
        return currNode;
    }

    /**
     * Creates a header for the map.
     */
    private List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> createHeader(int capacity) {
        List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header = new ArrayList<>(capacity);

        for (int i = 0; i < capacity; ++i) {
            header.add(null);
        }

        return header;
    }

    /**
     * Finds the index and the corresponding list node for a specified key.
     */
    private IPair<Integer, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> findIndexAndNode(TKey key) {
        int index = this.indexOf(key);

        IDoublyLinkedList<IKeyValueNode<TKey, TValue>> currList = this.header.get(index);

        if (currList == null) {
            return null;
        }

        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> currNode = currList.getHead();

        while (currNode != null) {
            if (currNode.getValue().getKey().equals(key)) {
                break;
            }

            currNode = currNode.next();
        }

        return (currNode == null) ? null : Pair.of(index, currNode);
    }

    /**
     * Finds the corresponding list node for the specified key.
     */
    private IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> findNode(TKey key) {
        IPair<Integer, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> nodeData = this.findIndexAndNode(key);
        return (nodeData == null) ? null : nodeData.second();
    }

    /**
     * Finds the corresponding key-value node for the specified key.
     */
    private IKeyValueNode<TKey, TValue> find(TKey key) {
        IPair<Integer, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> nodeData = this.findIndexAndNode(key);
        return (nodeData == null) ? null : nodeData.second().getValue();
    }

    /**
     * Adds a new node to the hash map.
     */
    private IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> addNode(TKey key, TValue value) {
        //
        // Find or create the corresponding linked-list for this key...
        //
        int index = this.indexOf(key);
        IDoublyLinkedList<IKeyValueNode<TKey, TValue>> currList = this.header.get(index);

        if (currList == null) {
            currList = new DoublyLinkedList<>();
            this.header.set(index, currList);
        }

        //
        // Create the new node and set it as the new head of the corresponding linked-list...
        //
        IKeyValueNode<TKey, TValue> newNode = KeyValueNode.of(key, value);
        IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> newListNode = DoublyLinkedListNode.of(newNode);
        currList.addToFront(newListNode);

        ++this.size;

        return newListNode;
    }

    /**
     * Removes an existing node from the hash map.
     */
    private void removeNode(int index, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node) {
        IDoublyLinkedList<IKeyValueNode<TKey, TValue>> currList = this.header.get(index);
        assert (currList != null);

        currList.remove(node);

        --this.size;
    }

    /**
     * Checks whether the hash map is over it's configured capacity.
     * When the number of entries in the hash table exceeds the product of the load factor
     * and the current capacity, the hash table is rehashed (that is, internal data structures are rebuilt)
     * so that the hash table has approximately twice the number of buckets.
     *
     */
    private boolean overCapacity() {
        return this.size() > this.header.size() * this.loadFactor;
    }

    /**
     * Rehashes the hash-map.
     */
    private void rehash() {
        int newCapacity = this.header.size() * 2;

        List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> newHeader = this.createHeader(newCapacity);

        IIterator<IKeyValueNode<TKey, TValue>> iterator = this.getIterator();
        this.header = newHeader;

        while (iterator.hasNext()) {
            IKeyValueNode<TKey, TValue> currNode = iterator.next();

            this.set(currNode.getKey(), currNode.getValue());
        }
    }

    /**
     * Gets the index of a key.
     */
    private int indexOf(TKey key) {
        int hash = this.hash(key);
        return hash % this.header.size();
    }

    /**
     * Gets the hash of a key.
     */
    private int hash(TKey key) {
        if (key == null) {
            return 0;
        }
        else {
            return this.keyComparator.getHashCode(key);
        }
    }
}
