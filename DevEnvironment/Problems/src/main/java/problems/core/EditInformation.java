package problems.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import problems.interfaces.EditType;
import problems.interfaces.IEditInformation;

/**
 * The EditInformation class implements an information of a specific edit.
 */
public final class EditInformation<T extends Comparable<T>> implements IEditInformation<T> {
    private final EditType editType;
    private final T srcValue;
    private final T destValue;
    private final IBinaryComparator<IEditInformation<T>> comparator;
    private final int hashCode;

    /**
     * Creates a new insert information.
     */
    public static <T extends Comparable<T>> IEditInformation<T> createInsert(
        T afterValue,
        T insertedValue) {
        return new EditInformation<>(EditType.Insert, afterValue, insertedValue);
    }

    /**
     * Creates a new remove-edit information.
     */
    public static <T extends Comparable<T>> IEditInformation<T> createRemove(T removedValue) {
        return new EditInformation<>(EditType.Remove, removedValue, null);
    }

    /**
     * Creates a new replacement information.
     */
    public static <T extends Comparable<T>> IEditInformation<T> createReplace(T currValue, T newValue) {
        return new EditInformation<>(EditType.Replace, currValue, newValue);
    }

    /**
     * The EditInformation constructor.
     */
    private EditInformation(EditType editType, T srcValue, T destValue) {
        Conditions.validateNotNull(
            editType,
            "The edit type.");

        this.editType = editType;
        this.srcValue = srcValue;
        this.destValue = destValue;
        this.comparator = EditInformation.defaultComparator();
        this.hashCode = this.comparator.getHashCode(this);
    }

    /**
     * Gets the type of edit.
     */
    @Override
    public EditType getType() {
        return this.editType;
    }

    /**
     * Gets the corresponding source value.
     */
    @Override
    public T getSrcValue() {
        return this.srcValue;
    }

    /**
     * Gets the corresponding destination value.
     */
    @Override
    public T getDestValue() {
        return this.destValue;
    }

    /**
     * Gets the string representation of an edit.
     */
    @Override
    public String toString() {
        return
            "Type = " + this.editType.toString() +
            ", SrcValue = " + this.srcValue +
            ", DestValue = " + this.destValue;
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
    public boolean isEqual(IEditInformation<T> other) {
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
    public int compareTo(IEditInformation<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IEditInformation<T>> defaultComparator() {
        return new EditInformation.Comparator<>();
    }

    /**
     * The Comparator class implements a comparator of an edit information.
     */
    public static final class Comparator<T extends Comparable<T>> extends
        AbstractBinaryComparator<IEditInformation<T>> {

        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IEditInformation<T> obj) {
            return new HashCodeBuilder(809, 811)
                .withObject(obj.getType())
                .withObject(obj.getSrcValue())
                .withObject(obj.getDestValue())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IEditInformation<T> lhs, IEditInformation<T> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getType(), rhs.getType())
                .withObject(lhs.getSrcValue(), rhs.getSrcValue())
                .withObject(lhs.getDestValue(), rhs.getDestValue())
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
        public int compareTo(IEditInformation<T> lhs, IEditInformation<T> rhs) {
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
                .withObject(lhs.getType(), rhs.getType())
                .withObject(lhs.getSrcValue(), rhs.getSrcValue())
                .withObject(lhs.getDestValue(), rhs.getDestValue())
                .build();
        }
    }
}
