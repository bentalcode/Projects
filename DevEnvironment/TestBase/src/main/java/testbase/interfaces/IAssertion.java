package testbase.interfaces;

import base.interfaces.IBinaryComparator;
import java.util.Iterator;

/**
 * The IAssertion interface defines an assertion.
 */
public interface IAssertion {
    /**
     * Asserts equality.
     */
    <T extends Comparable<T>> void assertEquals(
        Iterator<T> lhs,
        Iterator<T> rhs,
        String message);

    /**
     * Asserts equality.
     */
    <T extends Comparable<T>> void assertEquals(
        Iterator<T> lhs,
        Iterator<T> rhs,
        IBinaryComparator<T> comparator,
        String message);
}
