package testbase.interfaces;

import java.util.Iterator;

/**
 * The IAssert interface defines an asset.
 */
public interface IAssert {
    /**
     * Asserts equality.
     */
    <T> void assertEquals(
        Iterator<T> lhs,
        Iterator<T> rhs,
        String message);
}
