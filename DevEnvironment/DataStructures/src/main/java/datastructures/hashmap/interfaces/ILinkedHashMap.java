package datastructures.hashmap.interfaces;

import base.interfaces.IUnaryComparator;
import datastructures.map.interfaces.IMap;

/**
 * The ILinkedHashMap interface defines a linked hash map.
 *
 * Note:
 *  HashMap is implemented as a hash table, and there is no ordering on keys or values.
 *  TreeMap is implemented based on red-black tree structure, and it is ordered by the key.
 *  LinkedHashMap preserves the insertion order.
 */
public interface ILinkedHashMap<TKey extends Comparable<TKey>, TValue> extends
    IMap<TKey, TValue>,
    IUnaryComparator<ILinkedHashMap<TKey, TValue>> {
}
