package base.core;

import base.interfaces.IBinaryComparator;

/**
 * The Comparator class implements a binary comparator for a generic object.
 */
public final class Comparator<T extends Comparable<T>> implements IBinaryComparator<T> {
    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<T> DefaultComparator() {
        return new Comparator<>();
    }

    /**
     * The Comparator constructor.
     */
    private Comparator() {
    }

    /**
     * Gets a hash code of this instance.
     */
    @Override
    public int getHashCode(T obj) {
        return obj.hashCode();
    }

    /**
     * Checks whether two instances are equals.
     */
    public boolean isEqual(T lhs, T rhs) {
        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        return lhs.equals(rhs);
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
        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        return lhs.compareTo(rhs);
    }
}
