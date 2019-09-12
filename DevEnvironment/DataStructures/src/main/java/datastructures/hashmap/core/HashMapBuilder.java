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
    public IHashMapBuilder<TKey, TValue> set(TKey key, TValue value) {
        this.map.set(key, value);
        return this;
    }

    /**
     * Sets a key value node.
     */
    @Override
    public IHashMapBuilder<TKey, TValue> set(IKeyValueNode<TKey, TValue> node) {
        this.map.set(node.getKey(), node.getValue());
        return this;
    }

    /**
     * Sets an key-value nodes with an iterator.
     */
    @Override
    public IHashMapBuilder<TKey, TValue> set(IIterator<IKeyValueNode<TKey, TValue>> iterator) {
        while (iterator.hasNext()) {
            this.set(iterator.next());
        }

        return this;
    }

    /**
     * Builds the hash-map.
     */
    @Override
    public IHashMap<TKey, TValue> build() {
        return this.map;
    }
}
