package base.core;

import base.interfaces.IAlmostComparatorFactory;
import base.interfaces.IBinaryComparator;

/**
 * The AlmostComparatorFactory class implements a factory for creating almost comparators.
 */
public final class AlmostComparatorFactory implements IAlmostComparatorFactory {
    /**
     * The AlmostComparatorFactory constructor.
     */
    public AlmostComparatorFactory() {
    }

    /**
     * Creates a double comparator.
     */
    @Override
    public IBinaryComparator<Double> createDoubleComparator() {
        return new DoubleAlmostComparator();
    }
}
