package base.core;

import base.interfaces.IIterator;
import base.interfaces.IPrime;
import java.util.BitSet;

/**
 * The Prime class implements a prime number.
 */
public final class Prime implements IPrime {
    private static final int MAX_CACHED_NUMBER = 10000;

    private final int primesLength;
    private final BitSet primes;

    /**
     * The Prime constructor.
     */
    public Prime() {
        this(MAX_CACHED_NUMBER);
    }

    /**
     * The Prime constructor.
     * The cached numbers are defined at range: (0-maxCachedNumber)
     */
    public Prime(int maxCachedNumber) {
        //
        // Allocate a bit set for range: (0...maxNumber)
        //
        this.primesLength = maxCachedNumber + 1;
        this.primes = new BitSet(this.primesLength);

        //
        // Calculates the primes...
        //
        this.calculatePrimes(this.primes, this.primesLength);
    }

    /**
     * Checks whether a number is a prime number.
     */
    @Override
    public boolean isPrime(int number) {
        if (number <= 1) {
            return false;
        }

        //
        // If the number is cached, then return the result from the cache...
        //
        if (number < this.primes.length()) {
            return this.primes.get(number);
        }

        //
        // Otherwise, calculate the result...
        //
        return this.calculateIsPrime(number);
    }

    /**
     * Gets the next prime number.
     */
    @Override
    public int getNextPrime(int number) {
        int nextPrime;

        //
        // First, try finding the next prime number in the cache...
        //
        for (nextPrime = ArithmeticOperators.safeAdd(number, 1);
             nextPrime < this.primesLength;
             ++nextPrime) {

            if (this.primes.get(nextPrime)) {
                return nextPrime;
            }
        }

        //
        // If the next prime number is not in the cache,
        // then calculate for each candidate number whether it is a prime...
        //
        while(!this.isPrime(nextPrime)) {
            nextPrime = ArithmeticOperators.safeAdd(nextPrime, 1);
        }

        return nextPrime;
    }

    /**
     * Calculates prime numbers in range 0 to maxNumber.
     * Algorithm: Sieve of Eratosthenes.
     */
    @Override
    public BitSet calculatePrimes(int maxNumber) {
        Conditions.validate(
            maxNumber >= 10,
            "The max number should be equal or larger than 10.");

        //
        // Allocate a bit set for range: (0...maxNumber)
        //
        int length = maxNumber + 1;
        BitSet primes = new BitSet(length);

        //
        // Calculate primes...
        //
        this.calculatePrimes(primes, length);

        return primes;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<Integer> getIterator() {
        return PrimeIterator.make(this);
    }

    /**
     * Gets an iterator from a specific number.
     */
    @Override
    public IIterator<Integer> getIterator(int fromNumber) {
        return PrimeIterator.make(this, fromNumber);
    }

    /**
     * Calculates prime numbers in range 0 to length - 1.
     * Algorithm: Sieve of Eratosthenes.
     */
    private void calculatePrimes(BitSet primes, int length) {
        //
        // Set all number as primes besides zero and one...
        //
        primes.set(0, false);
        primes.set(1, false);

        for (int i = 2; i < length; ++i) {
            primes.set(i, true);
        }

        //
        // Cross off the non-prime numbers...
        //
        int currentPrime = 2;

        while (currentPrime < length) {
            this.crossOf(primes, length, currentPrime);

            //
            // Find the next prime...
            //
            Integer nextPrime = this.lookupNextPrime(primes, length, currentPrime);

            if (nextPrime == null) {
                break;
            }

            currentPrime = nextPrime;
        }
    }

    /**
     * Calculates whether a number is a prime.
     */
    private boolean calculateIsPrime(int number) {
        if (number <= 1) {
            return false;
        }

        int upperRange = (int)Math.sqrt(number);
        for (int i = 2; i <= upperRange; ++i) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }

    /**
     * Crosses-off the non-primes numbers.
     */
    private void crossOf(BitSet primes, int length, int currentPrime) {
        //
        // A multiplier of a prime is not a prime.
        // Therefore, crosses-off the remaining multiples of prime.
        // We starts after the currentPrime since this number is crossed off in the previous iteration...
        //
        for (int i = currentPrime * currentPrime; i < length; i += currentPrime) {
            primes.set(i, false);
        }
    }

    /**
     * Look-ups the next prime number.
     * returns null if the result od a prime number is not cached.
     */
    private Integer lookupNextPrime(BitSet primes, int length, int currentNumber) {
        int nextPrime = currentNumber + 1;

        while (nextPrime < length) {
            if (primes.get(nextPrime)) {
                return nextPrime;
            }

            ++nextPrime;
        }

        return null;
    }
}
