package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.IComparableComparator;
import base.interfaces.IInterval;
import java.util.ArrayList;
import java.util.List;

/**
 * The Interval class implements an interval.
 */
public final class Interval<Type extends Comparable<Type>> implements IInterval<Type> {
    private final Type start;
    private final Type end;
    private final IBinaryComparator<IInterval<Type>> comparator;
    private final int hashCode;

    /**
     * Creates a new instance of an interval.
     */
    public static<Type extends Comparable<Type>> IInterval<Type> make(Type start, Type end) {
        return new Interval<>(
            start,
            end,
            defaultComparator());
    }

    /**
     * The Interval constructor.
     */
    private Interval(
        Type start,
        Type end,
        IBinaryComparator<IInterval<Type>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of an interval.");

        this.start = start;
        this.end = end;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the start point of an interval.
     */
    @Override
    public Type start() {
        return this.start;
    }

    /**
     * Gets the end point of an interval.
     */
    @Override
    public Type end() {
        return this.end;
    }

    /**
     * Determines whether two sorted intervals overlap.
     */
    public static <Type extends Comparable<Type>> boolean overlap(IInterval<Type> left, IInterval<Type> right) {
        IComparableComparator<Type> comparable = base.core.Comparator.make();
        return comparable.compareTo(right.start(), left.end()) <= 0;
    }

    /**
     * Sorts intervals.
     */
    public static <Type extends Comparable<Type>> List<IInterval<Type>> sort(List<IInterval<Type>> intervals) {
        List<IInterval<Type>> sortedIntervals = new ArrayList<>(intervals);

        IBinaryComparator<IInterval<Type>> comparator = Interval.defaultComparator();
        sortedIntervals.sort(comparator.toComparator());

        return sortedIntervals;
    }

    /**
     * Gets the string representation of an interval.
     */
    @Override
    public String toString() {
        return "[" + this.start + "-" + this.end + "]";
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IInterval<Type> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IInterval<Type> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <Type extends Comparable<Type>> IBinaryComparator<IInterval<Type>> defaultComparator() {
        IBinaryComparator<Type> elementComparator = base.core.Comparator.make();
        return new Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of an interval.
     */
    public static final class Comparator<Type extends Comparable<Type>> extends AbstractBinaryComparator<IInterval<Type>> {
        private final IBinaryComparator<Type> elementComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<Type> elementComparator) {
            Conditions.validateNotNull(
                elementComparator,
                "The comparator of the an element.");

            this.elementComparator = elementComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IInterval<Type> obj) {
            return new HashCodeBuilder(19, 23)
                .withObject(obj.start(), this.elementComparator)
                .withObject(obj.end(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IInterval<Type> lhs, IInterval<Type> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.start(), rhs.start(), this.elementComparator)
                .withObject(lhs.end(), rhs.end(), this.elementComparator)
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IInterval<Type> lhs, IInterval<Type> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withObject(lhs.start(), rhs.start(), this.elementComparator)
                .withObject(lhs.end(), rhs.end(), this.elementComparator)
                .build();
        }
    }
}
