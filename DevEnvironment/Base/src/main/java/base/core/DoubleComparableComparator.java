package base.core;

import base.interfaces.IAlmostComparableComparator;
import base.interfaces.IAlmostEquatableComparator;
import base.interfaces.IComparableComparator;
import base.interfaces.IEquivalencyConstants;

/**
 * The DoubleComparableComparator interface defines a comparable comparator for doubles,
 * for determining a comparable order between two instances.
 */
public final class DoubleComparableComparator implements
    IComparableComparator<Double>,
    IAlmostComparableComparator<Double> {

    private final static double DefaultEpsilon = IEquivalencyConstants.doubleEpsilon;

    private final double epsilon;

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    public static int almostCompareTo(double lhs, double rhs) {
        return new DoubleComparableComparator().almostCompareTo(lhs, rhs);
    }

    /**
     * The DoubleComparableComparator constructor.
     */
    public DoubleComparableComparator() {
        this(DoubleComparableComparator.DefaultEpsilon);
    }

    /**
     * The DoubleComparableComparator constructor.
     */
    public DoubleComparableComparator(double epsilon) {
        this.epsilon = epsilon;
    }

     /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(Double lhs, Double rhs) {
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

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int almostCompareTo(Double lhs, Double rhs) {
        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        IAlmostEquatableComparator<Double> almostEquatableComparator = new DoubleEquatableComparator(this.epsilon);

        if (almostEquatableComparator.isAlmostEqual(lhs, rhs)) {
            return 0;
        }
        else if (lhs < rhs) {
            return -1;
        }
        else {
            return 1;
        }
    }
}
