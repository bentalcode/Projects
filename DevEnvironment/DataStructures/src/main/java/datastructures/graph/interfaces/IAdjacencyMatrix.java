package datastructures.graph.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.Map;
import java.util.Set;

/**
 * The IAdjacencyMatrix interface defines an adjacency matrix of a graph.
 */
public interface IAdjacencyMatrix<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<IAdjacencyMatrix<TKey, TValue>> {
    /**
     * Gets the connections of an adjacency matrix.
     */
    Map<IVertex<TKey, TValue>, Set<IVertex<TKey, TValue>>> connections();

    /**
     * Checks whether two vertices are connected.
     */
    boolean connected(IVertex<TKey, TValue> sourceVertex, IVertex<TKey, TValue> destinationVertex);

    /**
     * Gets the adjacent vertices of a vertex.
     */
    Set<IVertex<TKey, TValue>> getAdjacentVertices(IVertex<TKey, TValue> vertex);

    /**
     * Gets the adjacent edges of a vertex.
     */
    Set<IEdge<TKey, TValue>> getAdjacentEdges(IVertex<TKey, TValue> vertex);
}
