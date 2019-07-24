package testbase.core;

import base.core.Comparator;
import base.core.EqualBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
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
     * Asserts equality.
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
     * Asserts equality.
     */
    @Override
    public <T extends Comparable<T>> void assertEquals(
        IIterator<T> lhs,
        IIterator<T> rhs,
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
