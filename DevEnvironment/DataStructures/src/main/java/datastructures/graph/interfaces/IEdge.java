package datastructures.graph.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IUnaryComparator;

/**
 * The IEdge interface defines an edge of a graph.
 */
public interface IEdge<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<IEdge<TKey, TValue>> {
    /**
     * Gets a source vertex.
     */
    IVertex<TKey, TValue> source();

    /**
     * Gets a destination vertex.
     */
    IVertex<TKey, TValue> destination();

    /**
     * returns whether an edge is directed.
     */
    boolean directed();

    /**
     * Gets the comparator.
     */
    IBinaryComparator<IEdge<TKey, TValue>> getComparator();
}
