package testbase.core;

import base.interfaces.IBinaryComparator;
import testbase.interfaces.IAssertion;

import java.util.Iterator;

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
     * Asserts equality.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        Iterator<T> lhs,
        Iterator<T> rhs,
        String message) {

        IBinaryComparator<T> comparator = Comparator.DefaultComparator();

        this.assertEquals(
            lhs,
            rhs,
            comparator,
            message);
    }

    /**
     * Asserts equality.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        Iterator<T> lhs,
        Iterator<T> rhs,
        IBinaryComparator<T> comparator,
        String message) {

        boolean status = new EqualBuilder().withIterator(
            lhs,
            rhs,
            comparator).build();

        org.junit.Assert.assertTrue(
            message,
            status);
    }
}
