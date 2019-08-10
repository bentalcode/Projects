package base.interfaces;

/**
 * The IAlmostComparatorFactory interface defines a factory for creating almost comparators.
 */
public interface IAlmostComparatorFactory {
    /**
     * Creates a double comparator.
     */
    IBinaryComparator<Double> createDoubleComparator();
}
