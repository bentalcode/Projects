package datastructures.graph.interfaces;

import java.util.List;

/**
 * The IGraphDefinition interface defines a graph definition.
 */
public interface IGraphDefinition<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the vertices of the graph.
     */
    List<IVertex<TKey, TValue>> vertices();

    /**
     * Gets the edges of the graph.
     */
    List<IEdge<TKey, TValue>> edges();
}
