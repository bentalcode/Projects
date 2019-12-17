package base.core;

import base.interfaces.ICollectionComparator;
import base.interfaces.IComparableComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IListComparator;
import java.util.List;

/**
 * The ListComparator class implements a comparator for a list.
 */
public final class ListComparator<T extends Comparable<T>> extends AbstractBinaryComparator<List<T>> implements IListComparator<T> {
    private final ICollectionComparator<T> collectionComparator = new CollectionComparator<>();

    /**
     * The ListComparator constructor.
     */
    public ListComparator() {
    }

    /**
     * Gets the hash code of this instance.
     */
    @Override
    public int getHashCode(List<T> obj) {
        return this.collectionComparator.getHashCode(obj);
    }

    /**
     * Checks whether two instances are equals.
     */
    @Override
    public boolean isEqual(List<T> lhs, List<T> rhs) {
        return this.collectionComparator.isEqual(lhs, rhs);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(List<T> lhs, List<T> rhs) {
        return this.collectionComparator.compareTo(lhs, rhs);
    }

    /**
     * Checks whether the collection are equals with an element comparator.
     */
    @Override
    public boolean isEqual(List<T> lhs, List<T> rhs, IEquatableComparator<T> comparator) {
        return this.collectionComparator.isEqual(lhs, rhs, comparator);
    }

    /**
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(List<T> lhs, List<T> rhs, IComparableComparator<T> comparator) {
        return this.collectionComparator.compareTo(lhs, rhs, comparator);
    }
}
