package datastructures.hashmap.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Pair;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IPair;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.hashmap.HashMapException;
import datastructures.hashmap.interfaces.IHashMap;
import datastructures.node.core.KeyValueNode;
import datastructures.node.core.KeyValueNodeKeyIterator;
import datastructures.node.core.KeyValueNodeValueIterator;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.ArrayList;
import java.util.List;

/**
 * The HashMap class implements a hash map.
 */
public final class HashMap<TKey extends Comparable<TKey>, TValue> implements IHashMap<TKey, TValue> {
    private static int DefaultCapacity = 16;
    private static double DefaultLoadFactor = 0.75;

    private final double loadFactor;
    private final int capacity;
    private final IBinaryComparator<IHashMap<TKey, TValue>> comparator;
    private final IBinaryComparator<TKey> keyComparator;
    private List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header;
    private int size;

    /**
     * The HashMap constructor.
     */
    public HashMap() {
        this(
            HashMap.DefaultCapacity,
            HashMap.DefaultLoadFactor,
            HashMap.DefaultComparator(),
            base.core.Comparator.DefaultComparator());
    }

    /**
     * The HashMap constructor.
     */
    public HashMap(
        int capacity,
        double loadFactor,
        IBinaryComparator<IHashMap<TKey, TValue>> comparator,
        IBinaryComparator<TKey> keyComparator) {

        Conditions.validate(
            capacity > 0,
            "The capacity of a map has to be positive.");

        Conditions.validate(
            loadFactor > 0 && loadFactor < 1,
            "The load factor has to be between zero to one.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a hash map.");

        Conditions.validateNotNull(
            keyComparator,
            "The key comparator of a hash map.");

        this.loadFactor = loadFactor;
        this.capacity = capacity;
        this.comparator = comparator;
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
     * Sets a value for a specific key.
     *
     * Returns true for a creation of a key-value pair.
     * Returns false for an update of a key-value pair.
     */
    @Override
    public boolean set(TKey key, TValue value) {
        //
        // Find the corresponding node of the specified key...
        //
        IKeyValueNode<TKey, TValue> currNode = this.find(key);

        //
        // If the corresponding node is found, then simply update it's value and return...
        //
        if (currNode != null) {
            currNode.setValue(value);
            return false;
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
        this.addNode(key, value);

        return true;
    }

    /**
     * Removes a key from the map.
     * Returns the corresponding removed value, or null if the key was not found.
     */
    @Override
    public TValue remove(TKey key) {
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
        // Return the value of the removed node...
        //
        return currNode.getValue().getValue();
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
     * Gets an iterator of the hash map.
     */
    @Override
    public IIterator<IKeyValueNode<TKey, TValue>> getIterator() {
        return HashMapInternalIterator.of(this.header);
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
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IHashMap<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<TKey> keyComparator = base.core.Comparator.DefaultComparator();
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
                "The comparator of a key-value.");

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
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getKeyIterator(), this.keyComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
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
         * <p>
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

        return Pair.of(index, currNode);
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
     * Adds a new node to the hash-map.
     */
    private void addNode(TKey key, TValue value) {
        //
        // Find the corresponding linked-list for this key...
        //
        int index = this.indexOf(key);
        IDoublyLinkedList<IKeyValueNode<TKey, TValue>> currList = this.header.get(index);

        //
        // Create the new node and set it as the new head of the corresponding linked-list...
        //
        IKeyValueNode<TKey, TValue> newNode = KeyValueNode.of(key, value);
        currList.addToFront(newNode);

        ++this.size;
    }

    /**
     * Removes an existing node from the hash-map.
     */
    private void removeNode(int index, IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> node) {
        IDoublyLinkedList<IKeyValueNode<TKey, TValue>> currList = this.header.get(index);

        currList.remove(node);

        --this.size;
    }

    /**
     * Checks whether the hash-map is over it's configured capacity.
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
