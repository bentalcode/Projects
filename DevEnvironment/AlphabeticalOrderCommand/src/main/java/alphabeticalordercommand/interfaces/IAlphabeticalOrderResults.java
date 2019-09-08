package alphabeticalordercommand.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IIterator;

/**
 * The IAlphabeticalOrderResults interface defines results of an alphabetical order.
 */
public interface IAlphabeticalOrderResults extends IIterable<Character> {
    /**
     * Gets an iterator for iterating over the results.
     */
    IIterator<Character> getIterator();
}
