package base.interfaces;

import org.joda.time.DateTime;
import org.joda.time.Duration;

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
    <T extends Comparable<T>> IArrayComparator<T> createArrayComparator();

    /**
     * Create a two dimensional array comparator.
     */
    <T> ITwoDimensionalArrayComparator<T> createTwoDimensionalArrayComparator();

    /**
     * Create a collection comparator.
     */
    <T extends Comparable<T>> ICollectionComparator<T> createCollectionComparator();

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

    /**
     * Create a date-time comparator.
     */
    IBinaryComparator<DateTime> createDateTimeComparator();

    /**
     * Create a duration comparator.
     */
    IBinaryComparator<Duration> createDurationComparator();
}
