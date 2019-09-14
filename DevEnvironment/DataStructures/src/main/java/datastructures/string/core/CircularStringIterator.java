package datastructures.string.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.string.interfaces.ICircularString;

/**
 * The CircularStringIterator class implements an iterator of a circular string.
 */
public final class CircularStringIterator implements IIterator<Character> {
    private final ICircularString circularString;
    private int currIndex;

    /**
     * The CircularStringIterator constructor.
     */
    public CircularStringIterator(ICircularString circularString) {
        Conditions.validateNotNull(
            circularString,
            "The circular string.");

        this.circularString = circularString;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currIndex < this.circularString.size();
    }

    /**
     * Gets the next element.
     */
    @Override
    public Character next() {
        assert(this.hasNext());

        char currCharacter = this.circularString.charAt(this.currIndex);
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
