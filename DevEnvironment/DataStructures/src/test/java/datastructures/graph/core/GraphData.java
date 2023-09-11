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
import java.util.Map;

/**
 * The GraphData class implements test data of a graph.
 */
public final class GraphData<TKey extends Comparable<TKey>, TValue> implements IGraphData<TKey, TValue> {
    private final List<IVertex<TKey, TValue>> vertices;
    private final List<IEdge<TKey, TValue>> edges;
    private final Map<IEdge<TKey, TValue>, Integer> weights;
    private final List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> paths;
    private final ITwoDimensionalList<IVertex<TKey, TValue>> topologicalSearch;
    private final Map<IVertex<TKey, TValue>, Map<IVertex<TKey, TValue>, Integer>> shortestPaths;

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
        this.weights = null;
        this.paths = null;
        this.topologicalSearch = null;
        this.shortestPaths = null;
    }

    /**
     * The GraphData constructor.
     */
    public GraphData(
        List<IVertex<TKey, TValue>> vertices,
        List<IEdge<TKey, TValue>> edges,
        Map<IEdge<TKey, TValue>, Integer> weights,
        List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> paths,
        ITwoDimensionalList<IVertex<TKey, TValue>> topologicalSearch,
        Map<IVertex<TKey, TValue>, Map<IVertex<TKey, TValue>, Integer>> shortestPaths) {

        Conditions.validateNotNull(
            vertices,
            "The vertices of a graph.");

        Conditions.validateNotNull(
            edges,
            "The edges of a graph.");

        Conditions.validateNotNull(
            weights,
            "The weights of a graph.");

        Conditions.validateNotNull(
            paths,
            "The paths of a graph.");

        Conditions.validateNotNull(
            topologicalSearch,
            "The topologicalSearch of a graph.");

        Conditions.validateNotNull(
            topologicalSearch,
            "The shortest paths.");

        this.vertices = vertices;
        this.edges = edges;
        this.weights = weights;
        this.paths = paths;
        this.topologicalSearch = topologicalSearch;
        this.shortestPaths = shortestPaths;
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
     * Gets the weights of the graph.
     */
    @Override
    public Map<IEdge<TKey, TValue>, Integer> getWeights() {
        return this.weights;
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

    /**
     * Gets the shortest paths in the graph.
     */
    @Override
    public Map<IVertex<TKey, TValue>, Map<IVertex<TKey, TValue>, Integer>> getShortestPaths() {
        return this.shortestPaths;
    }
}
