package datastructures.tree.core;

import base.core.Conditions;
import datastructures.tree.interfaces.ITreeDataIterator;
import datastructures.tree.interfaces.IKeyIterator;
import java.util.Iterator;

/**
 * The KeyIterator class implements an iterator of keys of a B+ Tree.
 */
public final class KeyIterator<TKey extends Comparable<TKey>, TValue> implements IKeyIterator<TKey> {
    private final ITreeDataIterator<TKey, TValue> iterator;

    /**
     * The KeyIterator constructor.
     */
    public KeyIterator(ITreeDataIterator<TKey, TValue> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of data of a tree can not be null.");

        this.iterator = iterator;
    }

    /**
     * Gets an iterator for iterating over keys.
     */
    @Override
    public Iterator<TKey> iterator() {
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
    public TKey next() {
        return this.iterator.next().getKey();
    }

    /**
     * Removes the current key.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException("Removing data from a tree is not supported.");
    }
}
