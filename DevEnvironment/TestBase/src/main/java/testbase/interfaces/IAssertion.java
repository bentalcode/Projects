package testbase.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;

/**
 * The IAssertion interface defines an assertion.
 */
public interface IAssertion {
    /**
     * Asserts equality.
     */
    <T extends Comparable<T>> void assertEquals(
        IIterator<T> lhs,
        IIterator<T> rhs,
        String message);

    /**
     * Asserts equality.
     */
    <T extends Comparable<T>> void assertEquals(
        IIterator<T> lhs,
        IIterator<T> rhs,
        IBinaryComparator<T> comparator,
        String message);
}
