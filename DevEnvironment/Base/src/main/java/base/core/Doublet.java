package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.IDoublet;

/**
 * The Doublet class implements a doublet.
 */
public final class Doublet<Type1 extends Comparable<Type1>, Type2 extends Comparable<Type2>>
    implements IDoublet<Type1, Type2> {

    private final Type1 first;
    private final Type2 second;
    private final IBinaryComparator<IDoublet<Type1, Type2>> comparator;
    private final int hashCode;

    /**
     * Creates a new instance of a doublet.
     */
    public static<Type1 extends Comparable<Type1>, Type2
        extends Comparable<Type2>> IDoublet<Type1, Type2> of(Type1 first, Type2 second) {

        return new Doublet<>(
            first,
            second,
            defaultComparator());
    }

    /**
     * The Doublet constructor.
     */
    private Doublet(
        Type1 first,
        Type2 second,
        IBinaryComparator<IDoublet<Type1, Type2>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a doublet.");

        this.first = first;
        this.second = second;
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
     * Gets the string representation of a doublet.
     */
    @Override
    public String toString() {
        return "First: " + this.first + "Second: " + this.second;
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
    public boolean isEqual(IDoublet<Type1, Type2> other) {
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
    public int compareTo(IDoublet<Type1, Type2> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static
        <
            Type1 extends Comparable<Type1>,
            Type2 extends Comparable<Type2>
        > IBinaryComparator<IDoublet<Type1, Type2>> defaultComparator() {
        IBinaryComparator<Type1> firstElementComparator = base.core.Comparator.defaultComparator();
        IBinaryComparator<Type2> secondElementComparator = base.core.Comparator.defaultComparator();

        return new Comparator<>(
            firstElementComparator,
            secondElementComparator);
    }

    /**
     * The Comparator class implements a comparator of a doublet.
     */
    public static final class Comparator<Type1 extends Comparable<Type1>, Type2 extends Comparable<Type2>> extends AbstractBinaryComparator<IDoublet<Type1, Type2>> {
        private final IBinaryComparator<Type1> firstElementComparator;
        private final IBinaryComparator<Type2> secondElementComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(
            IBinaryComparator<Type1> firstElementComparator,
            IBinaryComparator<Type2> secondElementComparator) {

            Conditions.validateNotNull(
                firstElementComparator,
                "The comparator of the first element.");

            Conditions.validateNotNull(
                secondElementComparator,
                "The comparator of the second element.");

            this.firstElementComparator = firstElementComparator;
            this.secondElementComparator = secondElementComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IDoublet<Type1, Type2> obj) {
            return new HashCodeBuilder(13, 17)
                .withObject(obj.first(), this.firstElementComparator)
                .withObject(obj.second(), this.secondElementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IDoublet<Type1, Type2> lhs, IDoublet<Type1, Type2> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.first(), rhs.first(), this.firstElementComparator)
                .withObject(lhs.second(), rhs.second(), this.secondElementComparator)
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
        public int compareTo(IDoublet<Type1, Type2> lhs, IDoublet<Type1, Type2> rhs) {
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
                .build();
        }
    }
}
