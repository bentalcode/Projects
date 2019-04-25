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
     * Create a collection comparator.
     */
    <T> ICollectionComparator<T> createCollectionComparator();
}
