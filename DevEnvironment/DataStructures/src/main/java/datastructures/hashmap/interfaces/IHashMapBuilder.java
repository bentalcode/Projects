package datastructures.hashmap.interfaces;

import base.interfaces.IBuilder;
import datastructures.map.interfaces.IMapBuilder;

/**
 * The IHashMapBuilder interface defines a builder of a hash map.
 */
public interface IHashMapBuilder<TKey extends Comparable<TKey>, TValue> extends
    IBuilder<IHashMap<TKey, TValue>>,
    IMapBuilder<TKey, TValue> {
}
