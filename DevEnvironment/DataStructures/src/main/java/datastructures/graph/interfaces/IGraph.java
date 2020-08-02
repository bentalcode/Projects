package datastructures.graph.interfaces;

import base.interfaces.IUnaryComparator;
import base.interfaces.ICollection;
import java.util.Set;

/**
 * The IGraph interface defines a graph.
 */
public interface IGraph<TKey extends Comparable<TKey>, TValue> extends
    ICollection,
    IUnaryComparator<IGraph<TKey, TValue>> {

    /**
     * Gets the vertices of the graph.
     */
    Set<IVertex<TKey, TValue>> vertices();

    /**
     * Gets the edges of the graph.
     */
    Set<IEdge<TKey, TValue>> edges();

    /**
     * Gets the adjacency matrix.
     */
    IAdjacencyMatrix<TKey, TValue> getAdjacencyMatrix();

    /**
     * Gets the number of vertices in the graph.
     * The order is equal to |V(G)|.
     */
    int getOrder();

    /**
     * Gets the degree.
     * A vertex degree is the number of edges incident to a vertex. Notated as d(V).
     */
    int getDegree(IVertex<TKey, TValue> vertex);
}
