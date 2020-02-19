package base.interfaces;

import java.time.Duration;
import java.util.Date;

/**
 * The IComparatorFactory interface defines a factory for creating comparators.
 */
public interface IComparatorFactory {
    /**
     * Creates a generic comparator.
     */
    <T extends Comparable<T>> IBinaryComparator<T> createComparator();

    /**
     * Creates an array comparator.
     */
    <T extends Comparable<T>> IArrayComparator<T> createArrayComparator();

    /**
     * Creates a two dimensional array comparator.
     */
    <T> ITwoDimensionalArrayComparator<T> createTwoDimensionalArrayComparator();

    /**
     * Creates a collection comparator.
     */
    <T extends Comparable<T>> ICollectionComparator<T> createCollectionComparator();

    /**
     * Creates an iterator comparator.
     */
    <T> IIteratorComparator<T> createIteratorComparator();

    /**
     * Creates an iterable comparator.
     */
    <T> IIterableComparator<T> createIterableComparator();

    /**
     * Creates a map comparator.
     */
    <TKey, TValue> IMapComparator<TKey, TValue> createMapComparator();

    /**
     * Creates a date comparator.
     */
    IBinaryComparator<Date> createDateComparator();

    /**
     * Creates a duration comparator.
     */
    IBinaryComparator<Duration> createDurationComparator();
}
