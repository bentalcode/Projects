package base.core;

import base.interfaces.IBinaryComparator;

/**
 * The InvertComparator class implements an invert comparator for a defined comparator.
 */
public final class InvertComparator<T> extends AbstractBinaryComparator<T> {
    private final IBinaryComparator<T> comparator;

    /**
     * Creates an invert comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<T> make(IBinaryComparator<T> comparator) {
        return new InvertComparator<>(comparator);
    }

    /**
     * The InvertComparator constructor.
     */
    private InvertComparator(IBinaryComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator to invert.");

        this.comparator = comparator;
    }

    /**
     * Gets the hash code of this instance.
     */
    @Override
    public int getHashCode(T obj) {
        return this.comparator.getHashCode(obj);
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public boolean isEqual(T lhs, T rhs) {
        return this.comparator.isEqual(lhs, rhs);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(T lhs, T rhs) {
        return this.comparator.compareTo(rhs, lhs);
    }
}
