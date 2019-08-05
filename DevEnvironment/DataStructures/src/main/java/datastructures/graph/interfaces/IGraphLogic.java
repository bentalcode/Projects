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
}
