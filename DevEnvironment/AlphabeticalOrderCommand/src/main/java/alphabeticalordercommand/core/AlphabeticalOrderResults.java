package alphabeticalordercommand.core;

import alphabeticalordercommand.interfaces.IAlphabeticalOrderResults;
import base.core.ListIterator;
import base.interfaces.IIterator;
import java.util.ArrayList;
import java.util.List;

/**
 * The AlphabeticalOrderResults class implements results of an alphabetical order.
 */
public final class AlphabeticalOrderResults implements IAlphabeticalOrderResults {
    private final List<Character> characters = new ArrayList<>();

    /**
     * The AlphabeticalOrderResults constructor.
     */
    public AlphabeticalOrderResults() {
    }

    /**
     * Adds an alphabet.
     */
    public void add(char alphabet) {
        this.characters.add(alphabet);
    }

    /**
     * Gets an iterator for iterating over the results.
     */
    @Override
    public IIterator<Character> getIterator() {
        return ListIterator.of(this.characters);
    }
}
