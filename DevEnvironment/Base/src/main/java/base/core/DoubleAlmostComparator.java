package base.core;

/**
 * The DoubleAlmostComparator class implements an almost comparator for doubles.
 */
public final class DoubleAlmostComparator extends AbstractBinaryComparator<Double> {
    private final static double EPSILON = 0.001;

    private final double epsilon;

    /**
     * The DoubleAlmostComparator constructor.
     */
    public DoubleAlmostComparator() {
        this(DoubleAlmostComparator.EPSILON);
    }

    /**
     * The DoubleAlmostComparator constructor.
     */
    public DoubleAlmostComparator(double epsilon) {
        this.epsilon = epsilon;
    }

    /**
     * Gets the hash code of this instance.
     */
    @Override
    public int getHashCode(Double obj) {
        return obj.hashCode();
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

        double difference = Math.abs(lhs - rhs);

        return difference <= this.epsilon;
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

        if (this.isEqual(lhs, rhs)) {
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
