package base.core;

import base.interfaces.ICollectionComparator;
import base.interfaces.IComparableComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IIteratorComparator;
import java.util.Collection;

/**
 * The CollectionComparator class implements a comparator for a collection.
 */
public final class CollectionComparator<T extends Comparable<T>> extends AbstractBinaryComparator<Collection<T>> implements ICollectionComparator<T> {
    private final IIteratorComparator<T> iteratorComparator = new IteratorComparator<>();

    /**
     * The CollectionComparator constructor.
     */
    public CollectionComparator() {
    }

    /**
     * Gets the hash code of this instance.
     */
    @Override
    public int getHashCode(Collection<T> obj) {
        return new HashCodeBuilder(7, 11) 
            .withCollection(obj).build();
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public boolean isEqual(Collection<T> lhs, Collection<T> rhs) {
        return this.isEqual(lhs, rhs, Comparator.defaultComparator());
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(Collection<T> lhs, Collection<T> rhs) {
        return this.compareTo(lhs, rhs, Comparator.defaultComparator());
    }

    /**
     * Checks whether the collection are equals with an element comparator.
     */
    @Override
    public boolean isEqual(Collection<T> lhs, Collection<T> rhs, IEquatableComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        if (lhs == null && rhs == null) {
            return true;
        }

        if (lhs == null || rhs == null) {
            return false;
        }

        if (lhs.size() != rhs.size()) {
            return false;
        }

        return this.iteratorComparator.isEqual(Iterator.of(lhs), Iterator.of(rhs), comparator);
    }

    /**
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(Collection<T> lhs, Collection<T> rhs, IComparableComparator<T> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        if (lhs.size() < rhs.size()) {
            return -1;
        }

        if (lhs.size() > rhs.size()) {
            return 1;
        }

        return this.iteratorComparator.compareTo(Iterator.of(lhs), Iterator.of(rhs), comparator);
    }
}
