package datastructures.graph.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The IWalk interface defines a walk in a graph.
 * A walk is a finite or infinite sequence of edges which joins a sequence of vertices.
 */
public interface IWalk<TKey extends Comparable<TKey>, TValue> extends
    IIterable<IVertex<TKey, TValue>>,
    IReverseIterable<IVertex<TKey, TValue>>,
    IUnaryComparator<IWalk<TKey, TValue>> {

    /**
     * Adds a vertex.
     */
    void addVertex(IVertex<TKey, TValue> vertex);

    /**
     * Removes the last vertex.
     */
    void removeLastVertex();

    /**
     * Gets the vertices.
     */
    List<IVertex<TKey, TValue>> getVertices();

    /**
     * Checks whether a vertex has been visited before.
     */
    boolean visited(IVertex<TKey, TValue> vertex);
}
