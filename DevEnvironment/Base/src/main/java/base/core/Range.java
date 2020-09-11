package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.IRange;

/**
 * The Range class implements a range.
 */
public final class Range<T extends Comparable<T>> implements IRange<T> {
    private final T start;
    private final T end;
    private final RangeType rangeType;
    private final IBinaryComparator<IRange<T>> comparator;
    private final int hashCode;

    /**
     * Creates a new range.
     */
    public static <T extends Comparable<T>> IRange<T> make(T start, T end) {
        return new Range<>(start, end);
    }

    /**
     * Creates a new range.
     */
    public static <T extends Comparable<T>> IRange<T> make(
        RangeType rangeType,
        T start,
        T end) {

        return new Range<>(rangeType, start, end);
    }

    /**
     * Creates a new range.
     */
    public static <T extends Comparable<T>> IRange<T> make(
        RangeType rangeType,
        T start,
        T end,
        IBinaryComparator<IRange<T>> comparator) {

        return new Range<>(rangeType, start, end, comparator);
    }

    /**
     * The Range constructor.
     */
    private Range(
        T start,
        T end) {

        this(
            RangeType.InclusiveToInclusive,
            start,
            end,
            Comparator.make());
    }
    /**
     * The Range constructor.
     */
    private Range(
        RangeType rangeType,
        T start,
        T end) {

        this(
            rangeType,
            start,
            end,
            Comparator.make());
    }

    /**
     * The Range constructor.
     */
    private Range(
        RangeType rangeType,
        T start,
        T end,
        IBinaryComparator<IRange<T>> comparator) {

        Conditions.validateNotNull(
            start,
            "The start value of a range.");

        Conditions.validateNotNull(
            start,
            "The end value of a range.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a range.");

        this.start = start;
        this.end = end;
        this.rangeType = rangeType;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the start value.
     */
    @Override
    public T start() {
        return this.start;
    }

    /**
     * Gets the end value.
     */
    @Override
    public T end() {
        return this.end;
    }

    /**
     * Checks whether a value is in the defined range.
     */
    @Override
    public boolean inRange(T value) {
        return this.rangeType.inRange(this, value);
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return this.rangeType.toString(this);
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
    public boolean isEqual(IRange<T> other) {
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
    public int compareTo(IRange<T> other) {
        return this.comparator.compareTo(this, other);
    }
}
