package datastructures.graph.interfaces;

import java.util.List;

/**
 * The IGraphLogic interface defines detection logic of a graph.
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
     * Find paths by performing a Breadth-First search.
     */
    List<IWalk<TKey, TValue>> findPathsWithBreadthFirstSearch(IRoute<TKey, TValue> route);

    /**
     * Find paths by performing a Depth-First search.
     */
    List<IWalk<TKey, TValue>> findPathsWithDepthFirstSearch(IRoute<TKey, TValue> route);
}
