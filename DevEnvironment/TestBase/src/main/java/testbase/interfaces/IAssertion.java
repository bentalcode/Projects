package testbase.interfaces;

import base.interfaces.IEquatableComparator;
import base.interfaces.IIterable;
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
    <T> void assertEquals(
        T lhs,
        T rhs,
        IEquatableComparator<T> comparator,
        String message);

    /**
     * Asserts equality with arrays.
     */
    <T extends Comparable<T>> void assertEquals(
        T[] lhs,
        T[] rhs,
        String message);

    /**
     * Asserts equality with arrays.
     */
    <T> void assertEquals(
        T[] lhs,
        T[] rhs,
        IEquatableComparator<T> comparator,
        String message);

    /**
     * Asserts equality with iterators.
     */
    <T extends Comparable<T>> void assertEqualsWithIterators(
        IIterator<T> lhs,
        IIterator<T> rhs,
        String message);

    /**
     * Asserts equality with iterators.
     */
    <T> void assertEqualsWithIterators(
        IIterator<T> lhs,
        IIterator<T> rhs,
        IEquatableComparator<T> comparator,
        String message);

    /**
     * Asserts equality with iterables.
     */
    <T extends Comparable<T>> void assertEqualsWithIterables(
        IIterable<T> lhs,
        IIterable<T> rhs,
        String message);

    /**
     * Asserts equality with iterables.
     */
    <T> void assertEqualsWithIterables(
        IIterable<T> lhs,
        IIterable<T> rhs,
        IEquatableComparator<T> comparator,
        String message);
}
