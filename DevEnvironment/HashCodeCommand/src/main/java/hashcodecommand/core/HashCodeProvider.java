package hashcodecommand.core;

import base.core.Indexes;
import base.core.Prime;
import basicio.interfaces.IContentProvider;
import java.util.regex.Matcher;

/**
 * The HashCodeProvider class implements a provider of a hash code.
 */
public final class HashCodeProvider implements IContentProvider {
    private static final int PRE_CALCULATED_PRIMES = 10000;

    private final Prime prime;
    private int currentPrime;

    /**
     * The HashCodeProvider constructor.
     */
    public HashCodeProvider(int initialPrime) {
        this(
            PRE_CALCULATED_PRIMES,
            initialPrime);
    }

    /**
     * The HashCodeProvider constructor.
     */
    public HashCodeProvider(int preCalculatedPrimes, int initialPrime) {
        this.prime = new Prime(preCalculatedPrimes);
        this.currentPrime = initialPrime;
    }

    /**
     * Gets the new content.
     */
    @Override
    public String get(String currContent, Matcher matcher) {
        int hashCodeTokenStartIndex = matcher.start(3);
        int hashCodeTokenEndIndex = matcher.end(3) - 1;

        int preTokenStartIndex = matcher.start(0);
        int preTokenEndIndex = hashCodeTokenStartIndex - 1;
        int preTokenLength = Indexes.size(preTokenStartIndex, preTokenEndIndex);

        int postTokenStartIndex = hashCodeTokenEndIndex + 1;
        int postTokenEndIndex = matcher.end(0) - 1;
        int postTokenLength = Indexes.size(postTokenStartIndex, postTokenEndIndex);

        String newHashCodeToken = "(" + this.nextPrime() + ", " + this.nextPrime() + ")";

        StringBuilder newContent = new StringBuilder();

        if (preTokenLength > 0) {
            String preToken = currContent.substring(preTokenStartIndex, preTokenEndIndex + 1);
            newContent.append(preToken);
        }

        newContent.append(newHashCodeToken);

        if (postTokenLength > 0) {
            String postToken = currContent.substring(postTokenStartIndex, postTokenEndIndex + 1);
            newContent.append(postToken);
        }

        return newContent.toString();
    }

    /**
     * Creates a new prime number.
     */
    private int nextPrime() {
        this.currentPrime = this.prime.getNextPrime(this.currentPrime);
        return this.currentPrime;
    }
}
