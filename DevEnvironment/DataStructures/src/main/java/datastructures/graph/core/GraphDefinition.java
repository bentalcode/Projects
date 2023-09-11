package datastructures.graph.core;

import base.core.Conditions;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraphDefinition;
import datastructures.graph.interfaces.IVertex;
import java.util.List;

/**
 * The GraphDefinition class implements a definition of a graph.
 */
public final class GraphDefinition<TKey extends Comparable<TKey>, TValue> implements IGraphDefinition<TKey, TValue> {
    private final List<IVertex<TKey, TValue>> vertices;
    private final List<IEdge<TKey, TValue>> edges;

    /**
     * Creates new graph definition.
     */
    public static <TKey extends Comparable<TKey>, TValue> IGraphDefinition<TKey, TValue> make(
        List<IVertex<TKey, TValue>> vertices,
        List<IEdge<TKey, TValue>> edges) {

        return new GraphDefinition<>(vertices, edges);
    }

    /**
     * The GraphDefinition constructor.
     */
    public GraphDefinition(
        List<IVertex<TKey, TValue>> vertices,
        List<IEdge<TKey, TValue>> edges) {

        Conditions.validateNotNull(
            vertices,
            "The vertices of a graph.");

        Conditions.validateNotNull(
            edges,
            "The edges of a graph.");

        this.vertices = vertices;
        this.edges = edges;
    }

    /**
     * Gets the vertices of the graph.
     */
    @Override
    public List<IVertex<TKey, TValue>> vertices() {
        return this.vertices;
    }

    /**
     * Gets the edges of the graph.
     */
    @Override
    public List<IEdge<TKey, TValue>> edges() {
        return this.edges;
    }
}
