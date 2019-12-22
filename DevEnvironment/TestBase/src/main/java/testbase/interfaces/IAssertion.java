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
     * Asserts equality with booleans.
     */
    void assertEquals(
        boolean lhs,
        boolean rhs,
        String message);

    /**
     * Asserts equality with bytes.
     */
    void assertEquals(
        byte lhs,
        byte rhs,
        String message);

    /**
     * Asserts equality with shorts.
     */
    void assertEquals(
        short lhs,
        short rhs,
        String message);

    /**
     * Asserts equality with integers.
     */
    void assertEquals(
        int lhs,
        int rhs,
        String message);

    /**
     * Asserts equality with longs.
     */
    void assertEquals(
        long lhs,
        long rhs,
        String message);

    /**
     * Asserts equality with doubles.
     */
    void assertEquals(
        double lhs,
        double rhs,
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
    <T extends Comparable<T>> void assertEquals(
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
    <T extends Comparable<T>> void assertEqualsWithIterators(
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
