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
     * Creates a generic comparator.
     */
    @Override
    public <T extends Comparable<T>> IBinaryComparator<T> createComparator() {
        return Comparator.DefaultComparator();
    }

    /**
     * Creates an array comparator.
     */
    @Override
    public <T> IArrayComparator<T> createArrayComparator() {
        return new ArrayComparator<>();
    }

    /**
     * Creates a collection comparator.
     */
    @Override
    public <T> ICollectionComparator<T> createCollectionComparator() {
        return new CollectionComparator<>();
    }
}
