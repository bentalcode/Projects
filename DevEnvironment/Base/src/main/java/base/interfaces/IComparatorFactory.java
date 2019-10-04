package base.interfaces;

/**
 * The IComparatorFactory interface defines a factory for creating comparators.
 */
public interface IComparatorFactory {
    /**
     * Create a generic comparator.
     */
    <T extends Comparable<T>> IBinaryComparator<T> createComparator();

    /**
     * Create an array comparator.
     */
    <T> IArrayComparator<T> createArrayComparator();

    /**
     * Create a two dimensional array comparator.
     */
    <T> ITwoDimensionalArrayComparator<T> createTwoDimensionalArrayComparator();

    /**
     * Create a collection comparator.
     */
    <T> ICollectionComparator<T> createCollectionComparator();

    /**
     * Create an iterator comparator.
     */
    <T> IIteratorComparator<T> createIteratorComparator();

    /**
     * Create an iterable comparator.
     */
    <T> IIterableComparator<T> createIterableComparator();

    /**
     * Creates a map comparator.
     */
    <TKey, TValue> IMapComparator<TKey, TValue> createMapComparator();
}
