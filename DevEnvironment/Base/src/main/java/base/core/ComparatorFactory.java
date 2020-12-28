package base.core;

import base.interfaces.IArrayComparator;
import base.interfaces.IBinaryComparator;
import base.interfaces.ICollectionComparator;
import base.interfaces.IComparatorFactory;
import base.interfaces.IIterableComparator;
import base.interfaces.IIteratorComparator;
import base.interfaces.IMapComparator;
import base.interfaces.ITwoDimensionalArrayComparator;
import java.time.Duration;
import java.util.Date;

/**
 * The ComparatorFactory class implements a factory for creating binary comparators.
 */
public final class ComparatorFactory implements IComparatorFactory {
    /**
     * The ComparatorFactory constructor.
     */
    public ComparatorFactory() {
    }

    /**
     * Creates a generic comparator.
     */
    @Override
    public <T extends Comparable<T>> IBinaryComparator<T> createComparator() {
        return Comparator.make();
    }

    /**
     * Creates an almost double comparator with a default epsilon.
     */
    @Override
    public IBinaryComparator<Double> createAlmostDoubleComparator() {
        return new DoubleAlmostComparator();
    }

    /**
     * Creates an almost double comparator with a specified epsilon.
     */
    @Override
    public IBinaryComparator<Double> createAlmostDoubleComparator(double epsilon) {
        return new DoubleAlmostComparator(epsilon);
    }

    /**
     * Creates an array comparator.
     */
    @Override
    public <T extends Comparable<T>> IArrayComparator<T> createArrayComparator() {
        return new ArrayComparator<>();
    }

    /**
     * Creates a two dimensional array comparator.
     */
    @Override
    public <T> ITwoDimensionalArrayComparator<T> createTwoDimensionalArrayComparator() {
        return new TwoDimensionalArrayComparator<>();
    }

    /**
     * Creates a collection comparator.
     */
    @Override
    public <T extends Comparable<T>> ICollectionComparator<T> createCollectionComparator() {
        return new CollectionComparator<>();
    }

    /**
     * Creates an iterator comparator.
     */
    @Override
    public <T> IIteratorComparator<T> createIteratorComparator() {
        return new IteratorComparator<>();
    }

    /**
     * Creates an iterable comparator.
     */
    @Override
    public <T> IIterableComparator<T> createIterableComparator() {
        return new IterableComparator<>();
    }

    /**
     * Creates a map comparator.
     */
    @Override
    public <TKey, TValue> IMapComparator<TKey, TValue> createMapComparator() {
        return new MapComparator<>();
    }

    /**
     * Creates a date comparator.
     */
    @Override
    public IBinaryComparator<Date> createDateComparator() {
        return new DateComparator();
    }

    /**
     * Creates a duration comparator.
     */
    @Override
    public IBinaryComparator<Duration> createDurationComparator() {
        return new DurationComparator();
    }
}
