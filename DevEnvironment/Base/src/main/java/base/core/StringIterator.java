package base.core;

import base.interfaces.IIterator;

/**
 * The StringIterator class implements an iterator of a string.
 */
public final class StringIterator implements IIterator<Character> {
    private final String string;
    private int currIndex;

    /**
     * The StringIterator constructor.
     */
    public StringIterator(String string) {
        Conditions.validateNotNull(
            string,
            "The string.");

        this.string = string;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currIndex < this.string.length();
    }

    /**
     * Gets the next element.
     */
    @Override
    public Character next() {
        assert(this.hasNext());

        char currCharacter = this.string.charAt(this.currIndex);
        ++this.currIndex;

        return currCharacter;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currIndex = 0;
    }
}
