package base.core;

import base.interfaces.IArrayComparator;
import base.interfaces.IBinaryComparator;
import base.interfaces.ICollectionComparator;
import base.interfaces.IComparatorFactory;

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
     * Create a generic comparator.
     */
    @Override
    public <T extends Comparable<T>> IBinaryComparator<T> createComparator() {
        return base.core.Comparator.DefaultComparator();
    }

    /**
     * Create an array comparator.
     */
    @Override
    public <T> IArrayComparator<T> createArrayComparator() {
        return new ArrayComparator<>();
    }

    /**
     * Create a collection comparator.
     */
    @Override
    public <T> ICollectionComparator<T> createCollectionComparator() {
        return new CollectionComparator<>();
    }
}
