package datastructures.hashmap.core;

import base.interfaces.IIterator;
import datastructures.hashmap.interfaces.IHashMap;
import datastructures.hashmap.interfaces.IHashMapBuilder;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The HashMapBuilder class implements a builder of a hash-map.
 */
public final class HashMapBuilder<TKey extends Comparable<TKey>, TValue> implements IHashMapBuilder<TKey, TValue> {
    private final IHashMap<TKey, TValue> map = new datastructures.hashmap.core.HashMap<>();

    /**
     * The HashMapBuilder constructor.
     */
    public HashMapBuilder() {
    }

    /**
     * Sets a key value pair.
     */
    @Override
    public void set(TKey key, TValue value) {
        this.map.set(key, value);
    }

    /**
     * Sets a key value node.
     */
    @Override
    public void set(IKeyValueNode<TKey, TValue> node) {
        this.map.set(node.getKey(), node.getValue());
    }

    /**
     * Sets a key-value nodes with an iterator.
     */
    @Override
    public void set(IIterator<IKeyValueNode<TKey, TValue>> iterator) {
        while (iterator.hasNext()) {
            this.set(iterator.next());
        }
    }

    /**
     * Builds the hash-map.
     */
    @Override
    public IHashMap<TKey, TValue> build() {
        return this.map;
    }
}
