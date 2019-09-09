package base.core;

import base.interfaces.IBinaryComparator;

/**
 * The AbstractBinaryComparator class implements an abstract binary comparator.
 */
public abstract class AbstractBinaryComparator<T> implements IBinaryComparator<T> {
    /**
     * The AbstractBinaryComparator constructor.
     */
    protected AbstractBinaryComparator() {
    }

    /**
     * Converts the comparator to the native one.
     */
    @Override
    public java.util.Comparator<T> toComparator() {
        return new Comparator<>(this);
    }

    /**
     * The Comparator class implements a native java comparator.
     */
    private static class Comparator<T> implements java.util.Comparator<T> {
        private final IBinaryComparator<T> comparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<T> comparator) {
            this.comparator = comparator;
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        public int compare(T lhs, T rhs) {
            return this.comparator.compareTo(lhs, rhs);
        }
    }
}
