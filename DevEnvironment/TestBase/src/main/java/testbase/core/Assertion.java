package testbase.core;

import base.core.Comparator;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import org.junit.Assert;

import java.util.Collection;
import java.util.Map;
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
     * Asserts false.
     */
    @Override
    public void assertFalse(
        boolean expression,
        String message) {

        Assert.assertFalse(
            message,
            expression);
    }

    /**
     * Asserts not null.
     */
    @Override
    public void assertNotNull(
        Object obj,
        String message) {

        Assert.assertNotNull(
            message,
            obj);
    }

    /**
     * Fails a test with the given message.
     */
    @Override
    public void fail(String message) {
        Assert.fail(message);
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

        IBinaryComparator<T> comparator = Comparator.make();

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
     * Asserts equality with arrays.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        T[] lhs,
        T[] rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.make();

        this.assertEquals(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality with arrays.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        T[] lhs,
        T[] rhs,
        IEquatableComparator<T> comparator,
        String message) {

        boolean status = new EqualBuilder()
            .withArray(lhs, rhs, comparator)
            .build();

        this.assertTrue(
            status,
            message);
    }

    /**
     * Asserts equality with collections.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        Collection<T> lhs,
        Collection<T> rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.make();

        this.assertEquals(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality with collections.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        Collection<T> lhs,
        Collection<T> rhs,
        IEquatableComparator<T> comparator,
        String message) {

        boolean status = new EqualBuilder()
            .withCollection(lhs, rhs, comparator)
            .build();

        this.assertTrue(
            status,
            message);
    }

    /**
     * Asserts equality with maps.
     */
    @Override
    public <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void assertEquals(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        String message) {

        boolean status = new EqualBuilder()
            .withMap(lhs, rhs)
            .build();

        this.assertTrue(
            status,
            message);
    }

    /**
     * Asserts equality with maps.
     */
    @Override
    public <TKey extends Comparable<TKey>, TValue> void assertEquals(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IEquatableComparator<TKey> keyComparator,
        IEquatableComparator<TValue> valueComparator,
        String message) {

        boolean status = new EqualBuilder()
            .withMap(lhs, rhs, keyComparator, valueComparator)
            .build();

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

        IBinaryComparator<T> comparator = Comparator.make();

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

        boolean status = new EqualBuilder()
            .withIterator(lhs, rhs, comparator)
            .build();

        this.assertTrue(
            status,
            message);
    }

    /**
     * Asserts equality with iterator and reverse iterator.
     */
    @Override
    public <T extends Comparable<T>> void assertEqualsWithIteratorAndReverseIterator(
        IIterator<T> lhs,
        IReverseIterator<T> rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.make();

        this.assertEqualsWithIteratorAndReverseIterator(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality with iterator and reverse iterator.
     */
    @Override
    public <T extends Comparable<T>> void assertEqualsWithIteratorAndReverseIterator(
        IIterator<T> lhs,
        IReverseIterator<T> rhs,
        IEquatableComparator<T> comparator,
        String message) {

        boolean status = new EqualBuilder()
            .withIteratorAndReverseIterator(lhs, rhs, comparator)
            .build();

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

        IBinaryComparator<T> comparator = Comparator.make();

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

        boolean status = new EqualBuilder()
            .withIterable(lhs, rhs, comparator)
            .build();

        this.assertTrue(
            status,
            message);
    }
}
