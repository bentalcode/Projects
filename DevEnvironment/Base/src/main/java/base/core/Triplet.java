package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.ITriplet;

/**
 * The Triplet class implements a triplet.
 */
public final class Triplet
    <
        Type1 extends Comparable<Type1>,
        Type2 extends Comparable<Type2>,
        Type3 extends Comparable<Type3>
    > implements ITriplet<Type1, Type2, Type3> {

    private final Type1 first;
    private final Type2 second;
    private final Type3 third;
    private final IBinaryComparator<ITriplet<Type1, Type2, Type3>> comparator;
    private final int hashCode;

    /**
     * Creates a new instance of a triplet.
     */
    public static
    <
        Type1 extends Comparable<Type1>,
        Type2 extends Comparable<Type2>,
        Type3 extends Comparable<Type3>
    > ITriplet<Type1, Type2, Type3> of(Type1 first, Type2 second, Type3 third) {
        return new Triplet<>(
            first,
            second,
            third,
            defaultComparator());
    }

    /**
     * The Triplet constructor.
     */
    private Triplet(
        Type1 first,
        Type2 second,
        Type3 third,
        IBinaryComparator<ITriplet<Type1, Type2, Type3>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a triplet.");

        this.first = first;
        this.second = second;
        this.third = third;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the first value.
     */
    @Override
    public Type1 first() {
        return this.first;
    }

    /**
     * Gets the second value.
     */
    @Override
    public Type2 second() {
        return this.second;
    }

    /**
     * Gets the third value.
     */
    @Override
    public Type3 third() {
        return this.third;
    }

    /**
     * Gets the string representation of a range.
     */
    @Override
    public String toString() {
        return "First: " + this.first + "Second: " + this.second + "Third: " + this.third;
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
    public boolean isEqual(ITriplet<Type1, Type2, Type3> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    public int compareTo(ITriplet<Type1, Type2, Type3> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static
        <
            Type1 extends Comparable<Type1>,
            Type2 extends Comparable<Type2>,
            Type3 extends Comparable<Type3>
        > IBinaryComparator<ITriplet<Type1, Type2, Type3>> defaultComparator() {
        IBinaryComparator<Type1> firstElementComparator = base.core.Comparator.defaultComparator();
        IBinaryComparator<Type2> secondElementComparator = base.core.Comparator.defaultComparator();
        IBinaryComparator<Type3> thirdElementComparator = base.core.Comparator.defaultComparator();

        return new Comparator<>(
            firstElementComparator,
            secondElementComparator,
            thirdElementComparator);
    }

    /**
     * The Comparator class implements a comparator of a triplet.
     */
    public static final class Comparator
        <
            Type1 extends Comparable<Type1>,
            Type2 extends Comparable<Type2>,
            Type3 extends Comparable<Type3>
        > extends AbstractBinaryComparator<ITriplet<Type1, Type2, Type3>> {

        private final IBinaryComparator<Type1> firstElementComparator;
        private final IBinaryComparator<Type2> secondElementComparator;
        private final IBinaryComparator<Type3> thirdElementComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(
            IBinaryComparator<Type1> firstElementComparator,
            IBinaryComparator<Type2> secondElementComparator,
            IBinaryComparator<Type3> thirdElementComparator) {

            Conditions.validateNotNull(
                firstElementComparator,
                "The comparator of the first element.");

            Conditions.validateNotNull(
                secondElementComparator,
                "The comparator of the second element.");

            Conditions.validateNotNull(
                thirdElementComparator,
                "The comparator of the third element.");

            this.firstElementComparator = firstElementComparator;
            this.secondElementComparator = secondElementComparator;
            this.thirdElementComparator = thirdElementComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITriplet<Type1, Type2, Type3> obj) {
            return new HashCodeBuilder(43, 47)
                .withObject(obj.first(), this.firstElementComparator)
                .withObject(obj.second(), this.secondElementComparator)
                .withObject(obj.third(), this.thirdElementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ITriplet<Type1, Type2, Type3> lhs, ITriplet<Type1, Type2, Type3> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.first(), rhs.first(), this.firstElementComparator)
                .withObject(lhs.second(), rhs.second(), this.secondElementComparator)
                .withObject(lhs.third(), rhs.third(), this.thirdElementComparator)
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
        public int compareTo(ITriplet<Type1, Type2, Type3> lhs, ITriplet<Type1, Type2, Type3> rhs) {
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
                .withObject(lhs.first(), rhs.first(), this.firstElementComparator)
                .withObject(lhs.second(), rhs.second(), this.secondElementComparator)
                .withObject(lhs.third(), rhs.third(), this.thirdElementComparator)
                .build();
        }
    }
}
