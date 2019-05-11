package base.interfaces;

import java.util.BitSet;

/**
 * The IPrime interface defines complimentary APIs for a prime number.
 */
public interface IPrime {
    /**
     * Checks whether a number is a prime.
     */
    boolean isPrime(int prime);

    /**
     * Gets the next prime number.
     */
    int getNextPrime(int currentPrime);

    /**
     * Calculates prime numbers in range 0 to maxNumber.
     */
    BitSet calculatePrimes(int maxNumber);
}