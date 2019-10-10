package datastructures.graph.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IRoute interface defines a way or course taken in getting
 * from a starting vertex to a destination vertex in a graph.
 */
public interface IRoute<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<IRoute<TKey, TValue>> {
    /**
     * Gets the source vertex.
     */
    IVertex<TKey, TValue> source();

    /**
     * Gets the destination vertex.
     */
    IVertex<TKey, TValue> destination();
}
