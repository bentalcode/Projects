package datastructures.collections.core;

import base.core.EqualBuilder;
import base.core.ListIterator;
import base.interfaces.IEquatableComparator;
import datastructures.collections.interfaces.ICollectionEquatableComparator;
import datastructures.hashmap.interfaces.IHashMap;
import datastructures.hashmap.interfaces.ILinkedHashMap;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The CollectionEquatableComparator class implements an equatable comparator,
 * for determining equality between two instances.
 */
public final class CollectionEquatableComparator implements ICollectionEquatableComparator {
    /**
     * The CollectionEquatableComparator constructor.
     */
    public CollectionEquatableComparator() {
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public <TKey extends Comparable<TKey>, TValue> boolean isEqual(
        IHashMap<TKey, TValue> lhs,
        List<IKeyValueNode<TKey, TValue>> rhs) {

        return this.isEqual(lhs, rhs, KeyValueNode.DefaultComparator());
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public <TKey extends Comparable<TKey>, TValue> boolean isEqual(
        IHashMap<TKey, TValue> lhs,
        List<IKeyValueNode<TKey, TValue>> rhs,
        IEquatableComparator<IKeyValueNode<TKey, TValue>> comparator) {

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        if (lhs.size() != rhs.size()) {
            return false;
        }

        for (IKeyValueNode<TKey, TValue> rhsNode : rhs) {
            TKey lhsKey = rhsNode.getKey();
            TValue lhsValue = lhs.get(lhsKey);

            IKeyValueNode<TKey, TValue> lhsNode = KeyValueNode.of(lhsKey, lhsValue);

            if (!comparator.isEqual(lhsNode, rhsNode)) {
                return false;
            }
        }

        return true;
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public <TKey extends Comparable<TKey>, TValue> boolean isEqual(
        ILinkedHashMap<TKey, TValue> lhs,
        List<IKeyValueNode<TKey, TValue>> rhs) {

        return this.isEqual(lhs, rhs, KeyValueNode.DefaultComparator());
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public <TKey extends Comparable<TKey>, TValue> boolean isEqual(
        ILinkedHashMap<TKey, TValue> lhs,
        List<IKeyValueNode<TKey, TValue>> rhs,
        IEquatableComparator<IKeyValueNode<TKey, TValue>> comparator) {

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        if (lhs.size() != rhs.size()) {
            return false;
        }

        return new EqualBuilder()
            .withIterator(lhs.getIterator(), ListIterator.of(rhs), comparator)
            .build();
    }
}
