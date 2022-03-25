package algorithms.core;

import algorithms.interfaces.ICatalanNumber;
import base.interfaces.IIterator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CatalanNumber class implements a catalan number.
 */
public final class CatalanNumber implements ICatalanNumber {
    public static final int MAX_CALCULATED_NUMBER = 35;

    private final long[] catalans;
    private static final Logger log = LoggerFactory.getLogger(CatalanNumber.class);

    /**
     * The CatalanNumber constructor.
     */
    public CatalanNumber() {
        this(MAX_CALCULATED_NUMBER);
    }

    /**
     * The CatalanNumber constructor.
     * The CatalanNumber are defined at range: (0-maxCachedNumber)
     */
    public CatalanNumber(int maxCachedNumber) {
        //
        // Calculates the catalans for range: (0...maxNumber)
        //
        this.catalans = calculateCatalanNumbers(maxCachedNumber);
    }

    /**
     * Calculates a catalan number for n.
     */
    @Override
    public long calculateCatalan(int n) {
        validateN(n);

        if (n <= 1) {
            return 1;
        }

        if (n < this.catalans.length) {
            return this.catalans[n];
        }

        return calculateCatalanNumber(n);
    }

    /**
     * Calculates catalan numbers in range: (0...maxNumber)
     */
    @Override
    public long[] calculateCatalans(int maxNumber) {
        return calculateCatalanNumbers(maxNumber);
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<Long> getIterator() {
        return CatalanNumberIterator.make(this);
    }

    /**
     * Gets an iterator from a specific number.
     */
    @Override
    public IIterator<Long> getIterator(int fromNumber) {
        return CatalanNumberIterator.make(this, fromNumber);
    }

    /**
     * Calculates a catalan number.
     */
    public static long calculateCatalanNumber(int n) {
        validateN(n);

        if (n <= 1) {
            return 1;
        }

        long result = 0;
        for (int i = 0; i < n; ++i) {
            result += calculateCatalanNumber(i) * calculateCatalanNumber(n - i - 1);
        }

        return result;
    }

    /**
     * Calculates catalan numbers in range: (0...maxNumber)
     */
    public static long[] calculateCatalanNumbers(int maxNumber) {
        validateN(maxNumber);

        //
        // Allocate a result array for range: (0...maxNumber)
        //
        int length = maxNumber + 1;
        long[] catalans = new long[length];

        //
        // Calculate catalan numbers...
        //
        catalans[0] = 1;
        catalans[1] = 1;

        for (int number = 2; number <= maxNumber; ++number) {
            catalans[number] = calculateCatalanNumber(number, catalans);
        }

        return catalans;
    }

    /**
     * Calculates a catalan number.
     */
    private static long calculateCatalanNumber(int n, long[] catalans) {
        long result = 0;

        for (int i = 0; i < n; ++i) {
            result += catalans[i] * catalans[n - i - 1];
        }

        return result;
    }

    /**
     * Validates a number for calculating a catalan number.
     */
    private static void validateN(int n) {
        if (n < 0 || n > MAX_CALCULATED_NUMBER) {
            String errorMessage = "The number for calculating a catalan number is: (0-" + MAX_CALCULATED_NUMBER + "]";

            log.error(errorMessage);
            throw new ArithmeticException(errorMessage);
        }
    }
}
