package testbase.core;

import java.util.BitSet;

/**
 * The Prime class implements complementary APIs for primes.
 */
public final class Primes {
    private static final int MaxCachedNumber = 10000;
    private static final Prime Prime = new Prime(Primes.MaxCachedNumber);

    /**
     * Checks whether a number is a prime number.
     */
    public static boolean isPrime(int prime) {
        return Prime.isPrime(prime);
    }

    /**
     * Gets the next prime number.
     */
    public static int getNextPrime(int currentPrime) {
        return Prime.getNextPrime(currentPrime);
    }

    /**
     * Calculates prime numbers in range 0 to maxNumber.
     */
    public static BitSet calculatePrimes(int maxNumber) {
        return Prime.calculatePrimes(maxNumber);
    }
}
