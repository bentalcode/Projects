package datastructures.collections.interfaces;

import base.interfaces.IIterable;

/**
 * The ICollection interface defines a collection.
 */
public interface ICollection<T extends Comparable<T>> extends
    IAbstractCollection,
    IIterable<T> {
}
