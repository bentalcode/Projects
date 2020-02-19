package base.core;

import java.util.Date;

/**
 * The DateComparator class implements a comparator for a date.
 */
public final class DateComparator extends AbstractBinaryComparator<Date> {
    /**
     * The DateComparator constructor.
     */
    public DateComparator() {
    }

    /**
     * Gets the hash code of this instance.
     */
    @Override
    public int getHashCode(Date obj) {
        return obj.hashCode();
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public boolean isEqual(Date lhs, Date rhs) {
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
    public int compareTo(Date lhs, Date rhs) {
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
