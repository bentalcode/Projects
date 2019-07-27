package testbase.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;

/**
 * The IAssertion interface defines an assertion.
 */
public interface IAssertion {
    /**
     * Asserts true.
     */
    void assertTrue(
        boolean expression,
        String message);

    /**
     * Asserts equality with objects.
     */
    <T extends Comparable<T>> void assertEquals(
        T lhs,
        T rhs,
        String message);

    /**
     * Asserts equality with objects.
     */
    <T extends Comparable<T>> void assertEquals(
        T lhs,
        T rhs,
        IBinaryComparator<T> comparator,
        String message);

    /**
     * Asserts equality with iterators.
     */
    <T extends Comparable<T>> void assertEquals(
        IIterator<T> lhs,
        IIterator<T> rhs,
        String message);

    /**
     * Asserts equality with iterators.
     */
    <T extends Comparable<T>> void assertEquals(
        IIterator<T> lhs,
        IIterator<T> rhs,
        IBinaryComparator<T> comparator,
        String message);
}
