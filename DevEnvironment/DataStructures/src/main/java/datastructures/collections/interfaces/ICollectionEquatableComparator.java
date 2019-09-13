package datastructures.collections.interfaces;

import base.interfaces.IEquatableComparator;
import datastructures.hashmap.interfaces.IHashMap;
import datastructures.hashmap.interfaces.ILinkedHashMap;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The ICollectionEquatableComparator interface defines an equatable comparator for collections,
 * for determining equality between two instances.
 */
public interface ICollectionEquatableComparator {
    /**
     * Checks whether two instances are equals.
     */
    <TKey extends Comparable<TKey>, TValue> boolean isEqual(
        IHashMap<TKey, TValue> lhs,
        List<IKeyValueNode<TKey, TValue>> rhs);

    /**
     * Checks whether two instances are equals.
     */
    <TKey extends Comparable<TKey>, TValue> boolean isEqual(
        IHashMap<TKey, TValue> lhs,
        List<IKeyValueNode<TKey, TValue>> rhs,
        IEquatableComparator<IKeyValueNode<TKey, TValue>> comparator);

    /**
     * Checks whether two instances are equals.
     */
    <TKey extends Comparable<TKey>, TValue> boolean isEqual(
        ILinkedHashMap<TKey, TValue> lhs,
        List<IKeyValueNode<TKey, TValue>> rhs);

    /**
     * Checks whether two instances are equals.
     */
    <TKey extends Comparable<TKey>, TValue> boolean isEqual(
        ILinkedHashMap<TKey, TValue> lhs,
        List<IKeyValueNode<TKey, TValue>> rhs,
        IEquatableComparator<IKeyValueNode<TKey, TValue>> comparator);
}
