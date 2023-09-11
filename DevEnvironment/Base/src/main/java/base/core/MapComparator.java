package base.core;

import base.interfaces.IComparableComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IIterator;
import base.interfaces.IMapComparator;
import java.util.Map;

/**
 * The MapComparator class implements a comparator for a generic map.
 */
public final class MapComparator<TKey, TValue> implements IMapComparator<TKey, TValue> {
    /**
     * The CollectionComparator constructor.
     */
    public MapComparator() {
    }

    /**
     * Checks whether the collection are equals with an element comparator.
     */
    @Override
    public boolean isEqual(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IEquatableComparator<TKey> keyComparator,
        IEquatableComparator<TValue> valueComparator) {

        Conditions.validateNotNull(
            keyComparator,
            "The comparator of a key.");

        Conditions.validateNotNull(
            valueComparator,
            "The comparator of a value.");

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        if (lhs.size() != rhs.size()) {
            return false;
        }

        return this.isEqual(
            Iterator.make(lhs.entrySet()),
            Iterator.make(rhs.entrySet()),
            keyComparator,
            valueComparator);
    }

    /**
     * Checks whether the iterators of collections are equals with an element comparator.
     */
    @Override
    public boolean isEqual(
        IIterator<Map.Entry<TKey, TValue>> lhs,
        IIterator<Map.Entry<TKey, TValue>> rhs,
        IEquatableComparator<TKey> keyComparator,
        IEquatableComparator<TValue> valueComparator) {

        Conditions.validateNotNull(
            keyComparator,
            "The comparator of a key.");

        Conditions.validateNotNull(
            valueComparator,
            "The comparator of a value.");

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        while (lhs.hasNext() && rhs.hasNext()) {
            Map.Entry<TKey, TValue> lhsValue = lhs.next();
            Map.Entry<TKey, TValue> rhsValue = rhs.next();

            if (!keyComparator.isEqual(lhsValue.getKey(), rhsValue.getKey()) ||
                !valueComparator.isEqual(lhsValue.getValue(), rhsValue.getValue())) {

                return false;
            }
        }

        return !lhs.hasNext() && !rhs.hasNext();
    }

    /**
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IComparableComparator<TKey> keyComparator,
        IComparableComparator<TValue> valueComparator) {

        Conditions.validateNotNull(
            keyComparator,
            "The comparator of a key.");

        Conditions.validateNotNull(
            valueComparator,
            "The comparator of a value.");

        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        if (lhs.size() < rhs.size()) {
            return -1;
        }

        if (lhs.size() > rhs.size()) {
            return 1;
        }

        return this.compareTo(
            Iterator.make(lhs.entrySet()),
            Iterator.make(rhs.entrySet()),
            keyComparator,
            valueComparator);
    }

    /**
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(
        IIterator<Map.Entry<TKey, TValue>> lhs,
        IIterator<Map.Entry<TKey, TValue>> rhs,
        IComparableComparator<TKey> keyComparator,
        IComparableComparator<TValue> valueComparator) {

        Conditions.validateNotNull(
            keyComparator,
            "The comparator of a key.");

        Conditions.validateNotNull(
            valueComparator,
            "The comparator of a value.");

        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        while (lhs.hasNext() && rhs.hasNext()) {
            Map.Entry<TKey, TValue> lhsValue = lhs.next();
            Map.Entry<TKey, TValue> rhsValue = rhs.next();

            int status = keyComparator.compareTo(lhsValue.getKey(), rhsValue.getKey());

            if (status != 0) {
                return status;
            }

            status = valueComparator.compareTo(lhsValue.getValue(), rhsValue.getValue());

            if (status != 0) {
                return status;
            }
        }

        if (!lhs.hasNext() && !rhs.hasNext()) {
            return 0;
        }

        if (!lhs.hasNext()) {
            return -1;
        }

        return 1;
    }
}
