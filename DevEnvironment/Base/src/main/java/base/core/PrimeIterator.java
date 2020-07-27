package base.core;

import base.interfaces.IIterator;

/**
 * The PrimeIterator class implements an iterator of a prime.
 */
public final class PrimeIterator implements IIterator<Integer> {
    private static final int initialPrime = 1;

    private final Prime prime;
    private int currPrime;
    private final int maxPrime;

    /**
     * Creates a new iterator of a prime.
     */
    public static IIterator<Integer> of(Prime prime) {
        return new PrimeIterator(prime, initialPrime);
    }

    /**
     * Creates a new iterator of a prime.
     */
    public static IIterator<Integer> of(Prime prime, int currPrime) {
        return new PrimeIterator(prime, currPrime);
    }

    /**
     * The PrimeIterator constructor.
     */
    private PrimeIterator(Prime prime) {
        this(
            prime,
            initialPrime);
    }

    /**
     * The PrimeIterator constructor.
     */
    private PrimeIterator(Prime prime, int currPrime) {
        Conditions.validateNotNull(
            prime,
            "The prime.");

        this.prime = prime;
        this.maxPrime = this.maxPrime();
        this.reset(currPrime);
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currPrime <= this.maxPrime;
    }

    /**
     * Gets the next element.
     */
    @Override
    public Integer next() {
        assert(this.hasNext());

        this.currPrime = this.prime.getNextPrime(this.currPrime);

        return this.currPrime;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.reset(initialPrime);
    }

    /**
     * Resets the iterator.
     */
    public void reset(int currPrime) {
        this.currPrime = currPrime;
    }

    /**
     * Calculates the max prime number for an integer.
     */
    private int maxPrime() {
        int maxPrime = 2;

        int currNumber = Integer.MAX_VALUE;

        while (currNumber >= 2) {
            if (this.prime.isPrime(currNumber)) {
                maxPrime = currNumber;
                break;
            }

            --currNumber;
        }

        return maxPrime;
    }
}
