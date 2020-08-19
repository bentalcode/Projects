package testbase.interfaces;

import base.interfaces.IEquatableComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;

import java.util.Collection;
import java.util.Map;

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
     * Fails a test with the given message.
     */
    void fail(String message);

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
     * Asserts equality with integer arrays.
     */
    void assertEquals(
        int[] lhs,
        int[] rhs,
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
     * Asserts equality with collections.
     */
    <T extends Comparable<T>> void assertEquals(
        Collection<T> lhs,
        Collection<T> rhs,
        String message);

    /**
     * Asserts equality with collections.
     */
    <T extends Comparable<T>> void assertEquals(
        Collection<T> lhs,
        Collection<T> rhs,
        IEquatableComparator<T> comparator,
        String message);

    /**
     * Asserts equality with maps.
     */
    <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void assertEquals(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        String message);

    /**
     * Asserts equality with maps.
     */
    <TKey extends Comparable<TKey>, TValue> void assertEquals(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IEquatableComparator<TKey> keyComparator,
        IEquatableComparator<TValue> valueComparator,
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
     * Asserts equality with iterator and reverse iterator.
     */
    <T extends Comparable<T>> void assertEqualsWithIteratorAndReverseIterator(
        IIterator<T> lhs,
        IReverseIterator<T> rhs,
        String message);

    /**
     * Asserts equality with iterator and reverse iterator.
     */
    <T extends Comparable<T>> void assertEqualsWithIteratorAndReverseIterator(
        IIterator<T> lhs,
        IReverseIterator<T> rhs,
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
