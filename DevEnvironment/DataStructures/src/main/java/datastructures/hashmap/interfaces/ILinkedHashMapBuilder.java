package datastructures.hashmap.interfaces;

import base.interfaces.IBuilder;
import datastructures.map.interfaces.IMapBuilder;

/**
 * The ILinkedHashMapBuilder interface defines a builder of a linked hash map.
 */
public interface ILinkedHashMapBuilder<TKey extends Comparable<TKey>, TValue> extends
    IBuilder<ILinkedHashMap<TKey, TValue>>,
    IMapBuilder<TKey, TValue> {
}
