package datastructures.graph.core;

import base.core.Conditions;
import base.interfaces.IPair;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraphData;
import datastructures.graph.interfaces.IRoute;
import datastructures.graph.interfaces.IVertex;
import datastructures.graph.interfaces.IWalk;
import java.util.List;

/**
 * The GraphData class implements test data of a graph.
 */
public final class GraphData<TKey extends Comparable<TKey>, TValue> implements IGraphData<TKey, TValue> {
    private final List<IVertex<TKey, TValue>> vertices;
    private final List<IEdge<TKey, TValue>> edges;
    private final List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> paths;

    /**
     * The GraphData constructor.
     */
    public GraphData(
        List<IVertex<TKey, TValue>> vertices,
        List<IEdge<TKey, TValue>> edges,
        List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> paths) {

        Conditions.validateNotNull(
            vertices,
            "The vertices of a graph.");

        Conditions.validateNotNull(
            edges,
            "The edges of a graph.");

        Conditions.validateNotNull(
            paths,
            "The paths of a graph.");

        this.vertices = vertices;
        this.edges = edges;
        this.paths = paths;
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

    /**
     * Gets the paths for the defined routes in the graph.
     */
    @Override
    public List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> getPaths() {
        return this.paths;
    }
}
