package base.core;

import base.interfaces.IAlmostEquatableComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IEquivalencyConstants;

/**
 * The DoubleEquatableComparator class implements an equatable comparable comparator for doubles,
 * for determining an equality between two instances.
 */
public final class DoubleEquatableComparator implements
    IEquatableComparator<Double>,
    IAlmostEquatableComparator<Double> {

    private final static double DefaultEpsilon = IEquivalencyConstants.doubleEpsilon;

    private final double epsilon;

    /**
     * Checks whether two instances are almost equals.
     */
    public static boolean isAlmostEqual(double lhs, double rhs) {
        return new DoubleEquatableComparator().isEqual(lhs, rhs);
    }

    /**
     * The DoubleEquatableComparator constructor.
     */
    public DoubleEquatableComparator() {
        this(DoubleEquatableComparator.DefaultEpsilon);
    }

    /**
     * The DoubleEquatableComparator constructor.
     */
    public DoubleEquatableComparator(double epsilon) {
        this.epsilon = epsilon;
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public boolean isEqual(Double lhs, Double rhs) {
        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        return lhs.equals(rhs);
    }

    /**
     * Checks whether two instances are almost equals.
     */
    @Override
    public boolean isAlmostEqual(Double lhs, Double rhs) {
        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        double difference = Math.abs(lhs - rhs);

        return difference <= this.epsilon;
    }
}
