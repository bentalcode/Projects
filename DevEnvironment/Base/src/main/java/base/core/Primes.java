package base.core;

import java.util.BitSet;

/**
 * The Prime class implements complementary APIs for primes.
 */
public final class Primes {
    private static final int maxCachedNumber = 10000;
    private static final Prime prime = new Prime(Primes.maxCachedNumber);

    /**
     * Checks whether a number is a prime number.
     */
    public static boolean isPrime(int prime) {
        return Primes.prime.isPrime(prime);
    }

    /**
     * Gets the next prime number.
     */
    public static int getNextPrime(int currentPrime) {
        return prime.getNextPrime(currentPrime);
    }

    /**
     * Calculates prime numbers in range 0 to maxNumber.
     */
    public static BitSet calculatePrimes(int maxNumber) {
        return prime.calculatePrimes(maxNumber);
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Primes() {
    }
}
