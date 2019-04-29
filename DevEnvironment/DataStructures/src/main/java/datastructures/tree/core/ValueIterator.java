package datastructures.tree.core;

import base.core.Conditions;
import datastructures.tree.interfaces.ITreeDataIterator;
import datastructures.tree.interfaces.IValueIterator;
import java.util.Iterator;

/**
 * The ValueIterator class implements an iterator of values of a B+ Tree.
 */
public final class ValueIterator<TKey extends Comparable<TKey>, TValue> implements IValueIterator<TValue> {
    private final ITreeDataIterator<TKey, TValue> iterator;

    /**
     * The ValueIterator constructor.
     */
    public ValueIterator(ITreeDataIterator<TKey, TValue> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of data of a tree.");

        this.iterator = iterator;
    }

    /**
     * Gets an iterator for iterating over keys.
     */
    @Override
    public Iterator<TValue> iterator() {
        return this;
    }

    /**
     * Checks whether there is a next key.
     */
    @Override
    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    /**
     * Gets the next key.
     */
    @Override
    public TValue next() {
        return this.iterator.next().getValue();
    }

    /**
     * Removes the current key.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException("Removing data from a tree is not supported.");
    }
}
