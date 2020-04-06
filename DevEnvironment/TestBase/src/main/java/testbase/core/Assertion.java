package testbase.core;

import base.core.Comparator;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import org.junit.Assert;
import testbase.interfaces.IAssertion;

/**
 * The Assertion class implements an assertion.
 */
public final class Assertion implements IAssertion {
    /**
     * The Assertion constructor.
     */
    public Assertion() {
    }

    /**
     * Asserts true.
     */
    @Override
    public void assertTrue(
        boolean expression,
        String message) {

        Assert.assertTrue(
            message,
            expression);
    }

    /**
     * Asserts equality with booleans.
     */
    @Override
    public void assertEquals(
        boolean lhs,
        boolean rhs,
        String message) {

        this.assertTrue(lhs == rhs, message);
    }

    /**
     * Asserts equality with bytes.
     */
    @Override
    public void assertEquals(
        byte lhs,
        byte rhs,
        String message) {

        this.assertTrue(lhs == rhs, message);
    }

    /**
     * Asserts equality with shorts.
     */
    @Override
    public void assertEquals(
        short lhs,
        short rhs,
        String message) {

        this.assertTrue(lhs == rhs, message);
    }

    /**
     * Asserts equality with integers.
     */
    @Override
    public void assertEquals(
        int lhs,
        int rhs,
        String message) {

        this.assertTrue(lhs == rhs, message);
    }

    /**
     * Asserts equality with longs.
     */
    @Override
    public void assertEquals(
        long lhs,
        long rhs,
        String message) {

        this.assertTrue(lhs == rhs, message);
    }

    /**
     * Asserts equality with doubles.
     */
    @Override
    public void assertEquals(
        double lhs,
        double rhs,
        String message) {

        this.assertTrue(lhs == rhs, message);
    }

    /**
     * Asserts equality with integer arrays.
     */
    @Override
    public void assertEquals(
        int[] lhs,
        int[] rhs,
        String message) {

        boolean status = new EqualBuilder()
            .withIntegerArray(lhs, rhs)
            .build();

        this.assertTrue(status, message);
    }

    /**
     * Asserts equality with objects.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        T lhs,
        T rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.defaultComparator();

        this.assertEquals(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality with objects.
     */
    @Override
    public <T> void assertEquals(
        T lhs,
        T rhs,
        IEquatableComparator<T> comparator,
        String message) {

        boolean status = new EqualBuilder().withObject(
            lhs,
            rhs,
            comparator).build();

        this.assertTrue(
            status,
            message);
    }

    /**
     * Asserts equality with objects.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        T[] lhs,
        T[] rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.defaultComparator();

        this.assertEquals(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality with objects.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        T[] lhs,
        T[] rhs,
        IEquatableComparator<T> comparator,
        String message) {

        boolean status = new EqualBuilder().withArray(
            lhs,
            rhs,
            comparator).build();

        this.assertTrue(
            status,
            message);
    }

    /**
     * Asserts equality with iterators.
     */
    @Override
    public <T extends Comparable<T>> void assertEqualsWithIterators(
        IIterator<T> lhs,
        IIterator<T> rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.defaultComparator();

        this.assertEqualsWithIterators(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality with iterators.
     */
    @Override
    public <T extends Comparable<T>> void assertEqualsWithIterators(
        IIterator<T> lhs,
        IIterator<T> rhs,
        IEquatableComparator<T> comparator,
        String message) {

        boolean status = new EqualBuilder().withIterator(
            lhs,
            rhs,
            comparator).build();

        this.assertTrue(
            status,
            message);
    }

    /**
     * Asserts equality with iterables.
     */
    @Override
    public <T extends Comparable<T>> void assertEqualsWithIterables(
        IIterable<T> lhs,
        IIterable<T> rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.defaultComparator();

        this.assertEqualsWithIterables(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality with iterables.
     */
    @Override
    public <T> void assertEqualsWithIterables(
        IIterable<T> lhs,
        IIterable<T> rhs,
        IEquatableComparator<T> comparator,
        String message) {

        boolean status = new EqualBuilder().withIterable(
            lhs,
            rhs,
            comparator).build();

        this.assertTrue(
            status,
            message);
    }
}
