package hashcodecommand.core;

import base.core.Prime;
import base.core.Strings;
import basicio.interfaces.IContentProvider;
import java.util.regex.Matcher;

/**
 * The HashCodeProvider class implements a provider of a hash code.
 */
public final class HashCodeProvider implements IContentProvider {
    private static final int preCalculatedPrimes = 10000;

    private final Prime prime;
    private int currentPrime = 100;

    /**
     * The HashCodeProvider constructor.
     */
    public HashCodeProvider() {
        this(preCalculatedPrimes);
    }

    /**
     * The HashCodeProvider constructor.
     */
    public HashCodeProvider(int preCalculatedPrimes) {
        this.prime = new Prime(preCalculatedPrimes);
    }

    /**
     * Gets the new content.
     */
    @Override
    public String get(String currContent, Matcher matcher) {
        int hashCodeTokenStartIndex = matcher.start(3);
        int hashCodeTokenEndIndex = matcher.end(3);

        int preTokenStartIndex = matcher.start(0);
        int preTokenEndIndex = hashCodeTokenStartIndex - 1;
        int preTokenLength = Strings.length(preTokenStartIndex, preTokenEndIndex);

        int postTokenStartIndex = hashCodeTokenEndIndex + 1;
        int postTokenEndIndex = matcher.end(0);
        int postTokenLength = Strings.length(postTokenStartIndex, postTokenEndIndex);

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
