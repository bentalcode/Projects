package datastructures.string.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.string.interfaces.ICircularString;

/**
 * The CircularStringReverseIterator class implements a reverse iterator of a circular string.
 */
public final class CircularStringReverseIterator implements IReverseIterator<Character> {
    private final ICircularString circularString;
    private int currIndex;

    /**
     * The CircularStringReverseIterator constructor.
     */
    public CircularStringReverseIterator(ICircularString circularString) {
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
        return this.currIndex >= 0;
    }

    /**
     * Gets the next element.
     */
    @Override
    public Character next() {
        assert(this.hasNext());

        char currCharacter = this.circularString.charAt(this.currIndex);
        --this.currIndex;

        return currCharacter;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currIndex = this.circularString.size() - 1;
    }
}
