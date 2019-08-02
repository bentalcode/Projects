package base.interfaces;

import java.util.Map;

/**
 * The IMapComparator interface defines a comparator for generic map.
 */
public interface IMapComparator<TKey, TValue> {
    /**
     * Checks whether the collections are equals with an element comparator.
     */
    boolean isEqual(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IEquatableComparator<TKey> keyComparator,
        IEquatableComparator<TValue> valueComparator);

    /**
     * Checks whether the iterators are equals with an element comparator.
     */
    boolean isEqual(
        IIterator<Map.Entry<TKey, TValue>> lhs,
        IIterator<Map.Entry<TKey, TValue>> rhs,
        IEquatableComparator<TKey> keyComparator,
        IEquatableComparator<TValue> valueComparator);

    /**
     * Determines the relative order of collections with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IComparableComparator<TKey> keyComparator,
        IComparableComparator<TValue> valueComparator);

    /**
     * Determines the relative order of iterators with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(
        IIterator<Map.Entry<TKey, TValue>> lhs,
        IIterator<Map.Entry<TKey, TValue>> rhs,
        IComparableComparator<TKey> keyComparator,
        IComparableComparator<TValue> valueComparator);
}
