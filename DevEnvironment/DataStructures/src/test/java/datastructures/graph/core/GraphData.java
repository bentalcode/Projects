package datastructures.graph.core;

import base.core.Conditions;
import base.interfaces.IPair;
import base.interfaces.ITwoDimensionalList;
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
    private final ITwoDimensionalList<IVertex<TKey, TValue>> topologicalSearch;

    /**
     * The GraphData constructor.
     */
    public GraphData(
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
        this.paths = null;
        this.topologicalSearch = null;
    }

    /**
     * The GraphData constructor.
     */
    public GraphData(
        List<IVertex<TKey, TValue>> vertices,
        List<IEdge<TKey, TValue>> edges,
        List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> paths,
        ITwoDimensionalList<IVertex<TKey, TValue>> topologicalSearch) {

        Conditions.validateNotNull(
            vertices,
            "The vertices of a graph.");

        Conditions.validateNotNull(
            edges,
            "The edges of a graph.");

        Conditions.validateNotNull(
            paths,
            "The paths of a graph.");

        Conditions.validateNotNull(
            topologicalSearch,
            "The topologicalSearch of a graph.");

        this.vertices = vertices;
        this.edges = edges;
        this.paths = paths;
        this.topologicalSearch = topologicalSearch;
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

    /**
     * Gets the topological search of the graph.
     */
    @Override
    public ITwoDimensionalList<IVertex<TKey, TValue>> getTopologicalSearch() {
        return this.topologicalSearch;
    }
}
