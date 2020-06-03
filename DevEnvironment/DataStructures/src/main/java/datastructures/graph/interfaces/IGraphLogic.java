package datastructures.graph.interfaces;

import java.util.List;
import java.util.Map;

/**
 * The IGraphLogic interface defines logic of a graph.
 */
public interface IGraphLogic<TKey extends Comparable<TKey>, TValue> {
    /**
     * Detects whether a graph contains a loop.
     */
    boolean detectLoop();

    /**
     * Performs a topological search of a graph.
     */
    List<IVertex<TKey, TValue>> topologicalSearch();

    /**
     * Finds paths by performing a Breadth-First search.
     */
    List<IWalk<TKey, TValue>> findPathsWithBreadthFirstSearch(IRoute<TKey, TValue> route);

    /**
     * Finds paths by performing a Depth-First search.
     */
    List<IWalk<TKey, TValue>> findPathsWithDepthFirstSearch(IRoute<TKey, TValue> route);

    /**
     * Finds the shortest paths from the source vertex to all other vertices in the given graph.
     */
    Map<IVertex<TKey, TValue>, Integer> findShortestPaths(
        IVertex<TKey, TValue> src,
        Map<IEdge<TKey, TValue>, Integer> weights);
}
