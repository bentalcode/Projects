package testbase.core;

import base.core.Comparator;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IEquatableComparator;
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
     * Asserts equality with objects.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        T lhs,
        T rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.DefaultComparator();

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

        IBinaryComparator<T> comparator = Comparator.DefaultComparator();

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
    public <T extends Comparable<T>> void assertEquals(
        IIterator<T> lhs,
        IIterator<T> rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.DefaultComparator();

        this.assertEquals(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality with iterators.
     */
    @Override
    public <T> void assertEquals(
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
}
