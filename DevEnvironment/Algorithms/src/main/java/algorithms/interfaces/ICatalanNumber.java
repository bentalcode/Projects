package algorithms.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IIterator;

/**
 * The ICatalanNumber interface defines a catalan number.
 */
public interface ICatalanNumber extends IIterable<Long> {
    /**
     * Calculates a catalan number for n.
     */
    long calculateCatalan(int n);

    /**
     * Calculates catalan numbers in range 0 to maxNumber.
     */
    long[] calculateCatalans(int maxNumber);

    /**
     * Gets an iterator from a specific number.
     */
    IIterator<Long> getIterator(int fromNumber);
}
