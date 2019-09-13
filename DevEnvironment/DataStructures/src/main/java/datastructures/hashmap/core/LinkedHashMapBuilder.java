package datastructures.hashmap.core;

import base.interfaces.IIterator;
import datastructures.hashmap.interfaces.ILinkedHashMap;
import datastructures.hashmap.interfaces.ILinkedHashMapBuilder;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The LinkedHashMapBuilder class implements a builder of a linked hash-map.
 */
public final class LinkedHashMapBuilder<TKey extends Comparable<TKey>, TValue>
    implements ILinkedHashMapBuilder<TKey, TValue> {

    private final ILinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();

    /**
     * The LinkedHashMapBuilder constructor.
     */
    public LinkedHashMapBuilder() {
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
     * Sets an key-value nodes with an iterator.
     */
    @Override
    public void set(IIterator<IKeyValueNode<TKey, TValue>> iterator) {
        while (iterator.hasNext()) {
            this.set(iterator.next());
        }
    }

    /**
     * Builds the linked hash-map.
     */
    @Override
    public ILinkedHashMap<TKey, TValue> build() {
        return this.map;
    }
}
