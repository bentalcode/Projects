package datastructures.graph.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IVertex interface defines a vertex of a graph.
 */
public interface IVertex<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<IVertex<TKey, TValue>> {
    /**
     * Gets a key of a vertex.
     */
    TKey getKey();

    /**
     * Gets a value of a vertex.
     */
    TValue getValue();
}
