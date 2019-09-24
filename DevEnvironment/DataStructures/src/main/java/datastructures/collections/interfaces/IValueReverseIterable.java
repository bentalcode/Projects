package datastructures.collections.interfaces;

import base.interfaces.IReverseIterator;

/**
 * The IValueReverseIterable interface defines a reverse iterable of values.
 */
public interface IValueReverseIterable<TValue> {
    /**
     * Gets the reverse iterator of values.
     */
    IReverseIterator<TValue> getValueReverseIterator();
}
